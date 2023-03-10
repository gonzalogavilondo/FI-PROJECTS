#include "Antree.h"

void crearArbol(ntn **root)
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
        aux2 = insertSonValueNTN(aux, 8);
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

int isPair(ntn *node)
{
    return (node->value % 2 == 0 ? 1 : 0);
}

//void _hijosDePares(ntn *node, list **result) //En amplitud
//{
//    if (node == NULL) return;
//
//    ntq *q = createQueueNTN();
//    enqueueNTN(q, node);
//    while (!isEmptyQueueNTN(q))
//    {
//        ntn *aux = dequeueNTN(q);
//        ntlist *l = aux->sons;
//
//        while (l != NULL)
//        {
//            if(isPair(aux))
//            {
//                sortAdd(result, l->node->value);
//            }
//            enqueueNTN(q, l->node);
//            l = l->next;
//        }
//    }
//}

void _hijosDePares(ntn *node, list **result) //En profundidad
{
    if (node != NULL)
    {
        ntlist *sons = node->sons;
        while (sons != NULL)
        {
            if(isPair(node))
            {
                sortAdd(result, sons->node->value);
            }
            _hijosDePares(sons->node, result);
            sons = sons->next;
        }
    }
}

list *hijosDePares (ntn *root)
{
    list *result = NULL;

    _hijosDePares(root, &result);

    return result;
}
