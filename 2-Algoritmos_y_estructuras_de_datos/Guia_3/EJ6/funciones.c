#include "declaraciones.h"

void permutaciones(int lista[], int n, int i)
{
    if(i == n) //Criterio de base
    {
        imprimir(lista, n, i);
    }
    else
    {
        if(i < n)
        {
            for(int j = i; j < n; j++)
            {
                intercambia(lista ,i, j);
                permutaciones(lista, n, i+1); //Aproximacion progresiva
                intercambia(lista, i, j);

            }
        }

    }
}

void intercambia(int lista [], int i, int j)
{
    int aux = 0;

    //Metodo de la burbuja
    aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}

void imprimir(int lista[], int n, int i)
{
    for(int j = 0; j < n; j++)
    {
        printf("%d \t", lista[j]);
    }
    i = 0;
    printf("\n");
}
