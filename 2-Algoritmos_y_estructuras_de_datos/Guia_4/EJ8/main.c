#include "pilas.h"

int main()
{
    //Declaracion de variables
    PILA pS = NULL; //Indica que la pila esta vacia, que el primer valor no tiene sucesor
    int *px;

    //Reservo memoria
    px = (int*)malloc(sizeof(int));

    //Cargamos la pila
    cargar_pila(&pS);
    imprimir_pila(pS);

    //Borramos el ultimo elemento de la pila
    pop(&pS, px);
    imprimir_pila(pS);

    //Nos quedamos con el ultimo elemento
    peek_pila(&pS, px);
    printf("El ultimo elemento de la pila es: %d", *px);

    //Liberamos memoria
    free(px);

    return 0;
}
