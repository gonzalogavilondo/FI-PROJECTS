#include "declaraciones.h"

/**
 * EJERCICIO 0
 * Dado un Árbol binario:
 * Devolver la suma de los valores de todos
 * los nodos del árbol.
 */

void sumaNodos(btn *node, int *cnt_nodos)
{
    if(node != NULL)
    {
        (*cnt_nodos)++;
        sumaNodos(node->left, cnt_nodos);
        sumaNodos(node->right, cnt_nodos);
    }
}

/**
 * EJERCICIO 1
 * Dado un Árbol binario:
 * Devolver 1 si todos los padres tienen el valor
 * de la suma de sus hijos.
 * Devolver 0 si no se cumple.
 */

int esPadreSumaHijos(btn *node)
{
    int acum = 0;
    if(node == NULL) return 1;

    if(isLeaf(node))
    {
        return 1;
    }
    else
    {
        if(node->right != NULL)
        {
            acum += node->right->value;
        }
        if(node->left != NULL)
        {
            acum += node->left->value;
        }
        if(acum == node->value)
        {
            return(esPadreSumaHijos(node->left) & esPadreSumaHijos(node->right));
        }
        else
        {
            return 0;
        }
    }

}

/**
 * EJERCICIO 2
 * armar una función:
 * btn *crearSBT(btn *btree)
 * (y las funciones auxiliares necesarias)
 * que dado un Árbol binario devuelva un
 * árbol binario de búsqueda con los mismos
 * valores sin destruir el árbol original
 */

 void _crearSBT(btn **nodoSBT, btn *btree)
{
    if(btree != NULL)
    {
        insertValueSBT(nodoSBT, btree->value);
        _crearSBT(nodoSBT, btree->left);
        _crearSBT(nodoSBT, btree->right);
    }
}


btn *crearSBT(btn *btree)
{
    btn *rootSBT = NULL;
    _crearSBT(&rootSBT, btree);

    return rootSBT;
}


/**
 * EJERCICIO 3
 * armar una función:
 * btn *enComunAVL(btn *ab, btn *abb)
 * (y las funciones auxiliares necesarias)
 * que dado un Árbol binario (ab) y un ABB (abb)
 * Cree un árbol AVL con los elementos
 * que tienen en común ambos árboles
 */

void _enComunAVL(btn **avl, btn *ab, btn *abb)
{
    if(ab != NULL)
    {
        int res = inSBT(abb, ab->value);
        if(res == 1)
        {
            insertValueAVL(avl, ab->value);
        }
        _enComunAVL(avl, ab->left, abb);
        _enComunAVL(avl, ab->right, abb);
    }
}

btn *enComunAVL(btn *ab, btn *abb)
{
    btn *avl = NULL;
    _enComunAVL(&avl, ab, abb);

    return avl;
}


/**
 * EJERCICIO 4
 * armar una función:
 * btn *getNode(btn **ab, int value)
 * que dado un Árbol binario y un valor
 * devuelva el nodo (si está) y además cada vez
 * que un nodo es solicitado intercambia
 * el lugar con su padre (a menos que sea la raíz)
 */

 void _getNode(btn **ab, btn **nodeBTN, int value)
 {
     if((*ab) != NULL)
     {
         if(value == (*ab)->value)
         {
             (*nodeBTN) = (*ab);
         }
         _getNode(&(*ab)->left, nodeBTN, value);
         _getNode(&(*ab)->right, nodeBTN, value);
     }
 }

btn *_findParent(btn *ab, btn *nodeBTN, btn **result)
{
    if((ab) != NULL)
     {
         if((ab->left == nodeBTN) || (ab->right == nodeBTN))
         {
             *result = ab;
         }
         _findParent((ab)->left, nodeBTN, result);
         _findParent((ab)->right, nodeBTN, result);
     }

    return *result;
}

void _swapNode(btn **ab, btn *nodeBTN, btn *nodeP, btn *nodeGP)
{
    if(nodeP != (*ab)) //Si el padre no es igual a la raiz
    {
        btn *aux = NULL;
        if(nodeP->left == nodeBTN)
        {
            //Intercambiamos el nodo de la izquierda (nodoBTN) con el padre
            /** Linkeamos los hijos del nodoBTN (solicitado) con el nodoP y guardamos en un aux el nodo derecho del padre **/
            aux = nodeP->right;
            nodeP->right = nodeBTN->right;
            nodeP->left = nodeBTN->left;

            /** Linkeamos el nodoBTN como nuevo padre (hijo izquierdo el padre anterior e hijo derecho el hijo derecho anterior del padre) **/
            nodeBTN->left = nodeP;
            nodeBTN->right = aux;

            /** Linkeamos el nodo abuelo con el nuevo nodo padre **/
            if(nodeGP->left == nodeP)
            {
                nodeGP->left = nodeBTN;
            }
            else
            {
                nodeGP->right = nodeBTN;
            }
        }
        else if(nodeP->right == nodeBTN)
        {
            //Intercambiamos el nodo de la derecha (nodoBTN) con el padre
            /** Linkeamos los hijos del nodoBTN (solicitado) con el nodoP y guardamos en un aux el nodo derecho del padre **/
            aux = nodeP->left;
            nodeP->left = nodeBTN->left;
            nodeP->right = nodeBTN->right;

            /** Linkeamos el nodoBTN como nuevo padre (hijo izquierdo el padre anterior e hijo derecho el hijo derecho anterior del padre) **/
            nodeBTN->right = nodeP;
            nodeBTN->left = aux;

            /** Linkeamos el nodo abuelo con el nuevo nodo padre **/
            if(nodeGP->left == nodeP)
            {
                nodeGP->left = nodeBTN;
            }
            else
            {
                nodeGP->right = nodeBTN;
            }
        }
    }
}

btn *getNode(btn **ab, int value)
{
    btn *nodeBTN = NULL; //Declaro un nodo donde voy a guardar el nodo pedido

    _getNode(ab, &nodeBTN, value);//Obtengo el nodo que contiene el valor solicitado

    if(nodeBTN != NULL) //Si el nodo es distinto de NULL, quiere decir que está
    {
        btn *result = NULL; //Declaro un nodo result, donde voy a guardar el nodo de de la funcion _findparent
        btn *nodeP = _findParent(*ab, nodeBTN, &result); //Encuentra el nodo del padre de nodeBTN
        btn *nodeGP = _findParent(*ab, nodeP, &result); //Encuentra el nodo del abuelo de nodeBTN

        //Intercambio los nodos, si la raiz no es el padre
        _swapNode(ab, nodeBTN, nodeP, nodeGP);

    }
    else
    {
        printf("\nEl nodo no se encuentra en el arbol.\n");
    }

    return nodeBTN;
}
