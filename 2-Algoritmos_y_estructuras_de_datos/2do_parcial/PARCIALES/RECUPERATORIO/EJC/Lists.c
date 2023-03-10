#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

node *createNode(int x)
{
    node *newNode = (node*) malloc(sizeof(node));
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}

dNode *createDNode(int x)
{
    dNode *newNode = (dNode*) malloc(sizeof(dNode));
    newNode->value = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/**************************************************************/
/*                      PILA DE ENTEROS                       */
/**************************************************************/

/**
 *  Crea una pila con el valor NULL.
 */
stack *createS()
{
    stack *s = (stack *) malloc(sizeof(stack));
	s = NULL;
	return s;
}

/**
 *  Devuelve si una pila está vacía.
 */
int isEmptyS (stack *s)
{
    return (s == NULL);
}

/**
 *  Agrega un elemento a una pila. Retorna si pudo insertarlo o no.
 */
int push(stack **s, int x)
{
    if (s == NULL) return 0;

    node *newNode = createNode(x);

    newNode->next = *s;   //asigno al next la dir. actual de la pila
    *s = newNode;         //asigno la dir. nuevo a la pila

    return 1;
}

/**
 *  Remueve un elemento de la pila y lo retorna. Si no puede removerlo, retorna
 *  ECL(definido en la cabecera).
 */
int pop (stack **s)
{
    if (s == NULL) return ECL;
    if (isEmptyS(*s)) return ECL;

    int result;
    stack *aux = *s;    //guardo la dir. de la pila en aux

    result = aux->value;    //guardo el valor en x
    *s = aux->next;     //apunto s al siguiente
    free(aux);          //libero aux

    return result;
}

/**
 *  Recupera el último valor de la pila, sin retirarlo y lo devuelve. Si está vacía,
 *  retorna ECL(definido en la cabecera).
 */
int peekS(stack *s)
{
    return (isEmptyS(s)) ? ECL : s->value;
}

/**
 *  Imprime una pila y devuelve si pudo imprimirla o no.
 */
int printS(stack *s) ///muestra una pila
{
    if (isEmptyS(s)) return 0;

    stack *head = s;

    while (!isEmptyS(head))     ///recorre la pila sin perder la referencia, gracias al auxiliar tope
    {
        printf("%i\n", head->value);
        head = head->next;
    }
    printf("\n");

    return 1;
}

/**************************************************************/
/*                      FILA DE ENTEROS                       */
/**************************************************************/

/**
 *  Crea una fila con el front y rear apuntando a NULL.
 */
queue *createQ()
{
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/**
 *  Devuelve si una fila está vacía.
 */
int isEmptyQ (queue *q)
{
    return (q->front == NULL);
}

/**
 *  Agrega un elemento a una fila. Retorna si pudo insertarlo o no.
 */
int enqueue(queue **q, int x)
{
    if (q == NULL) return 0;

    node *newNode = createNode(x);

    if((*q)->rear != NULL)
    {        // Solo si ya hay nodos, corrige
        node *last = (*q)->rear;   // Puntero al ultimo nodo
        last->next = newNode;   // Ultimo apunta al nuevo
    }
    else
    {
        (*q)->front = newNode;    //Nuevo ultimo
    }

    (*q)->rear = newNode; //Nuevo ultimo

    return 1;
}

/**
 *  Remueve un elemento de la fila y lo retorna. Si no puede removerlo, retorna
 *  ECL(definido en la cabecera).
 */
int dequeue(queue **q)
{
    if (q == NULL) return ECL;
    if (isEmptyQ(*q)) return ECL;

    int result;

    node *first = (*q)->front;  // Guarda puntero al primero
    result = first->value;      // Toma valor
    (*q)->front = first->next;  // Actualiza “front”

    if(isEmptyQ(*q)) //Revisa si ahora esta vacio y si lo esta el rear apunta a NULL
    {
        (*q)->rear = NULL;      //No hay mas nodos
    }

    free(first);    // Libera primero
    return result;
}

/**
 *  Recupera el primer valor de la fila, sin retirarlo y lo devuelve. Si está vacía,
 *  retorna ECL(definido en la cabecera).
 */
int peekQ(queue *q)
{
    if (isEmptyQ(q))
    {
        return ECL;
    }
    else
    {
        node *first = q->front;
        return first->value;
    }
}

/**
 *  Imprime una fila y devuelve si pudo imprimirla o no.
 */
int printQ(queue *q)
{
    if (isEmptyQ(q)) return 0;

    node *first = q->front;
    while (first != NULL)
    {
        printf("%i\n", first->value);
        first = first->next;
    }
    printf("\n");

    return 1;
}

/**************************************************************/
/*                     LISTA DE ENTEROS                       */
/**************************************************************/

/**
 *  Retorna el size de la lista.
 */
int getSizeList (list *l)
{
    return l->size;
}

/**
 *  Settea el size de la lista.
 */
void setSizeList(list *l, int size)
{
    l->size = size;
}

/**
 *  Crea una lista con punteros a NULL y size 0.
 */
list *createList()
{
    list *l = (list *) malloc(sizeof(list));
	l->first = NULL;
	l->last = NULL;
	setSizeList(l, 0);
	return l;
}

/**
 *  Retorna si una lista está vacía.
 */
int isEmptyList (list *l)
{
    return (getSizeList(l) == 0);
}

/**
 *  Inserta un elemento en una lista vacía. Retorna si la inserción fue exitosa.
 */
int insertEmptyList (list *l, int x)
{
    if (l == NULL) return 0;

    dNode *newNode = createDNode(x);
    l->first = newNode;
    l->last = newNode;
    setSizeList(l, getSizeList(l) + 1);
    return 1;
}

/**
 *  Inserta un elemento al principio de una lista.
 *  Retorna si la inserción fue exitosa.
 */
int insertFirstList (list *l, int x)
{
    if (l == NULL) return 0;

    if (isEmptyList(l))
    {
        insertEmptyList(l, x);
    }
    else
    {
        dNode *newNode = createDNode(x);
        dNode *first = l->first;

        newNode->next = l->first;
        first->prev = newNode;

        l->first = newNode;     //Update al first
        setSizeList(l, getSizeList(l) + 1);;
    }
    return 1;
}

/**
 *  Inserta un elemento al final de una lista.
 *  Retorna si la inserción fue exitosa.
 */
int insertLastList (list *l, int x)
{
    if (l == NULL) return 0;

    if (isEmptyList(l))
    {
        insertEmptyList(l, x);
    }
    else
    {
        dNode *newNode = createDNode(x);
        dNode *last = l->last;

        newNode->prev = l->last;

        last->next = newNode;
        l->last = newNode;      //Update al last
        setSizeList(l, getSizeList(l) + 1);;
    }
    return 1;
}


/**
 *  Inserta un elemento en una posición de la lista.
 *  Retorna si la inserción fue exitosa.
 */
int insertPosList (list *l, int pos, int x)
{
    if (pos > getSizeList(l) || pos < 0) return 0;

    int result;

    if (pos == 0 || pos == getSizeList(l))
    {
            if (pos == 0)
            {
                result = insertFirstList(l, x);
            }
            else
            {
                result = insertLastList(l, x);
            }
    }
    else
    {
        dNode *newNode = createDNode(x);
        dNode *current = l->first;
        dNode *aux;

        for (int i = 0; i < pos; i++) //se posiciona en el elemento actual
        {
            current = current->next;
        }

        newNode->next = current;       //el actual se vuelve el siguiente
        newNode->prev = current->prev; //el anterior del actual se vuelve el anterior del nodo nuevo

        aux = current->prev;        //guardo la ref. del anterior al actual
        current->prev = newNode;    //el anterior al actual es el nuevo
        aux->next = newNode;          //el sig. del anterior es nuevo


        setSizeList(l, getSizeList(l) + 1);;
        result = 1;
    }

    return result;
}

/**
 *  Elimina el primer elemento de una lista.
 *  Retorna si la eliminación fue exitosa.
 */
int deleteFirstList(list **l)
{
    if (isEmptyList(*l)) return 0;

    if (getSizeList(*l) == 1)//si tiene un elemento me devuelve una lista vacia
    {
        *l = createList();
    }
    else
    {
        dNode *first = (*l)->first;
        dNode *next = first->next;

        (*l)->first = next;   //actualizo el first
        next->prev = NULL;   //al ser el primero queda el prev apuntando a NULL

        setSizeList((*l), getSizeList((*l)) - 1);;
        free(first);
    }
    return 1;
}

/**
 *  Elimina el último elemento de una lista.
 *  Retorna si la eliminación fue exitosa.
 */
int deleteLastList(list **l)
{
    if (isEmptyList(*l)) return 0;

    if (getSizeList((*l)) == 1)//si tiene un elemento me devuelve una lista vacia
    {
        *l = createList();
    }
    else
    {
        dNode *last = (*l)->last;
        dNode *prev = last->prev;

        (*l)->last = prev;   //actualizo el last
        prev->next = NULL;   //al ser el ultimo queda el next apuntando a NULL

        setSizeList((*l), getSizeList((*l)) - 1);
        free(last);
    }
    return 1;
}

/**
 *  Elimina un elemento en una posición de la lista.
 *  Retorna si la eliminación fue exitosa.
 */
int deletePosList(list **l, int pos)
{
    if (l == NULL) return 0;
    if (pos >= getSizeList((*l)) || pos < 0) return 0;

    int result = 0;

    if (pos == 0 || pos == getSizeList((*l)) - 1)
    {
        if (pos == 0)
        {
            result = deleteFirstList(l);
        }
        else
        {
            result = deleteLastList(l);
        }
    }
    else
    {
        dNode *current = (*l)->first;
        dNode *aux;

        for (int i = 0; i < pos; ++i) //se posiciona en el nodo actual
        {
            current = current->next;
        }

        aux = current->prev;        //apunto el anterior del actual, al siguiente del actual
        aux->next = current->next;

        aux = current->next;     //apunto el siguiente del actual, al anterior del actual
        aux->prev = current->prev;

        free(current);   //libero el nodo actual
        setSizeList((*l), getSizeList((*l)) - 1);
        result = 1;
    }

    return result;
}

/**
 *  Recupera el valor en una posición de una lista y lo retorna.
 *  En caso de error retorna ECL(definido en la cabecera).
 */
int getValueList(list *l, int pos)
{
    if (l == NULL) return ECL;
    if (pos >= getSizeList(l) || pos < 0) return ECL;

    dNode *current = l->first;
    for (int i = 0; i < pos; i++) ///se posiciona en el nodo actual
    {
        current = current->next;
    }

    return current->value;
}

/**
 *  Settea un valor en la lista en una posición.
 */
 int setValueList (list *l, int pos, int x)
 {
    if (l == NULL) return 0;
    if (pos >= getSizeList(l)) return 0;

    dNode *current = l->first;
    for (int i = 0; i < pos; i++) //se posiciona en el elemento actual
    {
        current = current->next;
    }

    current->value = x;
    return 1;

 }

/**
 *  Imprime una lista.
 */
int printList (list *l)
{
    if (l == NULL) return 0;
    if (isEmptyList(l)) return 0;

    dNode *current = l->first;
    for (int i = 0; i < getSizeList(l); i++)
    {
        printf("%i ", current->value);
        current = current->next;
    }
    printf("\n");
    return 1;
}

/**************************************************************/
/*                     LISTA DE STRINGS                       */
/**************************************************************/


listStr *createListStrNode(char *value)
{
    listStr *result = (listStr*)malloc(sizeof(listStr));
    result->value = value;
    result->next = NULL;
    return result;
}

listStr *listStrGetNext(listStr *l)
{
    return l->next;
}

int isEmptyListStr(listStr *l)
{
    int result = 1;
    if(l != NULL)
    {
        result = 0;
    }
    return result;
}

char *listStrGetValue(listStr *l)
{
    return l->value;
}

//A esta llama el usuario para agregar
void listStrAdd(listStr **l, char *value)
{
    if(!l) return;
    if((*l) == NULL)
    {
        (*l) = createListStrNode(value);
    }
    else
    {
        listStrAdd(&((*l)->next), value);
    }
}

void listStrAddFirst(listStr **l, char *value)
{
    if(!l) return;

    listStr *aux = createListStrNode(value);
    aux->next = (*l);
    (*l) = aux;
}

int printListStr(listStr *l)
{
    if (!l) return 0;
    if (isEmptyListStr(l)) return 0;

    listStr *aux = l;
    while(aux != NULL)
    {
        printf("%s ", aux->value);
        aux = aux->next;
    }
    printf("\n");
    return 1;
}

int printListStrWay(listStr *l)
{
    if (!l) return 0;
    if (isEmptyListStr(l)) return 0;

    listStr *aux = l;
    if(aux != NULL)
    {
        printf("%s", listStrGetValue(aux));
        aux = listStrGetNext(aux);
    }
    while(aux != NULL)
    {
        printf(" --> %s", listStrGetValue(aux));
        aux = listStrGetNext(aux);
    }
    puts("\n");

    return 1;
}
