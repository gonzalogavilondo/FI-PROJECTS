#include "Antree.h"

/**
    Crear una lista ordenada con los valores de los nodos hijos de cada nodo par de un
    árbol n-ario.

**/
int main()
{
    ntn *root = NULL;
    crearArbol(&root);
    printf("ARBOL N ARIO \n\n");
    printNTN(root);
    list *l = hijosDePares(root);
    puts("\n");
    printf("Lista de hijos de nodos con valores pares\n\n");
    printList(l);

    return 0;
}
