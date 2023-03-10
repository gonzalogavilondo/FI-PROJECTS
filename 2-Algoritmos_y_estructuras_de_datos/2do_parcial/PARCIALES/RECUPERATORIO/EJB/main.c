#include "Antree.h"
#include "Abtree.h"
/**
    Crear un �rbol binario de b�squeda con los valores de todos los nodos de un �rbol n-ario, siguiendo el recorrido mostrado en el ejemplo.
    NOTA: Es parte de la evaluaci�n reconocer el recorrido del �rbol n-ario para formar el ABB,
    ya que diferentes recorridos forman �rboles distintos.


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
