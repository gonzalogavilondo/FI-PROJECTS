#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#include <stdint.h>
typedef struct
{
    int dia;
    int mes;
    int anio;

} fecha;

typedef struct
{
    int long_nombre_mat;
    char *nombre;
    fecha aprobado;
    float promedio;

} catedras;

typedef struct
{
    int cnt_alumnos;
    int long_nombre;
    char *nombre;
    int matricula;
    catedras *materia;
    int cnt_materias;

} datos_alumno;


datos_alumno *reservar_memoria(int16_t cnt_alumnos, int16_t max_nombre, int16_t max_materias);
datos_alumno *agregar_alumnos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t nuevos_alumnos, int16_t max_materias, int16_t max_nombre);
datos_alumno *sacar_alumnos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t max_materias);
void ingresar_datos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t max_nombre, int16_t max_materias);
void imprimir_datos(const datos_alumno *alumnos, int16_t cnt_alumnos, FILE *salida);
void imprimir_datos_binario(datos_alumno *alumnos, FILE *falumnos, int16_t cnt_alumnos);
void imprimir_datos_recuperados(const datos_alumno *alumnos, int cnt_alumnos);
void liberar_memoria(datos_alumno *alumnos, int16_t cnt_alumnos);
void liberar_memoria_final(datos_alumno *alumnos, int cnt_modificaciones);
void intercambiar_datos(datos_alumno *alumnos, int16_t cnt_alumnos, int16_t max_materias);
void verificar_apertura(FILE *falumnos);
void recuperar_datos(datos_alumno *alumnos, char *nombre_b);
int elegir_apertura(FILE *falumnos);
void recuperar_datos_binario(datos_alumno *alumnos, char *nombre_b);


#endif // DECLARACIONES_H_INCLUDED
