#include "Graphs.h"

/**************** OPERACIONES BASICAS DE GRAFOS ******************/

/**
    Crea un vertice y lo devuelve.
**/

vertex *createVertex(char *value)
{
    vertex *v = (vertex *)malloc(sizeof(vertex));
    v->index = -1;  // No tiene valor hasta que no sea asignado a un grafo
    v->value = value;

    return v;
}

/**
    Crea un grafo y lo devuelve con tamaño 0.
**/

graph *createGraph()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->size = 0;
    return g;
}

/**
    Devuelve el tamaño de un grafo.
**/

int graphSize(graph *g)
{
    return g->size;
}

/**
    Agrega el indice del vertice, luego agrega ese vertice al grafo y devuelve el indice del vertice en el grafo
    De haber un grafo nulo o de estar lleno el grafo, devuelve -1(error)
**/

int graphAddVertex(graph *g, vertex *v)
{
    if (!g) return -1;  // g==NULL
    if (!v) return -1;  // v==NULL

    int result = -1;
    if ((graphSize(g) + 1) < MAX)
    {
        v->index = graphSize(g); //El indice del vertice es el tamaño del grafo en ese momento.
        g->V[g->size++] = v; //Agrega al grafo el vertice y despues hace un post - incremento para agrandar la matriz de adyacencias en la fila y columna.
        for (int i = 0; i < graphSize(g); i++)
        {
            g->A[v->index][i] = 0;
            g->A[i][v->index] = 0;
        }
        result = v->index;
    }

    return result;
}

/**
    Añade un vertice al grafo.
    Esta es la funcion que llama el usuario, donde le pasa el grafo y el valor que quiere que haya en el vertice.
    Crea el vertice y devuelve el grafo con el vertice incluido, devolviendo el indice de ese vertice en el grafo.

**/

int graphAddNewVertex(graph *g, char *value)
{
    int i = graphGetVertexIndex(g, value);

    if(i == NONE)
    {
        vertex *v = createVertex(value);
        i = graphAddVertex(g, v);
    }

    return i;
}

/**
    Eliminar vértice.
    -Si elimino el vertice -> Devuelve 1.
    -Si no lo pudo eliminar se debe a que el grafo es nulo o el indice es mayor al tamaño del grafo -> Devuelve 0.
**/

int graphDelVertex(graph *g, int indexVertex)
{
    if (!g) return 0;  // g==NULL
    if (indexVertex >= graphSize(g)) return 0;

    int result = 1;

    //Elimino la fila de indexVertex
    for(int j = 0; j < graphSize(g); j++)
    {
        for(int i = indexVertex; i < graphSize(g) - 1; i++)
        {
            g->A[i][j] = g->A[i + 1][j];
        }
    }

    //Elimino la columna de indexVertex
    for(int i = 0; i < graphSize(g) - 1; i++)
    {
        for(int j = indexVertex; j < graphSize(g) - 1; j++)
        {
            g->A[i][j] = g->A[i][j + 1];
        }
    }
    g->size--;

    //Actualizo los vertices para que el "nombre" y el "indice" se correspondan
    for(int i = indexVertex; i < graphSize(g); i++)
    {
        (g->V[i])->value = (g->V[i+1])->value;
    }
    free(g->V[g->size]); //Libero el ultimo lugar.

    return result;
}

/**
    Verificar si un vértice es adyacente de otro.
    -Si es adyacente -> Devuelve un 1.
    -Si no es adyacente -> Devuelve un 0.

**/

int isAdjVertex(graph *g, int fromVertex, int toVertex)
{
    int result = 0;
    if(graphExistArc(g, fromVertex, toVertex) || graphExistArc(g, toVertex, fromVertex))
    {
        result = 1;
    }
    return result;
}

/**
    Obtener la lista de vértices adyacentes.
    Paso el indice del vertice y se fija que vertices son adyacentes a éste y la devuelve en una lista.
**/

list *listAdjVertex(graph *g, int indexV)
{
    if(!g) return NULL;
    if(indexV >= graphSize(g)) return NULL;

    list *l = createList();

    for(int i = 0; i < graphSize(g); i++)
    {
        if(isAdjVertex(g, indexV, i))
        {
            if(graphExistArc(g, indexV, i))
            {
                insertLastList(l, i);
            }
        }
    }
    return l;
}

