#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

float *reservar_memoria(int cnt_elementos)
{
    float *vector = NULL;

    vector = (float *)calloc(cnt_elementos, sizeof(float));
    if(vector == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    return vector;
}

void completar_vector(float *vector, int cnt_elementos)
{
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("\t-COMPLETE EL VECTOR ORDENADO DE MENOR A MAYOR-\n\n");
        imprimir_vector(vector, cnt_elementos);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%f", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}

void imprimir_vector(float *vector, int cnt_elementos)
{
    printf("|\t");
    for(int j = 0; j < cnt_elementos; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}

int busqueda_secuencial(float *vector, float condicion, int cnt_elementos)
{
    int posi = -1;
    int i = 0;

    for(i = 0; i < cnt_elementos; i++)
    {
        if(vector[i] == condicion)
        {
            posi = i;
        }
    }
    return posi;
}

void imprimir(int posicion, float condicion)
{
    printf("\n\nLa condicion es hayar en el vector la posicion del numero: %.2f", condicion);

    if(posicion == -1)
    {
        printf("\n\nNo se ha podido encontrar la posicion del valor pedido.\n");
    }
    else
    {
        printf("\n\nLa posicion del numero pedido es: %d\n\n", posicion+1);
    }
}
