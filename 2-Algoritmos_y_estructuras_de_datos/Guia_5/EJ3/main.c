#include "declaraciones.h"
/*
    Genere un árbol binario ingresando los siguientes datos: 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17.
    Aplique las funciones anteriormente implementadas.
*/
int main()
{
    //Declaramos variables a utilizar
    btn *arbol = NULL; //Puntero al arbol
    int cnt_nodos = 0; //Donde vamos a devolver la cantidad de nodos
    int suma = 0; //Donde vamos a devolver la suma de todos los nodos
    int profundidad = 0; //Donde vamos a devolver la profundidad del arbol (Distancia entre el nodo raiz y el nodo hoja)

    //Insertamos valores
    insertar_datos(&arbol, 14);
    insertar_datos(&arbol, 15);
    insertar_datos(&arbol, 4);
    insertar_datos(&arbol, 9);
    insertar_datos(&arbol, 7);
    insertar_datos(&arbol, 18);
    insertar_datos(&arbol, 3);
    insertar_datos(&arbol, 5);
    insertar_datos(&arbol, 16);
    insertar_datos(&arbol, 4); //Duplicado, ya esta ingresado antes, entonces no lo va a tomar.
    insertar_datos(&arbol, 20);
    insertar_datos(&arbol, 17);

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
