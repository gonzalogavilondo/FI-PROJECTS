#include "Graphs.h"

graph *graphFrom2Graphs(graph *g, graph *h)
{
    graph *r = createGraph();

    for(int i = 0; i < graphSize(g); i++)
    {
        graphAddNewVertex(r, graphGetValueOf(g, i));
    }
    for(int i = 0; i < graphSize(h); i++)
    {
        graphAddNewVertex(r, graphGetValueOf(h, i));
    }

    int ii, jj;
    for(int i = 0; i < graphSize(r); i++)
    {
        for(int j = i; j < graphSize(r); j++)
        {
            ii = graphGetVertexIndex(g, graphGetValueOf(r, i));
            jj = graphGetVertexIndex(g, graphGetValueOf(r, j));
            if((ii != NONE) && (jj != NONE) && (graphExistArc(g, ii, jj) != 0))
            {
                graphSetDobleArc(r, i, j, graphCost(g, ii, jj));
            }
            ii = graphGetVertexIndex(h, graphGetValueOf(r, i));
            jj = graphGetVertexIndex(h, graphGetValueOf(r, j));
            if((ii != NONE) && (jj != NONE) && (graphExistArc(h, ii, jj) != 0))
            {
                graphSetDobleArc(r, i, j, graphCost(h, ii, jj));
            }
        }
    }
    return r;
}

