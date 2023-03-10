#include "pilas.h"

int main()
{
    //Declaracion de variables
    PILA pS = NULL; //Indica que la pila esta vacia, que el primer valor no tiene sucesor
    int *px;
    int n = 5;

    //Reservo memoria
    px = (int*)malloc(sizeof(int));

    while (n > 0)
    {
        push(&pS, n%2);
        n = n/2;
    }
    while(!isEmpty_pila(&pS))
    {
        printf("%d ", pop(&pS, px));
    }
    imprimir_pila(pS);

    //Liberamos memoria
    free(px);

    return 0;
}
