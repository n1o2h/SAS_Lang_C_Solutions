#include <stdio.h>

int main(){

    int montant;

    printf("entrer un monatnt: ");
    scanf("%d", &montant);
    montant += montant * 0.05;
    printf("l montant avec taxe ajoutee: %d$", montant);

    return 0;
}