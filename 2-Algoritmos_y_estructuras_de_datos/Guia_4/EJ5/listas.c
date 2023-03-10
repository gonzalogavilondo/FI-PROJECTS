#include "listas.h"
///////////////////////////LISTAS///////////////////////////

bool insert(int x, int k, LISTA *pS) ///inserta un elemento x en la lista ps, en la posicion k
{
    if (isFull_lista(*pS) || k > pS->rear)     ///si está llena o la posición es mayor a la última posición
    {
        return false;
    }
    else
    {
        for (int i = pS->rear; i > k; i--)  ///recorre de derecha a izquierda para mover elementos a la derecha
        {
            pS->A[i] = pS->A[i - 1];
        }
        pS->A[k] = x;
        (pS->rear)++;
        return true;
    }
}

bool delete(int k, LISTA *pS)   ///elimina el elemento que está en la posición k
{
    if (k >= pS->rear)  ///si intento borrar un elemento que no está en la lista
    {
        return false;
    }
    else
    {
        for (int i = k + 1; i < pS->rear; i++)  ///mueve elementos a la izquierda
        {
            pS->A[i - 1] = pS->A[i];
        }
        (pS->rear)--;
        return true;
    }
}

bool get(int k, LISTA pS, int *px) ///obtiene el elemento en la posición k y lo almacena en *px
{
    if (k >= pS.rear)
    {
        return false;
    }
    else
    {
        *px = pS.A[k];
        return true;
    }
}

bool traverse(LISTA pS)
{
    for (int i = 0; i < pS.rear; i++)
    {
        printf("%i\n", pS.A[i]);
    }
    printf("\n");
    return true;
}

bool isEmpty_lista(LISTA pS)
{
    if (pS.rear == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull_lista(LISTA pS)
{
    if (pS.rear == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void inicializar_lista(LISTA *pS)
{
    pS->rear = 0;
}

void cargar_filas(LISTA *fila1, LISTA *fila2)
{
    for(int i = 0; i < 10; i++)
    {
        insert(i+1, i, fila1);
        insert(i+1, i, fila2);

    }
}

void menu(LISTA fila1, LISTA fila2)
{
    int cliente = 0;
    int cajero = 0;

    for(int i = 0; i < 10; i++)
    {
        do
        {
            cliente = rand() % 100 + 1;

            switch (rand() % 2 + 1) ///ingresa un cliente a una fila random
            {
            case 1:     ///el cliente se pone en la fila 1
                insert(cliente, fila1.rear, &fila1);
                break;
            case 2:     ///el cliente se pone en la fila 2
                insert(cliente, fila2.rear, &fila2);
                break;
            }

            delete(cajero, &fila1);    ///el cajero atiende a un cliente de la fila 1
            delete(cajero, &fila2);    ///el cajero atiende a un cliente de la fila 2

            printf("FILA 1: \n\n");
            traverse(fila1);
            printf("\nFILA 2: \n\n");
            traverse(fila2);

        }while(!isEmpty_lista(fila1) && !isEmpty_lista(fila2));
    }

}
