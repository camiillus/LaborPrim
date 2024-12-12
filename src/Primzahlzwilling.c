#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *liste = NULL;
int anzahl = 0;

int istPrimzahl(int kandidat)
{
    if (kandidat < 2)
    {
        //printf("%d ist keine Primzahl!", kandidat);
        return 0;
    }

    for (int i = 2; i <= sqrt(kandidat); i++)
    {
        if ((kandidat % i) == 0)
        {
            //printf("%d ist keine Primzahl!\n", kandidat);
            return 0;
        }
    }
    anzahl++;
    liste = (int *) realloc(liste, (anzahl + 1) * sizeof(int));
    *(liste + anzahl - 1) = kandidat;

    if (liste==NULL)
    {
        return 0;
    }
    
    // printf("%d ist eine Primzahl!\n", kandidat);
    return 1;

}

int existiertPrimzahlzwillingImIntervall(int a, int b) {
    
    for (int i = a; i <= b - 2; i++) { // Wenn es nur bis b gehen wuerde, wuerde es noch das Intervall bis auf zwei Weitere Stellen pruefen und der Index waere ausserhalb des Intervalls.
        if (istPrimzahl(i) && istPrimzahl(i+2)) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    printf("Primzahlzwillinge im Intervall [10,30]? %s\n", existiertPrimzahlzwillingImIntervall(10,30) ? "Ja" : "Nein");
    return 0;
}
