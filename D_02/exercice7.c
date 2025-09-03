#include<stdio.h>

int main(){
    int a,b,r,m,n;
    printf("entrer une fraction: ");
    scanf("%d %d", &a, &b);

    m=a;
    n=b;
    while(b !=0){
        r =a%b;
        a = b; 
        b = r;
    }
    printf("la forme la plus simple : %d / %d", m/a,n/a);
}