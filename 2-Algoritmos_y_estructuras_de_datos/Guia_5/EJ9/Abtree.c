#include "declaraciones.h"

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: Árbol binario.
 * BTN - binary tree node: nodo de árbol binario.
 * SBT - Search Binary Tree: ABB - Árbol binario de búsqueda.
 * AVL - AVL Tree: Árbol AVL.
 * root: nodo raíz del árbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un árbol.
 */

/**************************************************************/
/*                     ÁRBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un valor entero
 */

btn *createBTN(int value)
{
    btn *n = (btn *)malloc(sizeof(btn));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */

int isLeaf(btn *node)
{
    int result = 0;

    if(node == NULL)
    {
        result = 0;
    }
    else if(node->left == NULL && node->right == NULL)
    {
        result = 1;
    }

    return result;
}

/**
 * Cuenta la cantidad de nodos de un árbol binario.
 */

int countBTN(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = 1 + countBTN(node->left) + countBTN(node->right);
    }
    return result;
}

/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * Devuelve la altura de un BTN
 * Calcula la altura solo cuando el atributo heigth del nodo es -1.
 */

int height(btn *node)
{
    int result = -1;
    if (node != NULL)
    {
        result = _max(height(node->left), height(node->right)) +1;
    }
    return result;
}

/**
 * Agrega un nodo en un árbol binario con el siguiente criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */

int insertBTN(btn **node, btn *newNode)
{
    if (node == NULL) return 0;  // error
    if (newNode == NULL) return 1;

    int result = 0;
    if (*node == NULL)
    {
        *node = newNode;
        result = 1;
    }
    else
    {
        if((countBTN((*node)->left) - countBTN((*node)->right)) > 0)
        {
            result = insertBTN(&((*node)->right), newNode);
        }
        else
        {
            result = insertBTN(&((*node)->left), newNode);
        }
    }
    return result;
}

/**
 * Agrega un valor a un BT con el criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */

int insertValueBTN(btn **node, int value)
{
    btn *newNode = createBTN(value);
    int result = insertBTN(node, newNode);
    if (!result)
    {
        printf("Duplicado: %d\n\n", (*node)->value);
        free(newNode);
    }
    return result;
}

/**
 * Imprime los valores de un BT en inorden
 */

void inorder(btn *node)
{
    if(node != NULL)
    {
        inorder(node->left); //Atravieza el sub-arbol izquierdo
        printf("%d ", node->value); //Visita la raiz
        inorder(node->right); //Atraviesa el sub-arbol derecho
    }
}

/**
 * Imprime los valores de un BT en postorder
 */

void postorder(btn *node)
{
    if(node != NULL)
    {
        postorder(node->left); //Atraviesa el sub-arbol izquierdo
        postorder(node->right); //Atraviesa el sub-arbol derecho
        printf("%d ", node->value); //Visita la raiz
    }

}

/**
 * Imprime los valores de un BT en preorder
 */

void preorder(btn *node)
{
    if(node != NULL)
    {
        printf("%d ", node->value); //Visita la raiz
        preorder(node->left); //Atraviesa el sub-arbol izquierdo
        preorder(node->right); //Atraviesa el sub-arbol derecho
    }

}

/**************************************************************/
/*             ÁRBOLES BINARIOS DE BÚSQUEDA                   */
/**************************************************************/

/**
 * Agrega un nodo a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          *newNode: puntero al nodo que se va a insertar en el SBT
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */

int insertNodeSBT(btn **node, btn *newNode)
{
    if (node == NULL) return 0;
    if (newNode == NULL) return 1;
    if ((*node) == NULL)
    {
        *node = newNode;
        return 1;
    }
    else
    {
        if (newNode->value < (*node)->value)
        {
            // si el nuevo es menor inserta a izquierda
            return insertNodeSBT(&((*node)->left), newNode);
        }
        else if((newNode->value > (*node)->value))
        {
            // si el nuevo es mayor a la derecha
            return insertNodeSBT(&((*node)->right), newNode);
        }
        else
        {
            return 0;
        }
    }
}

/**
 * Agrega un valor a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          value: el valor a agregar.
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */

