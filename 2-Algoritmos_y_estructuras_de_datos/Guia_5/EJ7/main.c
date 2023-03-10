#include "declaraciones.h"

int main()
{
    //Declaramos
    int valores[] = {1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8};
    int cnt = sizeof(valores)/sizeof(int); //Cantidad de elementos de valores
    btn *arbol = NULL;

    //Insertamos el arbol mientras lo balanceamos e imprimimos las rotaciones
    for(int i = 0; i < cnt; i++)
    {
        insertar_datos(&arbol, valores[i]);
    }

    //Imprimimos el arbol AVL resultante
    printf("\nArbol AVL resultante: \n\n");
    print_t(arbol);

    return 0;
}
