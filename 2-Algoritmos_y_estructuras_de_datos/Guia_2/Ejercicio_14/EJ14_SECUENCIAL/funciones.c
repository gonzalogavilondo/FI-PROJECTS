#include "declaraciones.h"

void OrdInsercion(int vector[LONGMAX], int cnt_elementos)
{
    int i, j, aux;

    for(i = 1; i < cnt_elementos; i++)
    {
        j = i;
        aux = vector[i];                  //Guarda el valor que quiere insertar en una variable auxiliar.
        while(j > 0 && aux < vector[j-1]) //Recorre de derecha a izquierda
        {
            vector[j] = vector[j-1];      //Se detiene cuando el anterior ya NO es mayor.
            j--;                          //En cada caso, corre el numero a la derecha.
        }
        vector[j] = aux;                  //Al terminar, coloca el valor en su posicion final.
    }

}

void busqueda_secuencial(int vector[LONGMAX], int condicion[7], int posicion[7])
{

    for(int j = 0; j < 7; j++)
    {
        for(int i = 0; i < LONGMAX; i++)
        {
            if(vector[i] == condicion[j])
            {
                posicion[j] = i;

            }

        }
    }
}


void imprimir_vector(int vector[LONGMAX], int cnt_elementos)
{
    printf("|\t");
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("%d\t", vector[j]);
    }
    printf("|\n\n");

}


void imprimir(int posicion[7], int condicion[7])
{
    int i;

    for(i = 0; i < 7; i++)
    {
        printf("\n\nLa condicion es hayar en el vector la posicion del numero: %d", condicion[i]);

        if(posicion[i] == -1)
        {
            printf("\n\nNo se ha podido encontrar la posicion del valor pedido.\n");
        }
        else
        {
            printf("\n\nLa posicion del numero pedido es: %d\n\n", posicion[i]+1);
        }

    }

}
