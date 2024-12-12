#include <stdio.h>
#include <math.h>

int schätzung = 0;

int schätzePrimBis(float grenze) {
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

int main(void) {
    printf("%i", schätzePrimBis(10));
    return 0;
}
