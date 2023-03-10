#include "Graphs.h"
#include "test.h"

/**
    Crear un nuevo grafo a partir de otros 2 grafos, teniendo en cuenta los nombres (o
    claves) de los vértices.

**/
int main()
{
    graph *g = ejemploGrafo();
    graph *h = ejemploConvexGraph();

    printf("Grafo 1: \n\n");
    graphPrint(g);
    puts("\n\n");
    printf("Grafo 2: \n\n");
    graphPrint(h);

    graph *r = graphFrom2Graphs(g, h);
    puts("\n\n");
    printf("Grafo resultante: \n\n");
    graphPrint(r);

    return 0;
}
