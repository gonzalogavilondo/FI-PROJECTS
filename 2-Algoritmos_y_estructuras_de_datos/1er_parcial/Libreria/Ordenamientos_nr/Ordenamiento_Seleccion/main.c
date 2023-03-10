#include "declaraciones.h"

/*
El ordenamiento por selección es uno de los más simples e intuitivos. Va eligiendo el menor valor, no
ordenado, y lo reemplaza en la sublista ya ordenada.
*/
int main()
{
    //Declaramos el vector y demas variables a utilizar
    int *vector = NULL;

    int cnt_elementos = 8;

    //Reservamos memoria
    vector = reservar_memoria(cnt_elementos);

    //Cargamos el vector
    completar_vector(vector, cnt_elementos);

    //Imprimo el vector antes de ordenarlo
    printf("-VECTOR INGRESADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Llamamos a la funcion "Ordenamiento por seleccion"
    OrdSeleccion(vector, cnt_elementos);

    //Imprimimos resultados
    printf("-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Liberamos memoria
    free(vector);

    return 0;
}
