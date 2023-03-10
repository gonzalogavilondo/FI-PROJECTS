#include "Antree.h"
#include "Abtree.h"

void _CrearABB(ntn *node, btn **nodeSBT)
 {
    if (node == NULL) return;

    insertValueSBT(nodeSBT, node->value); //Inserto el nodo raiz en el ABB
    ntq *q = createQueueNTN();
    enqueueNTN(q, node);
    while (!isEmptyQueueNTN(q))
    {
        ntn *aux = dequeueNTN(q);

        ntlist *l = aux->sons;
        while (l != NULL)
        {
            insertValueSBT(nodeSBT, l->node->value); //Inserto los hijos de cada nodo
            enqueueNTN(q, l->node);
            l = l->next;
        }
    }

 }

btn *CrearABB (ntn *rootAN)
{
    btn *rootSBT = NULL;
    _CrearABB(rootAN, &rootSBT);

    return rootSBT;
}
