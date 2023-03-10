#include "header_ops.h"

int main()
{
    float prom_1 = 0.0;
    float prom_2 = 0.0;
    float prom_3 = 0.0;
    float prom_total = 0.0;
    float max = 0.0;
    float vec1[COLS] = {0};
    float vec2[COLS] = {0};
    float vec3[COLS] = {0};
    float matx[FILS][COLS] = {{0.0}};

    completar_vector(vec1);
    completar_vector(vec2);
    completar_vector(vec3);
    completar_matriz(vec1, vec2, vec3, matx);
    prom_1 = promedio_por_fila(vec1);
    prom_2 = promedio_por_fila(vec2);
    prom_3 = promedio_por_fila(vec3);
    prom_total = promedio_total((const float (*)[COLS])matx);
    max = maximo_total((const float (*)[COLS])matx);
    printf("-VECTOR 1-\n");
    imprimir_vector(vec1);
    printf("-VECTOR 2-\n");
    imprimir_vector(vec2);
    printf("-VECTOR 3-\n");
    imprimir_vector(vec3);
    puts("\n");
    printf("Promedio de los elementos de los vectores 1, 2 y 3 respectivamente: %.1f, %.1f, %.1f\n", prom_1, prom_2, prom_3);
    printf("Promedio de los elementos de la matriz: %.1f\n", prom_total);
    printf("El maximo de todos los elementos de la matriz es: %.1f", max);
    return 0;
}
