#include "declaraciones.h"
/*
Implementar una función que busque el máximo de un arreglo usando recursividad
*/
int main()
{
    //Declaramos las variables a utilizar
    int a[10] = {1, 2, 44, 12, 6, 21, 91, 27, 31, 21};
    int max;

    //Llamamos la funcion maximo
    max = Maximo(a, 0, 9); //Le paso las posiciones iniciales y finales

    //Imprimo los resultados
    printf("El maximo es el numero: %d\n", max);

    return 0;
}
