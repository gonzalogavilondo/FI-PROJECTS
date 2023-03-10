#include "declaraciones.h"

int main()
{
    //Declaramos e inicializamos las variables
    int izq, der, posicion, x;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    x = 5;    //Valor a buscar
    izq = 0;  //Posicion inicial
    der = 19; //Posicion final

    //Llamamos a la funcion busqueda binaria
    posicion = busqueda_binaria(izq, der, x, array);

    //Imprimimos los resultados
    impresion(posicion, x);

    return 0;
}
