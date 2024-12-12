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

int primzahlZwilling(int zahl){
    if (!istPrimzahl(zahl)) // Wenn die Zahl keine Primzahl ist, breche Programm ab.
    {
        return 0;

    }else if(istPrimzahl(zahl -2)||istPrimzahl(zahl+2)){

        return 1; // es existiert ein Primzahlzwilling 


    }

    return 0; // kein Primzahlzwilling

    
}

int main(){

    // Testen von einer beliebigen Zahl
    int zahl = 1;

    if (primzahlZwilling(zahl)){
        printf("\nJa\n");
    }else if (!primzahlZwilling(zahl)){
        printf("\nNein\n");
    }
    
    
    
}