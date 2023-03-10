#include "AntreeSTR.h"

/**************************************************************/
/*                      Árboles N-ario                        */
/**************************************************************/

ntn *createNTN(char *value)
{
    ntn *n = (ntn *)malloc(sizeof(ntn));
    n->value = strdup(value);
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
        *nodoList = newNodoList;
    }
    else
    {
        insertNTL (&((*nodoList)->next), newNodoList);
    }
    return 1;
}


int insertSonNTN (ntn *node, ntn *newNode)
{
    if (node == NULL) return 0;

    return insertNTL(&(node->sons), createNTL(newNode));
}

ntn *insertSonValueNTN (ntn *node, char *value)
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

ntn *insertSonValueOfNTN(ntn *root, char *parent, char *value)
{
    ntn *parentNode = findNodeNTN(root, parent);
    ntn *result = createNTN(value);
    if (insertSonNTN(parentNode, result))
    {
        return result;
    }
    else
    {
        return NULL;
    }
}

ntn *findNodeNTN (ntn *node, char *value)
{
    ntn *result = NULL;
    if ((node == NULL) || (strcmp(node->value, value)) )
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

    if (node != NULL){
        for (int i = 0; i < level; i++)
        {
            printf ("    ");
        }
        printf ("+--(%s)\n", node->value);
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

void printProfundidad (ntn *node)
{
    if (node != NULL)
    {
        printf(" %s ", node->value);
        ntlist *l = node->sons;
        while (l != NULL)
        {
            printProfundidad(l->node);
            l = l->next;
        }
    }
}


void printAmplitud (ntn *node)
{
    if (node == NULL) return;

    ntq *q = createQueueNTN();

    enqueueNTN(q,node);

    while (!isEmptyQueueNTN(q))
    {
        ntn *aux = dequeueNTN(q);
        printf (" %s ", aux->value);

        ntlist *l = aux->sons;
        while (l != NULL)
        {
            enqueueNTN(q, l->node);
            l = l->next;
        }
    }
    printf ("\n");
}

void sizeNTree (ntn *node, int *size)
{
    if (node != NULL)
    {
        (*size)++;
        ntlist *l = node->sons;
        while (l != NULL)
        {
            sizeNTree(l->node, size);
            l = l->next;
        }
    }
}

/**************************************************************/
/*             Fila de Nodos de Árbol N-ario                  */
/**************************************************************/

ntq *createQueueNTN()
{
    ntq *q = (ntq *)malloc(sizeof(ntq));
    q->first = NULL;
    q->last = NULL;
    return q;
}

int enqueueNTN(ntq *queue, ntn *node)
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

ntn *dequeueNTN(ntq *queue)
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

int isEmptyQueueNTN(ntq *queue)
{
    return ((queue == NULL)||(queue->first == NULL))?1:0;
}

void printQueueNTN(ntq *queue)
{
    ntlist *l = queue->first;

    while(l != NULL)
    {
        printf(" %s ", l->node->value);
        l = l->next;
    }
    puts("\n");
}
