#include "declaraciones.h"

int main()
{
    //Declaramos
    int valores[] = {100, 29, 71, 82, 48, 39, 101, 22, 46, 17, 3, 20, 25, 10};
    int borrar[] = {100, 29, 39};
    int cnt = sizeof(valores)/sizeof(int); //Cantidad de elementos de valores
    int cntb = sizeof(borrar)/sizeof(int); //Cantidad de elementos de borrar
    btn *arbolAVL = NULL; //Donde voy a crear un arbol AVL
    btn *arbolBB = NULL; //Donde voy a crear un arbol normal BB
    btn *borrado = NULL; //Donde voy a guardar los nodos que borre del arbol AVL

    //Insertamos nodos en un arbol BB y AVL
    for(int i = 0; i < cnt; i++)
    {
        insertar_datos_AVL(&arbolAVL, valores[i]); //Aca insertamos en un arbol AVL, a medida que vamos insertando, se va balanceando el arbol
        insertar_datos(&arbolBB, valores[i]); //Aca insertamos en un arbol BB, no se balancea a medida que insertamos un nodo.
    }

    //Imprimimos el arbol BB y AVL
    printf("\nArbol BB: \n");
    print_t(arbolBB);
    printf("Arbol AVL: \n");
    print_t(arbolAVL);

    //Eliminamos valores
    for(int i = 0; i < cntb; i++)
    {
        borrado = borrarAVL(&arbolAVL, borrar[i]); //Borramos cada nodo pedido mientras que se balancea el arbol y cada nodo borrado lo guardamos en "borrado"
        printf("Eliminado: %d\n", borrado->valor); //Imprimimos por pantalla el contenido "valor" de cada nodo borrado para identificar cual es.
        print_t(arbolAVL);
    }

    //Imprimimos el arbol despues de borrar los nodos que contienen los valores: 100, 29, 39
    printf("\nArbol AVL resultante despues del borrado: \n");
    puts("\n");
    print_t(arbolAVL);

    return 0;
}
