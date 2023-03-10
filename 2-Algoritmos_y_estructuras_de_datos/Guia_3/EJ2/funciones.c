#include "declaraciones.h"

int funcion_potencia(int x, int n)
{
    int res = 0;
    if(n == 0) //Condicion base
    {
        res = 1;
    }
    else
    {
        if(n >= 1)
        {
            x = x*funcion_potencia(x, n-1);
        }
        res = x;
    }
    return res;
}
