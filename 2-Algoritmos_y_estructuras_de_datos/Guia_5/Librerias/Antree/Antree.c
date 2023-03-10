#include "declaraciones.h"

/**************************************************************/
/*                      Árboles N-ario                        */
/**************************************************************/

ntn *createNTN(int value)
{
    ntn *n = (ntn *)malloc(sizeof(ntn));
    n->value = value;
    n->sons = NULL;
    return n;
}

ntlist *createNTL(ntn *node)
{
    ntlist *n = (ntlist *)malloc(sizeof(ntlist));
    n->node = node;
    n->next = NULL;
    return n;
}

int insertNTL (ntlist **nodoList, ntlist *newNodoList)
{
    if (nodoList == NULL) return 0; //error
    if (*nodoList == NULL)
    {
        *nodoList = newNodoList; //Quiere decir que estoy al final de la lista o esta vacia -> inserto
    }
    else
    {
        insertNTL (&((*nodoList)->next), newNodoList); //Voy al final de la lista e inserto.
    }
    return 1;
}

int insertSonNTN (ntn *node, ntn *newNode)
{
    if (node == NULL) return 0;
    return insertNTL(&(node->sons), createNTL(newNode));
}

ntn *insertSonValueNTN (ntn *node, int value)
{
    ntn *result = createNTN(value);
    if (insertSonNTN (node, result))
    {
        return result;
    }
    else
    {
        return NULL;
    }
}


ntn *findNodeNTN (ntn *node, int value)
{
    ntn *result = NULL;
    if ((node == NULL) || (node->value == value))
    {
        result = node;
    }
    else
    {
        ntlist *l = node->sons;
        while ((l != NULL) && (result == NULL))
        {
            result = findNodeNTN(l->node, value);
            l = l->next;
        }
    }
    return result;
}

void _printNTN (ntn *node, int level)
{
    if (node != NULL)
        {
        for (int i = 0; i < level; i++)
        {
            printf ("    ");
        }
        printf ("+--(%06d)\n", node->value);

        ntlist *l = node->sons;
        while (l != NULL)
        {
            _printNTN(l->node, level+1);
            l = l->next;
        }
    }
}

void printNTN (ntn *node)
{
    _printNTN(node, 0);
}

/**************************************************************/
/*             Fila de Nodos de Árbol N-ario                  */
/**************************************************************/

ntq *createQueue()
{
    ntq *q = (ntq *)malloc(sizeof(ntq));
    q->first = NULL;
    q->last = NULL;
    return q;
}

void printQueue(ntq *queue)
{
    ntlist *l = queue->first;

    while(l != NULL)
    {
        printf(" %d ", l->node->value);
        l = l->next;
    }
    puts("\n");
}

int enqueue (ntq *queue, ntn *node)
{
    if (queue == NULL) return 0;

    ntlist *l = createNTL(node);
    l->node = node;
    if (insertNTL (&(queue->last), l))
    {
        queue->last = l;
        if (queue->first == NULL)
        {
            queue->first = queue->last;
        }
        return 1;
    }
    else
    {
        return 0;
    };

}

ntn *dequeue(ntq *queue)
{
    if (queue == NULL) return NULL;

    ntn *result = NULL;
    if (queue->first != NULL)
    {
        ntlist *l = queue->first;
        queue->first = l->next;
        if (queue->last == l)
        {
            queue->last = NULL;
        }
        result = l->node;
        l->next = NULL;
        free(l);
    }
    return result;
}

int isEmpty(ntq *queue)
{
    return ((queue == NULL)||(queue->first == NULL))?1:0;
}
