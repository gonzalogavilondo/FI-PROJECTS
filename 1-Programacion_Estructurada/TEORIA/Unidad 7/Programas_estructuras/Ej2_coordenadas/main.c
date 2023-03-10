#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef struct
    {
        float  x;
        float y;

    } coordenada;

    coordenada puntoA = {0}; //Ya que si quiero inicializar una estructura es lo mas parecido a un vector
    coordenada puntoB = {0};
    printf("Coordenada x del punto A: ");
    scanf("%f", &puntoA.x);
    printf("Coordenada y del punto A: ");
    scanf("%f", &puntoA.y);
    printf("\nCoordenada x del punto B: ");
    scanf("%f", &puntoB.x);
    printf("Coordenada y del punto B: ");
    scanf("%f", &puntoB.y);

    if( (puntoA.x == puntoB.x) && (puntoA.y == puntoB.y) )
    {
        printf("\n\nA y B son iguales \n");
    }
    else
    {
        printf("\n\nA y B son distintos \n");
    }

    return 0;
}
