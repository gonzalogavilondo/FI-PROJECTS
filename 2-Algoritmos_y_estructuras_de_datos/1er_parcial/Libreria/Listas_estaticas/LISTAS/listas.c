#include "listas.h"

bool insert(int x, int k, LISTA *pS)
{
     int i;
     // Puede insertar en la posición “rear”
     // pero no más alla
     if(isfull(pS) || k > pS->rear)
     {
         return false;
     }
     else
     {
         // Recorre de derecha a Izquierda
         // para mover elementos a la derecha
         for(i = pS->rear; i > k; i--)
         pS->A[i] = pS->A[i+1];
         pS->A[k] = x;
         pS->rear = (pS->rear+1);
         return true;
     }
}

bool deletee(int k, LISTA *pS)
{
    int i;
    // No puede eliminar elementos
    // que no están en la lista
    // Detecta empty (porque “rear”=0)
    if(k >= pS->rear)
    {
        return false;
    }
    else
    {
        // Mueve elementos a la izquierda
        for(i = k+1; i < pS->rear; i++)
        pS->A[i-1] = pS->A[i];
        pS->rear = (pS->rear-1);
        return true;
    }
}

bool get(int k, LISTA *pS, int *px)
{
    // No puede leer elementos que no
    // estan en la lista
    if(k >= pS->rear)
    {
        return false;
    }
    else
    {
        (*px) = pS->A[k];
        return true;
    }
}

bool traverse(LISTA *pS)
{
    int i;
    for(i = 0; i < pS->rear; i++)
    {
        printf("%i\n",pS->A[i]);
    }
    return true;
}

bool isempty(LISTA *pS)
{
    if(pS->rear == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isfull(LISTA *pS)
{
    if(pS->rear == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void imprimir_lista(LISTA *pS)
{
    printf("LISTA:\n");
    for(int i = 0; i < pS->rear; i++)
    {
        printf("%d ", pS->A[i]);
    }
    puts("\n");
}
