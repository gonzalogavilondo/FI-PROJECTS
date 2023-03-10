#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct btn
{
    int valor;
    struct btn *izq;
    struct btn *der;

}btn;

btn *crearNodoArbol(int dato); //Crear nodo
int insert(btn **arbol, btn *nuevo);
void insertar_datos(btn **arbol, int valor);
void preorder(btn *arbol);  //Raiz al principio
void inorder(btn *arbol);   //Raiz en el medio
void postorder(btn *arbol); //Raiz al final
void print_t(btn *tree);
int _print_t(btn *tree, int is_left, int offset, int depth, char s[20][255]);
int max(int a, int b);
int altura(btn *nodo);


#endif // DECLARACIONES_H_INCLUDED