/**
    Agrega una arista.
    Agrega en la matriz de adyacencias el costo (Agrega una arista).Devuelve un "1" si se pudo agregar.
    Si los indices "desde donde" y "hacia donde" Apunta el vertice son mayores al tamaño -> Devuelve un "0"(error)

**/

int graphSetArc(graph *g, int fromVertex, int toVertex, int cost)
{
    if (!g) return 0;
    if (fromVertex >= graphSize(g)) return 0;
    if (toVertex >= graphSize(g)) return 0;

    g->A[fromVertex][toVertex] = cost; //Agrega en la matriz de adyacencias el costo (Agrega una arista).

    return 1;
}

/**
    Agrega una arista en las dos direcciones.
    Agrega en la matriz de adyacencias el costo (Agrega una arista).Devuelve un "1" si se pudo agregar.
    Si los indices "desde donde" y "hacia donde" Apunta el vertice son mayores al tamaño -> Devuelve un "0"(error)

**/

int graphSetDobleArc(graph *g, int fromVertex, int toVertex, int cost)
{
    if (!g) return 0;
    if (fromVertex >= graphSize(g)) return 0;
    if (toVertex >= graphSize(g)) return 0;

    g->A[fromVertex][toVertex] = cost;
    g->A[toVertex][fromVertex] = cost;
    return 1;
}


/**

    Elimina una arista (Poniendo en la matriz de adyacencias un 0). Devuelve un "1" si se pudo agregar.
    -Si los indices "desde donde" y "hacia donde" Apunta el vertice son mayores al tamaño -> Devuelve un "0"(error)

**/

int graphDelArc(graph *g, int fromVertex, int toVertex)
{
    if (!g) return 0;
    if (fromVertex >= graphSize(g)) return 0;
    if (toVertex >= graphSize(g)) return 0;

    g->A[fromVertex][toVertex] = 0; //Elimina una arista (Poniendo en la matriz de adyacencias un 0).

    return 1;
}

/**
    Comprobar la existencia de una arista (arco).
    -Si existe -> Devuelve un 1.
    -Si no existe -> Devuelve un 0.
**/

int graphExistArc(graph *g, int indexV1, int indexV2)
{
    int result = 0;
    if(g->A[indexV1][indexV2] != 0 && g->A[indexV1][indexV2] != INF)
    {
        result = 1;
    }
    return result;
}

/**
    Calcula el costo de una arista desde (from) hasta (to).
    Devuelve infinito si se apunta a si mismo o si apunta a un vertice que no sea adyacente a él.
    Devuelve result (costo).

**/

int graphCost(graph *g, int from, int to)
{
    if (!g) return INF;
    int result = g->A[from][to];
    return (result != 0) ? result : INF;
}

/**
    Imprime el grafo.
**/

void graphPrint(graph *g)
{
    if (!g) return;

    for (int i = 0; i < graphSize(g); i++)
    {
        printf("%4d - %10s : ", i, g->V[i]->value);
        for (int j = 0; j < graphSize(g); j++)
        {
            printf(" %4d", g->A[i][j]);
        }
        printf("\n");
    }
}

/**
    Se fija si el indice es correcto
**/
int graphValideIndex(graph *g, int index)
{
    int result = 0;

    if((index >= 0) && (index < graphSize(g)))
    {
        result = 1;
    }
    return result;
}

/**
    Devuelve un valor del vertice donde se encuentra
**/
char *graphGetValueOf(graph *g, int index)
{
    char *result = NULL;
    if(graphValideIndex(g, index))
    {
        result = g->V[index]->value;
    }
    return result;
}

/**
    Busca el value de un grafo y devuelve el indice donde se encuentra
**/
int graphGetVertexIndex(graph *g, char *value)
{
    if(!g) return ECG;
    if(!value) return ECG;

    int i = 0;
    while( (i < graphSize(g)) && (strcmp(graphGetValueOf(g, i), value)))
    {
        i++;
    }
    return (i < graphSize(g)) ? i : INF;
}


/**************** CLASIFICACIONES DE GRAFOS ******************/

/**
    Cantidad de arcos
**/

int numberOfArcs(graph *g, int indexV)
{
    int cnt = 0;
    for(int i = 0; i < graphSize(g); i++)
    {
        if(graphExistArc(g, indexV, i))
        {
            cnt++;
        }
    }
    return cnt;
}

