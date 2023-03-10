#include <stdio.h>

int val = 10;             // declarada como global
//static int val=10;        // declarada como global pero solo accesible en main.c

void imprime(void);       // declarada como global, es externa por default
void imp_local(void);

int main()
{
   printf("Valor dentro de main = %d\n\n", val);
   val = 17;
   imprime();
   printf("Valor despues de llamar imprime = %d\n\n", val);
   val = 71;
   imp_local();
   printf("Valor despues de llamar imp_local = %d\n\n", val);

   return 0;
}

void imp_local(void)
{
   printf("Valor fuera de main (en imp_local) = %d\n\n",  val);
   val = 59;
}

