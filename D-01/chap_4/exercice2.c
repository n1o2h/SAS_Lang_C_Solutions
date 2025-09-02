#include<stdio.h>

int main(){
    int const PI = 3.14;
    float r = 10.0;
    float  i, j;
    float V;
    V = (4 / 3) * PI * r * r *r ; // V cosidere comme etant double
    printf("le volume de la sphere : %.2f \n", V);

    V = (4.0f / 3.0f) * PI * r * r *r ; // v considere comme etant float
    printf("le volume de la sphere : %.2f \n", V);

    return 0;
}