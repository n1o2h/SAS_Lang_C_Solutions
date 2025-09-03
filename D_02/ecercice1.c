#include<stdio.h>

int main(){

    char isbn[30];
    int i, group=1;

    printf("Entrer l'ISBN: ");
    scanf("%s", isbn);

    printf("le prefixe GS1 : ");
    for(i=0; isbn[i]!='\0'; i++){ // 978-0-393-97950-3
        if(isbn[i] == '-'){
            group++;
            printf("\n");
            switch(group){
                case 2: printf("Identifiant de groupe: ");break;
                case 3: printf("Code de l'editeur : ");break;
                case 4: printf("Numero d'article: ");break;
                case 5: printf("Chiffre de controle: ");break;
            }
        }else{
            printf("%c", isbn[i]);
        }
    }
        return 0;
    }