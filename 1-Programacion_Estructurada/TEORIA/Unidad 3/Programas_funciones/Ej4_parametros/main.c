#include  <stdio.h>

void modificar(int vble);    /* declaración */
//void modificar(int *vble);   /* declaración */

int main()
{
   int iValor = 1;

   printf("\niValor = %d antes de llamar a modificar.\n", iValor);

   modificar(iValor);             // pasa el valor de la variable
//   modificar(&iValor);            // pasa la dirección de la variable

   printf("\niValor = %d despues de llamar a modificar.\n", iValor);

   return 0;
}

void modificar(int val)           // definición
{
   printf("\niValor = %d en modificar.\n", val);

   val = 9;

   printf("\niValor modificado = %d en modificar.\n", val);
}

/****
void modificar(int *val)            // definición
{
   printf("\niValor = %d en modificar en direccion %#X (%d).\n", *val, val, val);

   *val = 9;

   printf("\niValor modificado = %d en modificar.\n", *val);
}
****/
