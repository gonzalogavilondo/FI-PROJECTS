/***** forma 2 de pasar un vector como parámetro
       utilizando otro parámetro para su longitud ****/

#include <stdio.h>

void imprimir_vector(short int vector[], int longitud);    // dirección y longitud del vector
void leer_vector(short int [], int);     // también es una forma válida, no tiene los nombres

int main()
{
    short int iValores[5];
    int longitud;

    longitud = sizeof(iValores)/sizeof(short);
    longitud = sizeof(iValores)/sizeof(iValores[0]);   // forma equivalente

    leer_vector(iValores, longitud);
    imprimir_vector(iValores, longitud);

    return 0;
}

void leer_vector(short int vector[], int longitud)
{
    printf("\nIngrese los valores del vector:\n\n");
    for(int cnt=0; cnt<longitud; cnt++)
    {
        printf("\tiValores[%d] = ", cnt);
        scanf("%hd", &vector[cnt]);
    }

    return ;
}

void imprimir_vector(short int vector[], int longitud)
{
    printf("\n\n\nImpresion del vector:\n\n");
    for(int cnt=0; cnt<longitud; cnt++)
    {
        printf("\tiValores[%d] = %3d\n", cnt, vector[cnt]);
    }
    puts("\n");
}
