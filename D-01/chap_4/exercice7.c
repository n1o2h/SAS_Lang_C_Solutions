#include<stdio.h>

int main(){
    int montant, billets, b20, b10, b5, B1;

    printf("Entrer un montant en dollars: ");
    scanf("%d", &montant);
    b20 = montant /20;
    montant = montant %20;
    b10 = montant /10;
    montant = montant %10;
    b5 = montant /5;
    montant = montant %5;
    B1 = montant /1;

    printf("billets de 20$ : %d",b20);
    printf("\nbillets de 10$ : %d",b10);
    printf("\nbillets de 25$ : %d",b5);
    printf("\nbillets de 1$ : %d",B1);

    return 0;


}