#include "declaraciones.h"

///////////////////////////PILAS////////////////////////////
bool push(PILA *pS, int x) ///agrega x a la pila pS
{
    if(isFull_pila(*pS))
    {
        return false;
    }
    else
    {
        pS->A[++(pS->top)] = x;     ///pre-incrementa el tope y asigna x arriba de la pila
        return true;
    }
}

bool pop(PILA *pS, int *px) ///remueve el elemento superior de la pila y lo almacena en *px.
{
    if (isEmpty_pila(*pS))
    {
        return false;
    }
    else
    {
        *px = pS->A[(pS->top)--];   ///pone el elemento superior en px y luego decrementa el tope
        return true;
    }
}

bool isEmpty_pila(PILA pS) ///Comprueba si la pila está vacía
{
    return (pS.top < 0); ///Si el tope es menor a 0 devuelve true, sino false.
}

bool isFull_pila(PILA pS)  ///Comprueba si la pila está llena
{
    return (pS.top >= MAX - 1); ///Si el tope es mayor o igual a MAX - 1, devuelve true, sino false.
}

bool peek_pila(PILA pS, int *px)   ///Recupera el último valor de la pila, sin retirarlo y lo almacena en *px
{
    if (isEmpty_pila(pS))
    {
        return false;
    }
    else
    {
        *px = pS.A[(pS.top)];   ///Pone el elemento superior en px y deja el tope como está, sin decrementarlo.
        return true;
    }
}

void inicializar_pila(PILA *pS)
{
    pS->top = -1;
}

void imprimir_pila(PILA pS)
{
    int num = 0;

    while(!isEmpty_pila(pS))   ///Mientras no esté vacía. Nota: vacía una copia de la pila, no la original
    {
        pop(&pS, &num);
        printf("%i\n", num);
    }
    printf("\n");
}

///////////////////////////FILAS////////////////////////////
bool enqueue(FILA *pS, int x)  ///Agrega un elemento a la fila
{
    if (isFull_fila(*pS))
    {
        return false;
    }
    else
    {
        pS->A[(pS->rear)] = x;                ///asigna el valor a la posición final
        pS->rear = (pS->rear + 1) % MAX;    ///si el rear es mayor o igual a MAX lo guarda en las primeras posiciones (arreglo circular)
        (pS->size)++;
        return true;
    }
}

bool dequeue(FILA *pS, int *px)    ///remueve un elemento de la fila
{
    if (isEmpty_fila(*pS))
    {
        return false;
    }
    else
    {
        *px = pS->A[(pS->front)]; ///almacena el elemento que está adelante en *px
        pS->front = (pS->front + 1) % MAX;  ///si el front es mayor o igual a MAX lo guarda en las primeras posiciones (arreglo circular)
        (pS->size)--;
        return true;
    }
}

bool isEmpty_fila(FILA pS)
{
    return (pS.size == 0);
}

bool isFull_fila(FILA pS)
{
    return (pS.size == MAX);
}

bool peek_fila(FILA pS, int *px)
{
    if (isEmpty_fila(pS))
    {
        return false;
    }
    else
    {
        *px = pS.A[(pS.front)];
        return true;
    }
}

void inicializar_fila(FILA *pS)
{
    pS->size = 0;
    pS->front = 0;
    pS->rear = 0;
}

void imprimir_fila(FILA pS)
{
    int num = 0;

    while(!isEmpty_fila(pS))   ///mientras no esté vacía. Nota: vacía una copia de la fila, no la original
    {
        dequeue(&pS, &num);
        printf("%i\n", num);
    }
    printf("\n");
}
