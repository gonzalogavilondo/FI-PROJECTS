#include "declaraciones.h"

int main()
{
    int values[] = {10, 75, 34, 22, 64, 53, 41, 5, 25, 74, 20, 15, 90};
    int count = sizeof(values) / sizeof(int);

    btn *root = NULL;

    //Insertamos
    insertValues(&root, values, count);

    //Imprimimos el arbol BB
    printf("\nArbol Binario de busqueda balanceado (AVL)\n");
    printBTN(root);

    return 0;
}
