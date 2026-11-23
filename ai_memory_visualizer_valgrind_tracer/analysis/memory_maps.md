# Cartes mémoire — AI Memory Visualizer

## Sommaire

1. [Méthode](#1-méthode)
2. [stack_example.c](#2-stack_examplec)
3. [aliasing_example.c](#3-aliasing_examplec)

## 1. Méthode

### 1.1 Compilation

Commande de la consigne (`Makefile` fourni) :

```
make
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -o stack_example stack_example.c
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -o heap_example heap_example.c
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g -o aliasing_example aliasing_example.c
```

Résultat :

```
aliasing_example.c: In function ‘main’:
aliasing_example.c:45:34: error: pointer ‘b’ used after ‘free’ [-Werror=use-after-free=]
   45 |     printf("  wrote b[3]=%d\n", b[3]);
      |                                  ^
aliasing_example.c:38:5: note: call to ‘free’ here
   38 |     free(a);
      |     ^~~~~~~
aliasing_example.c:44:6: error: pointer ‘b’ used after ‘free’ [-Werror=use-after-free=]
   44 |     b[3] = 1234;
      |      ^
aliasing_example.c:38:5: note: call to ‘free’ here
   38 |     free(a);
      |     ^~~~~~~
aliasing_example.c:42:36: error: pointer ‘b’ used after ‘free’ [-Werror=use-after-free=]
   42 |     printf("  reading b[2]=%d\n", b[2]);
      |                                    ^
aliasing_example.c:38:5: note: call to ‘free’ here
   38 |     free(a);
      |     ^~~~~~~
aliasing_example.c:40:5: error: pointer ‘b’ used after ‘free’ [-Werror=use-after-free=]
   40 |     printf("  after free(a): b=%p (dangling)\n", (void *)b);
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
aliasing_example.c:38:5: note: call to ‘free’ here
   38 |     free(a);
      |     ^~~~~~~
cc1: all warnings being treated as errors
make: *** [Makefile:18: aliasing_example] Error 1
```

**Compilateur :** `gcc (GCC) 16.2.1 20260810`

**Explication de l'erreur :** depuis GCC 12, l'avertissement `-Wuse-after-free` est inclus dans `-Wall`. GCC voit que `b` reçoit la valeur de `a` (ligne 34), puis que `a` est passé à `free()` (ligne 38). Il en déduit que tout usage ultérieur de `b` (lignes 40, 42, 44, 45) porte sur un bloc libéré. Avec `-Werror`, cet avertissement devient une erreur et `make` s'arrête : `aliasing_example` n'est pas produit, et `crash_example`, qui vient après dans le `Makefile`, n'est même pas compilé. Le bug est donc détecté avant toute exécution, par simple analyse du code par le compilateur.

**Commande utilisée pour obtenir malgré tout le binaire :**

```
make aliasing_example crash_example CFLAGS="-Wall -Wextra -Werror -pedantic -std=gnu89 -g -Wno-error=use-after-free"
```

**Pourquoi :** la consigne demande d'exécuter le programme normalement, puis de l'analyser avec Valgrind. Ces deux étapes exigent un exécutable. L'option `-Wno-error=use-after-free` ne corrige rien et ne désactive aucun avertissement. Tous les flags de la consigne restent actifs, l'avertissement est toujours affiché, et le code source n'est pas modifié. Seul cet avertissement précis n'est plus traité comme une erreur bloquante. Le binaire produit contient donc toujours le use-after-free, qui peut alors être observé à l'exécution. Cette option, absente de la consigne, a été proposée par l'IA (Claude).

### 1.2 Exécution

Depuis `programs/`, sans Valgrind :

```
./stack_example
./aliasing_example
./heap_example
```

### 1.3 Utilisation de l'IA

- **Outil / modèle :** TODO
- **Prompt(s) :**

```
TODO
```

- **Méthode de vérification :** TODO (code source, adresses réelles affichées, ...)

### 1.4 Légende des schémas

```
TODO
```

---

## 2. stack_example.c

### 2.1 Ce que fait le programme

- Le but du programme est de montrer le comportement de la mémoire sur la pile (stack) en créant des variables et en imprimant leurs adresses, la valeur du pointeur `p_local` et la valeur contenue dans `local_int`. Pour ce faire, `main` appelle `walk_stack(0, 3)`, qui s'appelle elle-même récursivement jusqu'à `depth = 3`. À chaque niveau, `walk_stack` appelle deux fois `dump_frame` (à l'entrée, `"enter"`, et après le retour de l'appel récursif, `"exit"`), qui déclare ses variables en fonction de `depth` et les affiche.
- Appels : `walk_stack` est appelée 4 fois (depth 0 à 3), `dump_frame` 8 fois. Les `[exit]` sortent dans l'ordre inverse des `[enter]` (3 → 0)
- Le programme n'utilise pas le tas : aucun `malloc`.

### 2.2 Sortie réelle

```
stack_example: recursion and stack frames
[enter] depth=0
  &local_int=0x7fff72fa6c54  p_local=0x7fff72fa6c54  local_int=100
  local_buf=0x7fff72fa6c60  local_buf[0]=A
  &marker=0x7fff72fa6ca4  marker=0
[enter] depth=1
  &local_int=0x7fff72fa6c24  p_local=0x7fff72fa6c24  local_int=101
  local_buf=0x7fff72fa6c30  local_buf[0]=B
  &marker=0x7fff72fa6c74  marker=10
[enter] depth=2
  &local_int=0x7fff72fa6bf4  p_local=0x7fff72fa6bf4  local_int=102
  local_buf=0x7fff72fa6c00  local_buf[0]=C
  &marker=0x7fff72fa6c44  marker=20
[enter] depth=3
  &local_int=0x7fff72fa6bc4  p_local=0x7fff72fa6bc4  local_int=103
  local_buf=0x7fff72fa6bd0  local_buf[0]=D
  &marker=0x7fff72fa6c14  marker=30
[exit] depth=3
  &local_int=0x7fff72fa6bc4  p_local=0x7fff72fa6bc4  local_int=103
  local_buf=0x7fff72fa6bd0  local_buf[0]=D
  &marker=0x7fff72fa6c14  marker=30
[exit] depth=2
  &local_int=0x7fff72fa6bf4  p_local=0x7fff72fa6bf4  local_int=102
  local_buf=0x7fff72fa6c00  local_buf[0]=C
  &marker=0x7fff72fa6c44  marker=20
[exit] depth=1
  &local_int=0x7fff72fa6c24  p_local=0x7fff72fa6c24  local_int=101
  local_buf=0x7fff72fa6c30  local_buf[0]=B
  &marker=0x7fff72fa6c74  marker=10
[exit] depth=0
  &local_int=0x7fff72fa6c54  p_local=0x7fff72fa6c54  local_int=100
  local_buf=0x7fff72fa6c60  local_buf[0]=A
  &marker=0x7fff72fa6ca4  marker=0
```

### 2.3 Déroulé de l'exécution

Adresses abrégées (`…6ca4` = `0x7fff72fa6ca4`). Adresses hautes en haut du schéma.

#### Étape 1 — `main` appelle `walk_stack(0, 3)` (lignes 35, 19-21)

```
PILE                                         TAS
+--------------------------------------+     (vide, jamais utilisé)
| main         (aucune variable locale) |
+--------------------------------------+
| walk_stack(0) depth=0 max_depth=3    |
|   marker = 0            @ …6ca4      |
+--------------------------------------+
```

Une frame est créée pour `walk_stack(0)`. `depth`, `max_depth` et `marker` naissent avec elle.

#### Étape 2 — `dump_frame("enter", 0)` (lignes 22, 3-17)

```
PILE
+--------------------------------------+
| walk_stack(0)  marker = 0  @ …6ca4   |
+--------------------------------------+
| dump_frame(0)                        |
|   local_buf = "A"         @ …6c60    |
|   local_int = 100         @ …6c54 <--+--+
|   p_local   = …6c54  ----------------+--+  alias de local_int
+--------------------------------------+
```

`p_local` contient l'adresse de `local_int` : `*p_local` et `local_int` désignent la même case. À la ligne 17, la frame est détruite : `local_int`, `local_buf` et `p_local` meurent.

#### Étape 3 — Récursion jusqu'à depth 3 (ligne 26)

```
PILE
+--------------------------------------+
| walk_stack(0)  marker = 0   @ …6ca4  |
| walk_stack(1)  marker = 10  @ …6c74  |
| walk_stack(2)  marker = 20  @ …6c44  |
| walk_stack(3)  marker = 30  @ …6c14  |
+--------------------------------------+
| dump_frame(3)                        |
|   local_buf = "D"   @ …6bd0          |
|   local_int = 103   @ …6bc4          |
|   p_local   = …6bc4 (alias)          |
+--------------------------------------+   <- sommet de la pile (adresse la plus basse)
```

Pile au maximum : 4 frames `walk_stack` vivantes en même temps, chacune 0x30 (48) octets sous la précédente. Avant chaque appel récursif, un `dump_frame("enter", d)` a été créé puis détruit.

#### Étape 4 — Dépilement (lignes 28, 30)

`walk_stack(3)` ne s'appelle plus (`depth == max_depth`). Elle appelle `dump_frame("exit", 3)`, puis se termine. Ensuite `walk_stack(2)` reprend après la ligne 26, et ainsi de suite jusqu'à `walk_stack(0)`.

Chaque `dump_frame("exit", d)` est une **nouvelle** frame : ses variables sont de nouveaux objets, placés aux mêmes adresses que ceux du `"enter"` (déjà détruits), parce que le sommet de pile est au même endroit.

#### Étape 5 — Retour dans `main` (ligne 36)

Toutes les frames `walk_stack` et `dump_frame` sont détruites. Il ne reste que la frame de `main`. Le tas n'a jamais été utilisé.

### 2.4 Durées de vie des variables

Toutes sur la pile :

- `depth`, `max_depth` (`walk_stack`) : naissent l. 19, meurent l. 30
- `marker` (`walk_stack`) : naît l. 21, meurt l. 30 (survit aux appels récursifs)
- `label`, `depth` (`dump_frame`) : naissent l. 3, meurent l. 17
- `local_int` (`dump_frame`) : naît l. 5, meurt l. 17 (8 instances distinctes)
- `local_buf` (`dump_frame`) : naît l. 6, meurt l. 17
- `p_local` (`dump_frame`) : naît l. 7, meurt l. 17

### 2.5 Ce que montrent les adresses réelles

- **La pile grandit vers les adresses basses** : `marker` passe de `…6ca4` (depth 0) à `…6c74` (depth 1), soit −0x30 (48 octets) par niveau.
- **Même adresse entre `enter` et `exit`** : pour `marker`, c'est la même variable, toujours vivante. Pour `local_int`, ce sont deux variables distinctes placées au même endroit.
- **L'ordre des déclarations n'impose pas l'ordre en mémoire** : `local_buf` est déclaré après `local_int` mais placé plus haut (`…6c60` > `…6c54`). C'est le compilateur qui décide.
- **ASLR** : d'une exécution à l'autre, les adresses changent (`0x7fff72fa…` puis `0x7ffe65be…`), mais les écarts entre variables restent identiques.

### 2.6 Revue de l'IA

Je n'ai trouvé aucune incohérences notable venant de l'IA. Elle m'a plutôt aidé même a comprendre, en complement de python tutor, l'entièreté du code et à mettre en page ce document. La seule chose à noté est qu'elle s'obstinait à me faire compiler avec des flag dont holberton nous avait jamais parlé (-Wno-error=use-after-free) alors qu'il suffisait d'enlever les flag originaux qui transforme les warnings en erreurs pour pouvoir aller au bout de la compilation.

## 3. aliasing_example.c

### 3.1 Ce que fait le programme

- `main` appelle `make_numbers(5)`, qui alloue sur le tas un tableau de 5 `int` (`0, 11, 22, 33, 44`) et renvoie son adresse dans `a`.
- `b = a` : `a` et `b` deviennent des alias du même bloc.
- `free(a)` libère le bloc, puis le programme continue à le lire et à l'écrire via `b` : c'est un use-after-free volontaire.

### 3.2 Sortie réelle

```
aliasing_example: aliasing and use-after-free (Valgrind should report it)
  a=0x55a5044ad420 b=0x55a5044ad420 a[2]=22 b[2]=22
  after free(a): b=0x55a5044ad420 (dangling)
  reading b[2]=1751512379
  wrote b[3]=1234
```

Relancé 3 fois, `b[2]` après `free` vaut à chaque fois une valeur différente (`224606846`, `1363590441`, `318052203`).

### 3.3 Déroulé de l'exécution

Adresses abrégées (`…d420` = `0x55a5044ad420`).

#### Étape 1 — Début de `main` (lignes 24-26)

```
PILE                                    TAS
+-------------------------------+       (vide)
| main                          |
|   a = NULL                    |
|   b = NULL                    |
|   n = 5                       |
+-------------------------------+
```

#### Étape 2 — `make_numbers(5)` alloue le bloc (lignes 4-19)

```
PILE                                    TAS
+-------------------------------+
| main   a = NULL  b = NULL     |
+-------------------------------+       +---------------------------+
| make_numbers  n = 5  i        |       | @ …d420  (20 octets)      |
|   arr = …d420  --------------------->  | 0 | 11 | 22 | 33 | 44     |
+-------------------------------+       +---------------------------+
```

`malloc` (l. 12) crée le bloc sur le tas. `arr` est une variable de la pile qui contient son adresse.

#### Étape 3 — Retour de `make_numbers` (lignes 19, 30)

```
PILE                                    TAS
+-------------------------------+       +---------------------------+
| main                          |       | @ …d420                   |
|   a = …d420  ------------------------> | 0 | 11 | 22 | 33 | 44     |
|   b = NULL                    |       +---------------------------+
+-------------------------------+
```

La frame de `make_numbers` est détruite : `arr`, `i` et `n` meurent. Le bloc, lui, **survit** : un bloc du tas ne meurt qu'au `free`. Son adresse a été copiée dans `a`, qui en devient propriétaire.

#### Étape 4 — `b = a` (ligne 34)

```
PILE                                    TAS
+-------------------------------+       +---------------------------+
| main                          |       | @ …d420                   |
|   a = …d420  ------------------------> | 0 | 11 | 22 | 33 | 44     |
|   b = …d420  ------------------------> |                           |
+-------------------------------+       +---------------------------+
```

`b` reçoit une copie de l'adresse, pas une copie du tableau. `a` et `b` sont des alias : un seul bloc, deux pointeurs.

#### Étape 5 — `free(a)` (ligne 38)

```
PILE                                    TAS
+-------------------------------+       +---------------------------+
| main                          |       | @ …d420  LIBÉRÉ           |
|   a = …d420  (pendant)  ------------> | métadonnées glibc | ...   |
|   b = …d420  (pendant)  ------------> |                           |
+-------------------------------+       +---------------------------+
```

Le bloc est rendu à l'allocateur, sa durée de vie est terminée. `free` ne modifie ni `a` ni `b` : ils contiennent toujours `…d420`, mais pointent vers une mémoire qui n'appartient plus au programme. **Les deux** sont des pointeurs pendants (dangling), pas seulement `a`.

#### Étape 6 — Accès via `b` (lignes 40-45)

- l. 40 : affiche la **valeur** de `b`, sans lire le bloc.
- l. 42 : lit `b[2]` dans le bloc libéré.
- l. 44 : écrit `1234` dans `b[3]` du bloc libéré.
- l. 45 : relit `b[3]`.

Le programme se termine normalement (l. 47) : pas de crash, mais un comportement indéfini.

### 3.4 Durées de vie et propriété

- `a`, `b`, `n` (`main`, pile) : naissent l. 24-26, meurent à la fin de `main` (l. 48)
- `n`, `i`, `arr` (`make_numbers`, pile) : naissent l. 4-7, meurent l. 20
- Bloc de 5 `int` (tas) : naît l. 12, meurt l. 38
- Propriétaire du bloc : `arr` (l. 12), puis `a` (l. 30). `b` (l. 34) est un simple alias, il ne doit pas libérer le bloc.

### 3.5 Bugs identifiés

- **l. 42 — lecture après libération** via `b` : `b[2]` ne vaut plus `22`, mais une valeur différente à chaque exécution.
- **l. 44 — écriture après libération** via `b` : écrase la mémoire de l'allocateur.
- **l. 45 — lecture après libération** via `b`.
- **l. 40** : ce n'est pas un accès mémoire au bloc, seule la valeur du pointeur est affichée. Le compilateur la signale quand même, car utiliser la valeur d'un pointeur après `free` est déjà indéfini selon la norme C.
- Potentiels risque de double free également dans ce type de code.