/**
    Grafo vacio

    -Si el tamaño del grafo es = 0 -> Devuelve un 1
    -Si el tamaño de un grafo es != 0 -> Devuelve un 0

**/

int isEmptyGraph(graph *g)
{
    return (graphSize(g) == 0) ? 1 : 0; //Si el tamaño del grafo = 0 -> Devuelve un 1, sino un 0.
}

/**
    ¿Como saber si un grafo es Grafo o Digrafo?
    Nos tenemos que fijar si toda la matriz es simetrica.

        -Si no es simetrica -> Es Digrafo -> Devuelve un 1.
        -Si es simetrica -> Es Grafo -> Devuelve un 0.
**/

int isDigraph(graph *g)
{
    int result = 1;
    for(int i = 0; i < graphSize(g); i++)
    {
        for(int j = i; j < graphSize(g); j++)
        {
            if(graphExistArc(g, i, j) == graphExistArc(g, j, i))
            {
                if(graphCost(g, i, j) == graphCost(g, j, i))
                {
                    result = 0;
                }
            }
        }
    }
    return result;
}

/**
    Grafo conexo
    -Hay que tomar un nodo y empezar a recorrerlo en profundidad
    Si cuando tomo un nodo y recorro en profundidad o amplitud llego a todos los demas (Hablando de grafos)
    Entonces el grafo es conexo

    -Si el grafo es conexo -> Devuelve un 1.
    -Si el grafo no es conexo -> Devuelve un 0.
**/

int isConvexGraph(graph *g)
{
    if (!g) return 0;

    list *vert = createList();
    list *visit = createList();

    for (int i = 0; i < graphSize(g); i++)
    {
        insertLastList(visit, 0); //visit[i] = 0
    }

    stack *s = createS();

    push(&s,0);
    while (!isEmptyS(s))
    {
        int e = pop(&s);
        if (getValueList(visit, e) == 0) //visit[e] == 0
        {
            for (int i = graphSize(g) - 1; i >= 0 ; --i)
            {
                if (graphExistArc(g, e, i))
                {
                    push(&s,i);
                }
            }
            setValueList(visit, e, 1);  //visit[e] = 1
            insertLastList(vert, e);
        }
    }

    return (getSizeList(vert) == graphSize(g)) ? 1 : 0;
}

/**
    Grafo Euleriano
    -¿Como saber si un grafo es Grafo Euleriano?
        Para saber si es eureliano tenemos que recorrer un camino pasando todos los vertices 1 vez y cumplir un
        ciclo, volviendo a su comienzo (Ciclo eureliano).
    -¿Como sabemos que podemos pasar por todas las aristas y volver al mismo punto?
        Hay una regla que dice que todos los vertices deben tener un numero par de aristas.
        Sabiendo esa regla -> podemos verificar si el grafo es euleriano.
    -Hay otra forma de recorrerlo SIN VOLVER AL PUNTO DE RETORNO
        La condicion es que debe haber DOS VERTICES con aristas IMPARES, si hay mas -> no es euleriano.

        -Si es Euleriano -> Devuelve un 1.
        -Si no es Euleriano -> Devuelve un 0.
**/

int isGraphEulerian(graph *g)
{
    if(isDigraph(g)) return 0; //Condicion necesaria
    if(!isConvexGraph(g)) return 0; //Condicion necesaria

    int result = 0;
    for(int i = 0; i < graphSize(g); i++)
    {
        if(numberOfArcs(g, g->V[i]->index) % 2 == 0)
        {
            result = 1;
        }
    }
    return result;
}

/**
    Eulerian cycle
    -Condicion necesaria: Para encontrar al menos un camino que recorra todos los vertices y vuelva al mismo
    sin repetir, Puede haber solo 2 nodos que contengan aristas impares, pero el resto deben ser pares.
    Luego, la manera de encontrar el ciclo o el camino, debo recorrer como si fuera un arbol en profundidad
    vamos probando por todos los lugares donde podemos ir, pero cada vez que vamos a un lugar vamos marcando
    los vertices que recorri y los arcos que utilice.
**/

void eulerianCycle(graph *g)
{

}

/**
    Grafo orientado
    -Si el grafo es orientado debe cumplir con solo una de las siguientes condiciones, siendo u y v dos vertices:
        *Es un digrafo, es decir que existe una arista (u, v) o una arista (u, v), pero no ambas a la vez con el mismo costo.
        *Los nodos u y v no estan conectados.

    -Si es orientado -> Devuelve 1.
    -Si no es orientado -> Devuelve 0.
**/

