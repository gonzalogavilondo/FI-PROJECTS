#include "Abtree.h"

void pruebaArbolBinario()
{

    int values[] = {15, 9, 6, 3, 4, 6, 2};
    int count = sizeof(values) / sizeof(int);

    btn *root = NULL;
    btn *ultimo = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n\n\n", values[i]);
        ultimo = createBTN(values[i]);
        insertBTN(&root, ultimo);
    }

    printf("Arbol Binario \n");
    printBTN(root);

    printf("\nLa altura del arbol es: %d \n", height(root));
    if (isLeaf(root))
    {
        printf("La raiz es una hoja.\n");
    }
    else
    {
        printf("La raiz no es una hoja.\n");
    }

    if (isLeaf(ultimo))
    {
        printf("OK! el ultimo nodo es Hoja.\n");
    }
    else
    {
        printf("ERROR! el ultimo nodo debe ser una hoja.\n");
    }

    printf("\nRecorridos del arbol\n\n");
    printf("Inorden:   ");
    inorder(root);
    printf("\n\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n\n");

    printf("Preorder:  ");
    preorder(root);
    printf("\n\n");

}

void pruebaArbolBinarioDeBusqueda()
{

    int values[] = {20, 10, 15, 12, 11, 5, 9, 2, 25, 39, 22, 30};
    int count = sizeof(values) / sizeof(int);

    btn *root = NULL;
    for (int i = 0; i < count; i++)
    {
        //printf("Agregando: %d\n", values[i]);
        if (!insertValueSBT(&root, values[i]))
        {
            printf("Error al insertar: %d \n", values[i]);
        };
    }

    printf("Arbol Binario de busqueda \n");
    printBTN(root);

    printf("Minimo valor: %d\n", getMinValueSBT(root));
    printf("Maximo valor: %d\n", getMaxValueSBT(root));

    for (int value = 0; value < 30; value += 5)
    {
        if (inSBT(root, value))
        {
            printf("Contiene: %d\n", value);
        }
        else
        {
            printf("No contiene: %d\n", value);
        }
    }

}


void pruebaEliminaEnABB()
{

    int values[] = {20, 10, 15,  5, 25, 39, 22, 30, 26, 23, 24};
    int count = sizeof(values) / sizeof(int);

    btn *root1 = NULL;
    btn *root2 = NULL;
    btn *root3 = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n", values[i]);
        if (insertValueSBT(&root1, values[i]))
        {
            insertValueSBT(&root2, values[i]);
            insertValueSBT(&root3, values[i]);
        }
        else
        {
            printf("Duplicado: %d \n", values[i]);
        };
    }

    int nro_del = 25; // probar 20 y 25
    printf("Árbol Binario de búsqueda \n");
    printBTN(root1);

    if (removeValueSBT(&root1, nro_del))
    {
        printf("\n\nElimina el %d reemplazando rama derecha \n", nro_del);
        printBTN(root1);
    }

    if (removeValueSBTRep(&root2, nro_del))
    {
        printf("\n\nElimina el %d reemplazando Min o Max \n", nro_del);
        printBTN(root2);
    }

    if (removeValueSBTSmart(&root3, nro_del))
    {
        printf("\n\nElimina el %d reemplazo \"inteligente\" \n", nro_del);
        printBTN(root3);
    }

}

void pruebaAVL()
{
    int values[] = {20, 10, 15, 5, 25, 39, 22, 30, 26, 23, 24};
    int count = sizeof(values) / sizeof(int);

    btn *rootSBT = NULL;
    btn *rootAVL = NULL;

    for (int i = 0; i < count; i++)
    {
        printf("\nAgregando: %d\n", values[i]);
        if(insertValueSBT(&rootSBT, values[i]))
        {
            insertValueAVL(&rootAVL, values[i]);
            printBTN(rootAVL);
        }
        else
        {
            printf("Error al insertar: %d \n", values[i]);
        };
    }


    printf("\n====================================================\n");
    printf("\nÁrbol AVL \n");
    printBTN(rootAVL);

    printf("\nÁrbol Binario de búsqueda \n");
    printBTN(rootSBT);

    printf("\nBalanceo \n");
    balanceTree(&rootSBT);
    printBTN(rootSBT);
    // Curiosidad!!
    // En este caso el balanceo posterior generó menos
    // rotaciones que la inserción ordenada,
    // y el árbol resultante es diferente.


    int value_del;
    value_del = 25;
    removeValueAVL(&rootAVL, value_del);
    printf("\nÁrbol AVL luego de eliminar %d\n", value_del);
    printBTN(rootAVL);

    value_del = 20;
    removeValueAVL(&rootAVL, value_del);
    printf("\nÁrbol AVL luego de eliminar %d\n", value_del);
    printBTN(rootAVL);

}

