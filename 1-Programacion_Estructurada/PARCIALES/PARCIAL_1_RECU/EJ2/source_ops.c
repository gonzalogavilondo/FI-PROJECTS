#include "header_ops.h"

void get_bytes_by_int (uint32_t elemento, uint8_t vector[]) //descompone un entero en sus bytes y lo guarda en un arreglo
{
    uint8_t mask = 0xFF;
    for (int i = 3; i > -1; i--)
    {
        vector[3-i] = (elemento >> i*8) & mask;
    }
}

void intercambiar_bytes(uint8_t bytes_vec_1[], uint8_t bytes_vec_2[], uint8_t posicion) //intercambian los bytes j-esimos de dos arreglos, en una posicion i-esima
{
    uint8_t aux = 0;
    aux = bytes_vec_1[posicion];
    bytes_vec_1[posicion] = bytes_vec_2[posicion];
    bytes_vec_2[posicion] = aux;
}

void bytes_to_int (uint8_t const bytes_vec[], uint32_t *entero) //transforma los 4 bytes (elementos de un arreglo) en un entero
{
    *entero = 0;
    for (int i = 0; i < BYTES; i++)
    {
        *entero += bytes_vec[i] << ((BYTES-1-i)*8);
    }
}

void aplicar_mascara (uint32_t vector_1[], uint32_t vector_2[], const uint8_t mask[][COLS]) //intercambian los bytes i-esimos de dos enteros de dos vectores, en la posicion i-ésima
{
    for (uint8_t i = 0; i < COLS; i++)
    {
        for (uint8_t j = 0; j < COLS; j++)
        {
            if (mask[i][j] == 1)
            {
                uint8_t bytes_vec_1[4] = {0};
                uint8_t bytes_vec_2[4] = {0};
                get_bytes_by_int(vector_1[i], bytes_vec_1);
                get_bytes_by_int(vector_2[i], bytes_vec_2);
                intercambiar_bytes(bytes_vec_1, bytes_vec_2, j); //CORRECCIÓN. Había puesto el i-ésimo elemento, pero para eso habría que poner la máscara como columnas.
                bytes_to_int(bytes_vec_1, &vector_1[i]);
                bytes_to_int(bytes_vec_2, &vector_2[i]);

            }
        }
    }
}

void imprimir_vector (const uint32_t vector[], uint8_t num_vector)
{
    printf("EL %i%c VECTOR ES: \n\n", num_vector, 248);
    printf("|\t");
    for (int i = 0; i < COLS; i++)
    {
        printf("0x%08X\t", vector[i]);
    }
    printf("|\n\n");
}
