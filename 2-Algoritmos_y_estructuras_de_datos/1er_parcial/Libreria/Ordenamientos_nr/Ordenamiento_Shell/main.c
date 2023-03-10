#include "declaraciones.h"

/*
El ordenamiento Shell es un algoritmo por inserción que intenta mejorar el desempeño del ordenamiento
por inserción comparando elementos lejanos. Para ello, ordena “sublistas” usando ordenamiento por
inserción. Las sublistas están definidas por un tamaño de intervalo K. Cuando K es igual a 1, el algoritmo
es similar a “Inserción” pero se ejecutará más rápido por el orden de los datos obtenidos en los pasos
anteriores

*/
int main()
{
    //Declaramos el vector y demas variables a utilizar
    int *vector = NULL;

    int cnt_elementos = CNT;

    //Reservamos memoria
    vector = reservar_memoria(cnt_elementos);

    //Cargamos el vector
    completar_vector(vector, cnt_elementos);

    //Imprimo el vector antes de ordenarlo
    printf("-VECTOR INGRESADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Llamamos a la funcion "Ordenamiento por insercion"
    OrdShell(vector, cnt_elementos);

    //Imprimimos resultados
    printf("\n\n-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Liberamos memoria
    free(vector);

    return 0;
}
/*
Observaciones:
a) Los valores de K no precisan decrecer de a 1. Por ejemplo, pueden usarse valores K = 10, 5, 2, 1
b) En el último paso, K tiene que ser 1, para ejecutar la ordenación sobre toda la lista.
c) Su complejidad no está totalmente definida y depende de la secuencia de valores de K.
d) Es más lento que Quicksort, pero no es recursivo, por lo que se ha utilizado en algunos casos en
sistemas embebidos
*/
