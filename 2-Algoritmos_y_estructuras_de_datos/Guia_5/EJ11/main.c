#include "declaraciones.h"

int main()
{
    int values[] = {40, 30, 20, 10, 5, 25, 35, 32, 50, 45, 42, 55};
    int deletee[] = {55, 32, 40, 30};
    int count = sizeof(values) / sizeof(int);
    int countd = sizeof(deletee) / sizeof(int);

    btn *root = NULL;

    //Insertamos datos
    insertValues(&root, values, count);

    //Imprimimos el arbol BB
    printf("Arbol AVL original\n");
    printBTN(root);

    //Removemos los valores pedidos
    removeValues(&root, deletee, countd);

    //Imprimir nuevamente
    printf("Arbol AVL despues del borrado\n");
    printBTN(root);

    return 0;
}
/******************************************************************************************************
Nota:En el ejercicio lo que me pedian era que en el caso que un nodo tenga dos hijos, sustituir
    por el mayor de la izquierda, originalmente la funcion tiene sustituir por el menor de la derecha
    solamente hay que cambiar donde dice temp = (*node)->right; por temp = (*node)->left; despues cambiar
    while (temp->left != NULL) por while (temp->right != NULL).
    Es decir que temp va a ser el nodo a la izquierda y va a buscar mientras que temporal a la derecha
    sea distinto de null, es decir, se va a ir por el mayor de la derecha como nos piden en el problema.
    Luego intercambiar en todo lo que diga right poner left y en todo lo que dice left poner right y listo.
*******************************************************************************************************/
