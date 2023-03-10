#include "declaraciones.h"

btn *crearNodoArbol(int dato)
{
    //Declaramos
    btn *aux;

    //Reservamos memoria
    aux = (btn*)malloc(sizeof(btn));

    //Seteamos valores
    aux->valor = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

int insert(btn **arbol, btn *nuevo)
{
    if(arbol == NULL)
    {
        return 0;
    }
    if(nuevo == NULL)
    {
        return 1;
    }
    if((*arbol) == NULL)
    {
        *(arbol) = nuevo;
        return 1;
    }
    else
    {
        if(nuevo->valor < (*arbol)->valor) //Si el nuevo dato es menor, se inserta a la izquierda
        {
            return insert(&((*arbol)->izq), nuevo);
        }
        else if(nuevo->valor > (*arbol)->valor) //Si el nuevo dato es mayor, se inserta a la derecha
        {
            return insert(&((*arbol)->der), nuevo);
        }
        else
        {
            return 0;
        }
    }
}

void insertar_datos(btn **arbol, int valor)
{
    btn *nuevo = crearNodoArbol(valor);
    if(!insert(arbol, nuevo))
    {
        printf("Duplicado: %d\n\n", nuevo->valor);
        free(nuevo);
    }
    //Esto es lo que cambia con respecto a la insercion normal.
    else
    {
        printf("Insert: %d \n", nuevo->valor);
        balancearArbol(arbol);
        //puts("\n");
        //print_t(*arbol); //Aca se puede ver como va insertando valores y cuando esta desbalanceado como va rotando los nodos
    }
}

void preorder(btn *arbol)
{
    if(arbol != NULL)
    {
        printf("%d ", arbol->valor); //Visita la raiz
        preorder(arbol->izq); //Atraviesa el sub-arbol izquierdo
        preorder(arbol->der); //Atraviesa el sub-arbol derecho
    }
}

void inorder(btn *arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq); //Atravieza el sub-arbol izquierdo
        printf("%d ", arbol->valor); //Visita la raiz
        inorder(arbol->der); //Atraviesa el sub-arbol derecho
    }
}

void postorder(btn *arbol)
{
    if(arbol != NULL)
    {
        postorder(arbol->izq); //Atraviesa el sub-arbol izquierdo
        postorder(arbol->der); //Atraviesa el sub-arbol derecho
        printf("%d ", arbol->valor); //Visita la raiz
    }
}

int altura(btn *nodo)
{
    int resultado = -1;
    if (nodo != NULL)
    {
        resultado = max(altura(nodo->izq), altura(nodo->der)) +1;
    }
    return resultado;
}

int max(int a, int b)
{
    return(a > b)? a:b;
}

int balanceFactor(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = altura(node->izq) - altura(node->der);
    }
    return result;
}

