#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int istPrimzahl(int kandidat)
{
    if (kandidat < 2)
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(kandidat); i++)
    {
        if ((kandidat % i) == 0)
        {
            return 0;
        }
    }
    
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

int schätzePrimBis(float grenze) { //erste Funktion
    if (grenze < 2)
    {
        return 0; 
    }
    return (grenze / log(grenze));
}

int schätzePrimVonBis(int von, int bis) {
	int differenz = (int) schätzePrimBis(bis) - schätzePrimBis(von);
    return differenz; 
}
