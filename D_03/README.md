
#  Documentation – Tableaux en langage C

## Q1 : Pourquoi les indices de tableau commencent-ils à 0 au lieu de 1 ?

En C (et dans la majorité des langages proches du matériel), un tableau est implémenté comme une **adresse mémoire de base** plus un **décalage**.

* L’élément `a[i]` est en fait équivalent à :

  ```c
  *(a + i)
  ```
* Donc si `i = 0`, on accède directement à l’adresse de base du tableau (`a`).
* Si les indices commençaient à 1, le calcul de l’adresse serait moins naturel et moins efficace au niveau machine.

 **Conclusion** : Les indices commencent à 0 pour des raisons d’efficacité et de simplicité d’adressage mémoire.

---

## Q2 : Que faire si je veux un tableau avec des indices allant de 1 à 10 au lieu de 0 à 9 ?

En C, les tableaux **commencent toujours à 0**. Mais tu peux « simuler » un tableau de 1 à 10 :

1. **Solution simple** : Déclarer un tableau de taille 11 et ignorer l’indice 0.

   ```c
   int tab[11]; // tab[1] à tab[10] utilisés
   ```
2. **Solution avancée** : Utiliser un pointeur :

   ```c
   int tab[10];
   int *p = tab - 1; // maintenant p[1] correspond à tab[0]
   ```

    Cette technique est risquée et peu lisible, donc à éviter.

---

## Q3 : Est-il possible d'utiliser un caractère comme indice de tableau ?

Oui , car en C un caractère (`char`) est représenté par son **code ASCII** (un entier).

Exemple :

```c
int freq[128]; // tableau pour compter fréquences
char c = 'A';
freq[c]++; // équivalent à freq[65]++ car 'A' vaut 65 en ASCII
```

 On utilise souvent cette technique pour manipuler les alphabets ou compter des fréquences de caractères.

---

## Q4 : Initialisateur désigné et multiple affectations

Exemple donné :

```c
int a[] = {4, 9, 1, 8, [0] = 5, 7};
```

* Ici `[0] = 5` réaffecte la première case du tableau (`a[0]`).
* Le standard C autorise qu’un élément soit initialisé plus d’une fois, mais **la dernière initialisation prévaut**.
* Le compilateur calcule la taille du tableau à partir du plus grand indice utilisé.

 Résultat :

* Le tableau `a` contient **6 éléments**.
* Contenu :

  ```
  a[0] = 5
  a[1] = 9
  a[2] = 1
  a[3] = 8
  a[4] = 7
  a[5] = 0 (par défaut car non initialisé)
  ```

---

## Q5 : Pourquoi je ne peux pas copier un tableau avec l’opérateur `=` ?

En C, les tableaux **ne sont pas affectables**.

* Tu ne peux pas écrire :

  ```c
  int a[5], b[5];
  a = b; //  Erreur
  ```
* Parce qu’un tableau est traité comme une **adresse constante** en mémoire, pas comme un objet copiable.

 **Solutions** :

* Utiliser une boucle `for` pour copier élément par élément :

  ```c
  for (int i = 0; i < 5; i++) {
      a[i] = b[i];
  }
  ```
* Ou utiliser `memcpy` de `<string.h>` :

  ```c
  memcpy(a, b, sizeof(a));
  ```
  