#include<stdio.h>

int main(){
    int i;
    float montant_pret, taux_pret, paiment_m, r, solde;

    printf("entrer le montant du pret: ");
    scanf("%f", &montant_pret);
    printf("entrer le taaux d'interet: ");
    scanf("%f", &taux_pret);
    printf("entrer le paiment monsuelle: ");
    scanf("%f", &paiment_m);

    r = taux_pret /(12*100);
    solde = montant_pret;

    for(i=1;i<=3;i++){
    solde = solde + (solde * r);
    solde = solde - paiment_m;
    printf("le solde restant apres le %d paimeent:  %.2f\n",i, solde);
    }

    return 0;


}