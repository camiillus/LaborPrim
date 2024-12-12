#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define VON 0
#define BIS 1000
#define SIZE 1000

int anzahlPrimzahlenImIntervall = 0;
int *speicherPlatz = NULL; 
int idx = 0;

int istPrimzahl(int zahl){

    if (zahl < 2) {
        return 0;
    }

    for (int i = 2; i <= sqrt(zahl); i++) {
        if ((zahl % i) == 0) {
            return 0;
        }
    }

    // Wenn keine Teiler gefunden wurden
    anzahlPrimzahlenImIntervall++;
    if (idx < SIZE) {
        *(speicherPlatz+(idx++)) = zahl;
    }

    return 1;
}

int main()
{
    speicherPlatz = calloc(SIZE, sizeof(int));

    if (speicherPlatz == NULL) {
        printf("Der Speicherplatz wurde nicht zugewiesen!");
        exit(0);
    } else {
        for (int i = VON; i < BIS; i++) {
            istPrimzahl(i); 
        }
    }

    for (int i = 0; i < anzahlPrimzahlenImIntervall; i++) {
        printf("%d\n", *(speicherPlatz+i));
    }

    free(speicherPlatz);

    return 0;
}
