#include "declaraciones.h"

int main()
{
    char values[] = {'M', 'D', 'H', 'B', 'A', 'C', 'S', 'K', 'I'};
    int count = sizeof(values) / sizeof(char);

    btn *root = NULL;

    //Insertamos
    insertValues(&root, values, count);

    //Imprimimos el arbol BB
    printf("Arbol AVL \n");
    printBTN(root);

    return 0;
}
