#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} fecha;

typedef struct
{
    char nombre[20];
    fecha aprobado;
    float promedio;
} catedras;

typedef struct
{
    char nombre[20];
    int matricula;
    catedras materia[30];
} datos_alumno;

void imprime_datos(datos_alumno [], int);     // int representa la dimension del vector

void ingresa_datos(datos_alumno [], int);     // int representa el indice del vector

#endif // HEADER_H_INCLUDED
