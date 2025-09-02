#include<stdio.h>

int main(){
    int const PI = 3.14;
    float r ;
    float V;
    
    printf("entrer le rayon de la sphere: ");
    scanf("%f", &r);
    V = (4.0f / 3.0f) * PI * r * r *r ;
    printf("le volume de la sphere : %.2f \n", V);

    return 0;
}