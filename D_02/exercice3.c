#include<stdio.h>
#include <stdlib.h>


int main(){
    int h, m, tmin, i, min;

    int volD[] = {480, 583,  679, 767, 840, 945, 1140, 1305};
    int volA[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    int def[8], proch=0;

    printf("Entrer une heure (24h)(hh:mm): ");
    scanf("%d : %d", &h, &m);

    tmin = h*60 + m;
    min = abs(tmin - volD[0]);

    for(i=1;i<7;i++){
        def[i] = abs(tmin - volD[i]);
        if(def[i] < min){
            min = def[i];
            proch= i;
        }
    }

    int dh = volD[proch] / 60;
    int dm = volD[proch] % 60;
    int ah = volA [proch] / 60;
    int am = volA [proch] % 60;

printf("L'heure de depart la plus proche est: \n");
printf("L'heure de depart la plus proche est  %02d:%02d , arrivant a  %02d:%02d", dh, dm, ah, am);
    // printf("Depart: %02d:%02d\n", dh, dm);
    // printf("Arrivee:   %02d:%02d\n", ah, am );

    return 0;


}