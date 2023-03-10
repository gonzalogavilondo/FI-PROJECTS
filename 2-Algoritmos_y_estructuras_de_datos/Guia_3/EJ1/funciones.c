#include "declaraciones.h"

int add_nr(int n)
{
    int suma = 0;

    for(int i = 1; i < n+1; i++)
    {
        suma += i;
    }

    return suma;
}

int add_r(int n)
{
    int suma = 0;
    if(n > 0)
    {
        suma = (n+add_r(n-1));
    }
    return suma;
}
