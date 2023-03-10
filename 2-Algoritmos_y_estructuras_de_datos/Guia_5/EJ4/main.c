#include "declaraciones.h"
/*
    El recorrido en pre-orden de un determinado árbol binario es: GEAIBMCLDFKJH y en inorden IABEGLDCFMKHJ.Resolver:
    a. Dibujar el árbol binario.
    b. Dar el recorrido en postorden.
    c. Diseñar una función para dar el recorrido en postorden dado el recorrido en
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
