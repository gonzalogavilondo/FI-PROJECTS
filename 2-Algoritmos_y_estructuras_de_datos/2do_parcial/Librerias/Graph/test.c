#include "test.h"

//ejemplo filminas profe grafos A
graph *ejemploGrafo()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "Madrid");  //0
    graphAddNewVertex(g, "Londres"); //1
    graphAddNewVertex(g, "Paris");   //2
    graphAddNewVertex(g, "Zurich");  //3
    graphAddNewVertex(g, "Berlin");  //4
    graphAddNewVertex(g, "Roma");    //5
    graphSetArc(g, 0, 1, 28);
    graphSetArc(g, 1, 0, 28);
    graphSetArc(g, 0, 2, 14);
    graphSetArc(g, 2, 0, 14);
    graphSetArc(g, 0, 5, 65);
    graphSetArc(g, 5, 0, 65);
    graphSetArc(g, 1, 2, 10);
    graphSetArc(g, 2, 1, 10);
    graphSetArc(g, 2, 4, 36);
    graphSetArc(g, 4, 2, 36);
    graphSetArc(g, 1, 4, 14);
    graphSetArc(g, 4, 1, 14);
    graphSetArc(g, 2, 3, 12);
    graphSetArc(g, 3, 2, 12);
    graphSetArc(g, 4, 5, 24);
    graphSetArc(g, 5, 4, 24);

    return g;
}

//ejemplo filminas profe grafos B
graph *ejemploDiGrafoA()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4
    graphSetArc(g, 0, 1, 17);
    graphSetArc(g, 0, 2, 15);
    graphSetArc(g, 0, 3, 12);
    graphSetArc(g, 1, 1, 9);
    graphSetArc(g, 1, 3, 21);
    graphSetArc(g, 2, 3, 10);
    graphSetArc(g, 2, 4, 8);
    graphSetArc(g, 3, 4, 22);
    graphSetArc(g, 4, 0, 25);

    return g;
}

//ejemplo filminas agustina
graph *ejemploDiGrafoB()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4
    graphSetArc(g, 0, 1, 1);
    graphSetArc(g, 0, 2, 2);
    graphSetArc(g, 1, 3, 3);
    graphSetArc(g, 2, 3, 4);
    graphSetArc(g, 3, 2, 5);
    graphSetArc(g, 3, 4, 6);
    graphSetArc(g, 4, 3, 7);

    return g;
}

//ejemplo filminas agustina
graph *ejemploDiGrafoC()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphSetArc(g, 0, 0, 1);
    graphSetArc(g, 0, 1, 2);
    graphSetArc(g, 1, 0, 3);
    graphSetArc(g, 1, 2, 4);

    return g;
}

//ejemplo filminas agustina
graph *ejemploOrientedGraphA()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4
    graphAddNewVertex(g, "F"); //5
    graphSetArc(g, 0, 1, 1);
    graphSetArc(g, 1, 2, 2);
    graphSetArc(g, 2, 4, 3);
    graphSetArc(g, 3, 1, 4);
    graphSetArc(g, 4, 3, 5);
    graphSetArc(g, 4, 5, 6);

    return g;
}

graph *ejemploOrientedGraphB()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphSetArc(g, 0, 1, 2);
    graphSetArc(g, 1, 2, 4);

    return g;
}

//ejemplo filminas agustina
graph *ejemploConvexGraph()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4
    graphSetDobleArc(g, 0, 1, 1);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 0, 4, 3);
    graphSetDobleArc(g, 1, 3, 4);
    graphSetDobleArc(g, 1, 4, 5);
    graphSetDobleArc(g, 2, 3, 6);
    graphSetDobleArc(g, 3, 4, 7);
    return g;
}

//ejemplo filminas agustina
graph *ejemploNotConvexGraph(){
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4

    graphSetDobleArc(g, 0, 1, 1);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 1, 2, 3);

    graphSetDobleArc(g, 3, 4, 5);

    return g;
}

