#include "livre_header.h"
#include <string.h>

// Ajouter un Livre au Stock
void ajouter_livre(livre l[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        do {
        printf("Entrer l'ISBN-13 (13 chiffres) : ");
        scanf("%s", l[i].isbn);

        if (verifierISBN(l[i].isbn)) {
            break;
        } else {
            printf(" ISBN invalide ! Doit contenir exactement 13 chiffres.\n");
            exit(0);
        }
    } while (1);
        printf("\tLe livre num %d: \n", i+1);
        printf("Entrer le titre du livre %d: ", i+1);
        scanf(" %[^\n]", l[i].titre);
        printf("Entrer l'auteur du livre %d: ", i+1);
        scanf(" %[^\n]", l[i].auteur);
        printf("Entrer le prix du livre %d: ", i+1);
        scanf("%f", &l[i].prix);
        printf("Entrer la quantite en stock: ");
        scanf("%d", &l[i].quantite);
    }
}

// Vérifie que l’ISBN est de 13 chiffres (sans tenir compte des tirets)
int verifierISBN(char *isbn) {
    if (strlen(isbn) != 13) return 0;  // doit avoir 13 caractères
    for (int i = 0; i < 13; i++) {
        if (!isdigit(isbn[i])) return 0;  // tous doivent être des chiffres
    }
    return 1;
}

// Afficher Tous les Livres Disponibles
void afficher_livre(livre l[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Livre num %d\n", i+1);
        printf("\tIsbn: %s \tTitre: %s \t Auteur: %s \t Prix: %.2f \t Quantite: %d\n",
            l[i].isbn, l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);
    }
}

// Mettre à Jour la Quantité d'un Livre
void mettre_quantite(livre *l, int n, char titr[30], int nov_quantite) {
    int i;
    for(i = 0; i < n; i++) {
        if(strcasecmp(l[i].titre, titr) == 0) {
            l[i].quantite = nov_quantite;
        }
    }
}

// Supprimer un Livre du Stock
void supprimer_livre(livre *l, int *n, char titre[30]){
    int i;
    for(i=0;i<*n;i++){
        if(strcasecmp(l[i].titre, titre) == 0){
            for(int j = i; j < *n - 1; j++) {
                l[j] = l[j+1];
            }
            (*n)--;
            // strcpy(l[i].titre, l[i+1].titre);
            // strcpy(l[i].auteur, l[i+1].auteur);
            // l[i].prix= l[i+1].prix;
            // l[i].quantite = l[i+1].quantite;
            
        }
    }
    printf("\n Les livre stokees apres la suppression du livre choisie: \n");
    afficher_livre(l, *n);
}

//Rechercher un livre par son titre
void rechercher_livre1(livre l[], int n, char titre[30]){
    int i;
    for(i = 0; i < n; i++) {
        if(strcasecmp(l[i].titre, titre) == 0) {
            printf("\nLe livre recherche: \n");
            printf("\tTitre: %s - \tAuteur: %s - \tPrix: %.2f - \tQantite: %d \t", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);
        }
    }
}

// Recherche binaire du livre par isbn 
int  rehercher_livre2(livre l[], int n, char ISBN[30]){
    int debut=0, fin= n-1, i;
    while(debut <= fin){
        int milieu =  (debut + fin) /2 ;
        int est_trouve = strcasecmp(l[milieu].isbn, ISBN);

        if(est_trouve == 0){
            return milieu;
        }
        else if(est_trouve < 0){
            debut = milieu + 1; 
        }
        else {
            fin = milieu - 1;
        }
    }
    return -1;
}

// Trie croissant des livre par ordre alphabetique
void tri_livre_aplh_cr(livre l[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(l[j].titre, l[j+1].titre) > 0)
                echanger(&l[j],&l[j+1]);
        }
    }
}

//Permutation des livres
void echanger(livre *l,livre *M){
    livre temp = *l;
    *l = *M;
    *M = temp;
}

// Trie decroissant des livre par ordre alphabetique
void tri_livre_aplh_dec(livre l[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(l[j].titre, l[j+1].titre) < 0)
                echanger(&l[j],&l[j+1]);
        }
    }
}

//Trie croissant des livre par le nombre de quantite
void tri_livre_quant_cr(livre l[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(l[j].quantite > l[j+1].quantite )
                echanger(&l[j],&l[j+1]);
        }
    }
}

//Trie decroissant des livre par le nombre de quantite
void tri_livre_quant_dec(livre l[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(l[j].quantite < l[j+1].quantite )
                echanger(&l[j],&l[j+1]);
        }
    }
}

