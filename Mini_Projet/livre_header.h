#ifndef LIVRE_FUNCTION_H
#define LIVRE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Définition de la structure du livre
typedef struct {
    char isbn[30];//les ajouter comme une structure sous structure
    char titre[30];
    char auteur[30];
    float prix;
    int quantite;
} livre;

void menue();
// Ajouter un Livre au Stock
void ajouter_livre(livre l[], int *n, int *count);

// Afficher Tous les Livres Disponibles
void afficher_livre(livre l[], int n);

//Rechercher un livre par son titre
void rechercher_livre1(livre l[], int n, char titre[30]);

// Rechercher livre par isbn
int rehercher_livre2(livre l[], int n, char ISBN[30]);

// Mettre à Jour la Quantité d'un Livre
void mettre_quantite(livre *l, int n, char titr[30], int nov_quantite);

// Supprimer un Livre du Stock
void supprimer_livre(livre *l, int *n, char titre[30]);

// Afficher le Nombre Total de Livres en Stock
int nbr_Tlivre(livre l[], int n);
//Verification de l'ISBN
int verifierISBN(char *isbn);
//Tri croissant par isbn
void tri_livre_ISBN(livre l[], int n);
//Permutation des livres
void echanger(livre *l,livre *M);
//Trie croissant et decroissant des livre par ordre alphabetique
void tri_livre_aplh(livre l[], int n,int order);
//Trie croissant et decroissant  des livre par le nombre de quatntite
void tri_livre_quant(livre l[], int n, int order);

#endif
