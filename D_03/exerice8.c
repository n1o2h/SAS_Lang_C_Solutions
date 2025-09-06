#include<stdio.h>
#include<string.h>

int main(){
    char PH[5];
    char fin;
    int i, j, len;

    printf("Entrre votre message: ");
    i=0;
    while(PH[i] == '?' || PH[i] == '.' || PH[i] == '!'){
        printf("Entrre votre message: ");
        PH[i] = getchar();
        i++;
    }
    printf("\n");
        for(int  j=0;j<i;j++)
            printf("%c", PH[i]);

}