#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    int i;
    char N[50];

    printf("Enter le numero de telephone: ");
    fgets(N, sizeof(N), stdin);
    
    size_t length;
    length = strlen(N);
        
        for(int i=0; i<length; i++){
        if(N[i] == 'A' || N[i] == 'B' || N[i] == 'C')
            printf("2");
        else if(N[i] == 'D' || N[i] == 'E' || N[i] == 'F')
            printf("3");
        else if(N[i] == 'G' || N[i] == 'H' || N[i] == 'I')
            printf("4");
        else if(N[i] == 'J' || N[i] == 'K' || N[i] == 'L')
            printf("5");
        else if(N[i] == 'M' || N[i] == 'N' || N[i] == 'O')
            printf("6");
        else if(N[i] == 'P' || N[i] == 'R' || N[i] == 'S')
            printf("7");
        else if(N[i] == 'T' || N[i] == 'U' || N[i] == 'V')
            printf("8");
        else if(N[i] == 'W' || N[i] == 'X' || N[i] == 'Y')
            printf("9");
        else 
            printf("%c", N[i]);
        }
        return 0;
    }