#include <stdio.h>

int suma(int op1, int op2);

void imprime(void)  // se puede agregar extern, es opcional
{
   extern int val;

   val = suma(val, 3*val);
   printf("Valor fuera de main (en imprime) = %d\n\n",  val);
}


