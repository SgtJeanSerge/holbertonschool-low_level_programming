# Analyse Valgrind

## 1. Méthode

- Programmes analysés : `heap_example`, `aliasing_example`
- Compilation : `make` (`-Wall -Wextra -Werror -pedantic -std=gnu89 -g`)
- Commande :

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./<programme>
```

- Rôle des options : <!-- une ligne par option : pourquoi elle est utile -->

---

## 2. heap_example

### 2.1 Sortie Valgrind (extrait utile)

```
  ==522== Memcheck, a memory error detector
  ==522== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
  ==522== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
  ==522== Command: ./heap_example
  ==522==
  heap_example: allocations and a deliberate leak
    alice=0x4a73480 name=0x4a734d0 age=30
    bob=0x4a73520 name=0x4a73570 age=41
  ==522==
  ==522== HEAP SUMMARY:
  ==522==     in use at exit: 6 bytes in 1 blocks
  ==522==   total heap usage: 5 allocs, 4 frees, 1,066 bytes allocated
  ==522==
  ==522== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
  ==522==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
  ==522==    by 0x1091CD: person_new (heap_example.c:21)
  ==522==    by 0x1092AE: main (heap_example.c:51)
  ==522==
  ==522== LEAK SUMMARY:
  ==522==    definitely lost: 6 bytes in 1 blocks
  ==522==    indirectly lost: 0 bytes in 0 blocks
  ==522==      possibly lost: 0 bytes in 0 blocks
  ==522==    still reachable: 0 bytes in 0 blocks
  ==522==         suppressed: 0 bytes in 0 blocks
  ==522==
  ==522== For lists of detected and suppressed errors, rerun with: -s
  ==522== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

### 2.2 Erreur n°1 — `6 bytes in 1 blocks are definitely lost`

- **Type d'erreur :** Fuite mémoire 
- **Objet mémoire :** bloc heap de 6 octets contenant `"Alice\0"` (5 caractères + `'\0'`), alloué par `malloc(len + 1)` dans `person_new` (`heap_example.c:21`), appelé depuis `main` (`heap_example.c:51`, `alice = person_new("Alice", 30)`).
- **Propriétaire :** le champ `alice->name`, c'est-à-dire un pointeur rangé **dans** la struct `Person` d'alice (bloc heap de 16 octets). C'est le seul pointeur vers ce bloc.
- **Violation de durée de vie :** `person_free_partial(alice)` (ligne 69) exécute seulement `free(p)` (ligne 41). La struct est libérée avant le nom : le champ `name` disparaît avec elle, et le bloc `"Alice\0"` reste alloué sans aucun pointeur pour le retrouver.

**Explication :**

```
Avant la ligne 69 :
STACK (main)        HEAP
alice ──────►  [ Person 16 o ]
               │ name ──────►  [ "Alice\0" 6 o ]
               │ age = 30

Après free(p) (ligne 41) :
alice ──────►  [ libéré ]
                              [ "Alice\0" 6 o ]  ← plus aucun pointeur
```

1. Ligne 21 : le nom est alloué sur le heap ; son adresse n'est stockée que dans `p->name`.
2. Ligne 69 → 41 : `free(p)` rend la struct au heap. Le pointeur `name` qu'elle contenait n'est plus accessible.
3. Fin du programme : Valgrind compte 5 `malloc` pour 4 `free`, et ne trouve aucun pointeur vers le bloc restant, d'où `definitely lost`.

## 3. aliasing_example

### 3.1 Sortie Valgrind (extrait utile)

==526== Memcheck, a memory error detector
==526== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==526== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==526== Command: ./stack_example
==526== 
stack_example: recursion and stack frames
[enter] depth=0
  &local_int=0x1fff000284  p_local=0x1fff000284  local_int=100
  local_buf=0x1fff000290  local_buf[0]=A
  &marker=0x1fff0002d4  marker=0
[enter] depth=1
  &local_int=0x1fff000254  p_local=0x1fff000254  local_int=101
  local_buf=0x1fff000260  local_buf[0]=B
  &marker=0x1fff0002a4  marker=10
[enter] depth=2
  &local_int=0x1fff000224  p_local=0x1fff000224  local_int=102
  local_buf=0x1fff000230  local_buf[0]=C
  &marker=0x1fff000274  marker=20
[enter] depth=3
  &local_int=0x1fff0001f4  p_local=0x1fff0001f4  local_int=103
  local_buf=0x1fff000200  local_buf[0]=D
  &marker=0x1fff000244  marker=30