int isOrientedGraph(graph *g)
{
    if(!g) return 0;
    if(!isDigraph(g)) return 0; //Condicion necesaria

    int result = 1;
    for(int i = 0; i < graphSize(g); i++)
    {
        for(int j = i; j < graphSize(g); j++)
        {
            if(graphExistArc(g, i, j) && graphExistArc(g, j, i))
            {
                result = 0;
            }
        }
    }
    return result;
}
/**
    Grafo completo
    -Un grafo completo es aquel que cada nodo se conecta con todos los demas.
    -Entonces, si encuentro un arco (conexion entre dos nodos) que no existe -> Ya no es un grafo completo.

    -Si es un grafo completo -> Devuelve 1.
    -Si no es un grafo completo -> Devuelve 0.
**/

int isCompletedGraph(graph *g)
{
    int result = 1;
    for(int i = 0; i < graphSize(g); i++)
    {
        for(int j = 0; j < graphSize(g); j++)
        {
            if(i != j && !graphExistArc(g, i, j))
            {
                result = 0;
            }
        }
    }
    return result;
}

/**
    Grafo Bipartito
    -Arrancamos de cualquier nodo y vamos recorriendo las aristas. Arrancamos desde un vertice y lo ponemos
    en el conjunto "A" y todos a los que ese nodo apunta los ponemos en el conjunto "B". Despues arrancamos desde
    otro vertice y vemos que si ya esta en alguno de los dos conjuntos, por ejemplo si esta en el conjunto de
    "A", todos sus nodos adyacentes deben estar en el conjunto B. Si esto pasa -> el grafo es Bipartito.
    Cuando hablamos de conjuntos hablamos de tener 2 vectores con los numeros de vertice (identificador).

    -Si el Grafo es Bipartito -> Devuelve 1.
    -Si el Grafo no es Bipartito -> Devuelve 0.

**/

void _isBipartiteGraph(graph *g, int vertex, int visited[], int a[], int b[])
{
    if(!g) return;

    if(visited[vertex] == 0)
    {
        visited[vertex] = 1;
        for(int i = 0; i < graphSize(g); i++)
        {
            if(g->A[vertex][i] > 0)
            {
                _isBipartiteGraph(g, i, visited, b, a);
            }
        }
    }
}

int isBipartiteGraph(graph *g, int from)
{
    if(!g) return -1;
    if(graphSize(g) <= from) return -1; //Codigo de error

    int result = 1;
    int v[MAX];
    int a[MAX];
    int b[MAX];

    for(int i = 0; i < graphSize(g); i++)
    {
        v[i] = 0;
        a[i] = 0;
        b[i] = 0;
    }
    v[from] = 1;

    for(int i = 0; i < graphSize(g); i++)
    {
        if(g->A[from][i] > 0)
        {
            _isBipartiteGraph(g, i, v, a, b);
        }
    }
    for(int i = 0; i < MAX; i++)
    {
        if(a[i] == b[i])
        {
            result = 0;
        }
    }

    return result;
}

/**
    Grafo simple
    -Son los que deben tener solo una arista entre dos nodos y no pueden tener bucles (Un vertice apuntado a si mismo)
    Para averiguarlo con matriz adyacente, solamente tengo que ver la diagonal principal.

    -Si es un grafo simple -> Devuelve 1.
    -Si no es un grafo simple -> Devuelve 0.

**/

int isSimpleGraph(graph *g)
{
    if(!g) return 0;
    if(isDigraph(g)) return 0; //Condicion necesaria

    int result = 1;
    for(int i = 0; i < graphSize(g); i++)
    {
        if(graphExistArc(g, i, i))
        {
            result = 0;
        }
    }
    return result;
}

/************************ ALGORITMO DE DIJSTRA ************************/

/**
    Algoritmo de Dijstra
    Averigua el camino mas corto entre un vertice y otro y devuelve todo el recorrido.
**/

