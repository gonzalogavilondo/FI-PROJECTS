#include "declaraciones.h"
/*
    Implementar funciones que permitan:
    a. Determinar el número de nodos de un árbol binario.
    b. La suma de todos los nodos.
    c. La profundidad de un árbol binario
*/
int main()
{
    //Declaramos variables a utilizar
    btn *arbol = NULL; //Puntero al arbol
    int cnt_nodos = 0; //Donde vamos a devolver la cantidad de nodos
    int suma = 0; //Donde vamos a devolver la suma de todos los nodos
    int profundidad = 0; //Donde vamos a devolver la profundidad del arbol (Distancia entre el nodo raiz y el nodo hoja)

    //Insertamos valores
    insertar_datos(&arbol, 4);
    insertar_datos(&arbol, 2);
    insertar_datos(&arbol, 1);
    insertar_datos(&arbol, 3);
    insertar_datos(&arbol, 6);
    insertar_datos(&arbol, 5);
    insertar_datos(&arbol, 7);

    //Imprimimos el arbol
    print_t(arbol);

    //Determinamos el numero de nodos del arbol
    cantidad_nodos(arbol, &cnt_nodos);
    printf("La cantidad de nodos es: %d\n\n", cnt_nodos);

    //Sumamos los valores de los nodos
    suma = suma_nodos(arbol);
    printf("La suma total de los nodos es: %d\n\n", suma);

    //Profundidad de un arbol
    profundidad = profundidad_arbol(arbol);
    printf("La profundidad del arbol es: %d\n\n", profundidad);

    //Imprimimos recorriendo diferentes formas
    puts("-PREORDER-");
    preorder(arbol);
    puts("\n\n-INORDER-");
    inorder(arbol);
    puts("\n\n-POSTORDER-");
    postorder(arbol);
    puts("\n");


    return 0;
}
