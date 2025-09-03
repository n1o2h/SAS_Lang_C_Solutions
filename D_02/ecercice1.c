#include<stdio.h>
#include <string.h>

int main(){
    char isbn[50];
    int i=0, j;
    size_t length;

    printf("entrer isbn: ");
    fgets(isbn, sizeof(isbn), stdin);

    length = strlen(isbn);

    if(isbn[0] == '9' && isbn[1]== '7' && (isbn[3] == '9' || isbn[3] == '8'))
        printf("prefixe GS1: %d%d%d", isbn[0], isbn[1], isbn[2]);
    
    for(int i=0; i<length;i++){
        if(isbn[i] == 9 && (isbn[i+1]))
    
    




















    while(isbn[i] != '\0'){
        if(isbn[i] != '-'){
            
        }
        else{
            ++i;
            printf("\n%c", isbn[i]);
            i++;
        }
    }

    return 0;
}