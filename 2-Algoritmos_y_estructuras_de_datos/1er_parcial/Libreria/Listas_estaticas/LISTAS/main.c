#include "listas.h"

int main()
{
    //Declaro las variables
    int A[MAX] = {1, 2, 3, 4, 5, 6, 7};
    LISTA *pS = NULL;
    int *px;

    //Reservo memoria para la LISTA
    pS = (LISTA*)malloc(sizeof(LISTA));
    px = (int*)malloc(sizeof(int));

    //Inicializo;
    pS->rear = 0;

    //Asigno valores con insert
    for(int i = 0; i < MAX; i++)
    {
        insert(A[i], i, pS);
    }
    imprimir_lista(pS);

    imprimir_lista(pS);


    //Libero memoria
    free(pS);
    free(px);

    return 0;
}

LISTA *ProcessArray(LISTA *listA, int x, int n)
{
    int i, j, k;
    i = 0;
    j = n-1;
    do
    {
        k = (i+j)/2;
        if (x <= listA[k])
        {
            j = k-1;
        }
        if(listA[k] <= x)
        {
            i = k+1;
        }
    }while(i <= j);

     if (listA[k] == x)
     {
        return(k);
     }
     else
     {
        return -1;
     }
     return listA;
}
