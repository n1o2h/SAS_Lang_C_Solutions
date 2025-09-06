#include<stdio.h>

int main(){
    char ch[81];
    int i, n;
    char c;

    printf("Entrer le message a chiffrer: ");
    scanf("%[^\n]s", ch);

    printf("Entrer le decalage (1 - 25): ");
    scanf("%d", &n);

    printf("le messaage chiffree: ");
    i=0;
    while(ch[i] != '\0'){
        c = ch[i];
        if(c  >= 'A' && c <= 'Z'){
            c = (((c - 'A') + n) % 26 + 'A');
        }
        else if(c >= 'a' && c  - 'a')
            c = ((( c - 'a' )+ n) %  26 + 'a');

        putchar(c);
        i++;
    }

    return 0;
}