vlink dijstra(graph *g, int origin)
{
    vlink result;
    result.count = graphSize(g);
    int notvisited[MAX];

    for (int i = 0; i < graphSize(g); i++)
    {
        result.pred[i] = origin;
        result.cost[i] = graphCost(g, origin, i);
        notvisited[i] = 1;
    }

    notvisited[origin] = 0;
    //printD(g,result, origin, 0, notvisited);

    for (int k = 1; k < graphSize(g) - 1; k++)
    {
        int min = INF;
        int nextVertex = -1;


        for (int i = 0; i < graphSize(g); i++)
        {
            if ((notvisited[i]) && (result.cost[i] < min))
            {
                min = result.cost[i];
                nextVertex = i;
            }
        }

        notvisited[nextVertex] = 0;
        //printD(g,result, nextVertex, k, notvisited);

        for (int i = 0; i < graphSize(g); i++)
        {
            if ((notvisited[i]) && ((min + graphCost(g, nextVertex, i)) < result.cost[i]))
            {
                result.cost[i] = (min + graphCost(g, nextVertex, i));
                result.pred[i] = nextVertex;
            }
        }
    }

    return result;
}

/**
    Obtiene el costo del recorrido mas corto (utilizando dijstra).
**/

int getCost (vlink d, int to)
{
    return d.cost[to];
}

/**
    Imprime la matriz de resultados
**/

void printD (graph *g, vlink d, int next, int step, int visited[])
{
    printf ("Paso %4d:\n", step);
    for (int i = 0; i < graphSize(g); i++)
    {
        printf (" %s %10s %s %4d %10s \n", (i==next)?">":" " , g->V[i]->value,(visited[i]==0)?"*":" ", d.cost[i], g->V[d.pred[i]]->value);
    }
    printf ("\n");
}

/**
    Funcion interna para imprimir el camino o recorrido utilizando el algoritmo de dijstra.
**/

void _printWay (graph *g, vlink d, int from, int to)
{
    if (from != to)
    {
        _printWay (g, d, from, d.pred[to]);
        printf (" %s -> ", g->V[to]->value);
    }
}

/**
    Imprime el camino o recorrido utilizando el algoritmo de dijstra.
**/

void printWay (graph *g, vlink d, int from, int to)
{
    printf (" %s -> ", g->V[from]->value);
    if (from != to)
    {
        _printWay (g, d, from, d.pred[to]);
        printf (" %s ", g->V[to]->value);
    }
}


/************************ RECORRIDOS DE GRAFOS ************************/

/**
    Recorrido en anchura(Amplitud)
**/

void graphBFP (graph *g, int from)
{
    if (!g) return;
    if (graphSize(g) <= from) return;

    list *visit = createList();

    for (int i = 0; i < graphSize(g); i++)
    {
        insertLastList(visit, 0); //visit[i] = 0
    }
    queue *q = createQ();

    setValueList(visit, from, 1); //v[from] = 1
    enqueue(&q, from);
    while (!isEmptyQ(q))
    {
        int e = dequeue(&q);
        for (int i = 0; i < graphSize(g); i++)
        {
            if(getValueList(visit, i) == 0 && graphExistArc(g, e, i)) // Si visit[i] == 0 && existe un arco entre "e" y "i"
            {
                setValueList(visit, i, 1); //v[i] = 1
                enqueue(&q, i);
            }
        }
        printf ("%s ", g->V[e]->value);
    }
    printf ("\n");
 }

/**
    Recorrido en profundidad
**/
void graphDFP (graph *g, int from)
{
    if (!g) return;
    if (graphSize(g) <= from) return;

    list *visit = createList();

    for (int i = 0; i < graphSize(g); i++)
    {
        insertLastList(visit, 0); //visit[i] = 0
    }

    stack *s = createS();

    push(&s, from);
    while (!isEmptyS(s))
    {
        int e = pop(&s);
        if (getValueList(visit, e) == 0) //visit[e] == 0
        {
            for (int i = graphSize(g) - 1; i >= 0 ; --i)
            {
                if (graphExistArc(g, e, i)) //Si existe un arco de e hacia i
                {
                    push(&s,i);
                }
            }
            setValueList(visit, e, 1);  //visit[e] = 1
            printf("%s ", g->V[e]->value);
        }
    }
    puts("\n");
}
/************************ ARBOL DE COBERTURA ************************/

/**
    Arbol de cobertura en amplitud
**/

