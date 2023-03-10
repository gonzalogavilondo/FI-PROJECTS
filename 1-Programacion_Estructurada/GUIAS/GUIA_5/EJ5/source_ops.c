#include "header_ops.h"

void imprimir_vector (const float vector[COLS])
{
    printf("|\t");
    for (int i = 0; i < COLS; i++)
    {
        printf("%.1f\t", vector[i]);
    }
    printf("|\n");
}

void completar_vector(float vector[COLS])
{
    static int num = 1;
    for (int i = 0; i < COLS; i++)
    {
        printf("COMPLETE EL %i%c VECTOR\n", num, 248);
        imprimir_vector(vector);
        printf("\nIngrese el valor del elemento %i: ", (i+1));
        scanf("%f", &vector[i]);
        system("cls || clear");

    }
    num++;
}

void imprimir_matriz (const float matriz[][COLS])
{
    for (int i = 0; i < FILS; i++){
        printf("|\t");
        for (int j = 0; j < COLS; j++){
            printf("%.1f\t", matriz[i][j]);
        }
        printf("|\n");
    }
}

void completar_matriz(const float vector1[FILS], const float vector2[FILS], const float vector3[FILS], float matriz[FILS][COLS])
{
    for (int i = 0; i < COLS; i++)
    {
        matriz[0][i] = vector1[i];
        matriz[1][i] = vector2[i];
        matriz[2][i] = vector3[i];
    }
}

float promedio_por_fila (const float vector[COLS])
{
    float res = 0.0;
    float prom_fil = 0.0;
    for (int i = 0; i < COLS; i++)
    {
        prom_fil +=  vector[i];
    }
    res = prom_fil/COLS;
    return res;
}

float promedio_total (const float matriz[FILS][COLS])
{
    float res = 0.0;
    float prom_total = 0.0;
    int dim = FILS*COLS;
    for (int i = 0; i < FILS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            prom_total += matriz[i][j];
        }
    }
    res = prom_total/dim;
    return res;
}

float maximo_total (const float matriz[FILS][COLS])
{
    float max_total = matriz[0][0];
    for (int i = 0; i < FILS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (max_total < matriz[i][j])
            {
                max_total = matriz[i][j];
            }
        }
    }
    return max_total;
}
