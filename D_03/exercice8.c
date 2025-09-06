#include<stdio.h>
#include<string.h>

int main(){
    char PH[100];
    char fin;
    int i, j, len;

    printf("Entrer votre message: ");
    //lecture de la phrase jusqua ., !, ?
    i=0;
    while((PH[i] = getchar()) != '.' && PH[i] != '!' && PH[i] != '?'){
        i++;
    }
    fin = PH[i];
    PH[i] = '\0';

    len = strlen(PH);

    printf("\nInversion de la phrase : ");
    //parcour de la fin vers le debut
    for(i= len-1; i>=0; i--){
        if(PH[i] == ' ' || i==0){
            if(i==0)
                j=0;
            else
                j = i+1;
        //afficher le mot
        while(PH[j] != ' ' && PH[j] != '\0'){
            putchar(PH[j]);
            j++;
        }
        putchar(' ');
    }
    }
    printf("%c", fin);//afficher le caractere final
    return 0;
}