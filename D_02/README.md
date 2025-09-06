# 📘 Documentation – FAQ sur le langage C

## Q1. Différence entre `%i` et `%d` ?

* `%d` : lit ou écrit un entier en **base 10**.
* `%i` : lit un entier mais détecte la **base** automatiquement (décimal, octal `0`, hexadécimal `0x`).
   En écriture (`printf`), `%i` et `%d` sont identiques.

---

## Q2. Comment afficher le caractère `%` avec `printf` ?

Il faut écrire `%%`. Exemple :

```c
printf("Taux: 50%%\n"); // affiche : Taux: 50%
```

---

## Q3. Que fait `\t` (tabulation) et où sont les tabulations ?

* `\t` avance le curseur jusqu’au **prochain multiple de 8 caractères** (souvent).
* La largeur dépend du terminal ou de l’éditeur.

---

## Q4. Que fait `scanf` si on entre une valeur non numérique ?

* `scanf` **échoue** : il laisse l’entrée invalide dans le buffer et ne modifie pas la variable.
   Il faut vider le buffer (`while (getchar() != '\n');`).

---

## Q5. Comment `scanf` "remet" des caractères ?

`scanf` lit seulement ce dont il a besoin et **laisse le reste dans le buffer**.
Exemple :

```c
scanf("%d", &x); // lit 123 dans "123abc"
```

* `x = 123`, et `"abc"` reste dans l’entrée pour la prochaine lecture.

---

## Q6. Que fait `scanf` si on met de la ponctuation entre les nombres ?

* Par défaut, `scanf` ignore les espaces, pas la ponctuation.
* Si l’utilisateur tape `1,2,3` et on fait `scanf("%d %d %d")`, la lecture échoue après `1`.

---

## Q7. Pourquoi `%` ne marche pas avec un flottant ?

L’opérateur `%` n’est défini **que pour les entiers**.
 Pour flottants, utiliser `fmod` de `<math.h>` :

```c
double r = fmod(5.5, 2.0); // r = 1.5
```

---

## Q8. Pourquoi `/` et `%` avec des négatifs sont compliqués ?

Parce que le standard C a dû définir un comportement portable :

* Le quotient est **tronqué vers 0**.
* Le reste suit la règle :

  ```
  (a/b)*b + (a%b) == a
  ```

---

## Q9. C a-t-il des rvalues ?

Oui .

* **lvalue** : une expression qui désigne un emplacement mémoire (`x`).
* **rvalue** : une valeur temporaire ou calculée (`x+1`).

---

## Q10. Pourquoi `v += e` ≠ `v = v + e` si `v` a un effet de bord ?

Exemple :

```c
a[i++] = a[i++] + 5; // non défini
a[i++] += 5;         // défini
```

L’évaluation des effets de bord diffère selon la syntaxe.

---

## Q11. Pourquoi `++` et `--` existent-ils ?

* Plus concis et lisibles.
* À l’origine, certains compilateurs pouvaient générer du code plus rapide, mais aujourd’hui c’est surtout une question de **syntaxe pratique**.

---

## Q12. `++` et `--` fonctionnent-ils avec `float` ?

Oui ✅.

```c
float x = 1.5;
x++; // x = 2.5
```

---

## Q13. Quand l’incrémentation (postfixe) a-t-elle lieu ?

* Postfixe (`i++`) : utilise d’abord la valeur, puis incrémente.
* Préfixe (`++i`) : incrémente puis utilise.

---

## Q14. Comment éviter la confusion `=` vs `==` ?

* Activer les **warnings** (`-Wall` avec GCC).
* Certains écrivent volontairement :

  ```c
  if (3 == x) // au lieu de x == 3
  ```

---

## Q15. Type de `(i > 0 ? i : f)` si `i` est `int` et `f` est `float` ?

Résultat : **float**.
C applique les conversions usuelles (promotion vers le type le plus large).

---

## Q16. Autres formes de `switch` ?

Oui :

* `switch` imbriqués.
* `case` groupés.
* `default` optionnel.

---

## Q17. Quelle indentation est meilleure pour `switch` ?

Pas de règle stricte, mais la plus lisible est :

```c
switch (x) {
    case 1:
        ...
        break;
    case 2:
        ...
        break;
    default:
        ...
}
```

---

## Q18. `while(1)` ou `for(;;)` pour boucle infinie ?

Les deux sont équivalents.

* `for(;;)` est plus classique en C.
* `while(1)` est plus lisible pour certains.

---

## Q19. Faut-il éviter `continue` ?

Non , ce n’est pas « interdit ».

* Utilisé à bon escient, `continue` rend le code plus clair.
* Mais un excès peut rendre la boucle moins lisible.

---

## Q20. Pourquoi `goto` est mal vu ?

Parce qu’il casse la **structure du programme** et rend le code spaghetti difficile à maintenir.
 À utiliser uniquement pour gérer des erreurs ou sorties multiples.

---

## Q21. Instruction nulle (`;`) a-t-elle d’autres usages ?

Oui :

```c
while (getchar() != '\n') ; // vider le buffer
```

---

## Q22. Autre manière de signaler une boucle vide ?

Oui, mettre le corps vide `{}` au lieu de `;`.

---

## Q23. Comment écrire un entier signé en octal ou hexadécimal ?

* `%o` → octal
* `%x` ou `%X` → hexadécimal
* Les entiers signés sont **convertis en non signés** avant affichage.

---

## Q24. Et si le nombre est négatif ?

Il sera affiché comme si c’était un entier non signé (complément à deux).

---

## Q25. Pourquoi les constantes flottantes sont en `double` par défaut ?

Parce que `double` est le type flottant standard le plus utilisé et plus précis que `float`.

---

## Q26. Constantes hexadécimales flottantes ?

Exemple :

```c
double x = 0x1.8p+1; // = 3.0
```

Utile pour exprimer exactement des valeurs binaires.

---

## Q27. Pourquoi `%lf` pour `scanf` et `%f` pour `printf` ?

* `scanf("%lf", &d)` lit un `double`.
* `printf("%f", d)` affiche un `double` (promotion automatique des floats vers double en arguments).

---

## Q28. Comment prononcer `char` ?

En anglais : **“car”** ou **“char”** (comme dans character).

---

## Q29. Quand l’importance du `char` signé ou non ?

* Quand on stocke des valeurs > 127.
* Utilisé en traitement de caractères étendus (UTF-8, etc.).

---

## Q30. Pourquoi `\n` est un saut de ligne ?

* Sur Unix/Linux : `\n = LF (line feed)`
* Sur Windows : `\r\n = CRLF`
* Le compilateur traduit automatiquement selon la plateforme.

---

## Q31. Pourquoi utiliser `scanf` au lieu de `getchar` ?

* `scanf` peut lire et convertir directement des nombres.
* `getchar` lit seulement un caractère brut.

---

## Q32. Promotions intégrales et `unsigned int` ?

Si `int` n’est pas assez grand pour contenir la valeur, un `char` ou `short` est promu en `unsigned int`.

---

## Q33. Affecter une valeur trop grande ?

Cela cause un **dépassement** : la valeur est tronquée ou wrap-around.
Exemple :

```c
char c = 300; // peut donner 44 selon la machine
```

---

## Q34. Pourquoi des définitions de type (`typedef`) ?

* Plus lisible, portable.
* Exemple :

  ```c
  typedef enum { false, true } Bool;
  ```
* Mieux qu’une macro `#define BOOL int` car le compilateur connaît vraiment le type.

---

## Q35. `sizeof` est-il toujours déterminable à la compilation ?

Oui  (sauf cas particuliers avec VLA - tableaux à longueur variable en C99).

---
