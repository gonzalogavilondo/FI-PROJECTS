#include "fila.h"

bool enqueue(FILA *pS, int x)
{
     if(isFull_fila(pS))
     {
         return false;
     }
     else
    {
         pS->A[pS->rear] = x;
         pS->rear = (pS->rear+1) % MAX;
         pS->size = pS->size + 1;
         return true;
    }
}

bool dequeue(FILA *pS, int *px)
{
    if(isEmpty_fila(pS))
    {
        return false;
    }
    else
    {
        (*px) = pS->A[pS->front];  //La variable “front” indica la posición, en el arreglo, del elemento que está listo para salir de la fila
        pS->front = (pS->front+1) % MAX;
        pS->size = pS->size - 1;
        return true;
    }
}

bool isEmpty_fila(FILA *pS)
{
     if(pS->size == 0)
     {
         return(true);
     }
     else
     {
         return(false);
     }
}

bool isFull_fila(FILA *pS)
{
    if( pS->size == MAX)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool peek_fila(FILA *pS, int *px)
{
    if(isEmpty_fila(pS))
    {
        return false;
    }
    else
    {
        (*px) = pS->A[(pS->front)];
        return true;
    }
}

void imprimir_fila(FILA pS)
{
    int num = 0;

    while (!isEmpty_fila(&pS))   ///mientras no esté vacía. Nota: vacía una copia de la fila, no la original
    {
        dequeue(&pS, &num);
        printf("%i\n", num);
    }
    printf("\n");
}

void inicializar_fila(FILA *pS)
{
    pS->size = 0;
    pS->front = 0;
    pS->rear = 0;
}
