#include "fila.h"

int main()
{
    //Declaro las variables
    int A[MAX] = {1, 2, 3, 4, 5, 6, 7};
    FILA *pS = NULL;
    int *px;

    //Reservo memoria para la FILA
    pS = (FILA*)malloc(sizeof(FILA));
    px = (int*)malloc(sizeof(int));

    //Inicializo
    inicializar_fila(pS);

    //Asigno valores con enqueue
    for(int i = 0; i < MAX; i++)
    {
        enqueue(pS, A[i]);
    }
    imprimir_fila(*pS);

    //Quito valores con dequeue
    dequeue(pS, px); //Le quitamos el valor de la primera posicion, es decir el '1' en este caso.
    printf("Le quitamos la primera posicion\n");
    imprimir_fila(*pS);

    //Pedimos un valor en la posicion px (Primera posicion de la fila, que deberia ser '2' ahora, por eliminar el primer elemento)
    peek_fila(pS, px);
    printf("El valor ahora en la primera posicion es: %d", *px);

    //Libero memoria
    free(pS);
    free(px);

    return 0;
}
