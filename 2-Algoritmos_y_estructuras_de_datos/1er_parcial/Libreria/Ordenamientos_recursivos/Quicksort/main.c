#include "declaraciones.h"

int main()
{
    int salida[MAX] = {4, 5, 6, 7, 9, 3, 2, 1};
    int low = 0;
    int cnt = MAX; //Cantidad de elementos

    puts("ORDENAMIENTO POR QUICKSORT\n");
    ///Ordenamos mediante Quick-sort
    quicksort(salida, low, cnt - 1);
    imprimir_datos(salida);

    return 0;
}