int insertValueSBT(btn **node, int value)
{
    btn *newNode = createBTN(value);
    int result = insertNodeSBT(node, newNode);
    if (!result)
    {
        printf("Duplicado: %d\n\n", (*node)->value);
        free(newNode);
    }
    return result;
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor mínimo de un
 * SBT.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn **getMinNodeSBT(btn **node)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    if (((*node)->left) != NULL)
    {
        return getMinNodeSBT(&(*node)->left);
    }
    else
    {
        return node;
    }
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor máximo de un
 * SBT.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */

btn **getMaxNodeSBT(btn **node)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    if (((*node)->right) != NULL)
    {
        return getMaxNodeSBT(&(*node)->right);
    }
    else
    {
        return node;
    }
}

/**
 * Devuelve el valor mínimo de un SBT
 */

int getMinValueSBT(btn *node)
{
    if (node == NULL) return -1;
    btn **r = getMinNodeSBT(&node);
    return (*r)->value;
}

/**
 * Devuelve el valor máximo de un SBT
 */

int getMaxValueSBT(btn *node)
{
    if (node == NULL) return -1;
    btn **r = getMaxNodeSBT(&node);
    return (*r)->value;
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor solicitado de
 * un SBT.
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar.
 */

btn **findNodeSBT(btn **node, int value)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return NULL;  // []->nodo

    if ((*node)->value == value)
    {
        return node;
    }
    else if ((*node)->value > value)
    {
        return findNodeSBT(&((*node)->left), value);
    }
    else
    {
        return findNodeSBT(&((*node)->right), value);
    }
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión recursiva)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */

btn *findSBTr(btn *node, int value)
{
    if(node == NULL || node->value == value)
    {
        return node;
    }
    else if(value < node->value)
    {
        return findSBTr(node->left, value);
    }
    else
    {
        return findSBTr(node->right, value);
    }

}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión iterativa)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */

