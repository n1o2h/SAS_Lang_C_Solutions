#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char B1FF[100],c;
    int i;

    printf("Entrre votre message: ");
    // gets(B1FF);
    scanf(" %[^\n]s", B1FF);
    // fgets(B1FF, (char)(sizeof(B1FF)/sizeof(B1FF[0])), stdin); // se termine par \n not \0
    
    int length;
    length = strlen(B1FF);
    for(i=0;i<length;i++){
        c=toupper(B1FF[i]);
        if(c == 'A')
            printf("4");
        else if(c=='B')
            printf("8");
        else if(c=='E')
            printf("3");
        else if(c=='I')
            printf("1");
        else if(c=='O')
            printf("0");
        else if(c=='S') 
            printf("5");
        else
            printf("%c", c);
    }
    printf("!!!!!!!!!!");
}