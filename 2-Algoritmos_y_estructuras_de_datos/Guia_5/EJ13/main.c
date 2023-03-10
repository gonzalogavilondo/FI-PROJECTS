#include "declaraciones.h"

int main()
{
    int values[] = {3, 2, 18, 5, 20, 90, 77, 40, 34, 12};
    int count = sizeof(values) / sizeof(int);

    btn *rootAVL = NULL;
    btn *rootBB = NULL;

    //Insertamos datos
    insertValuesAVL(&rootAVL, values, count);
    insertValuesBB(&rootBB, values, count);

    //Imprimimos los arboles
    /**
    A)
    **/
    printf("\nArbol AVL \n");
    printBTN(rootAVL);

    //Pausa y clear
    system("pause");
    system("cls || clear");

    /**
    B)
    **/
    printf("Arbol BB \n");
    printBTN(rootBB);

    /**
    C)
        La eficiencia en este tipo de casos, de un AVL sobre un ABB se justifica que el arbol AVL queda
        mucho mas balanceado que el arbol binario de busqueda, y la eficiencia se ve cuando queremos hallar
        un nodo especifico.Por ejemplo, si queremos hallar el nodo que contiene el valor 34, podemos observar
        que en el arbol AVL vamos a tener que hacer muchas menos comparaciones que en el arbol BB, que
        claramente en este caso no esta cumpliendo su principal funcion, que es facilitarnos la busqueda.

    **/

    return 0;
}
