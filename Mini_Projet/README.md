# Mini-Projet : Système de Gestion de Stock dans une Librairie

## Objectif
- Le projet consiste à créer un programme en C qui permet de gérer le stock de livres dans une librairie. Le programme doit offrir les fonctionnalités suivantes :
1. Ajouter un livre au stock.
2. Afficher tous les livres disponibles.
3. Rechercher un livre par son titre.(strcmp)
4. Mettre à jour la quantité d'un livre.(*l)
5. Supprimer un livre du stock.
6. Afficher le nombre total de livres en stock.

## Détails du Projet

### 1. Ajouter un Livre au Stock
- Le programme demande les informations suivantes pour chaque livre :
  - Titre du livre.
  - Auteur du livre.
  - Prix du livre.
  - Quantité en stock.
- Les informations sont stockées dans des tableaux distincts pour chaque attribut (titre, auteur, prix, quantité).

### 2. Afficher Tous les Livres Disponibles
- Le programme parcourt les tableaux et affiche les détails de chaque livre (titre, auteur, prix, quantité).

### 3. Mettre à Jour la Quantité d'un Livre
- Le programme permet de modifier la quantité en stock pour un livre donné.
- L'utilisateur spécifie le titre du livre et la nouvelle quantité.

### 4. Supprimer un Livre du Stock
- Le programme permet de supprimer un livre du stock en fonction de son titre.
- Après la suppression, le livre n'apparaît plus dans la liste des livres disponibles.

### 5. Afficher le Nombre Total de Livres en Stock
- Le programme calcule et affiche le nombre total de livres en stock, en additionnant les quantités de tous les livres.

## Fonctionnalités Requises
- **Variables** : Pour stocker les informations des livres (titre, auteur, prix, quantité).
- **Conditions** : Pour rechercher un livre, mettre à jour la quantité, et supprimer un livre.
- **Boucles** : Pour parcourir les livres et afficher leurs détails.
- **Tableaux** : Pour stocker plusieurs attributs des livres.


### documentation ###
1. strcmp vs strcasecmp en C
- strcmp

- Prototype : int strcmp(const char *s1, const char *s2);
- 
- Fonction : Compare deux chaînes de caractères sensibles à la casse.

- Valeur de retour :
```c
< 0 si s1 < s2

0 si s1 == s2

> 0 si s1 > s2
```
###  Exemple :
```c
#include <stdio.h>
#include <string.h>

int main() {
    printf("%d\n", strcmp("Hello", "Hello")); // 0
    printf("%d\n", strcmp("Hello", "hello")); // négatif (car 'H' < 'h')
    return 0;
}
```
- strcasecmp (non standard C, mais disponible dans POSIX)
- 
- Prototype : int strcasecmp(const char *s1, const char *s2);
- 
- Fonction : Compare deux chaînes sans tenir compte de la casse.
- 
- Valeur de retour : même logique que strcmp.

###  Exemple :
```c
#include <stdio.h>
#include <strings.h> // POSIX

int main() {
    printf("%d\n", strcasecmp("Hello", "hello")); // 0 (insensible à la casse)
    return 0;
}
```

###  Résumé :

- strcmp : sensible à la casse (A ≠ a).
- 
- strcasecmp : insensible à la casse (A == a).

2. Search Algorithms
### A. Linear Search (Recherche linéaire)
- Pseudocode
- LINEAR_SEARCH(array, n, target):
```c
    for i from 0 to n-1:
        if array[i] == target:
            return i
    return -1
```
### Implémentation en C
```c
#include <stdio.h>

int linear_search(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target)
            return i; // trouvé
    }
    return -1; // non trouvé
}

int main() {
    int arr[] = {3, 7, 1, 9, 5};
    int n = 5, target = 9;

    int result = linear_search(arr, n, target);

    if(result != -1)
        printf("Élément trouvé à l'indice %d\n", result);
    else
        printf("Élément non trouvé\n");

    return 0;
}
```
### B. Binary Search (Recherche dichotomique)

-  Nécessite un tableau trié.

- Pseudocode
- BINARY_SEARCH(array, left, right, target):
```c
    while left <= right:
        mid = (left + right) / 2
        if array[mid] == target:
            return mid
        else if array[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```
### Implémentation en c
```c
#include <stdio.h>

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // non trouvé
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = 5, target = 7;

    int result = binary_search(arr, n, target);

    if(result != -1)
        printf("Élément trouvé à l'indice %d\n", result);
    else
        printf("Élément non trouvé\n");

    return 0;
}
```

###  Différence entre les deux algorithmes :

- Linear Search : simple, fonctionne sur n’importe quel tableau (non trié), mais temps O(n).

- Binary Search : plus rapide (O(log n)), mais exige un tableau trié.