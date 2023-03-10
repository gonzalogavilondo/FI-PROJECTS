#include <stdio.h>
#include <stdlib.h>
#define DIM 5

void copiar_vector(const float[], float[]);
int main()
{
    float fuente[DIM] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float destino[DIM] = {0.0};
    copiar_vector(fuente, destino);
    return 0;
}

void copiar_vector(const float fuente[], float destino[])
{
    for (int i = 0; i < DIM; i++)
    {
        destino[i] = fuente[i];
    }
}


