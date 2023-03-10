#include "header_ops.h"

void imprimir_vector (const float vector[COLS])
{
    printf("|\t");
    for (int i = 0; i < COLS; i++)
    {
        printf("%.2f\t", vector[i]);
    }
    printf("|\n\n");
}

void completar_vector(float vector[COLS])
{
    static int num = 1; //contador para que en la impresión aparezca qué vector se está completando. Declarado estático para que por cada llamada lo aumente y no haya que pasarlo como argumento.
    for (int i = 0; i < COLS; i++)
    {
        printf("COMPLETE EL %i%c VECTOR\n", num, 248); //el 248 es el equivalente a poner el caracter 'ª', que  C .
        imprimir_vector(vector);
        printf("Ingrese el valor %i: ", (i+1));
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
            printf("%.2f\t", matriz[i][j]);
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

float promedio_por_fila (const float vector[COLS])  //suma los valores del vector y lo divide por el total.
{
    float prom_fil = 0.0;
    for (int i = 0; i < COLS; i++)
    {
        prom_fil +=  vector[i];
    }
    prom_fil = prom_fil/COLS;
    return prom_fil;
}

float promedio_total (const float matriz[FILS][COLS]) //suma los valores de la matriz y lo divide por el total.
{
    float prom_total = 0.0;
    for (int i = 0; i < FILS; i++){
            prom_total += promedio_por_fila(matriz[i]);
    }
    prom_total = prom_total/FILS;
    return prom_total;
}

float maximo_total (const float matriz[FILS][COLS])
{
    float max_total = matriz[0][0]; //CORRECION. Había inicializado el máximo en 0, si se ingresaban todos nro negativos no andaba.
    for (int i = 0; i < FILS; i++){    //recorre la matriz con los dos for.
        for (int j = 0; j < COLS; j++){
            if (max_total < matriz[i][j]) //si el elemento de la matriz es mayor al máximo
            {
                max_total = matriz[i][j]; //lo acumula en max_total
            }
        }
    }
    return max_total;
}
