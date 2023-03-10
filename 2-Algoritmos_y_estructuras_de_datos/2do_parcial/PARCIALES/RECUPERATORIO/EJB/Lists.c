#include <stdio.h>
#include <stdlib.h>
#include "Lists.h"

node *createNode(int x)
{
    node *newNode = (node*) malloc(sizeof(node));
    newNode->value = x;
    newNode->next = NULL;
    return newNode;
}


/**************************************************************/
/*                      PILA DE ENTEROS                       */
/**************************************************************/

/**
 *  Crea una pila con el valor NULL.
 */
stack *createS()
{
    stack *s = (stack *) malloc(sizeof(stack));
	s = NULL;
	return s;
}

/**
 *  Devuelve si una pila está vacía.
 */
int isEmptyS (stack *s)
{
    return (s == NULL);
}

/**
 *  Agrega un elemento a una pila. Retorna si pudo insertarlo o no.
 */
int push(stack **s, int x)
{
    if (s == NULL) return 0;

    node *newNode = createNode(x);

    newNode->next = *s;   //asigno al next la dir. actual de la pila
    *s = newNode;         //asigno la dir. nuevo a la pila

    return 1;
}

/**
 *  Remueve un elemento de la pila y lo retorna. Si no puede removerlo, retorna
 *  ECL(definido en la cabecera).
 */
int pop (stack **s)
{
    if (s == NULL) return ECL;
    if (isEmptyS(*s)) return ECL;

    int result;
    stack *aux = *s;    //guardo la dir. de la pila en aux

    result = aux->value;    //guardo el valor en x
    *s = aux->next;     //apunto s al siguiente
    free(aux);          //libero aux

    return result;
}

/**
 *  Recupera el último valor de la pila, sin retirarlo y lo devuelve. Si está vacía,
 *  retorna ECL(definido en la cabecera).
 */
int peekS(stack *s)
{
    return (isEmptyS(s)) ? ECL : s->value;
}

/**
 *  Imprime una pila y devuelve si pudo imprimirla o no.
 */
int printS(stack *s) ///muestra una pila
{
    if (isEmptyS(s)) return 0;

    stack *head = s;

    while (!isEmptyS(head))     ///recorre la pila sin perder la referencia, gracias al auxiliar tope
    {
        printf("%i\n", head->value);
        head = head->next;
    }
    printf("\n");

    return 1;
}

/**************************************************************/
/*                      FILA DE ENTEROS                       */
/**************************************************************/

/**
 *  Crea una fila con el front y rear apuntando a NULL.
 */
