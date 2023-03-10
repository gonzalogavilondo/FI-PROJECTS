#include "declaraciones.h"
/*
    El recorrido en pre-orden de un determinado �rbol binario es: GEAIBMCLDFKJH y en inorden IABEGLDCFMKHJ.Resolver:
    a. Dibujar el �rbol binario.
    b. Dar el recorrido en postorden.
    c. Dise�ar una funci�n para dar el recorrido en postorden dado el recorrido en
    preorden e inorden y escribir un programa para comprobar el resultado del
    apartado anterior.
*/
int main()
{
   char *preorder = "GEAIBMCLDFKJH";
   char *inorder = "IABEGLDCFMKHJ";
   int aux;

   aux = strlen(preorder);

   printf("El preorder es: %s\n", preorder);
   printf("El inorder es: %s\n", inorder);
   printf("El postorder es: ");
   postorder(preorder, inorder, aux);

   return 0;
}
