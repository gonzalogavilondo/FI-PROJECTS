#include "declaraciones.h"

int main()
{
    int salida[MAX] = {4, 5, 6, 7, 9, 3, 2, 1};
    int low = 0;
    int cnt = MAX; //Cantidad de elementos

    ///Ordenamos mediante merge-sort
    mergesort(salida, low, cnt);
    puts("ORDENAMIENTO POR MERGESORT\n");
    imprimir_datos(salida);

    return 0;
}
