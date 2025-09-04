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
            printf("chiffre: %d -> occurence: %d  \n", i, digit_seen[i]);
            digit_seen[i] = 0;
        }
    return 0;
}