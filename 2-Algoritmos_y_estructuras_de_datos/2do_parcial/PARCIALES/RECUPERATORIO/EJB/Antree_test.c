#include "Antree.h"
#include "Abtree.h"

void sample (ntn **root)
{
    ntn *aux = NULL;
    ntn *aux2 = NULL;
    if (root != NULL)
    {
        *root = createNTN (8);
        aux = insertSonValueNTN(*root, 9);
        insertSonValueNTN(aux, 3);
        insertSonValueNTN(aux, 5);
        insertSonValueNTN(aux, 1);
        aux = insertSonValueNTN(*root, 4);
        aux2 = insertSonValueNTN(aux, 6);
        aux = insertSonValueNTN(*root, 2);

    }
}



