#ifndef ANTREESTR_H_INCLUDED
#define ANTREESTR_H_INCLUDED
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
    char *value;
    ntlist *sons;
} ntn;


/**************************************************************/
/*                      Árboles N-ario                        */
/**************************************************************/

ntn *createNTN(char *value);
ntlist *createNTL(ntn *node);
int insertNTL (ntlist **nodoList, ntlist *newNodoList);
int insertSonNTN (ntn *node, ntn *newNode);
ntn *insertSonValueNTN (ntn *node, char *value);
ntn *insertSonValueOfNTN(ntn *node, char *parent, char *value);
ntn *findNodeNTN (ntn *node, char *value);
void _printNTN (ntn *node, int level);
void printNTN (ntn *node);
void printProfundidad (ntn *node);
void printAmplitud (ntn *node);

/**************************************************************/
/*             Fila de Nodos de Árbol N-ario                  */
/**************************************************************/
typedef struct ntQueue {
    ntlist *first;
    ntlist *last;
} ntq;

void printQueueNTN(ntq *q);
ntq *createQueueNTN();
int enqueueNTN(ntq *queue, ntn *node);
ntn *dequeueNTN(ntq *queue);
int isEmptyQueueNTN(ntq *queue);


#endif // ANTREESTR_H_INCLUDED
