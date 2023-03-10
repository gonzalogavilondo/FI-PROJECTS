#include <header.h>

int main()
{
    float matriz[FILS][COLS] = {{0.0}};
    float vec1[COLS] = {0};
    float vec2[COLS] = {0};
    float vec3[COLS] = {0};

    completar_vector(vec1,1);
    completar_vector(vec2,2);
    completar_vector(vec3,3);
    completar_matriz(vec1, vec2, vec3, matriz);
    printf("LA MATRIZ RESULTANTE ES\n\n");
    imprimir_matriz(matriz);






    return 0;
}
