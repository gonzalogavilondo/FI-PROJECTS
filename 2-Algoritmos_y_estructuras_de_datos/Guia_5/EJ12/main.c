#include "declaraciones.h"
/*
    El recorrido en postorden de un ABB que contiene caracteres es: DMLCTAISRUNOKB Y en
    inorden es: DMATLCBIKUSRON A) Dibujar el arbol binario. B) Dar el recorrido en preorden.
*/
int main()
{
   //Hice a mano el arbol y me quedo preorder: BAMDTCLKIOURSN, entonces uso este programa para verificar si me da el postorder.
   char *preorder = "BAMDTCLKIOURSN";
   char *inorder = "DMATLCBIKUSRON";
   int aux;

   aux = strlen(preorder);

   printf("El preorder es: %s\n", preorder);
   printf("El inorder es: %s\n", inorder);
   printf("El postorder es: ");
   postorder(preorder, inorder, aux);

   return 0;
}
