#include "declaraciones.h"

///Quicksort
void quicksort(int *arreglo, int izquierda, int derecha)
{
    if (izquierda < derecha) //Criterio base
    {
        int indiceParticion = particion(arreglo, izquierda, derecha);
        quicksort(arreglo, izquierda, indiceParticion);
        quicksort(arreglo, indiceParticion + 1, derecha); //Aproximaci�n progresiva
    }
}

int particion(int *arreglo, int izquierda, int derecha)
{
    //Elegimos el pivote, es el primero
    int pivote = arreglo[izquierda];

    //Ciclo infinito
    while(1)
    {
        //Mientras cada elemento desde la izquierda est� en orden (sea menor que el
        //pivote) contin�a avanzando el �ndice
        while (arreglo[izquierda] < pivote)
        {
            izquierda++;
        }
        //Mientras cada elemento desde la derecha est� en orden (sea mayor que el
        //pivote) contin�a disminuyendo el �ndice
        while (arreglo[derecha] > pivote)
        {
            derecha--;
        }
        /*
        Si la izquierda es mayor o igual que la derecha significa que no
        necesitamos hacer ning�n intercambio
        de variables, ya que los elementos ya est�n en orden (al menos en esta
        iteraci�n)
        */
        if (izquierda >= derecha)
        {
            //Indicar "en d�nde nos quedamos" para poder dividir el arreglo de nuevo
            //y ordenar los dem�s elementos
            return derecha;

        }
        else
        {     /*
              Si las variables quedaron "lejos" (es decir, la izquierda no super� ni
              alcanz� a la derecha)
              significa que se detuvieron porque encontraron un valor que no estaba
              en orden, as� que lo intercambiamos
              */
              intercambiar(&arreglo[izquierda], &arreglo[derecha]);
              /*
              Ya intercambiamos, pero seguimos avanzando los �ndices
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
