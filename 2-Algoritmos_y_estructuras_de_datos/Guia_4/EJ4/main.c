#include <stdio.h>
#include <stdlib.h>
#include "header_listas_est.h"
/*
    Simule la dinámica de dos filas de un banco donde hay un único cajero. Para ello, existen
    tres posibles situaciones:
    a. Ingresa un cliente a alguna de las dos filas (aleatorio).
    b. El cajero atiende un cliente de la fila 1.
    c. El cajero atiende a un cliente de la fila 2.
    Muestre por pantalla cada una de las filas a medida que opera.
*/
int main()
{
    FILA fil1;
    FILA fil2;
    inicializar_fila(&fil1);
    inicializar_fila(&fil2);

    //Cargamos las filas
    cargar_filas(&fil1, &fil2);
    printf("FILA 1: \n\n");
    imprimir_fila(fil1);
    printf("FILA 2: \n\n");
    imprimir_fila(fil2);

    //Hago un menu con los 3 casos y que mientras imprima
    menu(fil1, fil2);


    return 0;
}
