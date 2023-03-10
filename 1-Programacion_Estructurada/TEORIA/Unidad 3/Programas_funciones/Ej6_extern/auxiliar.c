#include <stdio.h>

void imprime(void)  // se puede agregar extern, es opcional
{
   extern int val;

   printf("Valor fuera de main (en imprime) = %d\n\n",  val);
   val = 29;
}

