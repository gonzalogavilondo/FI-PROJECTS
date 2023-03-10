#include "header_ops.h"

int main()
{
    float prom_1 = 0.0, prom_2 = 0.0, prom_3 = 0.0, prom_total = 0.0, mx = 0.0;
    float vec1[COLS] = {0}; //{2.14, 4.56, 6.54, 9.87, 3.21}
    float vec2[COLS] = {0}; //{5.43, 4.32, 7.65, 1.23, 3.56}
    float vec3[COLS] = {0}; //{4.87, 9.32, 4.67, 8.76, 2.78}
    float matx[FILS][COLS] = {{0.0}};
    completar_vector(vec1);
    completar_vector(vec2);
    completar_vector(vec3);
    completar_matriz(vec1, vec2, vec3, matx);
    prom_1 = promedio_por_fila(vec1);
    prom_2 = promedio_por_fila(vec2);
    prom_3 = promedio_por_fila(vec3);
    prom_total = promedio_total((const float (*)[COLS])matx);
    mx = maximo_total((const float (*)[COLS])matx);
    printf("VECTOR 1\n");
    imprimir_vector(vec1);
    printf("VECTOR 2\n");
    imprimir_vector(vec2);
    printf("VECTOR 3\n");
    imprimir_vector(vec3);
    printf("Promedio de los numeros de los vectores 1, 2 y 3, respectivamente: %.3f, %.3f, %.3f\n", prom_1, prom_2, prom_3);
    printf("Promedio de los numeros de la matriz: %.3f\n", prom_total);
    printf("El maximo de todos los valores de la matriz es: %.2f", mx);
    return 0;
}
