#include <stdio.h>

long factorial(int num);            /* declaracion de la funcion */

int main()
{
   int valor = 5;                   /* ojo 12 es el valor maximo por el limite de long*/
   long resultado;

   resultado = factorial(valor);
   printf("El factorial de %d es %ld\n\n", valor, resultado);

   valor = 12;
   resultado = factorial(valor);
   printf("El factorial de %d es %ld\n", valor, resultado);

   return 0;
}

long factorial(int num)              /* definicion de la funcion */
{
    long resultado;

    if(num == 1)
        resultado = 1;                      /* condición parada  */
    else
        resultado = num*factorial(num-1);   /* llamada recursiva */

    return resultado;
}
