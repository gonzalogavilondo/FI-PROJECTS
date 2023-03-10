#include <stdio.h>

int main()
{
   char car[60];          /* permite ingresar hasta 60 letras */

   printf("Ingrese un string (dos palabras separadas por un espacio): ");
//   fflush(stdin);         /* limpia el buffer de entrada */
   scanf("%s",car);                    /* lee hasta el primer espacio */
   printf("Palabra1 = %s (ingresada con un scanf)\n",car);
   scanf("%s",car);                    /* lee la segunda palabra automaticamente */
   printf("Palabra2 = %s (ingresada con otro scanf)\n",car);

   printf("\nIngrese un string de menos de 10 caracteres (sin espacios!): ");
//   fflush(stdin);         /* limpia el buffer de entrada */
   scanf("%s",car);
   printf("Mensaje = %10s (alineado derecha, ancho 10)\n",car);
   printf("Mensaje = %-10s (alineado izquierda, ancho 10)\n",car);
// scanf("%c",&c);                     /* lee el \n que quedo pendiente */

   printf("\nIngrese un string de mas de 10 caracteres (sin espacios!): ");
//   fflush(stdin);         /* limpia el buffer de entrada */
   scanf("%s",car);
   printf("Mensaje = %s (ancho 10 pero imprime el total igual)\n",car);
//   scanf("%c",&c);                     /* lee el \n que quedo pendiente */

   printf("\nIngrese un string de varias palabras (que contenga espacios): ");
// //   fflush(stdin);         /* limpia el buffer de entrada */
   scanf("%[^\n]",car);                /* lee hasta el enter, el espacio tambien */
//   scanf("%c",&c);                     /* lee el \n que quedo pendiente */
   printf("Mensaje = %s\n",car);

   printf("\nIngrese un string de varias palabras con espacios (A, B o C termina): ");
//   fflush(stdin);         /* limpia el buffer de entrada */
   scanf("%[^A-C]",car);               /* habria que terminar de ingresar los caracteres que quedaron */
   printf("Mensaje = %s\n",car);
   scanf("%[^\n]",car);                /* lee el resto del mensaje anterior hasta el enter */
   printf("Mensaje = %s\n",car);

   return 0;
}
