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

//Nota: Como vemos, preorder, inorder y postorder hacen referencia a donde se ubica la raiz.

void cantidad_nodos(btn *arbol, int *cnt_nodos)
{
    if(arbol != NULL)
    {
        (*cnt_nodos)++;
        cantidad_nodos(arbol->izq, cnt_nodos);
        cantidad_nodos(arbol->der, cnt_nodos);
    }
}

int suma_nodos(btn *arbol)
{
    if(arbol == NULL)
    {
        return 0;
    }
    return(arbol->valor + suma_nodos(arbol->izq) + suma_nodos(arbol->der));
}

int profundidad_arbol(btn *arbol)
{
    if(arbol == NULL)
    {
        return 0;
    }
    else
    {
        //Calculamos la profundidad de cada subarbol
        int profundidad_der = profundidad_arbol(arbol->der);
        int profundidad_izq = profundidad_arbol(arbol->izq);

        //Usamos el mas grande
        if(profundidad_der > profundidad_izq)
        {
            return (profundidad_der + 1);
        }
        else
        {
            return (profundidad_izq + 1);
        }
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
