#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct btNode btn;
typedef struct btNode
{
    int value;
    btn *left;
    btn *right;

} btn;

/************* FUNCIONES ÁRBOLES BINARIOS**************/

btn *createBTN(int value);
int isLeaf(btn *node);
int countBTN(btn *node);
int _max(int a, int b);
int height(btn *node);
int insertBTN(btn **node, btn *newNode);
int insertValueBTN(btn **node, int value);
void inorder(btn *node);
void postorder(btn *node);
void preorder(btn *node);

/*********** FUNCIONES ÁRBOLES BINARIOS DE BÚSQUEDA ***********/

int insertNodeSBT(btn **node, btn *newNode);
int insertValueSBT(btn **node, int value);
btn **getMinNodeSBT(btn **node);
btn **getMaxNodeSBT(btn **node);
int getMinValueSBT(btn *node);
int getMaxValueSBT(btn *node);
btn **findNodeSBT(btn **node, int value);
btn *findSBTr(btn *node, int value);
btn *findSBTi(btn *node, int value);
btn *findSBTii(btn *node, int value);
int inSBT(btn *node, int value);
btn *removeNodeSBT(btn **node);
btn *removeNodeSBTRep(btn **node);
btn *removeNodeSBTSmart(btn **node);
int removeValueSBT(btn **node, int value);
int removeValueSBTRep(btn **node, int value);
int removeValueSBTSmart(btn **node, int value);

/******************** FUNCIONES ÁRBOLES AVL *********************/

int balanceFactor(btn *node);
int leftRotation(btn **node);
int rightRotation(btn **node);
int isAVL(btn *node);
int balance(btn **node);
int balanceTree(btn **node);
int insertNodeAVLSimple(btn **node, btn *newNode);
int insertNodeAVL(btn **node, btn *newNode);
int insertValueAVL(btn **node, int value);
btn *removeNodeAVL(btn **node);
int removeValueAVL(btn **node, int value);

/******************** ADICIONALES *************************/

void printBTN(btn *tree);
int _printBTN(btn *tree, int is_left, int offset, int depth, char s[20][255]);

/******************* EJERCICIO ACTUAL *********************/

void insertValuesAVL(btn **root, int values[], int count);
void insertValuesBB(btn **root, int values[], int count);

#endif // DECLARACIONES_H_INCLUDED
