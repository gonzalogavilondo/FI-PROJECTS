#ifndef GRAPHS_H_INCLUDED
#define GRAPHS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lists.h"
#include "Antree.h"

#define MAX 12
#define INF 9999
#define NONE 9999
#define ECG -1  //error code lists

typedef struct Graph graph;
typedef struct GraphVertex vertex;
typedef struct VertexLink vlink;  //Vinculos entre nodos (predecesor y costo)

typedef struct VertexLink
{
    int pred[MAX];
    int cost[MAX];
    int count;

} vlink;

typedef struct GraphVertex
{
    int index;
    char *value;

} vertex;

typedef struct Graph
{
    vertex *V[MAX];   // vertices list
    int A[MAX][MAX];  // adjacency matrix
    int size;         // cantidad de vértices

} graph;

typedef struct FloydRes fres;
typedef struct FloydRes
{
 int D[MAX][MAX];
 int C[MAX][MAX];
 int count;

} fres;


/**************** OPERACIONES BASICAS DE GRAFOS ******************/
vertex *createVertex(char *value); //Crea un vertice y lo devuelve
graph *createGraph(); //Crea un grafo
int graphSize(graph *g); //Tamaño del grafo
int graphAddVertex(graph *g, vertex *v); //Agrega un vertice (Una nueva fila y columna en la matriz de adyacencias)
int graphAddNewVertex(graph *g, char *value); //Agrega ese nuevo vertice al grafo, devolviendo el indice de ese vertice
int graphDelVertex(graph *g, int indexVertex);//Elimina un vertice del grafo
int isAdjVertex(graph *g, int indexV1, int indexV2); //Determinar si un vertice es adyacente de otro
list *listAdjVertex(graph *g, int indexV);//Lista de vertices adyacentes
int graphSetArc(graph *g, int fromVertex, int toVertex, int cost); //Insertar una arista (arco)
int graphSetDobleArc(graph *g, int fromVertex, int toVertex, int cost); //Inserta una arista en las dos direcciones
int graphDelArc(graph *g, int fromVertex, int toVertex); //Borrar una arista (arco)
int graphExistArc(graph *g, int fromVertex, int toVertex); //Determinar si existe un arco
int graphCost(graph *g, int from, int to);
void graphPrint(graph *g); //Impresion de un grafo
int graphValideIndex(graph *g, int index);
char *graphGetValueOf(graph *g, int index);
int graphGetVertexIndex(graph *g, char *value);


/**************** CLASIFICACIONES DE GRAFOS ******************/
int numberOfArcs(graph *g, int indexV); //Cantidad de aristas de un vertice.
int isEmptyGraph(graph *g);
int isDigraph(graph *g); //Saber si el grafo es digrafo.
int isConvexGraph(graph *g); //Saber si es un grafo conexo
int isGraphEulerian(graph *g); //Saber si es un grafo eureliano.
int isOrientedGraph(graph *g); //Saber si es un grafo orientado.
int isCompletedGraph(graph *g); //Saber si es un grafo completo.
void _isBipartiteGraph(graph *g, int vertex, int visited[], int a[], int b[]);
int isBipartiteGraph(graph *g, int from);
int isSimpleGraph(graph *g); //Saber si es un grafo simple.
void eulerianCycle(graph *g); //Ciclo eureliano


/************************ ALGORITMO DE DIJSTRA ************************/
vlink dijstra(graph *g, int origin);
int getCost (vlink d, int to); //Obtiene el costo
void printD (graph *g, vlink d, int next, int step, int visited[]); //Imprime la matriz de resultados
void _printWay (graph *g, vlink d, int from, int to); //Funcion interna para imprimir el camino o recorrido utilizando el algoritmo de dijstra.
void printWay (graph *g, vlink d, int from, int to); //Imprime el camino o recorrido utilizando el algoritmo de dijstra.


/************************ RECORRIDOS DE GRAFOS ************************/
void graphBFP (graph *g, int from); //Recorrido en amplitud (Anchura)
void graphDFP (graph *g, int from); //Recorrido en profundidad

/************************ ARBOL DE COBERTURA ************************/
ntn *graphBFTree (graph *g, int from); //Arbol de cobertura en amplitud
void _graphDFTree (graph *g, ntn *root, int parent, int vertex, int visited[]); //Funcion interna de Arbol de cobertura en profundidad
ntn *graphDFTree (graph *g, int from); //Arbol de cobertura en profundidad
graph *kruskal(graph *g); //Algoritmo de kruskal, arbol de cobertura de coste minimo

/************************ EJERCICIOS DE EJEMPLO ************************/
graph *graphFromNtree(ntq *q);
ntq *insertTreeInQueue(ntq *q, ntn *root);

/************************ EJERCICIO ************************/
graph *graphFrom2Graphs(graph *g1, graph *g2);
void _graphFrom2Graphs(graph *g, ntn *node);

#endif // GRAPHS_H_INCLUDED
