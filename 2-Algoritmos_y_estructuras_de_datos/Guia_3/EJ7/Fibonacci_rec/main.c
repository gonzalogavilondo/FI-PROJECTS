#include "declaraciones.h"
/*
Cierto matem�tico italiano de nombre Leonardo de Pisa, pero mejor conocido como
Fibonacci, propuso el siguiente problema: Suponga que acabamos de comprar una pareja
de conejos adultos. Al cabo de un mes, esa pareja tiene una pareja de conejitos (un conejo
y una coneja). Un mes despu�s, nuestra primera pareja tiene otra pareja de conejitos
(nuevamente, un conejo y una coneja) y, al mismo tiempo, sus primeros hijos se han vuelto
adultos. As� que cada mes que pasa, cada pareja de conejos adultos tiene una pareja de
conejitos, y cada pareja de conejos nacida el mes anterior se vuelve adulta. La pregunta es,
�cu�ntas parejas de conejos adultos habr� al cabo de n meses? Escriba un programa que
resuelva el problema de Fibonacci utilizando algoritmos recursivos y no recursivos.
*/
int main()
{
    int n, resultado;

    //Pedimos al usuario la cantidad de meses
    printf("Ingrese la cantidad de meses: ");
    scanf("%d", &n);

    //Llamamos a la funcion fibonacci
    resultado = fibonacci(n);

    //Imprimimos resultados
    printf("La cantidad de parejas es: %d", resultado);



    return 0;
}
