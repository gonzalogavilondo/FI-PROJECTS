#include "listas.h"
/*
    Simule la dinámica de dos filas de un banco donde hay un único cajero. Para ello, existen
    tres posibles situaciones:
    a. Ingresa un cliente a alguna de las dos filas (aleatorio).
    b. El cajero atiende un cliente de la fila 1.
    c. El cajero atiende a un cliente de la fila 2.
    Muestre por pantalla cada una de las filas a medida que opera.

    HACER EL EJERCICIO UTILIZANDO LISTAS.

*/
int main()
{
    //Declaro las variables a utilizar
    LISTA fila1;
    LISTA fila2;

    //Inicializo
    inicializar_lista(&fila1);
    inicializar_lista(&fila2);

    //Cargo las filas con clientes
    cargar_filas(&fila1, &fila2);
    printf("FILA 1: \n\n");
    traverse(fila1);
    printf("FILA 2: \n\n");
    traverse(fila1);

    //Hago un menu con los 3 casos y que mientras imprima
    menu(fila1, fila2);

    return 0;
}
