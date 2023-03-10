#include "declaraciones.h"
int main()
{
    //Declaro las variables
    int A[MAX] = {1, 2, 3, 4, 5, 6, 7};
    PILA *pS = NULL;
    FILA *pF = NULL;
    int *pxF;
    int *pxP;

    //Reservo memoria para la LISTA
    pS = (PILA*)malloc(sizeof(PILA));
    pF = (FILA*)malloc(sizeof(FILA));

    pxF = (int*)malloc(sizeof(int));
    pxP = (int*)malloc(sizeof(int));

    //Inicializo;
    pS->top = -1;
    inicializar_fila(pF);


    //Asigno valores con insert a pila y a fila
    for(int i = 0; i < MAX; i++)
    {
        push(pS, A[i]);
        enqueue(pF, A[i]);
    }
    imprimir_fila(*pF);
    imprimir_pila(*pS);


    while (!isEmpty_fila(pF))
    {
        push(pS, dequeue(pF, pxF));
    }
    while (!isEmpty_pila(pS))
    {
        enqueue(pF, pop(pS, pxP));
    }
    imprimir_fila(*pF);



    //Libero memoria
    free(pS);
    free(pF);
    free(pxF);
    free(pxP);


    return 0;
}
