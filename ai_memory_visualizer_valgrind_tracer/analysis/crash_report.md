# Rapport de crash — crash_example

## 1. Description du crash

- Programme : `crash_example`
- Compilation : `make` (`-Wall -Wextra -Werror -pedantic -std=gnu89 -g`), aucun avertissement.
- Sortie observée (dans un terminal) :

```
crash_example: deterministic NULL dereference (segmentation fault)
  requesting n=0
Segmentation fault (core dumped)
```

- Code de retour : `139` = 128 + 11, 11 étant le numéro du signal `SIGSEGV`.
- Instruction fautive : `nums[0] = 42;` (`crash_example.c:32`). La ligne 34 (`printf` de `nums[0]`) n'est jamais atteinte.

## 2. Analyse de la cause racine

### 2.1 Chaîne causale

1. Ligne 25 : `n` vaut `0`.
2. Ligne 30 : `allocate_numbers(0)` est appelé.
3. Ligne 9-10 : `n <= 0` est vrai, la fonction renvoie `NULL` **avant** le `malloc` de la ligne 12. Aucun bloc n'est alloué.
4. Ligne 30 : `nums` reçoit `NULL`. Le retour n'est pas vérifié.
5. Ligne 32 : `nums[0] = 42` équivaut à `*(nums + 0) = 42`, soit une écriture de 4 octets à l'adresse `0x0`.
6. Le processeur détecte un accès à une page non mappée ; le noyau envoie `SIGSEGV` au processus, qui est terminé.

La cause racine n'est pas la ligne 32 seule : c'est l'**absence de vérification** de la valeur de retour à la ligne 30, alors que `allocate_numbers` documente par son code qu'elle peut renvoyer `NULL`.

### 2.2 Mémoire concernée : pile, tas ou aucune des deux ?

```
STACK (main)                      
nums = 0x0 (NULL) ──────►  adresse 0 : non mappée (ni pile, ni tas)
n    = 0
```

- `nums` et `n` sont des variables locales de `main`, sur la **pile**. Elles sont valides.
- L'adresse visée, `0x0`, n'appartient **ni à la pile ni au tas** : aucun bloc heap n'existe dans ce programme (le `malloc` n'est jamais exécuté).

## 3. Pourquoi l'accès mémoire est invalide

`NULL` ne désigne aucun objet : la norme C rend son déréférencement indéfini. En pratique, sous Linux, les pages des adresses basses (dont la page 0) ne sont jamais mappées dans l'espace d'adressage du processus. Toute lecture ou écriture à cette adresse provoque une faute de page que le noyau ne peut pas résoudre, d'où `SIGSEGV`.

- **Catégorie de comportement indéfini :** déréférencement d'un pointeur NULL (NULL pointer dereference), ici en **écriture**.
- **Pourquoi le crash est déterministe :** `n` est une constante (0), donc `nums` vaut `NULL` à chaque exécution, et l'adresse 0 n'est jamais mappée. Le résultat ne dépend ni de l'état du tas ni du hasard.

Remarque : en sortie redirigée vers un fichier ou un pipe (`./crash_example | cat`), les deux lignes de `printf` n'apparaissent pas. `stdout` y est mis en tampon par blocs, et le processus est tué avant que le tampon soit vidé. Ce n'est pas un signe que le crash a lieu plus tôt.

## 4. Critique des propositions de l'IA

Question posée à Claude (Claude Code) : « Quelles sont les causes possibles de ce segfault et les corrections possibles ? »

### 4.1 Causes proposées

- **« Déréférencement de `NULL` renvoyé par `allocate_numbers` »** — correct. Confirmé par la chaîne causale (section 2.1).
- **« `malloc(0)` a renvoyé `NULL` »** — faux. `malloc` n'est jamais appelé : la fonction sort ligne 10, avant la ligne 12.
- **« Échec de `malloc` par manque de mémoire »** — spéculatif et faux ici. Ce cas existe dans le code (ligne 13-14) mais n'est pas celui qui s'exécute : avec `n = 0`, on ne l'atteint pas.
- **« Le `free(nums)` provoque le crash »** — faux. Le programme meurt ligne 32 ; et `free(NULL)` est défini par la norme comme ne faisant rien.

### 4.2 Corrections proposées

- **Vérifier le retour : `if (!nums) return 1;` après la ligne 30** — correct. Traite la cause racine.
- **Remplacer `n = 0` par une valeur positive** — correct pour ce cas précis, mais insuffisant : le code reste fragile pour toute autre valeur nulle ou négative.
- **Faire `malloc(0)` au lieu de renvoyer `NULL` quand `n == 0`** — incorrect. `malloc(0)` peut renvoyer `NULL` ou un pointeur vers un bloc de taille 0 ; dans le second cas, `nums[0] = 42` devient une écriture hors limites dans le tas (heap buffer overflow). On remplace un crash visible par un comportement indéfini silencieux.
