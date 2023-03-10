#include "declaraciones.h"

void imprimir_vector(int *vector, int cnt_elementos)
{
    printf("|\t");
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("%d\t", vector[j]);
    }
    printf("|\n\n");

}

void OrdInsercion(int *vector, int cnt_elementos)
{
    int i, j, aux;

    for(i = 1; i < cnt_elementos; i++)
    {
        j = i;
        aux = vector[i]; //Guarda el valor que quiere insertar en una variable auxiliar.
        while(j > 0 && aux < vector[j-1]) //Recorre de derecha a izquierda
        {
            vector[j] = vector[j-1];      //Se detiene cuando el anterior ya NO es mayor.
            j--;                          //En cada caso, corre el numero a la derecha.
        }
        vector[j] = aux;                  //Al terminar, coloca el valor en su posicion final.
    }

}
