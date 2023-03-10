#include "declaraciones.h"

int main()
{
    int values[] = {50, 25, 75, 10, 40, 60, 90, 35, 45, 70, 42};
    int count = sizeof(values) / sizeof(int);

    btn *root = NULL;

    //Insertamos
    insertValues(&root, values, count);

    //Imprimimos el arbol BB
    printf("Arbol Binario de busqueda ");
    printBTN(root);

    return 0;
}