btn *findSBTi(btn *node, int value)
{
    while ((node != NULL) && (node->value != value))
    {
        if (node->value > value)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return node;
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión iterativa en reducida)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */

btn *findSBTii(btn *node, int value)
{
    while ((node != NULL) && (node->value != value))
    {
        node = (node->value > value) ? node->left : node->right;
    }
    return node;
}

/**
 * Devuelve 1 si un valor se encuentra en el árbol, o 0 si no se encuentra
 */

int inSBT(btn *node, int value)
{
    node = findSBTr(node, value);
    return (node != NULL) ? 1 : 0;
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por su rama Derecha y agregando
 * la rama Izquierda a la rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */

btn *removeNodeSBT(btn **node)
{
    if(!node)
    {
        return NULL;
    }
    if(!(*node))
    {
        return NULL;
    }

    btn *aux = *node;
    insertNodeSBT(&(aux->right), aux->left); //A mi rama derecha, le voy a insertar mi rama izquierda
    *node = aux->right;
    aux->right = NULL;
    aux->left = NULL;

    return aux;
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por el máximo de su rama
 * izquierda, o en su defecto por el mínimo de su rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */

btn *removeNodeSBTRep(btn **node)
{
    btn *temp = NULL;

    if (!node) return NULL;
    if (!(*node)) return NULL;
    else if((*node)->left == NULL) // Un solo hijo, a la derecha
    {
        temp = *node;
        (*node) = (*node)->right; // Coloca el hijo de la derecha en lugar del nodo
        free(temp);
    }
    else if ((*node)->right == NULL) // Un solo hijo, a la izquierda
    {
        temp = *node;
        (*node) = (*node)->left; // Coloca hijo de la izquierda en lugar del nodo
        free(temp);
    }
    else if((*node)->left != NULL && (*node)->right!= NULL) // Dos hijos
    {
        temp = (*node)->right; // hijo de la derecha
        while (temp->left != NULL) // busca el menor valor del arbol a la derecha
        {
            temp = temp->left;
        }
        temp->left = (*node)->left; // Inserta sub-arbol de la izquierda
        temp = (*node);
        (*node) = (*node)->right; // Coloca nodo de la derecha en lugar del nodo
        free(temp);
    }

    return (*node);
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por
 * 1) el máximo de su rama izquierda, si la rama izquierda es igual o más alta
 * que la derecha.
 * 2) el mínimo de su rama derecha, si la rama derecha es más
 * alta que la izquierda.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */

btn *removeNodeSBTSmart(btn **node)
{
    if (!node) return NULL;
    if (!(*node)) return NULL;

    btn **aux;
    if((height((*node)->left) - height((*node)->right)) >= 0)
    {
        aux = getMaxNodeSBT(&((*node)->left));
    }
    else
    {
        aux = getMinNodeSBT(&((*node)->right));
    }

    btn *result = *node;         // Resguarda el nodo que será eliminado.
    *node = removeNodeSBT(aux);  // Reemplaza el nodo con el resultado de la
                                 // eliminación del auxiliar.
    if (*node != NULL)
    {
        // Si no era una hoja
        // Se vincula el nodo reemplazado con los hijos del auxiliar.
        (*node)->left = result->left;
        (*node)->right = result->right;
    }
    // Importante! se desvincula el auxiliar de sus hijos.
    result->left = NULL;
    result->right = NULL;
    return result;
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo por el hijo derecho.
 * Devuelve 1 si pudo eliminarlo,
 * Devuelve 0 si no pudo
 */

int removeValueSBT(btn **node, int value)
{
    btn *deleted = removeNodeSBT(findNodeSBT(node, value));
    int result = (deleted != NULL) ? 1 : 0;
    free(deleted);
    return result;
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * derecha. Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */

int removeValueSBTRep(btn **node, int value)
{
    btn *deleted = removeNodeSBTRep(findNodeSBT(node, value));
    int result = (deleted != NULL) ? 1 : 0;
    free(deleted);
    return result;
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * según cual sea más alto.
 * Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */

int removeValueSBTSmart(btn **node, int value)
{
    btn *deleted = removeNodeSBTSmart(findNodeSBT(node, value));
    int result = (deleted != NULL) ? 1 : 0;
    free(deleted);
    return result;
}

/**************************************************************/
/*                         ÁRBOLES AVL                        */
/**************************************************************/

/**
 * Devuelve el Factor de Equilibrio (o Factor de Balanceo) de un BTN
 */

int balanceFactor(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = height(node->left) - height(node->right);
    }
    return result;
}

/**
 * Realiza una rotación a izquierda sobre un nodo.
 * (el nodo debe tener un hijo a derecha).
 */

int leftRotation(btn **node)
{
    if (node == NULL)return 0;
    if (*node == NULL) return 0;
    if ((*node)->right == NULL) return 0;

    // imprimir la rotación (debe estar comentado)
    printf("\nRotacion a izquierda %d -> %d \n", (*node)->right->value, (*node)->value);

    btn *aux = (*node)->right;
    (*node)->right = aux->left;
    aux->left = *node;
    *node = aux;

    return 1;
}

/**
 * Realiza una rotación a derecha sobre un nodo.
 * (el nodo debe tener un hijo a la izquierda).
 */

int rightRotation(btn **node)
{
    if (node == NULL) return 0;
    if (*node == NULL) return 0;
    if ((*node)->left == NULL) return 0;

    // imprimir la rotación (debe estar comentado)
    printf("\nRotacion a derecha %d -> %d \n", (*node)->left->value, (*node)->value);

    btn *aux = (*node)->left;
    (*node)->left = aux->right;
    aux->right = *node;
    *node = aux;

    return 1;
}

/**
 * Devuelve 1 si verifica que el nodo es raíz de un subárbol AVL.
 * Devuelve 0 si no lo es.
 */

int isAVL(btn *node)
{
    if (node == NULL) return 1;

    if (abs(balanceFactor(node)) < 2)
    {
        if (isAVL(node->left))
        {
            return isAVL(node->right);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

/**
 * Balancea nodo de un árbol AVL.
 */

int balance(btn **node)
{
    if(node == NULL)
    {
        return 0;
    }
    if(*node == NULL)
    {
        return 0;
    }

    int bf = balanceFactor(*node);

    if(bf <= -2)
    {
        if(balanceFactor((*node)->right) > 0)
        {
            rightRotation(&((*node)->right));
        }
        leftRotation(node);
    }
    else if(bf >= 2)
    {
        if(balanceFactor((*node)->left) < 0)
        {
            leftRotation(&((*node)->left));
        }
        rightRotation(node);
    }
    if(abs(balanceFactor(*node)) > 1)
    {
        balance(node);
    }

    return 1;
}

/**
 * Balancea un SBT convirtiéndolo en un árbol AVL.
 */

int balanceTree(btn **node)
{
    if(node == NULL)
    {
        return 0;
    }
    if (*node == NULL)
    {
        return 0;
    }
    balanceTree(&((*node)->left));
    balanceTree(&((*node)->right));
    balance(node);
    if(!isAVL(*node))
    {
        balanceTree(node);
    }
    return 1;
}

/**
 * Inserta un Nodo en un AVL
 * Esta es una versión simplificada que utiliza la función de
 * inserción de un SBT y luego balancea todo el árbol.
 * Notar que al intentar balancear todo el árbol recorre todos
 * los nodos.
 */

int insertNodeAVLSimple(btn **node, btn *newNode)
{
    int result = insertNodeSBT(node, newNode);
    if(!result)
    {
        printf("Duplicado: %d\n\n", newNode->value);
        free(newNode);
    }
    //Esto es lo que cambia con respecto a la insercion normal.La diferencia es que va balanceando el arbol a medida que inserta valores.
    else
    {
        balanceTree(node); //Balancea todo el arbol mientras va insertando cada nodo.
    }
    return result;
}

/**
 * Inserta un Nodo en un AVL
 */

int insertNodeAVL(btn **node, btn *newNode)
{
    if (node == NULL) return 0;
    if (newNode == NULL) return 1;
    if ((*node) == NULL)
    {
        *node = newNode;
        return 1;
    }
    else
    {
        if (newNode->value < (*node)->value)
        {
            // Si el nuevo es menor, inserta a izquierda
            if(insertNodeAVL(&((*node)->left), newNode))
            {
                balance(node); //Si inserto por esta rama
                //Se pudo haber producido un desbalance
                return 1;
            }
        }
        else if((newNode->value > (*node)->value))
        {
            // Si el nuevo es mayor, inserta a la derecha
            if(insertNodeAVL(&((*node)->right), newNode))
            {
                balance(node); //Si inserto por esta rama
                //Se pudo haber producido un desbalance
                return 1;
            }
        }
        else
        {
            return 0;
        }
        return 0;
    }
}

/**
 * Inserta un Valor en un AVL
 */

int insertValueAVL(btn **node, int value)
{
    btn *newNode = createBTN(value);
    int result = insertNodeAVL(node, newNode);
    if (!result)
    {
        free(newNode);
    }
    return result;
}

/**
 * Elimina un Nodo de un AVL
 */

btn *removeNodeAVL(btn **node)
{
    btn *result = removeNodeSBTSmart(node);
    if (result != NULL)
    {
        balanceTree(node);
    }
    return result;
}

/**
 * Elimina un Valor de un AVL
 */

int removeValueAVL(btn **node, int value)
{
    int result = removeValueSBTSmart(node, value);
    if (result)
    {
        balanceTree(node);
    }
    return result;
}


/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un árbol.
 */

int _printBTN(btn *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[200];
    int width = 5;

    if (!tree) return 0;
    // sprintf(b, "(%03d)", tree->value);
     sprintf(b, "(%03d)bf:%d ", tree->value, balanceFactor(tree));
    // sprintf(b, "(%03d)bf:%d h:%d", tree->value, balanceFactor(tree),
    // height(tree));

    int left = _printBTN(tree->left, 1, offset, depth + 1, s);
    int right = _printBTN(tree->right, 0, offset + left + width, depth + 1, s);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++)
    {
        s[2 * depth][offset + left + i] = b[i];
    }

    if (depth && is_left)
    {
        for (int i = 0; i < width + right; i++)
        {
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';
        }

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    }
    else if (depth && !is_left)
    {
        for (int i = 0; i < left + width; i++)
        {
            s[2 * depth - 1][offset - width / 2 + i] = '-';
        }

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los valores de los nodos deben estar entre 0 y 999).
 */

void printBTN(btn *tree)
{
    char s[20][255];
    for (int i = 0; i < height(tree)*3; i++)
    {
        sprintf(s[i], "%80s", " ");
    }
    _printBTN(tree, 0, 0, 0, s);

    puts("\n");
    for (int i = 0; i < height(tree)*3; i++)
    {
        printf("%s\n", s[i]);
    }
}

void insertValues(btn **root, int values[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("\nAgregando: %d\n", values[i]);
        if(!insertValueAVL(root, values[i]))
        {
            printf("Error al insertar: %d \n", values[i]);
        }
        else
        {
            puts("\n");
            printBTN(*root); //Con este print vemos como se va armando el arbol.
        }
    }
}
