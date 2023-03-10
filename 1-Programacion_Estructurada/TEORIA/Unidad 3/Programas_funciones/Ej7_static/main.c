#include <stdio.h>

void cuenta(void);

int main()
{
   cuenta();
   cuenta();
   cuenta();
   cuenta();

   return 0;
}

void cuenta()
{
   static int cnt = 0;    /* se inicializa a 0 por default (no es aconsejable) */

   printf("Valor del contador = %d\n\n", cnt++);
}
