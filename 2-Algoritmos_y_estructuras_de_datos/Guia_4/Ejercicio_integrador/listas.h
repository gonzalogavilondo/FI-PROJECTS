#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define LONGMAX 40
#define CNT_LIBROS 4
typedef struct
{
    char nombre[LONGMAX];
    char genero_literario[LONGMAX];
    int cnt_paginas;
    int cnt_capitulos;
    int posicion;

}CARACT;

typedef struct NODO NODO;
struct NODO *lista;
struct NODO
{
    CARACT libro;
    NODO *next;
};

void liberar_memoria(NODO *lista);
void deletee(NODO **lista, int pos);
void insert(NODO **lista, int pos);
void traverse(CARACT informacion);
int length(NODO *lista);
CARACT get(NODO *lista, int pos);
bool isEmpty(NODO *lista);
bool sort(NODO *lista);
bool search(NODO *lista, int *pos, char aux[LONGMAX]);
void intercambiar(NODO *lista, int pos1, int pos2);
int mayor(NODO *lista);
void inicializar_lista(NODO **lista);


//FUNCIONES
int leer(NODO *lista);
NODO *cargar_libro(int pos);
void sacar_libro(NODO **lista, int pos);
void ver_biblioteca(NODO *lista);

#endif // LISTAS_H_INCLUDED
