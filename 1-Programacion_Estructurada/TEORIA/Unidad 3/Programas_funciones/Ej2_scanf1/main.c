#include <stdio.h>

int main()
{
   int valor,      /* valor entero ingresado */
       cnt;        /* cantidad de campos ingresados */
   char car;       /* permite el ingreso de un caracter */
   float fvalor;   /* valor flotante ingresado */

   printf("Ingrese un entero <,> y un flotante = ");
   cnt=scanf("%d %c %f", &valor, &car, &fvalor);         /* atención a los datos, debe ingresar un caracter */
   printf("Entero = %d, caracter = %c, flotante = %8.1f, retorno = %d\n",  valor, car, fvalor, cnt);

   printf("\nIngrese un valor hexadecimal = ");
   scanf("%x", &valor);
   printf("Valor = %d, en hexadecimal = %x\n", valor,  valor);

   return 0;
}

