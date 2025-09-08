#ifndef LIVRE_FUNCTION_H
#define LIVRE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du livre
typedef struct {
    char titre[30];
    char auteur[30];
    float prix;
    int quantite;
} livre;

// Ajouter un Livre au Stock
void ajouter_livre(livre l[], int n);

// Afficher Tous les Livres Disponibles
void afficher_livre(livre l[], int n);

//Rechercher un livre par son titre
void rechercher_livre(livre l[], int n, char titre[30]);

// Mettre à Jour la Quantité d'un Livre
void mettre_quantite(livre *l, int n, char titr[30], int nov_quantite);

// Supprimer un Livre du Stock
void supprimer_livre(livre *l, int *n, char titre[30]);

// Afficher le Nombre Total de Livres en Stock
int nbr_Tlivre(livre l[], int n);

#endif
