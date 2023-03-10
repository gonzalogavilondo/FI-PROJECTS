#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void completar_vector(float *vector, int elementos)
{
    for(int j = 0; j < elementos; j++)
    {
        printf("Rellene el arreglo: \n\n");
        imprimir_vector(vector, elementos);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%f", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}

float *reservar_memoria(int cantidad_datos)
{
    float *datos = NULL;
    //Reservo memoria para la cantidad de datos.
    datos = (float *)calloc(cantidad_datos, sizeof(float));

    if(datos == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(1);
    }

    //No pongo el else, donde diria que si se asigno memoria correctamente, cuando no aparece nada, doy por hecho que reservo una m
    system("pause");
    system("cls || clear");

    return datos;
}

void imprimir_vector(float *vector, int elementos)
{
    printf("|\t");
    for(int j = 0; j < elementos; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}
