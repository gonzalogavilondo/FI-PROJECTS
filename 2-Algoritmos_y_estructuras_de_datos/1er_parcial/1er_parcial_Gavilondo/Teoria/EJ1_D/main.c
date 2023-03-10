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
        push(&pS, n%2);  //Agregamos a una pila el residuo de n al dividir por 2 (El numero en binario).
        n = n/2;
    }
    imprimir_pila(pS);
    while(!isEmpty_pila(&pS))
    {
        printf("%d ", pop(&pS, px)); //Imprimimos lo que sacamos de una pila, como sale el ultimo que entro primero
                                     //Entonces va imprimiendo el residuo al revez, como debe hacerse para representar un numero binario.
    }
    imprimir_pila(pS);

    //Liberamos memoria
    free(px);

    return 0;
}
