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

int schaetzePrimBisGauss(float grenze) { 
    if (grenze < 2)
    {
        return 0; 
    }
    return (grenze / log(grenze));
}

int schaetzePrimVonBis(int von, int bis) {
	int differenz = (int) schätzePrimBis(bis) - schätzePrimBis(von);
    return differenz; 
}


int existiertPrimzahlzwillingImIntervall(int von, int bis) {
    
    for (int i = von; i <= bis - 2; i++) { // -2 weil sonst, wuerde es noch das Intervall bis auf zwei Weitere Stellen pruefen und der Index waere ausserhalb des Intervalls.
        if (istPrimzahl(i) && istPrimzahl(i+2)) { 
            return 1;
        }
    }
    return 0;
}

void schreibePrimzahlenInDatei(const char *dateiName, int von, int bis) { // ein Zeiger, der auf den Speicherbereich(Datei), wo die Zahlen abgespeichert sind zeigt. Durch const koennen die nicht veraendert werden.  
    FILE *datei = fopen(dateiName, "w"); 
	
    if (!datei) {
        printf("Fehler beim Öffnen der Datei %s\n", dateiName);
        return;
    }
    
    for (int i = von; i <= bis; i++) {
        if (istPrimzahl(i)) {
            fprintf(datei, "%d\n", i); // fprintf, da wir jede i-te Primzahl in die Datei reinschreiben wollen und nicht in der Konsole ausgeben wollen.
        }
    }
    fclose(datei);
}

void schreibePrimzahlzwillingeInDatei(const char *dateiName, int von, int bis) {
    FILE *datei = fopen(dateiName, "w");
    if (!datei) {
        printf("Fehler beim Öffnen der Datei %s\n", datei);
        return;
    }
    
    for (int i = von; i <= bis - 2; i++) {
        if (istPrimzahl(i) && istPrimzahl(i+2)) {
            fprintf(datei, "Primzahl=%d DerZwilling=%d\n", i, i+2);
        }
    }
    fclose(datei);
}
