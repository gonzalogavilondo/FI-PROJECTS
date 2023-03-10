#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#define COLS 3

void mostrar_arr(const uint32_t [], uint8_t);
int main()
{

    uint32_t arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    mostrar_arr(arr, 12);
    return 0;
}

void mostrar_arr(const uint32_t arr[], uint8_t cant_elems)
{
    uint8_t filas = cant_elems/COLS;
    for(int i = 0; i < filas; i++)
    {
        printf("|\t");
        for(int j = 0; j < COLS; j++)
        {
            int k = COLS*i+j;
            printf("%i\t", arr[k]);
        }
        printf("|\n");
   }
}
/*
int matriz_a_lineal(int matriz[][])
{
    int elem = 0;
    for(int i = 0; i < k/COLS; i++)
    {
        elem = COLS*i+j;
        printf("|%i\t", elem);
    }
    return elem;
}*/

