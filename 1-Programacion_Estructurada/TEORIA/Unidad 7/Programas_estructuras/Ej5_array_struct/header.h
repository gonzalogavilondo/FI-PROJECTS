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
    char nombre[30];
    fecha aprobado;
    float promedio;
} catedras;

typedef struct
{
    char nombre[25];
    int matricula;
    catedras materia[30];
} datos_alumno;

#endif // HEADER_H_INCLUDED
