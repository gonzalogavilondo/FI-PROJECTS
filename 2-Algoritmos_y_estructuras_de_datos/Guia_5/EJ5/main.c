#include "declaraciones.h"

int main()
{
    //Declaramos
    int valores_1[] = {10, 100, 20, 80, 40, 70};
    int valores_2[] = {5, 10, 20, 30, 40, 50, 60};
    int cnt_1 = sizeof(valores_1)/sizeof(int); //Cantidad de elementos de valores
    int cnt_2 = sizeof(valores_2)/sizeof(int); //Cantidad de elementos de borrar
    int avl;
    btn *arbol1 = NULL;
    btn *arbol2 = NULL;

    //Insertamos valores
    for(int i = 0; i < cnt_1; i++)
    {
        insertar_datos(&arbol1, valores_1[i]);
    }
    for(int i = 0; i < cnt_2; i++)
    {
        insertar_datos(&arbol2, valores_2[i]);
    }

    //Preguntamos si es un arbol AVL
    avl = isAVL(arbol1);
    verificar_AVL(avl, 1);
    avl = isAVL(arbol2);
    verificar_AVL(avl, 2);

    //Imprimimos resultados
    printf("ARBOL 1 AVL: \n");
    print_t(arbol1);
    puts("\n");
    printf("ARBOL 2 AVL: \n");
    print_t(arbol2);
    puts("\n");


    return 0;
}
