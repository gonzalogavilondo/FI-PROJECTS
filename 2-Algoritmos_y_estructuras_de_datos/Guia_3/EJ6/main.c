#include "declaraciones.h"
/*
    La función factorial n! cuenta el número de permutaciones. Pero, si las necesitáramos
    ¿cómo se generarían? Para darnos una idea, demos un vistazo a las 4! = 24 permutaciones
    de los números 1, 2, 3 y 4:
    1234 1243 1324 1342 1423 1432 2134 2143 2314 2341 2413 2432 3124 3142 3214 3241
    Si observas bien, notarás que las 24 permutaciones de los cuatro números 1, 2, 3 y 4 se
    pueden obtener de la siguiente forma: primero escribamos las 3! = 6 permutaciones que
    comienzan con 1, luego las 6 que comienzan con 2, luego las 6 que comienzan con 3 y
    finalmente las 6 que comienzan con 4. Es decir, hemos dividido la tarea de escribir las 4!
    permutaciones en las 4 tareas de escribir un elemento y las 3! permutaciones de los 3
    restantes. En general, podemos dividir la tarea de escribir las n! permutaciones de n
    elementos en las n tareas de escribir uno de ellos y las (n-1)! permutaciones de los demás.
    Escribir un algoritmo que tome como entrada un número n del 1 al 10 y escriben las n!
    permutaciones de {1, 2, ..., n}.
*/

int main()
{
    int lista[3] = {1, 2, 3};
    int n = sizeof(lista)/sizeof(int);
    int i = 0;

    //Llamo a la funcion permutacion
    permutaciones(lista, n, i);


    return 0;
}
