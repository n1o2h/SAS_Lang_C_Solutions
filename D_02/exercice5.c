#include <stdio.h>

int main(){
    int num, nd;
    char nl;

    printf("Entrer une note numerique en deux chiffres(inf a 100): ");
    scanf("%2d", &num);

    nd = num / 10;
    if(nd / 10 ==0){
        switch (nd){
            case 0: printf("\nla note litterale: F");
                break;
            case 1: printf("\nla note litterale: F");
                break;
            case 2: printf("\nla note litterale: F");
                break;
            case 3: printf("\nla note litterale: F");
                break;
            case 4: printf("\nla note litterale: F");
                break;
            case 5: printf("\nla note litterale: F");
                break;
            case 6: printf("\nla note litterale: D");
                break;
            case 7: printf("\nla note litterale: C");
                break;
            case 8: printf("\nla note litterale: B");
                break;
            case 9: printf("\nla note litterale: A");
                break;
            default : printf("\nla note est non trouvable!");
                break;
        }
    }else if(nd/10 == 1){
        printf("\nla note literale : A");
    }else{
        printf("\nError , la note n'est pas correct veuilez saisr une note compris entre 0 et 100!");
    }

    return 0;
}