#include "fila.h"

int main()
{
    FILA pF;
    int *px;

    //Reservo memoria al puntero px
    px = (int*)malloc(sizeof(int));

    //Inicializamos los elementos de la fila
    inicializar_fila(&pF);

    //Cargamos la fila
    cargar_fila(&pF);
    imprimir_fila(pF);

    //Quitamos el primero que entro, es decir el 1, que seria el primero que llego a la "fila"
    dequeue(&pF, px);
    imprimir_fila(pF);

    //Recuperamos el valor del inicio de la fila
    peek_fila(&pF, px);
    printf("El valor ahora en la primera posicion es: %d", *px);


    //Libero memoria
    free(px);

    return 0;
}
