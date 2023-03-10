#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>

typedef struct btn
{
    int valor;
    struct btn *izq;
    struct btn *der;

}btn;

btn *crearNodoArbol(int dato); //Crear nodo
btn *borrarAVL (btn **nodo, int valor);
btn *borrarNodo(btn **nodo);
btn **buscarPtr(int valor, btn **nodo);
int insert(btn **arbol, btn *nuevo);
void insertar_datos(btn **arbol, int valor);
void preorder(btn *arbol);  //Raiz al principio
void inorder(btn *arbol);   //Raiz en el medio
void postorder(btn *arbol); //Raiz al final
int altura(btn *nodo);
int max(int a, int b);
int balanceFactor(btn *node);
int isAVL(btn *node);
void verificar_AVL(int avl, int n);
int rotar_a_derecha(btn **nodo);
int rotar_a_izquierda(btn **nodo);
int balancear(btn **nodo);
int balancearArbol(btn **nodo);
void print_t(btn *tree);
int _print_t(btn *tree, int is_left, int offset, int depth, char s[20][255]);


#endif // DECLARACIONES_H_INCLUDED
