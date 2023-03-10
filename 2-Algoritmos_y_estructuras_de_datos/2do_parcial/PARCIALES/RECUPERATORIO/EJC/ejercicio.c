#include "Graphs.h"

int grafoIncluidoenOtro(graph *g, graph *h)
{
    if(!isDigraph(g)) return 0;
    if(!isDigraph(h)) return 0;

    //Siendo g el grafo original y h el grafo que debe estar incluido.
    int result = 1;
    int vertex = 1; //Variable para controlar si son iguales los vertices
    int arco = 1;  //Variable para controlar que haya un arco en ambos grafos entre los mismos vertices
    listStr *l = NULL;

    while(vertex == 1 && arco == 1)
    {

        for(int i = 0; i < graphSize(h); i++)
        {
            while(vertex != 0)
            {
                listStrAdd(&l, graphGetValueOf(g, i)); //Guardo en una lista el valor de cada vertice del grafo original

                if (listStrGetValue(l) != graphGetValueOf(h, i)) //Comparo el valor de la lista con el valor del vertice del grafo h
                {
                    vertex = 0;
                }
                listStrGetNext(l);
            }

        }
        int ii, jj;

        for(int i = 0; i < graphSize(h); i++)
        {
            for(int j = 0; j < graphSize(h); j++) //Como es un Digrafo tengo que recorrerlo todo.
            {
                while(arco != 0)
                {
                    ii = graphGetVertexIndex(g, graphGetValueOf(h, i));
                    jj = graphGetVertexIndex(g, graphGetValueOf(h, j));
                    if((ii != NONE) && (jj != NONE) && (graphExistArc(g, ii, jj) != 0) && (graphExistArc(h, i, j) != 0))
                    {
                        arco = 1;
                    }
                    else
                    {
                        arco = 0;
                    }
                }
            }
        }
        if(vertex == 0 || arco == 0)
        {
            result = 0;
        }
    }

    return result;
}

