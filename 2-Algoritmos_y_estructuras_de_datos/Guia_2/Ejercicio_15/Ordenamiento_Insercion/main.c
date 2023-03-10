#include "declaraciones.h"

/*
Uno de los m�todos m�s simples para ordenar un arreglo es el de inserci�n. La base del m�todo est� en
recorrer el arreglo, elemento por elemento, e insertarlo en la lista de elementos previos en la posici�n que
corresponda para mantener el orden hasta llegar al final.
*/
int main()
{
    int vector[] = {13, 96, 5, 1, 54, 2, 42, 7, 38, 9, 6, 20};
    int cnt_elementos = sizeof(vector)/sizeof(int);

    //Imprimo el vector antes de ordenarlo
    printf("-VECTOR INGRESADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Llamamos a la funcion "Ordenamiento por insercion"
    OrdInsercion(vector, cnt_elementos);

    //Imprimimos resultados
    printf("\n\n-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    return 0;
}
