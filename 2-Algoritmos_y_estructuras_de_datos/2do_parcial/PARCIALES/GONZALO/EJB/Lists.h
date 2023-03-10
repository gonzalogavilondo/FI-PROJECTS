#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED
#define ECL -1  //error code lists

#include <stdbool.h>
#define CNT 10

typedef struct node node;   ///Nodo para lista simplemente enlazada
struct node
{
    int value;
    node *next;
};


node *createNode(int x);

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
typedef struct List list;
typedef struct List
{
    int value;
    list *next;

} list;

list *createListNode(int value);
list *listGetNext(list *l);
void insertListPos(list **lista, int pos, int x);
void deleteListPos(list **lista, int pos);
int existValueList(list **lista, int x);
void swapList(list *lista, int pos1, int pos2);
int printList(list *lista);
int length(list *lista);
int getValueListPos(list *lista, int pos);
int posMay(list *lista);
int isEmpty(list *lista);
int isSort(list *lista);
void freeMemoryList(list *lista);
int listGetValue(list *l);
void sortAdd(list **l, int value);

/**************************************************************/
/*                     LISTA DE STRINGS                      */
/**************************************************************/

typedef struct ListStr listStr;
typedef struct ListStr
{
    char *value;
    listStr *next;

} listStr;

listStr *createListStrNode(char *value);
listStr *listStrGetNext(listStr *l);
char *listStrGetValue(listStr *l);
void listStrAdd(listStr **l, char *value);
void listStrAddFirst(listStr **l, char *value);

#endif // LISTS_H_INCLUDED
