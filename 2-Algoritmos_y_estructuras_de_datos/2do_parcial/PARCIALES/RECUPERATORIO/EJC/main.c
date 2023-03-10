#include "Graphs.h"
#include "test.h"

/**
    Saber si un grafo dirigido y ponderado está incluido en otro.
     Teniendo en cuenta que los nombres de los vértices pueden estar en índices diferentes
    y que deben coincidir las aristas.

**/
int main()
{
    graph *g = ejemploDiGrafoA();
    graph *h = ejemploDiGrafoA();

    printf("Grafo 1: \n\n");
    graphPrint(g);
    puts("\n\n");
    printf("Grafo 2: \n\n");
    graphPrint(h);

    int resultado = grafoIncluidoenOtro(g, h);
    if(resultado == 1)
    {
        printf("El segundo grafo esta incluido en el primero.\n");
    }
    else
    {
        printf("El segundo grafo no esta incluido en el primero.\n");
    }

    return 0;
}
