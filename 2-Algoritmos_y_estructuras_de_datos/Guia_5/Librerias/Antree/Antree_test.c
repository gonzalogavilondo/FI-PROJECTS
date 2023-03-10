#include "declaraciones.h"

void prueba1()
{
    ntn *root = NULL;
    ntn *aux =NULL;

    root = createNTN (100);
    aux = insertSonValueNTN(root, 1001);
    insertSonValueNTN(aux, 991);
    insertSonValueNTN(aux, 992);
    insertSonValueNTN(aux, 993);
    aux = insertSonValueNTN(root, 1002);
    insertSonValueNTN(aux, 881);
    insertSonValueNTN(aux, 882);
    aux = insertSonValueNTN(root, 1003);
    insertSonValueNTN(aux, 771);
    insertSonValueNTN(aux, 772);
    insertSonValueNTN(aux, 773);
    insertSonValueNTN(aux, 774);
    aux = insertSonValueNTN(root, 1004);
    insertSonValueNTN(aux, 661);

    //printNTN (root);

    aux = findNodeNTN(root, 772);
    insertSonValueNTN(aux, 221);

    printNTN (root);

    puts("\n\n");
    sample(&root);
    printNTN(root);

}


void sample (ntn **root)
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


void printProfundidad (ntn *node)
{
    if(node == NULL) return;
    printf(" %d ", node->value);
    ntlist *l = node->sons;
    while(l != NULL)
    {
        printProfundidad(l->node);
        l = l->next;
    }
    // 1  5  6  20  18  3  4  12  17  2  15
}


void printAmplitud (ntn *nodo)
{
    if(nodo == NULL) return;
    ntq *q = createQueue();
    enqueue(q, nodo);
    while(!isEmpty(q))
    {
        nodo = dequeue(q);
        ntlist *l = nodo->sons;
        while(l != NULL)
        {
            enqueue(q, l->node);
            l = l->next;
        }
        printf(" %d ", nodo->value);
    }
    printf("\n");
    free(q);

    // 1  5  20  18  6  3  15  4  12  17  2
}

void prueba2()
{
    ntn *root = NULL;
    sample(&root);
    printNTN(root);
    printf ("\nRecorrido en profundidad: \n");
    printProfundidad(root);
    printf ("\nRecorrido en amplitud: \n");
    printAmplitud(root);
}

void pruebaCreaLista()
{
    ntn *root = NULL;
    sample(&root);
    printNTN(root);
    ntq *q = crearLista(root, 1);
    printQueue(q);
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
        enqueue(q, nodo);
    }
}

ntq *crearLista(ntn *root, int level)
{
    ntq *result = createQueue();

    _crearLista(root, level, 0, result);

    return result;

}

