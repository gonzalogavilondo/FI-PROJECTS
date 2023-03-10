#include "declaraciones.h"

///Quicksort
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


//IMPRIMIR
void imprimir_datos(int *vector)
{
    for(int cnt = 0; cnt < MAX; cnt++)
    {
        printf("%d ", vector[cnt]);
    }
    printf("\n");
}
