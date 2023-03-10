#ifndef HEADER_LISTAS_DIN_H_INCLUDED
#define HEADER_LISTAS_DIN_H_INCLUDED
#define ECL -1  //error code lists
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;   ///Nodo para lista simplemente enlazada
struct node
{
    int value;
    node *next;
};

typedef struct dNode dNode;    ///Nodo para lista doblemente enlazada
struct dNode
{
	int value;
	dNode *prev;
	dNode *next;
};

/**************************************************************/
/*                      PILA DE ENTEROS                       */
/**************************************************************/

typedef struct node stack;

stack *createS();
int isEmptyS(stack *s);
int push(stack **s, int x);
int pop(stack **s);
int peekS(stack *s);
int printS(stack *s);

/**************************************************************/
/*                      FILA DE ENTEROS                       */
/**************************************************************/

typedef struct
{
    node *front;
    node *rear;
}queue;

queue *createQ();
int isEmptyQ (queue *q);
int enqueue(queue **q, int x);
int dequeue(queue **q);
int peekQ(queue *q);
int printQ(queue *q);

/**************************************************************/
/*                     LISTA DE ENTEROS                       */
/**************************************************************/

typedef struct
{
    dNode *first;
    dNode *last;
    int size;
}list;

list *createList();
int getSizeList (list *l);
int isEmptyList (list *l);
int insertEmptyList (list *l, int x);
int insertFirstList (list *l, int x);
int insertLastList (list *l, int x);
int insertPosList (list *l, int x, int pos);
int deleteFirstList(list **l);
int deleteLastList(list **l);
int deletePosList(list **l, int pos);
int get(list *l, int pos);
int printList(list *l);

#endif // HEADER_LISTAS_DIN_H_INCLUDED
