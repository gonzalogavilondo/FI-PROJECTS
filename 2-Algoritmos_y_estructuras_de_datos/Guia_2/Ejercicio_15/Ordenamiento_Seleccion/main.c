#include "declaraciones.h"

/*
El ordenamiento por selección es uno de los más simples e intuitivos. Va eligiendo el menor valor, no
ordenado, y lo reemplaza en la sublista ya ordenada.
*/
int main()
{
    int vector[] = {13, 96, 5, 1, 54, 2, 42, 7, 38, 9, 6, 20};
    int cnt_elementos = sizeof(vector)/sizeof(int);

    //Imprimo el vector antes de ordenarlo
    printf("-VECTOR INGRESADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Llamamos a la funcion "Ordenamiento por seleccion"
    OrdSeleccion(vector, cnt_elementos);

    //Imprimimos resultados
    printf("-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    return 0;
}
