#ifndef CABECERAS_H_INCLUDED
#define CABECERAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSO,
    VERDADERO
}bool_t;

typedef struct
{
    int hh;
    int mm;
}hora_t;

typedef struct
{
    hora_t hora;
    float valor;
}registro_t;

typedef struct
{
    registro_t min;
    registro_t max;
    float prom;
}resumen_t;

int leer_temperatura(FILE*, void*, int);
float obtener_temp_prom(registro_t*, int);
typedef bool_t (*ptr_comp)(registro_t, registro_t);
registro_t obtener_temp_minimax(registro_t*, int, ptr_comp);
int leer_datos(FILE*, registro_t**);
void mostrar_datos(resumen_t, const registro_t*, int);
void guardar(FILE*, resumen_t, const registro_t*, int);
void verificar_salida(FILE*);

#endif // CABECERAS_H_INCLUDED
