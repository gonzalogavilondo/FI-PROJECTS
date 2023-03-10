#include <header.h>

void completar_vector(float vector[COLS], int n)
{
    for(int j = 0; j < COLS; j++)
    {
        printf("COMPLETE VECTOR NUMERO %i \n\n", n);
        imprimir_vector(vector);
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%f", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"

    }
}
void imprimir_vector(float vector[COLS])
{
    printf("|\t");
    for(int j = 0; j < COLS; j++)
    {
        printf("%.2f\t", vector[j]);
    }
    printf("|\n\n");

}
void completar_matriz(const float vector1[COLS], const float vector2[COLS], const float vector3[COLS], float matriz[FILS][COLS])
{
    for(int j = 0; j < COLS; j++)
    {
        matriz[0][j] = vector1[j];
        matriz[1][j] = vector2[j];
        matriz[2][j] = vector3[j];
    }

}
void imprimir_matriz(const float matriz[FILS][COLS])
{
    for(int i = 0; i < FILS; i++)
    {
        printf("|    ");
        for(int j = 0; j < COLS; j++)
        {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("|\n\n");
    }
}
