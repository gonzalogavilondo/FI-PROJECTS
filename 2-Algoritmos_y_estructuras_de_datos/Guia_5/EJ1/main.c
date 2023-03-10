#include "declaraciones.h"
/*
    Defina la estructura de nodo de un árbol binario e implemente las operaciones de
    inserción, recorrido en in-orden, pre-orden y pos-orden.
*/
int main()
{
    //Declaramos
    btn *arbol = NULL;

    //Insertamos valores
    insertar_datos(&arbol, 4);
    insertar_datos(&arbol, 2);
    insertar_datos(&arbol, 1);
    insertar_datos(&arbol, 3);
    insertar_datos(&arbol, 6);
    insertar_datos(&arbol, 5);
    insertar_datos(&arbol, 7);

    //Imprimimos el Arbol BB de forma mas visual
    printf("ARBOL BB: \n\n");
    print_t(arbol);

    //Imprimimos recorriendo diferentes formas
    puts("-PREORDER-");
    preorder(arbol);
    puts("\n\n-INORDER-");
    inorder(arbol);
    puts("\n\n-POSTORDER-");
    postorder(arbol);
    puts("\n");

    return 0;
}
