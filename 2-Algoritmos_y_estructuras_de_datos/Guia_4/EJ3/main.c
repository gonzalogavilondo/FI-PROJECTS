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

    //Tomo un valor con get
    get(3, pS, px); //Tomo el valor "4" que esta en la posicion k = 3.
    printf("El valor de px: %d\n\n", *px); //Deberia imprimir "4"

    //Funcion traverse
    traverse(pS); //Imprime la lista en vertical.

    //Eliminamos todo
    for(int i = 0; i < MAX; i++)
    {
        delete(i, pS);
    }
    puts("\n");
    imprimir_lista(pS); //Deberia imprimir todos valores que quedaron en memoria o randoms

    //Libero memoria
    free(pS);
    free(px);

    return 0;
}
