#include<stdio.h>
#include<stdbool.h>

int main(){
    int digit_seen[10]= {0};
    int digit;
    long n;   
    printf("Entrer un nombre: ");
    scanf("%ld", &n);

    while(n > 0){
        digit = n%10;
        if(digit_seen[digit]== 0)
            digit_seen[digit] += 1;
        else
            digit_seen[digit] +=1;
        n/=10;
    }
    
    printf("les chiffres repetes: ");
    for(int i=0; i<10;i++){
        if(digit_seen[i] > 1)
        printf(" %d ", i);
    }
    return 0;
}