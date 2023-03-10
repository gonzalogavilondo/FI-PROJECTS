#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <declaraciones_funciones.h>

int *reservar_memoria(int cantidad_datos)
{
    int *datos = NULL;
    //Reservo memoria para la cantidad de datos.
    datos = (int *)calloc(cantidad_datos, sizeof(int));

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

void completar_vector(int *vec, int COLS)
{
    for(int j = 0; j < COLS; j++)
    {
        printf("VECTOR\n\n");
        imprimir_vector(vec, COLS);
        printf("\nAsigne un valor al elemento [%i]: ", j+1);
        scanf("%i", &vec[j]);
        system("cls || clear");
    }

}

void imprimir_vector(int *vec, int COLS)
{
    printf("|\t");
    for(int j = 0; j < COLS; j++)
    {
        printf("%i\t", vec[j]);
    }
    printf("|\n\n");
}

void ordenar_vector(int *vec, int COLS)
{
    int aux = 0;
    for(int j = 0; j < COLS-1; j++)
    {
        if (vec[j] > vec[j+1])
        {
            aux = vec[j];
            vec[j] = vec[j+1];
            vec[j+1] = aux;
        }

    }

}

void imprimir_descendente(int *vec, int COLS)
{
    printf("|\t");
    for(int j = COLS-1; j >= 0; j--)
    {
        printf("%i\t", vec[j]);
    }
    printf("|\n\n");

}

