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

