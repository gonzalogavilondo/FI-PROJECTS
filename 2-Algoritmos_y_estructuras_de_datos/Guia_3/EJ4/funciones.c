#include "declaraciones.h"

int Maximo(int a[], int inf, int sup)
{
    if (inf == sup)
    {
        return (a[inf]);
    }
    int medio = (inf + sup)/2;
    int maxIzq = Maximo(a, inf, medio);
    int maxDer = Maximo(a, medio+1, sup);

    if(maxIzq > maxDer)
    {
        return(maxIzq);
    }
    else
    {
        return(maxDer);
    }
}

