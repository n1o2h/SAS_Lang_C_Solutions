#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

int main(){
    int val=0, i=0;
    char N[50], c;

    printf("Enter un mot: ");
    fgets(N, sizeof(N), stdin); // all time fgets finished by \n not \0

    i=0;
        while(N[i] != '\n'){
            c = toupper(N[i]);
    
                if(c == 'A' || c== 'E' || c == 'I' ||c == 'L' || c == 'N' || c == 'O' || c == 'R'|| c == 'S' || c == 'T' || c == 'U')
                    val+=1;
                else if(c == 'D' || c == 'G')
                    val+=2;
                else if(c == 'B' || c == 'C' || c == 'M' || c == 'P')
                    val+=3;
                else if(c == 'F' || c == 'H' || c == 'V'|| c == 'W' || c == 'Y' )
                    val+=4;
                else if(c == 'K' )
                    val+=5;
                else if(c == 'J' || c == 'x' )
                    val+=8;
                else if(c == 'Q' || c == 'Z')
                    val+=10;
                else 
                    continue;
        i++;
        }
        printf("valeur Scrabble: %d", val); 
        return 0;
    }