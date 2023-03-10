#include "Antree.h"

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

ntn *insertSonValueOfNTN(ntn *root, int parent, int value){

    ntn *parentNode = findNodeNTN(root, parent);
    ntn *result = createNTN(value);

    if(insertSonNTN(parentNode, result))
    {
        return result;
    }
    else
    {
        return NULL;
    }
}

int removeNodeNTN(ntn *root, ntn *node)
{
    if(!root) return 0;
    if(!node) return 0;

    int result = 0;
    ntlist **l = &(root->sons);
    while((result == 0) && ((*l) != NULL))
    {
        if(node == (*l)->node)
        {
            ntlist *aux = (*l);
            (*l) = aux->next;
            aux->node = NULL;
            aux->next = NULL;
            free(aux);
            result = 1;
        }
        else
        {
            result = removeNodeNTN((*l)->node, node);
        }
        l = &((*l)->next);
    }
    return result;
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
        printf ("+--(%02d)\n", node->value);

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
        printf(" %d ", node->value);
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
    enqueueNTN(q, node);
    while (!isEmptyQueueNTN(q))
    {
        ntn *aux = dequeueNTN(q);
        printf (" %d ", aux->value);

        ntlist *l = aux->sons;
        while (l != NULL)
        {
            enqueueNTN(q, l->node);
            l = l->next;
        }
    }
    printf ("\n");
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

void printQueueNTN(ntq *queue)
{
    ntlist *l = queue->first;

    while(l != NULL)
    {
        printf(" %d ", l->node->value);
        l = l->next;
    }
    puts("\n");
}

int enqueueNTN(ntq *queue, ntn *node)
{
    if (queue == NULL) return 0;

    ntlist *l = createNTL(node);
    l->node = node;
    if (insertNTL (&(queue->last), l))
    {
        queue->last = l;
        if (queue->first == NULL){
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

