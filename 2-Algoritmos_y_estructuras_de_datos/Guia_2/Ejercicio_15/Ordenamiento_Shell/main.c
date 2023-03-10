#include "declaraciones.h"

/*
El ordenamiento Shell es un algoritmo por inserci�n que intenta mejorar el desempe�o del ordenamiento
por inserci�n comparando elementos lejanos. Para ello, ordena �sublistas� usando ordenamiento por
inserci�n. Las sublistas est�n definidas por un tama�o de intervalo K. Cuando K es igual a 1, el algoritmo
es similar a �Inserci�n� pero se ejecutar� m�s r�pido por el orden de los datos obtenidos en los pasos
anteriores

*/
int main()
{
    int vector[] = {13, 96, 5, 1, 54, 2, 42, 7, 38, 9, 6, 20};
    int cnt_elementos = sizeof(vector)/sizeof(int);

    //Imprimo el vector antes de ordenarlo
    printf("-VECTOR INGRESADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Llamamos a la funcion "Ordenamiento por insercion"
    OrdShell(vector, cnt_elementos);

    //Imprimimos resultados
    printf("\n\n-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    return 0;
}
/*
Observaciones:
a) Los valores de K no precisan decrecer de a 1. Por ejemplo, pueden usarse valores K = 10, 5, 2, 1
b) En el �ltimo paso, K tiene que ser 1, para ejecutar la ordenaci�n sobre toda la lista.
c) Su complejidad no est� totalmente definida y depende de la secuencia de valores de K.
d) Es m�s lento que Quicksort, pero no es recursivo, por lo que se ha utilizado en algunos casos en
sistemas embebidos
*/
