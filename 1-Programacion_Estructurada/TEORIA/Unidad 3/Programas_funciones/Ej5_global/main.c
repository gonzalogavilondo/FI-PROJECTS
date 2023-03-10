#include <stdio.h>

int val = 10;             // declarada como global

void imprime(void);

int main()
{
   int val = 3;         // con igual nombre, la local prevalece sobre la global

   printf("Valor dentro de main = %d\n", val);
   val = 17;
   imprime();

   return 0;
}

void imprime()
{
   printf("Valor fuera de main = %d\n", val);
}
