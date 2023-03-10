#include <stdio.h>

void eleccion(unsigned opcion, int num)
{
   if(opcion==1)              /* if bloque if/ese */
   {
      if (num==1)             /* 1 */
      {
         printf("Es un 1\n");
      }
      else                    /* 2 o 3 u otro */
      {
         if(num==2)           /* 2 */
         {
            printf("Es un 2\n");
         }
         else                 /* 3 u otro */
         {
            if(num==3)        /* 3 */
            {
               printf("Es un 3\n");
            }
            else              /* otro */
            {
               printf("No es ni 1 ni 2 ni 3\n");
            }
         }
      }
   }                          /* end if bloque if/else */
   else                       /* if bloque switch */
   {
      switch (num)            /* begin switch */
      {
         case 1:
            printf("Es un 1\n");
            break;
         case 2:
            printf("Es un 2\n");
            break;
         case 3:
            printf("Es un 3\n");
            break;
         default:
            printf("No es ni 1 ni 2 ni 3\n");
      }                       /* end switch */
   }                          /* end if bloque switch */
}


