#include "declaraciones.h"

bool push(PILA *pS, int x)
{
     if(isFull(pS))
     {
         return false;
     }
     else
     {
         pS->A[++(pS->top)] = x;
         return true;
     }

}

bool pop(PILA *pS, int *px)
{
    if(isEmpty(pS))
    {
        return false;
    }
    else
    {
        (*px) = pS->A[(pS->top)--];
        return true;
    }
}

bool isEmpty(PILA *pS)
{
    return (pS->top < 0);
}

bool isFull(PILA *pS)
{
    return (pS->top >=MAX-1);
}

bool peek(PILA *pS, int *px)
{
    if(isEmpty(pS))
    {
        return false;
    }
    else
    {
        (*px) = pS->A[(pS->top)];
        return true;
    }
}

void imprimir_pila(PILA pS)
{
    int num = 0;

    while(!isEmpty(&pS))   ///Mientras no esté vacía. Nota: vacía una copia de la pila, no la original
    {
        pop(&pS, &num);
        printf("%i\n", num);
    }
    printf("\n");
}

void inicializar_pila(PILA *pS)
{
    pS->top = -1;
}
