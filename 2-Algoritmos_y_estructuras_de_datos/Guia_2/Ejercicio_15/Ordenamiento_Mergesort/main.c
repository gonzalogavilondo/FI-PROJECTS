#include "declaraciones.h"

int main()
{
    int vector[] = {13, 96, 5, 1, 54, 2, 42, 7, 38, 9, 6, 20};
    int cnt_elementos = sizeof(vector)/sizeof(int);
    int low = 0;

    ///Vector ingresado
    puts("VECTOR INGRESADO\n");
    imprimir_datos(vector);
    ///Ordenamos mediante merge-sort
    mergesort(vector, low, cnt_elementos);
    puts("\nVECTOR ORDENADO POR MERGESORT\n");
    imprimir_datos(vector);

    return 0;
}
