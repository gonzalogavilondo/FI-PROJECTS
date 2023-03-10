#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//LISTAS
typedef struct
{
    char *nombre;
    char *concepto;
    int cnt_paginas;
    int cnt_capitulos;

}CARACTERISTICAS;

typedef struct
{
    CARACTERISTICAS libro;
    struct NODO *next;

}NODO;

NODO *inicializar_lista(NODO *lista); //Se inicializa la lista en NULL para verificar si la lista tiene algun nodo, si no tiene... devuelve NULL.






//FUNCIONES
void cargar_libros(int contador);
void menu();

#endif // DECLARACIONES_H_INCLUDED
