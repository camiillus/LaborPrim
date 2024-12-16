#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prim.h"

int main(){

    // Testen von einer beliebigen Zahl
    int zahl = 1;

    if (primzahlZwilling(zahl)){
        printf("\nJa\n");
    }else if (!primzahlZwilling(zahl)){
        printf("\nNein\n");
    }
    
    
    
}
