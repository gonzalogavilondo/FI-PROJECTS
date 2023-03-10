#include "Antree.h"
#include "Abtree.h"
/**
    Crear un árbol binario de búsqueda con los valores de todos los nodos de un árbol n-ario, siguiendo el recorrido mostrado en el ejemplo.
    NOTA: Es parte de la evaluación reconocer el recorrido del árbol n-ario para formar el ABB,
    ya que diferentes recorridos forman árboles distintos.


**/
int main()
{
    ntn *root = NULL;
    sample(&root);
    printf("ARBOL N ARIO \n\n");
    printNTN(root);
    btn *rootSBT = CrearABB(root);
    printf("\n\nARBOL SBT");
    printBTN(rootSBT);
    puts("\n");

    return 0;
}
