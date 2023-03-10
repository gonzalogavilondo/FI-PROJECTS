#include "declaraciones.h"

///Mergesort
void mergesort(int *vector, int low, int high)
{
     int mid;
     if(low < high)
     {
         mid = (low+high)/2;
         mergesort(vector, low, mid);
         mergesort(vector, mid+1, high);
         merge(vector, low, mid, high);
    }
}

void merge(int *vector, int low, int mid, int high)
{
    int i , m, k, l, temp[MAX];
    l = low; //Posición en 1ra lista
    m = mid + 1; //Posición en 2da lista
    i = low; //Posición en lista nueva
    //Junta los dos arrays ordenados en “temp”
    //hasta copiar completamente uno de ellos
    while((l <= mid)&&(m <= high))
    {
        if(vector[l] <= vector[m])
        {
            temp[i] = vector[l];
            l++;
        }
        else
        {
            temp[i] = vector[m];
            m++;
        }
        i++;
    }
    //Faltan copiar elementos de 2da lista
    if(l > mid)
    {
        for(k = m; k <= high; k++)
        {
            temp[i] = vector[k];
            i++;
        }
    }
    //Faltan copiar elementos de 1ra lista
    else
    {
        for(k = l; k <= mid; k++)
        {
            temp[i] = vector[k];
            i++;
        }
    }
    //Copia la lista final al arreglo original
    for(k = low; k <= high; k++)
    {
        vector[k] = temp[k];
    }

}

//IMPRIMIR
void imprimir_datos(int *vector)
{
    for(int cnt = 0; cnt < MAX; cnt++)
    {
        printf("%d ", vector[cnt]);
    }
    printf("\n");
}
