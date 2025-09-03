#include<stdio.h>

int main(){
    printf("l'affichage des valeurs: \n");
    printf("\nentier: %d",sizeof(int));
    printf("\nshort: %d",sizeof(short));
    printf("\nlong: %d",sizeof(long));
    printf("\ndouble: %d",sizeof(double));
    printf("\nlong double: %d",sizeof(long double));

    return 0;
}