#include "declaraciones.h"
/****************************************************/
/*                      TEST                        */
/****************************************************/

void test_ejercicio0()
{
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int count = sizeof(values) / sizeof(int);
    int cnt_nodos = 0;
    btn *root = NULL;
    for (int i = 0; i < count; i++)
    {
        if (!insertValueBTN(&root, values[i]))
        {
            printf("Duplicado: %d \n", values[i]);
        };
    }

    printf("Árbol Binario \n");
    printBTN(root);
    sumaNodos(root, &cnt_nodos);
    printf("\nLa suma de los nodos es %d\n", cnt_nodos);
}

void test_ejercicio1()
{
    int values[] = {15, 9, 6, 3, 4, 6, 2};
    int count = sizeof(values) / sizeof(int);
    btn *root = NULL;
    for (int i = 0; i < count; i++)
    {
        printf("Agregando: %d\n", values[i]);
        if (!insertValueBTN(&root, values[i]))
        {
            printf("Duplicado: %d \n", values[i]);
        };
    }

    printf("Árbol Binario \n");
    printBTN(root);

    if (esPadreSumaHijos(root))
    {
        printf("Todos los los padres son la suma de sus hijos \n");
    }
    else
    {
        printf("NO todos los los padres son la suma de sus hijos \n");
    }
}

void test_ejercicio2()
{
    int values[] = {15, 9, 6, 20, 23, 19, 11};
    int count = sizeof(values) / sizeof(int);
    btn *root = NULL;
    for (int i = 0; i < count; i++)
    {
        insertValueBTN(&root, values[i]);
    }

    btn *rootSBT = crearSBT(root);

    printf("\nArbol Binario \n");
    printBTN(root);

    printf("\nArbol Binario de busqueda \n");
    printBTN(rootSBT);

}


void test_ejercicio3()
{
    int valuesABB[] = {6, 3, 4, 9, 10, 2, 1};
    int countABB = sizeof(valuesABB) / sizeof(int);
    btn *abb = NULL;
    for (int i = 0; i < countABB; i++) //Inserta los valores de valuesABB en el arbol binario de busqueda abb
    {
        insertValueSBT(&abb, valuesABB[i]);
    }

    int valuesAB[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int countAB = sizeof(valuesAB) / sizeof(int);
    btn *ab = NULL;
    for (int i = 0; i < countAB; i++) //Inserta los valores de valuesAB en el arbol binario ab
    {
        insertValueBTN(&ab, valuesAB[i]);
    }

    btn *avl = enComunAVL(ab, abb); //Funcion que crear un arbol AVL con los valores que tienen en comun ab y abb.

    printf("\nArbol Binario \n");
    printBTN(ab);

    printf("\nArbol Binario de busqueda \n");
    printBTN(abb);

    printf("\nArbol AVL \n");
    printBTN(avl);

}

void test_ejercicio4()
{

    int valuesAB[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int countAB = sizeof(valuesAB) / sizeof(int);
    btn *ab = NULL;
    for (int i = 0; i < countAB; i++)
    {
        insertValueBTN(&ab, valuesAB[i]);
    }

    printf("\nArbol Binario \n");
    printBTN(ab);

    int solicitado;
    solicitado = 3;
    getNode(&ab, solicitado);
    printf("\nArbol Binario luego de solicitar %d\n", solicitado);
    printBTN(ab);

    solicitado = 5;
    getNode(&ab, solicitado);
    printf("\nArbol Binario luego de solicitar %d\n", solicitado);
    printBTN(ab);

    solicitado = 7;
    getNode(&ab, solicitado);
    printf("\nArbol Binario luego de solicitar %d\n", solicitado);
    printBTN(ab);

    solicitado = 3;
    getNode(&ab, solicitado);
    printf("\nArbol Binario luego de solicitar %d\n", solicitado);
    printBTN(ab);

}
