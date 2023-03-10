#include "declaraciones.h"
/*
Aplique las funciones anteriores al siguiente array de enteros A (-8, 4, 5, 9, 12, 18, 25, 40,
60). Buscar los números 12, 40, -8, 15, 60, -10, y 75 utilizando búsqueda binaria y secuencial
para ello adecuar el vector A como corresponda.

*/
int main()
{
    //Declaramos los vectores, uno con los datos y otro con los valores a hallar.
    int A[LONGMAX] = {-8, 4, 5, 9, 12, 18, 25, 40, 60};
    int condicion[7] = {12, 40, -8, 15, 60, -10, 75};
    int posicion[7] = {-1, -1, -1, -1, -1, -1, -1};

    //Antes de realizar la busqueda, debemos ordenar el vector "A".(Ya esta ordenado, pero por si ingresamos otro vector mas adelante)
    OrdInsercion(A, LONGMAX); //Ordenamos el vector A

    //Busqueda secuencial
    busqueda_secuencial(A, condicion, posicion);

    //Imprimimos resultados
    printf("-VECTOR ORDENADO-\n\n");
    imprimir_vector(A, LONGMAX);
    printf("-VECTOR CONDICION-\n\n");
    imprimir_vector(condicion, 7);
    puts("\n");
    printf("RESULTADOS CON BUSQUEDA SECUENCIAL:\n");
    puts("----------------------------------------------------------------");
    imprimir(posicion, condicion);
    puts("\n\n----------------------------------------------------------------");

    return 0;
}
