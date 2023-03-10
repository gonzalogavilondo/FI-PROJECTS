#include "cosas_raras.h"

int minimo (const int vector[], int dim) /*Retorna el valor m�nimo del arreglo*/
{
    int min = vector[0];
    for (int i = 0; i < dim; i++)
    {
        if (min > vector[i])
        {
            min = vector[i];
        }
    }
    return min;
}

int maximo (const int vector[], int dim) /*Retorna el valor m�ximo del arreglo*/
{
    int max = vector[0];
    for (int i = 0; i < dim; i++)
    {
        if (max < vector[i])
        {
            max = vector[i];
        }
    }
    return max;
}

int suma_negativos (const int vector[], int dim, int minimo) /*Retorna la suma de los elementos negativos del arreglo, menos el m�nimo*/
{
    int sum_neg = 0;
    for (int j = 0; j < dim; j++)
    {
        if (vector[j] < 0 && vector[j] != minimo)
        {
            sum_neg += vector[j];
        }
    }
    return sum_neg;
}

float prod_positivos (const int vector[], int dim, int maximo) /*Retorna la multiplicaci�n de los elementos postivos del arreglo, menos el m�ximo*/
{
    float prod_pos = 1;
    for (int j = 0; j < dim; j++)
    {
        if (vector[j] > 0 && vector[j] != maximo)
        {
            prod_pos *= vector[j];
        }
    }
    return prod_pos;
}
