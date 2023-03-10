#include "declaraciones.h"

int busqueda_binaria(int izq, int der, int x, int array[])
{
    int med = 0;
    if(izq > der)
    {
        return -1;
    }
    else
    {
        med = (izq + der)/2;
        if(x == array[med])
        {
            return(med);
        }
        else if(x > array[med])
        {
            return(busqueda_binaria(med+1, der, x, array));
        }
        else
        {
            return(busqueda_binaria(izq, med-1, x, array));
        }
    }
}
void impresion(int posicion, int x)
{
    if(posicion == -1)
    {
        printf("El valor no existe.\n");
    }
    else
    {
        printf("El valor de %d esta en la posicion %d", x, posicion+1);
    }

}
