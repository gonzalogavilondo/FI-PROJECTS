#include <stdio.h>

void eleccion(unsigned opcion, int num);

int main()
{
   unsigned opt;           /* 1=utiliza if/else; 2=utiliza switch; 3=fin */
   int num;                /* numero a analizar, con 0 sale */

   do                      /* verifica que opcion sea 0 o 1 */
   {
      printf("\nIngrese una opcion (1=utiliza if/else; 2=utiliza switch; 3=finaliza): ");
      scanf("%u", &opt);

      num=1;
      while ( ((opt==1) || (opt==2)) && (num!=0) )
      {
         printf("\nIngrese un numero (0=finaliza): ");
         scanf("%i", &num);

         eleccion(opt, num);
      }                    /* mientras numero no sea 0 */

   } while (opt!=3);

   return 0;
}
