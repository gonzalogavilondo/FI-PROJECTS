#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define COLOR 3
#define POSICION_X 80
#define POSICION_Y 60

void muestra_pantalla (const int[COLOR][POSICION_X][POSICION_Y]);
int main()
{
    int pantalla[COLOR][POSICION_X][POSICION_Y] ={{{0}}};
    muestra_pantalla(pantalla);
    return 0;
}

void muestra_pantalla (const int pantalla[COLOR][POSICION_X][POSICION_Y])
{
        for (int i = 0; i < POSICION_X; i++)
        {
            printf("|||\t");
            for (int j = 0; j < POSICION_Y; j++)
            {
                printf("%i\t", pantalla[0][i][j]);
            }
            printf("|||\n");
        }
}

/*NO ENTIENDOOOOOOOOOOOOOOOOOOO*/
