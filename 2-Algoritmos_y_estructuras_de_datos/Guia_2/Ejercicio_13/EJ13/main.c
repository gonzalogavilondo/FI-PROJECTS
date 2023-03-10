#include "declaraciones.h"

/*
Dada una matriz (5x5) triangular superior ingresada por el usuario, encontrar el dato x
utilizando búsqueda binaria e indicar su posición en el arreglo
*/
int main()
{
    //Declaramos la matriz triangular y el vector donde van a ser almacenados los datos de forma estatica.
    float matriz[FILSMAX][COLSMAX] = {{0.0}};
    float vector[LONGMAX] = {0.0};
    float condicion = 1.0; //El valor que quiero encontrar.
    int posicion = 0;

    //Le pedimos al usuario que complete la matriz
    completar_matriz(matriz);

    //Mapeamos la matriz
    mapear_matriz(matriz, vector);

    //Ordenamos el vector resultante de la matriz diagonal. Llamamos a la funcion "Ordenamiento por insercion"
    OrdInsercion(vector);

    //Realizamos la busqueda binaria (Para realizar esta busqueda, el vector tiene que ya estar ordenado)
    posicion = busqueda_binaria(vector, condicion);

    //Imprimimos los resultados
    printf("-MATRIZ TRIANGULADA-\n\n");
    imprimir_matriz(matriz);
    printf("-VECTOR ORDENADO-\n\n");
    imprimir_vector(vector);
    puts("\n\n");
    imprimir(posicion, condicion);


    return 0;
}
