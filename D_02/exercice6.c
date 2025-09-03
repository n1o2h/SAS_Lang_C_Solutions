#include<stdio.h>

int main(){
    int m, n, r;

    printf("Entrer deux entiers: ");
    scanf("%d %d", &m, &n);

    while(n !=0){
        r =m%n;
        m = n; 
        n = r;
    }
    printf("le pgcd est : %d\n",m);
}

