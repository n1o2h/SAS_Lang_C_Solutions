#include <stdio.h>

int main(){
    int x, S;

    printf("Entrer la valeur de x: ");
    scanf("%d", &x);

    S = (3*x*x*x*x*x) + (2*x*x*x*x) - (5*x*x*x) - (x*x) + (7*x) -6;
    printf(" la valeur du polynome : %d", S);
}