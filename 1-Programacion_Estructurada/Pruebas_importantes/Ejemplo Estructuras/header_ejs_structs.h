#ifndef HEADER_EJS_STRUCTS_H_INCLUDED
#define HEADER_EJS_STRUCTS_H_INCLUDED
#include <stdio.h>
#include <locale.h>
#include <stdint.h>

typedef struct
{
    uint8_t b0;
    uint8_t b1;
    uint8_t b2;
    uint8_t b3;
} bytes_t;

typedef union
{
    int valor;
    bytes_t bytes_entero;
    char caracter;
}entero_t;

void alterar_valor (entero_t *);
void imprimir_campo (entero_t *);

#endif // HEADER_EJS_STRUCTS_H_INCLUDED
