#include <stdio.h>
#include "declaraciones_funciones_reales.h"

int suma(int n1, int n2)
{
    float res;

    res = (n1 + n2);

    return res;
}

int multiplicacion(int n1, int n2)
{
    float res;

    res = (n1*n2);

    return res;
}
void carteles (int numero, int resultado)
{
    if (numero == resultado)
    {
        printf("Bien hecho!\n");
    }
    else
    {
        printf("Incorrecto. Vuelve a intentarlo con otra cuenta!\n");
    }

}

