#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  n-ary Tree Node Struct
 */

typedef struct ntNode ntn;
typedef struct ntList ntlist;

typedef struct ntList
{
    ntn *node;
    ntlist *next;

} ntlist;

typedef struct ntNode
{
    int value;
    ntlist *sons;

} ntn;

/**************************************************************/
/*                      Funciones Árboles N-ario              */
/**************************************************************/

ntn *createNTN(int value);
ntlist *createNTL(ntn *node);
int insertNTL (ntlist **nodoList, ntlist *newNodoList);
int insertSonNTN (ntn *node, ntn *newNode);
ntn *insertSonValueNTN (ntn *node, int value);
ntn *findNodeNTN (ntn *node, int value);
void _printNTN (ntn *node, int level);
void printNTN (ntn *node);

/**************************************************************/
/*             Fila de Nodos de Árbol N-ario                  */
/**************************************************************/

typedef struct ntQueue
{
    ntlist *first;
    ntlist *last;

} ntq;

ntq *createQueue();
void printQueue(ntq *q);
int enqueue (ntq *queue, ntn *node);
ntn *dequeue(ntq *queue);
int isEmpty(ntq *queue);



/**************************************************************/
/*             Funciones de prueba                 */
/**************************************************************/
void prueba1();
void sample (ntn **root);
void printProfundidad (ntn *node);
void printAmplitud (ntn *nodo);
void prueba2();

void pruebaCreaLista();

ntq *crearLista(ntn *root, int level);
void _crearLista(ntn *nodo, int level, int levelActual, ntq *q);


#endif // DECLARACIONES_H_INCLUDED