//ejemplo filminas agustina
graph *ejemploCompleteGraph()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4

    graphSetDobleArc(g, 0, 1, 1);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 0, 3, 3);
    graphSetDobleArc(g, 0, 4, 5);

    graphSetDobleArc(g, 0, 1, 1);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 0, 2, 3);
    graphSetDobleArc(g, 0, 4, 5);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 0, 2, 3);
    graphSetDobleArc(g, 0, 4, 5);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 0, 2, 3);
    graphSetDobleArc(g, 0, 4, 5);
    return g;
}

//ejemplo filminas agustina
graph *ejemploGrafoBipartito()
{
    graph *bp = createGraph();
    graphAddNewVertex(bp, "A"); //0
    graphAddNewVertex(bp, "B"); //1
    graphAddNewVertex(bp, "C"); //2
    graphAddNewVertex(bp, "D"); //3
    graphAddNewVertex(bp, "E"); //4
    graphAddNewVertex(bp, "F"); //5
    graphAddNewVertex(bp, "G"); //6

    //A-(DEFG)
    graphSetDobleArc(bp, 0, 3, 1);
    graphSetDobleArc(bp, 0, 4, 2);
    graphSetDobleArc(bp, 0, 5, 3);
    graphSetDobleArc(bp, 0, 6, 4);

    //B-(DEFG)
    graphSetDobleArc(bp, 1, 3, 5);
    graphSetDobleArc(bp, 1, 4, 6);
    graphSetDobleArc(bp, 1, 5, 7);
    graphSetDobleArc(bp, 1, 6, 8);

    //C-(DEFG)
    graphSetDobleArc(bp, 2, 3, 9);
    graphSetDobleArc(bp, 2, 4, 10);
    graphSetDobleArc(bp, 2, 5, 11);
    graphSetDobleArc(bp, 2, 6, 12);

    return bp;
}

//ejemplo filminas agustina (no dirigido)
graph *ejemploCompleteGraphA()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2
    graphAddNewVertex(g, "D"); //3
    graphAddNewVertex(g, "E"); //4

    graphSetDobleArc(g, 0, 1, 1);
    graphSetDobleArc(g, 0, 2, 2);
    graphSetDobleArc(g, 0, 3, 3);
    graphSetDobleArc(g, 0, 4, 4);

    graphSetDobleArc(g, 1, 2, 5);
    graphSetDobleArc(g, 1, 3, 6);
    graphSetDobleArc(g, 1, 4, 7);

    graphSetDobleArc(g, 2, 4, 8);
    graphSetDobleArc(g, 2, 3, 9);

    graphSetDobleArc(g, 3, 4, 10);
    return g;
}

//ejemplo filminas agustina (dirigido)
graph *ejemploCompleteGraphB()
{
    graph *g = createGraph();
    graphAddNewVertex(g, "A"); //0
    graphAddNewVertex(g, "B"); //1
    graphAddNewVertex(g, "C"); //2

    graphSetArc(g, 0, 1, 1);
    graphSetArc(g, 0, 2, 2);

    graphSetArc(g, 1, 0, 3);
    graphSetArc(g, 1, 2, 4);

    graphSetArc(g, 2, 0, 5);
    graphSetArc(g, 2, 1, 6);

    return g;
}

graph *ejemploCrearLista()
{
    graph *g = createGraph();
    ntn *root = NULL;
    sample(&root);
    printf("ARBOL N ARIO \n\n");
    printNTN(root);
    ntq *q = crearLista(root, 3);
    puts("\n");
    printQueueNTN(q);

    return g;
}

void ejemploGrafoDesdeArbol(graph *g)
{
    ntq *q = createQueueNTN();
    ntq *aux = createQueueNTN();
    graphPrint(g);
    puts("\n");

    //Armo los arboles de cobertura y voy poniendo los nodos en la cola o lista.
    for(int i = 0; i < 5; i++)
    {
        ntn *root = graphDFTree(g, i);
        enqueueNTN(q, root);
        enqueueNTN(aux, root);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ARBOL DE COBERTURA: \n\n", i+1);
        printNTN(dequeueNTN(aux));
        puts("\n");
    }

    puts("\n");
    printf("GRAFO RESULTANTE:\n\n");
    graph *fnt = graphFromNtree(q);
    graphPrint(fnt);

}
