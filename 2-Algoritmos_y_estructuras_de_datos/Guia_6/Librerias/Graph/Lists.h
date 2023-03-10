#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED
#define ECL -1  //error code lists

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

node *createNode(int x);
dNode *createDNode(int x);

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
int peekQueue(queue *q);
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
int insertPosList (list *l, int pos, int x);
int deleteFirstList(list **l);
int deleteLastList(list **l);
int deletePosList(list **l, int pos);
int getValueList(list *l, int pos);
int setValueList(list *l, int pos, int x);
int printList(list *l);

#endif // LISTS_H_INCLUDED
