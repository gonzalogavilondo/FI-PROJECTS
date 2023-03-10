#include "fila.h"

///////////////////////////FILAS///////////////////////////

bool isEmpty_fila(FILA *pF)
{
    return (pF->front==NULL);
}

bool isFull_fila(FILA *pF)
{
    return (false);
}

bool peek_fila(FILA *pF, int *px)
{
    NODO *pS;
    if(isEmpty_fila(pF))
    {
        return (false);
    }
    else
    {
        pS = pF->front;
        (*px) = pS->valor;
        return (true);
    }
}

bool enqueue(FILA *pF, int x)
{
     NODO *Nuevo;
     NODO *pS; // Ultimo nodo
     if(isFull_fila(pF))// NO ES NECESARIO
     {
         return (false);
     }
     else
     {
         Nuevo = (NODO*) malloc(sizeof(NODO));
         Nuevo->valor = x;
         Nuevo->next = NULL;
         if(pF->rear!=NULL)// solo si ya hay nodos, corrige
         {
             pS = pF->rear; // Puntero al ultimo nodo
             pS->next = Nuevo; // Ultimo apunta al nuevo
         }
         else
         {
            pF->front = Nuevo; // Nuevo ultimo
         }
         pF->rear = Nuevo; // Nuevo ultimo
         return (true);
     }
}

bool dequeue(FILA *pF, int *px)
{
    NODO *pS;
    if(isEmpty_fila(pF))
    {
        return (false);
    }
    else
    {
        pS = pF->front; // Guarda puntero al primero
        (*px) = pS->valor; // Toma valor
        pF->front = pS->next; // Actualiza “front”
        if(pS->next==NULL)
        {
            pF->rear = NULL; // No hay mas nodos
        }
        free(pS); // Libera primero
        return (true);
    }
}

void inicializar_fila(FILA *pF)
{
    pF->front = NULL;
    pF->rear = NULL;
}

bool imprimir_fila(FILA pF)
{
    NODO *primero = pF.front;

    if(isEmpty_fila(&pF))
    {
        return (false);
    }
    else
    {
        while(primero != NULL)   ///mientras no esté vacía. Nota: vacía una copia de la fila, no la original
        {
            printf("%d\n", primero->valor);
            primero = primero->next;
        }
        printf("\n");
        return (true);

    }
}

void cargar_fila(FILA *pF)
{
    for(int i = 1; i < 10; i++)
    {
        enqueue(pF, i);
    }

}
