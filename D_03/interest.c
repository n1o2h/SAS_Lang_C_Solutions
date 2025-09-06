#include <stdio.h>

#define NUM_RATES ((int)(sizeof(value)/sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main() {
    int i, low_rate, num_years, year, month;
    double value[5];

    printf("Taux d'interet: ");
    scanf("%d", &low_rate);
    printf("Nombre d'annees: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    // Boucle sur les années
    for (year = 1; year <= num_years; year++) {
        // Pour chaque année : 12 mois de composition
        for (month = 1; month <= 12; month++) {
            for (i = 0; i < NUM_RATES; i++) {
                double monthly_rate = (low_rate + i) / 100.0 / 12.0;
                value[i] += value[i] * monthly_rate;
            }
        }
        // Après 12 mois, on affiche la valeur de fin d'année
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}
