#include "declaraciones.h"

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

//Divide y vencerás
void quicksort(int *arreglo, int izquierda, int derecha)
{
    if (izquierda < derecha) //Criterio base
    {
        int indiceParticion = particion(arreglo, izquierda, derecha);
        quicksort(arreglo, izquierda, indiceParticion);
        quicksort(arreglo, indiceParticion + 1, derecha); //Aproximación progresiva
    }
}

int particion(int *arreglo, int izquierda, int derecha)
{
    //Elegimos el pivote, es el primero
    int pivote = arreglo[izquierda];

    //Ciclo infinito
    while(1)
    {
        //Mientras cada elemento desde la izquierda esté en orden (sea menor que el
        //pivote) continúa avanzando el índice
        while (arreglo[izquierda] < pivote)
        {
            izquierda++;
        }
        //Mientras cada elemento desde la derecha esté en orden (sea mayor que el
        //pivote) continúa disminuyendo el índice
        while (arreglo[derecha] > pivote)
        {
            derecha--;
        }
        /*
        Si la izquierda es mayor o igual que la derecha significa que no
        necesitamos hacer ningún intercambio
        de variables, ya que los elementos ya están en orden (al menos en esta
        iteración)
        */
        if (izquierda >= derecha)
        {
            //Indicar "en dónde nos quedamos" para poder dividir el arreglo de nuevo
            //y ordenar los demás elementos
            return derecha;

        }
        else
        {     /*
              Si las variables quedaron "lejos" (es decir, la izquierda no superó ni
              alcanzó a la derecha)
              significa que se detuvieron porque encontraron un valor que no estaba
              en orden, así que lo intercambiamos
              */
              intercambiar(&arreglo[izquierda], &arreglo[derecha]);
              /*
              Ya intercambiamos, pero seguimos avanzando los índices
              */
              izquierda++;
              derecha--;
        }
        //El while se repite hasta que izquierda >= derecha
    }
}
void intercambiar(int *a, int *b)
{
    int temporal = *a;
    *a = *b;
    *b = temporal;
}
