#ifndef HEADER_REC_H_INCLUDED
#define HEADER_REC_H_INCLUDED
#include <stdint.h>
#include <stdio.h>
#define COLUMNAS 4
#define FILAS 5
#define BYTES 4

void aplicar_mascara(uint32_t v1[], uint32_t v2[], const uint8_t [FILAS][COLUMNAS]);
void entero_a_bytes(uint32_t elemento, uint8_t vector[]);
void intercambiar_bytes(uint8_t *elemento_vectorA, uint8_t *elemento_vectorB);
void bytes_a_entero(uint8_t elemento[], uint32_t *entero);
void mostrar_vector (uint32_t vector[], uint8_t numero);



#endif // HEADER_REC_H_INCLUDED