queue *createQ()
{
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

/**
 *  Devuelve si una fila está vacía.
 */
int isEmptyQ (queue *q)
{
    return (q->front == NULL);
}

/**
 *  Agrega un elemento a una fila. Retorna si pudo insertarlo o no.
 */
int enqueue(queue **q, int x)
{
    if (q == NULL) return 0;

    node *newNode = createNode(x);

    if((*q)->rear != NULL)
    {        // Solo si ya hay nodos, corrige
        node *last = (*q)->rear;   // Puntero al ultimo nodo
        last->next = newNode;   // Ultimo apunta al nuevo
    }
    else
    {
        (*q)->front = newNode;    //Nuevo ultimo
    }

    (*q)->rear = newNode; //Nuevo ultimo

    return 1;
}

/**
 *  Remueve un elemento de la fila y lo retorna. Si no puede removerlo, retorna
 *  ECL(definido en la cabecera).
 */
int dequeue(queue **q)
{
    if (q == NULL) return ECL;
    if (isEmptyQ(*q)) return ECL;

    int result;

    node *first = (*q)->front;  // Guarda puntero al primero
    result = first->value;      // Toma valor
    (*q)->front = first->next;  // Actualiza “front”

    if(isEmptyQ(*q)) //Revisa si ahora esta vacio y si lo esta el rear apunta a NULL
    {
        (*q)->rear = NULL;      //No hay mas nodos
    }

    free(first);    // Libera primero
    return result;
}

/**
 *  Recupera el primer valor de la fila, sin retirarlo y lo devuelve. Si está vacía,
 *  retorna ECL(definido en la cabecera).
 */
int peekQ(queue *q)
{
    if (isEmptyQ(q))
    {
        return ECL;
    }
    else
    {
        node *first = q->front;
        return first->value;
    }
}

/**
 *  Imprime una fila y devuelve si pudo imprimirla o no.
 */
int printQ(queue *q)
{
    if (isEmptyQ(q)) return 0;

    node *first = q->front;
    while (first != NULL)
    {
        printf("%i\n", first->value);
        first = first->next;
    }
    printf("\n");

    return 1;
}

/**************************************************************/
/*                     LISTA DE ENTEROS                      */
/**************************************************************/

list *createListNode(int value)
{
    list *result = (list*)malloc(sizeof(list));
    result->value = value;
    result->next = NULL;
    return result;
}

list *listGetNext(list *l)
{
    return l->next;
}

int listGetValue(list *l)
{
    return l->value;
}

void sortAdd(list **l, int value)
{
    if(!l) return;

    if((*l) == NULL || ( (*l)->value > value) )
    {
        list *aux = createListNode(value);
        aux->next = (*l);
        (*l) = aux;
    }
    else
    {
        sortAdd(&((*l)->next), value);
    }
}

void freeMemoryList(list *l) //Libera memoria.
{
    list *aux = l;
    list *borrar;
    while (aux != NULL)
    {
        borrar = aux;
        aux = aux->next;
        free(borrar);
    }
}

int isEmpty(list *l) //Retorna 1 si la lista esta vacía y 0 si no lo está.
{
    return(l == NULL ? 1 : 0);
}

int length(list *l) //Retorna la cantidad de nodos en la lista.
{
    list *aux = l;
    int cnt = 0;
    while (aux != NULL)
    {
        cnt++;
        aux = aux->next;
    }
    return cnt;
}

void insertListPos(list **l, int pos, int x) //Insertar un elemento en la lista en "pos".
{
    //CNT ES LA CANTIDAD DE LOS NODOS QUE TENGAMOS
    if (pos <= CNT + 1) //Controlamos que existe la posicion pasada, lo hacemos si la posicion es menor o igual que la cantidad de nodos +1
    {                        //El +1 es porque si la lista esta vacia me devuelve 0 y yo quiero insertar en la posicion 1 por ejemplo.
        list *nuevo; //Creo el nuevo nodo
        nuevo = (list*)malloc(sizeof(list)); //Asigno memoria para el nuevo nodo.
        nuevo->value = x;    //Guardo la informacion.
        if (pos == 1)        //Ahora a el nodo lo enlazo en la lista, si lo inserto como primer elemento de la lista, entonces debo reacomodar la lista
        {
            nuevo->next = *l; //Next apunta ahora al primero de la lista.
            *l = nuevo;       //Igualamos la lista con la direccion del primer nodo.
        }
        else
            if (pos == CNT + 1) //Si la posicion a la cual voy a asignar un nodo es al final de la lista
            {
                list *aux = *l; //Creamos un puntero al inicio de la lista
                while (aux->next != NULL) //Vamos avanzando en la lista y recorriendola
                {
                    aux = aux->next;
                }                       //Cuando salimos del while, es porque llegamos al ultimo lugar
                aux->next = nuevo;       //Entonces enlazamos el ultimo nodo de la lista que tiene NULL con el nuevo
                nuevo->next = NULL;     //Como es el ultimo, el siguiente va a ser NULL.
            }
            else                       //Si no ingresamos ni al principio, ni al final el nuevo nodo, entonces estamos en este caso
            {
                list *aux = *l; //Creamos un nuevo nodo apuntando al primer elemento de la lista
                for (int i = 1; i <= pos - 2; i++) //Recorremos la lista y avanzamos hasta la posicion ANTERIOR a la que vamos a insertar, para engancharlo con el nuevo nodo
                {
                    aux = aux->next;
                }                            //Una vez que termino el for, estamos en la posicion ANTERIOR a la que queremos tener el nuevo nodo.
                list *siguiente = aux->next; //Creamos un puntero que apunte a el nodo siguiente que es donde se va a insertar el nuevo nodo
                aux->next = nuevo;           //Enlazamos el nuevo nodo
                nuevo->next = siguiente;    //Ponemos el nuevo next apuntando a siguiente.
            }
    }
}

int printList(list *l) //Imprime o recorre la lista.
{
    list *aux = l;
    if(isEmpty(l))
    {
        return (0);
    }
    else
    {
        while (aux != NULL) //Recorre toda la lista
        {
            printf("%i ", aux->value); //Vamos imprimiendo el tipo de dato entero que es valor.
            aux = aux->next;
        }
        printf("\n");
        return (1);
    }
}


int getValueListPos(list *l, int pos) //Extrae la informacion del nodo de la posicion "pos" sin eliminarlo.
{
    if (pos <= length(l))
    {
        int informacion;
        if (pos == 1) //Si la posicion es el primer valor de la lista
        {
            informacion = l->value; //Extraemos cuanto vale el numero en la primera posicion de la lista
            l = l->next;
        }
        else //Si no es la posicion 1 el nodo que queremos extraer, entonce seguimos
        {
            list *aux = l; //Creamos un puntero auxiliar que apunta al primer elemento de la lista
            for (int i = 1; i <= pos - 2; i++) //Recorremos la lista hasta el nodo ANTERIOR al que queremos extraer
            {
                aux = aux->next;
            }
            list *prox = aux->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a extraer
            informacion = prox->value; //Asignamos a la informacion el valor del que queremos extraer.
        }
        return informacion;
    }
    else
    {
        return -1; //Codigo de error
    }
}


void deleteListPos(list **l, int pos) //Elimina el nodo de la posicion "pos" pero sin devolver informacion.
{
    if (pos <= length(*l)) //Validacion de si existe la posicion que nos pasan.
    {
         list *borrar; //Creamos un puntero a nodo para borrar.
        if (pos == 1)        //Si la posicion es la primera de la lista
        {
            list *aux = *l;
            borrar = aux;
            aux = aux->next; //Ahora, lista avanza al siguiente nodo como primer elemento.
            *l = aux;
        }
        else //Si no esta en el primer elemento de la lista, tenemos que buscar donde esta pos
        {
            list *aux = *l; //Creamos un nodo que apunte al primero de la lista
            for (int i = 1; i <= pos - 2; i++) //Recorremos hasta la posicion anterior a la posicion que nos pasan
            {
                aux = aux->next;
            }
            list *prox = aux->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a borrar
            aux->next = prox->next; //Aca salteamos el que vamos a borrar.
            borrar = prox;         //Asignamos borrar al elemento de la posicion pos
        }
        free(borrar); //Elimina borrar.
    }
}

void swapList(list *l, int pos1, int pos2) //Intercambia las informaciones de los nodos en las posiciones "pos1" con "pos2"
{
    int aux;
    if (pos1 <= length(l) && pos2 <= length(l))
    {
        list *aux1 = l;
        for (int i = 1; i < pos1; i++)
        {
            aux1 = aux1->next;
        }
        list *aux2 = l;
        for (int i = 1; i < pos2; i++)
        {
            aux2 = aux2->next;
        }
        aux = aux1->value;
        aux1->value = aux2->value;
        aux2->value = aux;
    }
}

int posMay(list *lista) //Retorna la posicion del nodo con mayor informacion.
{
    if (!isEmpty(lista))
    {
        int may = lista->value;
        int x = 1;
        int pos = x;
        list *aux = lista->next;
        while (aux != NULL)
        {
            x++;
            if (aux->value > may)
            {
                may = aux->value;
                pos = x;
            }
            aux = aux->next;
        }
        return pos;
    }
    else
    {
        return -1;
    }
}

int isSort(list *lista) //Debe retornar 1 si la lista esta ordenada de menor a mayor, 0 en caso contrario.
{
    if (length(lista) > 1)
    {
        list *aux1 = lista;
        list *aux2 = lista->next;
        while (aux2 != NULL)
        {
            if (aux2->value > aux1->value) //Esta ordenada
            {
                return (1);
            }
            aux2 = aux2->next;
            aux1 = aux1->next;
        }
    }
    return (0); //No esta ordenada
}

int existValueList(list **lista, int x) //Debe retornar 1 si existe la informacion que llega en el parametro, 0 en caso contrario.
{
    list *aux = *lista;
    while (aux != NULL)
    {
        if (aux->value == x)
        {
            return (1);
        }
        aux = aux->next;
    }
    return (0);
}

/**************************************************************/
/*                     LISTA DE STRINGS                       */
/**************************************************************/


listStr *createListStrNode(char *value)
{
    listStr *result = (listStr*)malloc(sizeof(listStr));
    result->value = value;
    result->next = NULL;
    return result;
}

listStr *listStrGetNext(listStr *l)
{
    return l->next;
}

char *listStrGetValue(listStr *l)
{
    return l->value;
}

void listStrAdd(listStr **l, char *value)
{
    if(!l) return;
    if((*l) == NULL)
    {
        (*l) = createListStrNode(value);
    }
    else
    {
        listStrAdd(&((*l)->next), value);
    }
}

void listStrAddFirst(listStr **l, char *value)
{
    if(!l) return;

    listStr *aux = createListStrNode(value);
    aux->next = (*l);
    (*l) = aux;
}

