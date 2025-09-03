#include<stdio.h>

int main(){
    int  mm1, jj1, aa1, mm2, jj2,aa2;

    printf("Entrez la première date (mm/jj/aa) : ");
    scanf("%d %d %d", &mm1, &jj1, &aa1);
    printf("Entrez la deuxième date (mm/jj/aa) : ");
    scanf("%d %d %d", &mm2, &jj2, &aa2);

    if(aa1 < aa2){
        printf("%d/%d/%d est plus tot que %d/%d/%d", mm1, jj1, aa1, mm2, jj2, aa2);
    }else if(aa1 > aa2){
        printf("%d/%d/%d est plus tot que %d/%d/%d", mm2, jj2, aa2, mm1, jj1, aa1);
    }else{
        if(mm1<mm2)
            printf("%d/%d/%d est plus tot que %d/%d/%d", mm1, jj1, aa1, mm2, jj2, aa2);
        else if(mm1> mm2)
            printf("%d/%d/%d est plus tot que %d/%d/%d", mm2, jj2, aa2, mm1, jj1, aa1);
        else{
            if(jj1<jj2)
            printf("%d/%d/%d est plus tot que %d/%d/%d", mm1, jj1, aa1, mm2, jj2, aa2);
        else if(jj1> jj2)
            printf("%d/%d/%d est plus tot que %d/%d/%d", mm2, jj2, aa2, mm1, jj1, aa1);
        else
            printf("%d/%d/%d est identique a  %d/%d/%d", mm1, jj1, aa1, mm2, jj2, aa2);
        }
    }
    return 0;
}