// Afficher le Nombre Total de Livres en Stock
int nbr_Tlivre(livre l[], int n){
    int i;
    int nbr_Tlivre = 0;
    for(i=0;i<n;i++){
        nbr_Tlivre += l[i].quantite;
    }
    return nbr_Tlivre;
}
void menue(){
    livre l[3];
    int ch, n, nov_q, nbr_Tli, pos;
    char rech_l[50], titre[30],  sup_titre[30], ISBN[30];
    do{
    printf("\n*******MENUE*******\n");
    printf("1. Ajouter un Livre au Stock\n");
    printf("2. Afficher Tous les Livres Disponibles\n");
    printf("3.Rechercher un livre par son titre\n");
    printf("4. Mettre a jour la quantite d'un livre\n");
    printf("5. Supprimer un livre du stock\n");
    printf("6. Afficher le nombre total de livres en stock\n");
    printf("7. Rechercher un livre par son Isbn\n");
    printf("8. Trie croissant des livre par ordre alphabetique\n");
    printf("9. Trie decroissant des livre par ordre alphabetique\n");
    printf("10. Trie croissant des livre par le nombre de quatntite \n");
    printf("11. Trie decroissant des livre par le nombre de quantite\n");



    printf("0. Sortir du program");
    printf("\n*************************\n");
    
    printf("veuiez saisir votre choix(de 0 -> 11): ");
    scanf("%d", &ch);
    
        switch (ch){

        case 1 :printf("\n*************************\n");
                printf("Entrer le nombre de livre que vous voulez stokees : ");
                scanf("%d", &n);
                ajouter_livre(l, n);
            break;
        case 2:
                printf("\n*************************\n");
                printf("Les Livres Stokees: \n");
                afficher_livre(l, n);
            break;
        case 3:printf("\n*************************\n");
                printf("Entrer le titre du  livre a recherche: ");
                scanf(" %[^\n]s", rech_l);
                rechercher_livre1(l, n, rech_l);
            break;
        case 7:printf("\n*************************\n");
                printf("Entrer le ISBN du  livre a recherche: ");
                scanf(" %[^\n]s", ISBN);
                pos = rehercher_livre2(l, n, ISBN);
                if(pos == -1)
                    printf("Le livre n'existe pas dans le stock");
                else
                    printf("\nle livre recherhe:\n");
                    printf("\tIsbn: %s \tTitre: %s \t Auteur: %s \t Prix: %.2f \t Quantite: %d\n",
                    l[pos].isbn, l[pos].titre, l[pos].auteur, l[pos].prix, l[pos].quantite);
            break;
        case 4: printf("\n*************************\n");
                printf("Entrer le titre du livre a mettre a jour: ");
                scanf(" %[^\n]s", titre);
                printf("Entrer la nouvelle quantite de stock pour ce livre: ");
                scanf("%d", &nov_q);
                mettre_quantite(l, n, titre, nov_q);
                printf("Les Livres Stokees Apres La Mise a Jour: \n");
                afficher_livre(l, n);
            break;
        case 6: printf("\n*************************\n");
                nbr_Tli = nbr_Tlivre(l, n);
                printf("le nombre total des livres en stock: %d\n", nbr_Tli);
            break;
        case 5: printf("\n*************************\n");
                printf("Entrer le titre du livre a supprimer du stock: ");
                scanf(" %[^\n]s", sup_titre);
                supprimer_livre(l, &n, sup_titre);
                
            break;
        case 8:printf("\n*************************\n");
                printf("\nAvant le Trie Croissant: \n");
                afficher_livre(l,n);
                tri_livre_aplh_cr(l, n);
                printf("\nApres le Trie Croissant: \n");
                afficher_livre(l, n);
                break;
        case 9:printf("\n*************************\n");
                printf("\nAvant le Trie Croissant: \n");
                afficher_livre(l,n);
                tri_livre_aplh_dec(l, n);
                printf("\nApres le Trie Croissant: \n");
                afficher_livre(l, n);
                break;
        case 10:printf("\n*************************\n");
                printf("\nAvant le Trie Croissant: \n");
                afficher_livre(l,n);
                tri_livre_quant_cr(l, n);
                printf("\nApres le Trie Croissant: \n");
                afficher_livre(l, n);
                break;
        case 11:printf("\n*************************\n");
                printf("\nAvant le Trie Croissant: \n");
                afficher_livre(l,n);
                tri_livre_quant_dec(l, n);
                printf("\nApres le Trie Croissant: \n");
                afficher_livre(l, n);
                break;
        case 0:printf("\nAU REVOIR!!!\n");
                exit(0);
        default:printf("\nle choix est invalide veuiez saisir un choix entre 1 et 7!\n");
            break;
        }
    }while(ch != 0);
}