ntn *graphBFTree (graph *g, int from)
{
    if (!g) return NULL;
    if (graphSize(g) <= from) return NULL;

    ntn *root = createNTN(from);

    int v[MAX];
    for (int i = 0; i < graphSize(g); i++)
    {
        v[i] = 0;
    }

    queue *q = createQ();

    v[from] = 1;

    enqueue(&q, from);
    while (!isEmptyQ(q))
    {
        int e = dequeue(&q);
        for (int i = 0; i < graphSize(g); i++)
        {
            if ((v[i]==0) && (g->A[e][i] != 0))
            {
                v[i] = 1;
                insertSonValueOfNTN(root, e, i);
                enqueue(&q, i);
            }
        }
    }
    return root;
}

/**
    Arbol de cobertura en profundidad
**/

void _graphDFTree (graph *g, ntn *root, int parent, int vertex, int visited[])
{
    if (!g) return;
    if (!root) return;
    if (visited[vertex] == 0)
    {
        visited[vertex] = 1;
        insertSonValueOfNTN (root, parent, vertex);
        for(int i = 0; i < graphSize(g); i++)
        {
            if (g->A[vertex][i] > 0)
            {
                _graphDFTree(g, root, vertex, i, visited);
            }
        }
    }
}

ntn *graphDFTree (graph *g, int from)
{
    if (!g) return NULL;
    if (graphSize(g) <= from) return NULL;

    int v[MAX];
    for (int i = 0; i < graphSize(g); i++)
    {
        v[i] = 0;
    }
    ntn *root = createNTN(from);
    v[from] = 1;
    for (int i = 0; i < graphSize(g); i++)
    {
        if (g->A[from][i] > 0)
        {
            _graphDFTree(g, root, from, i, v);
        }
    }
    return root;
}

/**
    Algoritmo de Kruskal
    -Genera un arbol de cobertura con el menor costo posible.
**/

graph *kruskal(graph *g)
{
    if (!g) return NULL;
    if(!isConvexGraph(g)) return NULL;
    if(!isSimpleGraph(g)) return NULL;

    graph *k = createGraph();
    int v[MAX];
    for (int i = 0; i < graphSize(g); i++)
    {
        v[i] = 0;
        graphAddNewVertex (k, strdup(g->V[i]->value));
    }

    int minFrom, minTo;
    int count = 0;
    while (count < (graphSize(g) - 1))
    {
        int minCost = INF;
        for (int i = 0; i < graphSize(g); i++)
        {
            for (int j = 0; j < graphSize(g); j++)
            {
                if ((v[j] == 0) && (graphCost(g, i, j) < minCost))
                {
                    minCost = graphCost(g, i, j);
                    minFrom = i;
                    minTo = j;
                }
            }
        }
        graphSetArc(k, minFrom, minTo, minCost);
        graphSetArc(k, minTo, minFrom, minCost);
        v[minFrom] = 1;
        v[minTo] = 1;
        count++;
    }
    return k;
}

/**
    Algoritmo de Floyd
**/

void floyd(graph *g, fres *r)
{
    r->count = graphSize(g);
    for (int i = 0; i < graphSize(g); i++)
    {
        for (int j = 0; j < graphSize(g); j++)
        {
             r->D[i][j] = i;
             r->C[i][j] = graphCost(g, i, j);
        }
    }
    for (int k = 0; k < graphSize(g); k++)
    {
        for (int i = 0; i < graphSize(g); i++)
        {
            for (int j = 0; j < graphSize(g); j++)
            {
                int cost = (r->C[i][k] + r->C[k][j]);
                if ((i!=j)&&(cost < r->C[i][j]))
                {
                    r->D[i][j] = r->D[k][j];
                    r->C[i][j] = cost;
                }
            }
        }
     }
}

/**************************************************************/
/*                       Ejemplos                             */
/**************************************************************/

/**
    Obtener un grafo a partir de arboles de cobertura
**/

void _graphFromNtree(graph *g, ntn *node)
{
    if (node != NULL)
    {
        char *aux = (char*)malloc(10*sizeof(char));
        sprintf(aux, "%d", node->value);
        graphAddNewVertex(g, aux); //Seteamos los vertices
        ntlist *l = node->sons;
        while (l != NULL)
        {
            _graphFromNtree(g, l->node);
            graphSetDobleArc(g, node->value, l->node->value, 1);
            l = l->next;
        }
    }
}

graph *graphFromNtree(ntq *q)
{
    graph *fnt = createGraph();

    while(!isEmptyQueueNTN(q))
    {
        _graphFromNtree(fnt, dequeueNTN(q));
    }

    return fnt;
}
