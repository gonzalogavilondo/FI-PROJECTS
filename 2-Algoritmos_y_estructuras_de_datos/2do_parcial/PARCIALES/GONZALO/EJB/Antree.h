#ifndef HEADER_NTREE_H_INCLUDED
#define HEADER_NTREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lists.h"

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
/*                      Árboles N-ario                        */
/**************************************************************/

ntn *createNTN(int value);
ntlist *createNTL(ntn *node);
int insertNTL (ntlist **nodoList, ntlist *newNodoList);
int insertSonNTN (ntn *node, ntn *newNode);
ntn *insertSonValueNTN (ntn *node, int value);
ntn *insertSonValueOfNTN(ntn *node, int valueParent, int valueSon);
int removeNodeNTN(ntn *root, ntn *node);
ntn *findNodeNTN (ntn *node, int value);
void _printNTN (ntn *node, int level);
void printNTN (ntn *node);
void printProfundidad (ntn *node);
void printAmplitud (ntn *node);

/**************************************************************/
/*             Fila de Nodos de Árbol N-ario                  */
/**************************************************************/
typedef struct ntQueue
{
    ntlist *first;
    ntlist *last;
} ntq;

ntq *createQueueNTN();
void printQueueNTN(ntq *q);
int enqueueNTN(ntq *queue, ntn *node);
ntn *dequeueNTN(ntq *queue);
int isEmptyQueueNTN(ntq *queue);

/**************************************************************/
/*             Funciones del ejercicio                        */
/**************************************************************/
void crearArbol(ntn **root);
list *hijosDePares (ntn *root);
void _hijosDePares(ntn *node, list **result);


#endif // HEADER_NTREE_H_INCLUDED