[exit] depth=3
  &local_int=0x1fff0001f4  p_local=0x1fff0001f4  local_int=103
  local_buf=0x1fff000200  local_buf[0]=D
  &marker=0x1fff000244  marker=30
[exit] depth=2
  &local_int=0x1fff000224  p_local=0x1fff000224  local_int=102
  local_buf=0x1fff000230  local_buf[0]=C
  &marker=0x1fff000274  marker=20
[exit] depth=1
  &local_int=0x1fff000254  p_local=0x1fff000254  local_int=101
  local_buf=0x1fff000260  local_buf[0]=B
  &marker=0x1fff0002a4  marker=10
[exit] depth=0
  &local_int=0x1fff000284  p_local=0x1fff000284  local_int=100

### 3.2 Erreur n°1 — `Invalid read of size 4` (ligne 42)

- **Type d'erreur :** use-after-free en lecture.
- **Accès :** `b[2]`, lu pour le `printf` de la ligne 42.
- **Position dans le bloc :** `b[2]` = 2 × 4 = **8 octets** après le début du bloc de 20 octets.
- **Taille :** 4 octets, la taille d'un `int`.
- **Alias utilisé :** `b`, alors que le bloc a été libéré via `a`.

**Explication :** à la ligne 38, le bloc a été rendu à l'allocateur. La lecture de `b[2]` porte sur une mémoire dont la durée de vie est terminée. Le résultat est indéfini : l'allocateur a pu réutiliser ces octets pour ses propres métadonnées, donc la valeur affichée n'est pas forcément `22`. Le programme ne plante pas, ce qui rend le bug invisible sans Valgrind.

### 3.3 Erreur n°2 — `Invalid write of size 4` (ligne 44)

- **Type d'erreur :** use-after-free en écriture.
- **Accès :** `b[3] = 1234;`
- **Position dans le bloc :** `b[3]` = 3 × 4 = **12 octets** après le début du bloc.
- **Taille :** 4 octets.
- **Alias utilisé :** `b`.

**Explication :** c'est l'erreur la plus grave des trois. Une lecture après libération renvoie une valeur fausse ; une écriture **modifie** une mémoire qui n'appartient plus au programme. Si l'allocateur a réutilisé ce bloc (pour ses métadonnées ou pour un `malloc` suivant), l'écriture corrompt ces données, et le plantage peut survenir beaucoup plus loin, sans lien apparent avec la ligne 44.

### 3.4 Erreur n°3 — `Invalid read of size 4` (ligne 45)

- **Type d'erreur :** use-after-free en lecture.
- **Accès :** `b[3]`, relu pour le `printf` de la ligne 45.
- **Position dans le bloc :** **12 octets** après le début du bloc.
- **Taille :** 4 octets.
- **Alias utilisé :** `b`.

**Explication :** même mécanisme que l'erreur n°1. Le fait que la ligne 44 ait écrit `1234` à cet endroit ne rend pas la lecture valide : le bloc reste libéré. Si la valeur affichée est bien `1234`, c'est par hasard (personne n'a réutilisé ces octets entre-temps), pas parce que l'accès est correct.

### 3.5 Bilan des fuites

Aucune fuite : le seul bloc alloué par le programme (ligne 12) est libéré ligne 38. Valgrind doit afficher `All heap blocks were freed -- no leaks are possible`.

Ce programme montre l'erreur **inverse** de `heap_example` : là-bas, le bloc vivait trop longtemps (jamais libéré) ; ici, il est libéré **trop tôt**, alors qu'un alias (`b`) s'en sert encore.

## 4. Revue de l'IA

### 4.1 Affirmation de l'IA

Outil : Claude (Claude Code), à qui j'ai demandé une structure pour ce fichier. Il a prévu **2 erreurs** pour `aliasing_example` : « une lecture et une écriture après `free` ».

### 4.2 Pourquoi elle est incomplète

L'IA a raisonné par **type** d'erreur, alors que Valgrind signale chaque **accès** invalide séparément. Après `free(a)` (ligne 38), il y a trois accès via `b` : elle a oublié la relecture de `b[3]` à la ligne 45, qui ressemble à la lecture de la ligne 42. Ma carte mémoire de la tâche 0 (`memory_maps.md`, section 3.5) listait déjà ces trois accès.

### 4.3 Correction

Trois use-after-free, confirmés par `ERROR SUMMARY: 3 errors from 3 contexts` :

- ligne 42 : `Invalid read of size 4` (`b[2]`, 8 octets dans le bloc) ;
- ligne 44 : `Invalid write of size 4` (`b[3]`, 12 octets dans le bloc) ;
- ligne 45 : `Invalid read of size 4` (`b[3]`, 12 octets dans le bloc).
