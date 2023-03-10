#include "declaraciones.h"
/*
La función factorial de n se define de la siguiente forma: Si n es igual a 0, entonces n! es
igual a 1. Si n es mayor que 0, entonces n! es igual al producto de (n-1)! y n. Como puedes
ver, definimos n! en términos de (n-1)!, que a su vez está definido en términos de ((n-1)-
1)!, que a su vez... Después de n pasos, n! está definido en términos de 0!, pero como
sabemos que 0! es igual a 1, no hay necesidad de continuar. Hagamos un ejemplo:
4! = 4*3! = 4*(3*2!) = 4*(3*(2*1!)) = 4*(3*(2*(1*0!))) = 4*(3*(2*(1*1))) = 4*(3*(2*1)) =
4*(3*2) = 4*6 = 24.
Por cierto, el factorial de n cuenta el número de permutaciones de n objetos distintos.
a. Calcule el factorial de un número n en modo recursivo y no recursivo.
b. Pruebe las funciones con diferentes valores de n (10, 20, 40, 60) y analice el tiempo de
cálculo.
*/
int main()
{
    int num, res_nr, res_r;

    //Pedimos el numero al usuario
    printf("Ingrese el numero que desea calcular su factorial: ");
    scanf("%d", &num);

    //Llamamos a la funcion factorial no recursiva
    res_nr = factorial_nr(num);

    //Llamamos a la funcion factorial recursiva
    res_r = factorial_r(num);

    //Imprimimos los resultados
    printf("\nEl factorial de %d en forma no recursiva es: %d\n", num, res_nr);
    printf("\nEl factorial de %d en forma recursiva es: %d\n", num, res_r);


    return 0;
}
