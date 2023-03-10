#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LONGMAX 10

typedef struct
{
    char nombre[LONGMAX];
    int matricula;
    int porcentaje_materias_ap;

}CARRERA;

typedef struct NODO NODO;
struct NODO *LISTA;
struct NODO
{
    CARRERA alumno;
    NODO *next;
};

void liberar_memoria();
void deletee(int pos);
void insert(int pos);
void traverse(CARRERA informacion);
int length();
bool isEmpty();
bool sort();
void intercambiar(int pos1, int pos2);
CARRERA get(int pos);


//FUNCIONES
NODO *cargar_alumno(int pos);
void ultimas_materias();

#endif // LISTAS_H_INCLUDED
