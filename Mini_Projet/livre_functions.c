#include "livre_header.h"
#include <string.h>

// Ajouter un Livre au Stock
void ajouter_livre(livre l[], int n) {
    int i;
    for(i = 0; i < n; i++) {
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
// Afficher Tous les Livres Disponibles
void afficher_livre(livre l[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Livre num %d\n", i+1);
        printf("\tTitre: %s \t Auteur: %s \t Prix: %.2f \t Quantite: %d\n", 
            l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);
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
void rechercher_livre(livre l[], int n, char titre[30]){
    int i;
    for(i = 0; i < n; i++) {
        if(strcasecmp(l[i].titre, titre) == 0) {
            printf("\nLe livre recherche: \n");
            printf("\tTitre: %s - \tAuteur: %s - \tPrix: %.2f - \tQantite: %d \t", l[i].titre, l[i].auteur, l[i].prix, l[i].quantite);
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
    int ch, n, nov_q, nbr_Tli;
    char rech_l[50], titre[30],  sup_titre[30];
    do{
    printf("\n*******MENUE*******\n");
    printf("1. Ajouter un Livre au Stock\n");
    printf("2. Afficher Tous les Livres Disponibles\n");
    printf("3.Rechercher un livre par son titre\n");
    printf("4. Mettre a jour la quantite d'un livre\n");
    printf("5. Supprimer un livre du stock\n");
    printf("6. Afficher le nombre total de livres en stock\n");
    printf("0. Sortir du program");
    printf("\n*************************\n");
    
    printf("veuiez saisir votre choix(de 1 -> 6): ");
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
                rechercher_livre(l, n, rech_l);
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
        case 0:printf("\nAU REVOIR!!!\n");
                exit(0);
        default:printf("\nle choix est invalide veuiez saisir un choix entre 1 et 6!\n");
            break;
        }
    }while(ch != 0);
}

