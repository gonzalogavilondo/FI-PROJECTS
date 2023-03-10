#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdint.h>


typedef struct
{
    int cnt_personas;
    int edad;
    int long_nombre;
    float altura;
    char *nombre;

}datos_persona;

int elegir_apertura(void);
datos_persona *reservar_memoria(int16_t max_nombre, int16_t max_personas);
datos_persona *reallocar_memoria(datos_persona *persona);
datos_persona * recuperar_datos(datos_persona *persona, char *nombre);
datos_persona *recuperar_datos_binario(datos_persona *persona, char *nombre_b);
void ingresar_datos(datos_persona *persona, int16_t max_nombre);
void verificar_apertura(FILE *informacion);
void grabar_datos(const datos_persona *persona, FILE *salida);
void grabar_datos_binario(const datos_persona *persona, FILE *informacion);
void imprimir_datos_finales(const datos_persona *persona, FILE *salida);
void liberar_memoria(datos_persona *persona);

#endif // DECLARACIONES_H_INCLUDED
