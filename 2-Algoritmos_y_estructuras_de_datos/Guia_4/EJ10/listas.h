#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
///////////////////////////LISTAS///////////////////////////

#define CNT 4
typedef struct NODO NODO;
struct NODO *lista;
struct NODO
{
    int valor;
    NODO *next;
};
void inicializar_lista(NODO **lista);
void insert(NODO **lista, int pos, int x);
void deletee(NODO **lista, int pos);
void liberar_memoria(NODO *lista);
void intercambiar(NODO *lista, int pos1, int pos2);
bool traverse(NODO *lista);
int length(NODO *lista);
int get(NODO *lista, int pos);
int mayor(NODO *lista);
int posMayor(NODO *lista);
bool isEmpty(NODO *lista);
bool sort(NODO *lista);
bool search(NODO *lista, int x);


#endif // DECLARACIONES_H_INCLUDED
