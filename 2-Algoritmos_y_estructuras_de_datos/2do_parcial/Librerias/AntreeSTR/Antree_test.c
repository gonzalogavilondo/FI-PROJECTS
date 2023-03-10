#include "Graphs.h"

void prueba1()
{
    ntn *root = NULL;
    ntn *aux = NULL;

    root = createNTN ("Carlos");
    aux = insertSonValueNTN(root, "Pepe");
    insertSonValueNTN(aux, "Gonzalo");
    insertSonValueNTN(aux, "A");
    insertSonValueNTN(aux, "B");
    aux = insertSonValueNTN(root, "C");
    insertSonValueNTN(aux, "Pedro");
    insertSonValueNTN(aux, "Soda stereo");
    aux = insertSonValueNTN(root, "Pablo");
    insertSonValueNTN(aux, "Juan");
    insertSonValueNTN(aux, "Juanchi");
    insertSonValueNTN(aux, "Roberto");
    insertSonValueNTN(aux, "Leto");
    aux = insertSonValueNTN(root, "Daniel");
    insertSonValueNTN(aux, "Pollo");

    //printNTN (root);

    aux = findNodeNTN(root, "Juan");
    insertSonValueNTN(aux, "Argentina");

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
        *root = createNTN ("Vicente");
        aux = insertSonValueNTN(*root, "Gonzalo");
        insertSonValueNTN(aux, "Micaela");
        aux = insertSonValueNTN(*root, "Cristian");
        aux = insertSonValueNTN(*root, "Silvina");
        aux2 = insertSonValueNTN(aux, "Carina");
        insertSonValueNTN(aux2, "Nehuen");
        insertSonValueNTN(aux2, "Pedro");
        insertSonValueNTN(aux2, "Carlos");
        insertSonValueNTN(aux2, "Picante");
        aux = insertSonValueNTN(aux, "Altoque");

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

void pruebaCrearLista()
{
    ntn *root = NULL;
    sample(&root);
    printf("\n\nARBOL N ARIO \n\n");
    printNTN(root);
    ntq *q = crearLista(root, 3);
    puts("\n");
    printQueueNTN(q);
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
