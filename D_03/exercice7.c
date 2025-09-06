#include<stdio.h>

int main(){
    int T1[5], T2[5],T3[5], T4[5],T5[5], TL[5], TC[5];
    int i;

    printf("Entrer la ligne 1:");
    for(i=0;i<5;i++)
        scanf("%d", &T1[i]);
    printf("Entrer la ligne 2:");
    for(i=0;i<5;i++)
        scanf("%d", &T2[i]);
    printf("Entrer la ligne 3:");
    for(i=0;i<5;i++)
        scanf("%d", &T3[i]);
    printf("Entrer la ligne 4:");
    for(i=0;i<5;i++)
        scanf("%d", &T4[i]);
    printf("Entrer la ligne 5:");
    for(i=0;i<5;i++)
        scanf("%d", &T5[i]);
    
    for(i=0;i<5;i++){
        TC[i]= T1[i]+ T2[i]+ T3[i]+ T4[i]+ T5[i];
    }
    
    printf("\nTotaux des collones: ");
    for(i=0;i<5;i++){
        printf("%d  ", TC[i]);
    }
    int S1=0,S2=0,S3=0,S4=0,S5=0;

    for(i=1;i<5;i++){
        S1+= T1[i];
        S2+= T2[i];
        S3+= T3[i];
        S4+= T4[i];
        S5+= T5[i];
    }
    for(i=1;i<5;i++){
        T1[0] += T1[i];
        T2[0] += T2[i];
        T3[0] += T3[i];
        T4[0] += T4[i];
        T5[0] += T5[i];

    }
    printf("\n");
    printf("\nTotaux des lignes: ");
    printf("%d  %d  %d  %d  %d", T1[0],T2[0],T3[0],T4[0], T5[0]);

    return 0;
}