int isAVL(btn *nodo)
{
    if(nodo == NULL)
    {
        return 1;
    }
    if(abs(balanceFactor(nodo)) < 2)
    {
        if(isAVL(nodo->izq))
        {
            return isAVL(nodo->der);
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

void verificar_AVL(int avl, int n)
{
    if(avl == 1)
    {
        printf("El arbol %d es AVL\n\n", n);
    }
    else
    {
        printf("El arbol %d no es AVL\n\n", n);
    }
}

int rotar_a_derecha(btn **nodo)
{
    if(nodo == NULL)
    {
        return 0;
    }
    if(*nodo == NULL)
    {
        return 0;
    }
    if((*nodo)->izq == NULL)
    {
        return 0;
    }

    printf("Rot a der: %d -> %d \n", (*nodo)->izq->valor, (*nodo)->valor);

    //Rotamos, es como el metodo de la burbuja para hacer un intercambio de variables pero con punteros.
    btn *aux = (*nodo)->izq;
    (*nodo)->izq = aux->der;
    aux->der = *nodo;
    *nodo = aux;

    return 1;
}

int rotar_a_izquierda(btn **nodo)
{
    if(nodo == NULL)
    {
        return 0;
    }
    if(*nodo == NULL)
    {
        return 0;
    }
    if((*nodo)->der == NULL)
    {
        return 0;
    }

    printf("Rot a izq: %d -> %d \n", (*nodo)->valor, (*nodo)->der->valor);

    //Rotamos, es como el metodo de la burbuja para hacer un intercambio de variables pero con punteros.
    btn *aux = (*nodo)->der;
    (*nodo)->der = aux->izq;
    aux->izq = *nodo;
    *nodo = aux;

    return 1;
}

int balancear(btn **nodo)
{
    if(nodo == NULL)
    {
        return 0;
    }
    if(*nodo == NULL)
    {
        return 0;
    }

    int bf = balanceFactor(*nodo);

    if(bf <= -2)
    {
        if(balanceFactor((*nodo)->der) > 0)
        {
            rotar_a_derecha(&((*nodo)->der));
        }
        rotar_a_izquierda(nodo);
    }
     else if(bf >= 2)
    {
        if(balanceFactor((*nodo)->izq) < 0)
        {
            rotar_a_izquierda(&((*nodo)->izq));
        }
        rotar_a_derecha(nodo);
    }
    if(abs(balanceFactor(*nodo)) > 1)
    {
        balancear(nodo);
    }

    return 1;
}

int balancearArbol(btn **nodo)
{
    if(nodo == NULL)
    {
        return 0;
    }
    if (*nodo == NULL)
    {
        return 0;
    }
    balancearArbol(&((*nodo)->izq));
    balancearArbol(&((*nodo)->der));
    balancear(nodo);
    if(!isAVL(*nodo))
    {
        balancearArbol(nodo);
    }
    return 1;
}

btn *borrarAVL (btn **nodo, int valor)
{
    btn *eliminado = NULL;
    btn **eliminar = NULL;

    eliminar = buscarPtr(valor, nodo);
    eliminado = borrarNodo(eliminar);

    if(eliminado != NULL)
    {
        balancearArbol(nodo);
    }
    return eliminado; //Devuelvo el nodo eliminado.
 }

btn *borrarNodo(btn **nodo)
{
    if(!nodo)
    {
        return NULL;
    }
    if(!(*nodo))
    {
        return NULL;
    }

    btn *aux = *nodo;
    insert(&(aux->der), aux->izq); //A mi rama derecha, le voy a insertar mi rama izquierda
    *nodo = aux->der;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

btn **buscarPtr(int valor, btn **nodo)
{
    if(nodo == NULL) //[]->[]->nodo
    {
        return NULL;
    }
    if((*nodo) == NULL) //[]->nodo
    {
        return NULL;
    }
    if((*nodo)->valor == valor)
    {
        return nodo;
    }
    else if(valor < (*nodo)->valor)
    {
        return buscarPtr(valor, &((*nodo)->izq));
    }
    else
    {
        return buscarPtr(valor, &((*nodo)->der));
    }
}

int _print_t(btn *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if(!tree)
    {
        return 0;
    }
    sprintf(b, "(%03d)", tree->valor);
    //sprintf(b, "(%03d)bf:%d ", tree->valor, balanceFactor(tree)); //Si quiero ver el factor de balanceo tambien
    //sprintf(b, "(%03d)bf:%dh:%d ", tree->valor, balanceFactor(tree), altura(tree)); //Si quiero ver ademas la altura.

    int izq  = _print_t(tree->izq,  1, offset, depth + 1, s);
    int der = _print_t(tree->der, 0, offset + izq + width, depth + 1, s);

    for(int i = 0; i < strlen(b); i++)
    {
        s[2 * depth][offset + izq + i] = b[i];
    }
    if(depth && is_left)
    {

        for(int i = 0; i < width + der; i++)
        {
            s[2 * depth - 1][offset + izq + width/2 + i] = '-';
        }
        s[2 * depth - 1][offset + izq + width/2] = '+';
        s[2 * depth - 1][offset + izq + width + der + width/2] = '+';

    }
    else if(depth && !is_left)
    {
        for(int i = 0; i < izq + width; i++)
        {
            s[2 * depth - 1][offset - width/2 + i] = '-';
        }
        s[2 * depth - 1][offset + izq + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
    return izq + width + der;
}

void print_t(btn *tree)
{
    char s[20][255];
    for (int i = 0; i < altura(tree)*3; i++)
    {
        sprintf(s[i], "%80s", " ");
    }
    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < altura(tree)*3; i++)
    {
        printf("%s\n", s[i]);
    }
}
