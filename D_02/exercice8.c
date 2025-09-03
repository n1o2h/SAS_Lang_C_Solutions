#include<stdio.h>

int main(){
    int n, car;

    printf("entrer un nombre: ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        car = i*i;
        if(car %2 == 0 && car <= n)
            printf("%d\n", car);
    }
}