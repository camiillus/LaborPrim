#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <unistd.h> 

#define VON 1
#define BIS 100000

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


int main(void)


{   
    time_t time1, time2;
    time(&time2);
    //hier beginnt die Kontrolle (probiert das Intervall [VON;BIS])
    for (int i = VON; i <  BIS; i++)
    {
        istPrimzahl(i);
    }

    for (int i = 0; i < anzahl; i++)
    {
        //printf("%d ", *(liste + i));

    }

    free(liste);
    time(&time2);

    printf("Difference is %.6f seconds", difftime(time2, time1)); 
    return 0;
}