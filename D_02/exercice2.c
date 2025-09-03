#include <stdio.h>

int main(){

    int n, nv;
    printf("Entrer un nombre a deux chiffre: ");
    scanf("%2d", &n);

    printf("le nombre inverse %d%d", n%10, n/10);
    return 0;
}