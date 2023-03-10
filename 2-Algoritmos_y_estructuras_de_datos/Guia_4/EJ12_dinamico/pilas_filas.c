#include "declaraciones.h"

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
        NODO_1 * Nuevo;
        Nuevo = (NODO_1 *) malloc(sizeof(NODO));
        Nuevo->valor = x;
        Nuevo->next = pS; //Esto lo que hace es decir de donde me prendo, yo estoy creando un nuevo nodo o un nuevo puntero a estructura y tengo que referenciar de donde la tengo que enganchar, antes habia un puntero a NULL, ahora yo tengo que decirle que no es NULL, sino que es un nuevo NODO y de donde viene ese nuevo nodo.
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

void imprimir_fila(FILA pF)
{
    int num = 0;

    while(!isEmpty_fila(&pF))   ///Mientras no esté vacía. Nota: vacía una copia de la fila, no la original
    {
        dequeue(&pF, &num);
        printf("%i\n", num);
    }
    printf("\n");
}

