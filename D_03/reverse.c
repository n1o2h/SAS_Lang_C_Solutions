#include<stdio.h>
// #define N 10

int main(){
    int a[5], i;

    printf("Entrer %d nombre: ", (int)(sizeof(a)/sizeof(a[0])));
    for(i=0;i<(int)(sizeof(a)/sizeof(a[0]));i++)
        scanf("%d", &a[i]);
    
    printf("Dans l'ordre inverse: ");
    i=0;
    for(i=(int)(sizeof(a)/sizeof(a[0]))-1; i>=0;i--)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}