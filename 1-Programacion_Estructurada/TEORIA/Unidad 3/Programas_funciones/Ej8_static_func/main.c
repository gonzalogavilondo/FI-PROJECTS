#include <stdio.h>

int val=10;             // declarada como global

void imprime(void);     // declarada como global, es externa por default
void imp_local(void);
int suma(int op1, int op2);
//static int suma(int op1, int op2);

int main()
{
   imprime();
   val = suma(5, 20);
   imprime();
   imp_local();

   return 0;
}

int suma(int op1, int op2)
{
   int result;

   result = op1 + op2;

   return result;
}

void imp_local(void)
{
   val = suma(10, 15);
   printf("Valor fuera de main (en imp_local) = %d\n\n",  val);
}

