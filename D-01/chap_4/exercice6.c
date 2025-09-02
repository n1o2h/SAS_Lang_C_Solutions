#include <stdio.h>

int main(){
    int x, S;
    printf("La regle de Horner\n");
    
    printf("Entrer la valeur de x: ");
    scanf("%d", &x);

    S = ((((3*x+2)*x-5)*x-1)*x+7)*x-6;
    printf(" la valeur du polynome : %d", S);
}