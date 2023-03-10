#include "declaraciones.h"

/*
Uno de los métodos más simples para ordenar un arreglo es el de inserción. La base del método está en
recorrer el arreglo, elemento por elemento, e insertarlo en la lista de elementos previos en la posición que
corresponda para mantener el orden hasta llegar al final.
*/
int main()
{
    //Declaramos el vector y demas variables a utilizar
    int *vector = NULL;

    int cnt_elementos = 0;

    //Le pedimos al usuario la cantidad de elementos del vector
    printf("Ingrese la cantidad de elementos del vector: ");
    scanf("%d", &cnt_elementos);
    system("pause");
    system("cls|| clear");

    //Reservamos memoria
    vector = reservar_memoria(cnt_elementos);

    //Cargamos el vector
    completar_vector(vector, cnt_elementos);

    //Imprimo el vector antes de ordenarlo
    printf("-VECTOR INGRESADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Llamamos a la funcion "Ordenamiento por insercion"
    OrdInsercion(vector, cnt_elementos);

    //Imprimimos resultados
    printf("\n\n-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector, cnt_elementos);

    //Liberamos memoria
    free(vector);

    return 0;
}
