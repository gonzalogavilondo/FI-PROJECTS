#ifndef MYINCLUDE_H_INCLUDED
#define MYINCLUDE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    char titulo[5];
    char *nombre;
    char *apellido;
} name;

typedef struct
{
    name nombre;
    int matricula;
    date nacim;
} datos_alumno;

void ingreso_datos(datos_alumno *, int);                   // recibe la estructura completa del alumno
int  reserva_memoria(datos_alumno *alumno[], int, int);    // recibe el vector de estructuras completo
void imprime_datos(datos_alumno *[], int);                 // puntero a vector de estructuras
void libera_memoria(datos_alumno *alumno[], int);

#endif // MYINCLUDE_H_INCLUDED
