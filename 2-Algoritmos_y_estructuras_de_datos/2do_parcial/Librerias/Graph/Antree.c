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

ntn *insertSonValueOfNTN(ntn *root, int parent, int value)
{

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

int sizeNTN(ntn *node)
{
    int cnt = 0;
    ntq *q = createQueueNTN();
    enqueueNTN(q, node);
    while (!isEmptyQueueNTN(q))
    {
        ntn *aux = dequeueNTN(q);

        ntlist *l = aux->sons;
        while (l != NULL)
        {
            enqueueNTN(q, l->node);
            l = l->next;
        }
        cnt++;
    }

    return cnt;
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

/**************************************************************/
/*                       Ejemplos                             */
/**************************************************************/

void sample(ntn **root)
{
    ntn *aux = NULL;
    ntn *aux2 = NULL;
    if (root != NULL)
    {
        *root = createNTN (1);
        aux = insertSonValueNTN(*root, 5);
        insertSonValueNTN(aux, 6);
        aux = insertSonValueNTN(*root, 20);
        aux = insertSonValueNTN(*root, 18);
        aux2 = insertSonValueNTN(aux, 3);
        insertSonValueNTN(aux2, 4);
        insertSonValueNTN(aux2, 12);
        insertSonValueNTN(aux2, 17);
        insertSonValueNTN(aux2, 2);
        aux = insertSonValueNTN(aux, 15);

        /*+--(000001)
            +--(000005)
                +--(000006)
            +--(000020)
            +--(000018)
                +--(000003)
                    +--(000004)
                    +--(000012)
                    +--(000017)
                    +--(000002)
                +--(000015)*/

    }
}

void _crearLista(ntn *nodo, int level, int levelActual, ntq *q)
{
    if(!nodo) return;

    if(level > levelActual)
    {
        ntlist *l = nodo->sons;
        while(l != NULL)
        {
            _crearLista(l->node, level, levelActual + 1, q);
            l = l->next;
        }
    }
    else if(level == levelActual)
    {
        enqueueNTN(q, nodo);
    }
}

ntq *crearLista(ntn *root, int level)
{
    ntq *result = createQueueNTN();

    _crearLista(root, level, 0, result);

    return result;
}
