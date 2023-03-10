#include "header_listas_est.h"

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

void cargar_filas(FILA *fil1, FILA *fil2)
{
    for (int i = 0; i < 10; i++)    ///cargo las filas con clientes
    {
        enqueue(fil1, i);
        enqueue(fil2, i);
    }
}
void menu(FILA fil1, FILA fil2)
{
    int cliente = 0;
    int cajero = 0;
    do
    {
        cliente = rand() % 100 + 1;

        switch (rand() % 2 + 1) ///ingresa un cliente a una fila random
        {
        case 1:     ///el cliente se pone en la fila 1
            enqueue(&fil1, cliente);
            break;
        case 2:     ///el cliente se pone en la fila 2
            enqueue(&fil2, cliente);
            break;
        }

        dequeue(&fil1, &cajero);    ///el cajero atiende a un cliente de la fila 1
        dequeue(&fil2, &cajero);    ///el cajero atiende a un cliente de la fila 2


        printf("FILA 1: \n\n");
        imprimir_fila(fil1);
        printf("\nFILA 2: \n\n");
        imprimir_fila(fil2);

    }while (!isEmpty_fila(fil1) && !isEmpty_fila(fil2));
}
