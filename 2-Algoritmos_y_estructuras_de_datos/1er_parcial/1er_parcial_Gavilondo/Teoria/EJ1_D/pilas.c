#include "pilas.h"

///////////////////////////PILAS///////////////////////////
bool isEmpty_pila(PILA *ppS)
{
    return((*ppS)==NULL);
}

bool isFull_pila(PILA *ppS) //Esta funcion es innecesaria, ya que una pila dinamica nunca esta llena.
{
    return (false);
}

bool peek_pila(PILA *ppS, int *px)
{
    PILA pS;
    if(isEmpty_pila(ppS))
    {
        return (false);
    }
    else
    {
        pS = (*ppS);
        (*px) = pS->valor;
        return (true);
    }
}

bool push(PILA *ppS, int x)
{
    PILA pS;
    if(isFull_pila(ppS))// NO ES NECESARIO
    {
        return (false);
    }
    else
    {
        pS = (*ppS);
        NODO *Nuevo;
        Nuevo = (NODO *) malloc(sizeof(NODO));
        Nuevo->valor = x;
        Nuevo->next = pS;
        (*ppS) = Nuevo;
        return (true);
    }
}
bool pop(PILA *ppS, int *px)
{
    PILA pS;
    if(isEmpty_pila(ppS))
    {
        return (false);
    }
    else
    {
        pS = (*ppS);
        (*px) = pS->valor;
        (*ppS) = pS->next;
        free(pS);
        return (true);
    }
}

void cargar_pila(PILA *pS)
{
    for(int i = 0; i < 10; i++)
    {
        push(pS, i);
    }
}

bool imprimir_pila(PILA pS)
{
    PILA tope = pS;
    if(isEmpty_pila(&pS))
    {
        return (false);
    }
    else
    {
        while(!isEmpty_pila(&tope))   ///Mientras no esté vacía. Nota: vacía una copia de la pila, no la original
        {
            printf("%d\n", tope->valor);
            tope= tope->next;
        }
        printf("\n");
        return (true);
    }
    free(tope);
}
