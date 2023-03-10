#ifndef HEADER_OPS_H_INCLUDED
#define HEADER_OPS_H_INCLUDED
#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <math.h>
#define COLS 4
#define BYTES 4 //CORECCIÓN. Agregue la constante BYTES porque se separa los enteros en 4 bytes, pero la cantidad de vectores que hay es independiente a eso.

void aplicar_mascara (uint32_t [], uint32_t [], const uint8_t [][COLS]);
void imprimir_vector (const uint32_t [], uint8_t);
void get_bytes_by_int (uint32_t, uint8_t []);
void intercambiar_bytes(uint8_t [], uint8_t [], uint8_t);
void bytes_to_int (uint8_t const [], uint32_t *);

#endif // HEADER_OPS_H_INCLUDED
