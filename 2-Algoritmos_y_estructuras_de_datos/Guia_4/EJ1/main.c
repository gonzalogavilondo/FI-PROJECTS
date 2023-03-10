#include "pila.h"

int main()
{
    //Declaro las variables
    int A[MAX] = {1, 2, 3, 4, 5, 6, 7};
    PILA *pS = NULL;
    int *px;

    //Reservo memoria para la PILA
    pS = (PILA*)malloc(sizeof(PILA));
    px = (int*)malloc(sizeof(int));

    pS->top = -1;

    //Agregamos los valores a la pila con push apilando uno encima de otro
    for(int i = 0; i < MAX; i++)
    {
        push(pS, A[i]);
    }
    imprimir_pila(*pS);

    //Quitamos el ultimo valor por ser una pila
    pop(pS, px);        //Le quitamos el valor de la ultima posicion, es decir el '7' en este caso.

    //Nota: En la pila quedo como ultimo elemento el valor '6'.
    puts("PILA DESPUES DE POP\n");
    imprimir_pila(*pS);

    //Pedimos un valor en la posicion px (ultima posicion de la pila)
    peek(pS, px);
    printf("El elemento en la posicion px (ultimo elemento de la pila) es: %d", *px);
    //Nota: Vimos como resultado que nos da '6' se verifico el eliminado del ultimo elemento de la pila.

    //Liberamos memoria
    free(pS);
    free(px);

    return 0;
}
