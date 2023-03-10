#include "declaraciones.h"

///////////////////////////PILAS///////////////////////////
bool isEmpty_pila(PILA *ppS)
{
    return((*ppS)==NULL);
}

bool isFull_pila(PILA *ppS) //Esta funcion es innecesaria, ya que una pila dinamica nunca esta llena.
{
    return (false);
}

bool peek_pila(PILA *ppS, int *px)
{
    PILA pS;
    if(isEmpty_pila(ppS))
    {
        return (false);
    }
    else
    {
        pS = (*ppS);
        (*px) = pS->valor;
        return (true);
    }
}

bool push(PILA *ppS, int x)
{
    PILA pS;
    if(isFull_pila(ppS))// NO ES NECESARIO
    {
        return (false);
    }
    else
    {
        pS = (*ppS);
        NODO_1 * Nuevo;
        Nuevo = (NODO_1 *) malloc(sizeof(NODO_1));
        Nuevo->valor = x;
        Nuevo->next = pS; //Esto lo que hace es decir de donde me prendo, yo estoy creando un nuevo nodo o un nuevo puntero a estructura y tengo que referenciar de donde la tengo que enganchar, antes habia un puntero a NULL, ahora yo tengo que decirle que no es NULL, sino que es un nuevo NODO y de donde viene ese nuevo nodo.
        (*ppS) = Nuevo;
        return (true);
    }
}
bool pop(PILA *ppS, int *px)
{
    PILA pS;
    if(isEmpty_pila(ppS))
    {
        return (false);
    }
    else
    {
        pS = (*ppS);
        (*px) = pS->valor;
        (*ppS) = pS->next;
        free(pS);
        return (true);
    }
}
bool imprimir_pila(PILA pS)
{
    PILA tope = pS;
    if(isEmpty_pila(&pS))
    {
        return (false);
    }
    else
    {
        while(!isEmpty_pila(&tope))   ///Mientras no esté vacía. Nota: vacía una copia de la pila, no la original
        {
            printf("%d\n", tope->valor);
            tope= tope->next;
        }
        printf("\n");
        return (true);
    }
    free(tope);
}

///////////////////////////FILAS///////////////////////////

bool isEmpty_fila(FILA *pF)
{
    return (pF->front==NULL);
}

bool isFull_fila(FILA *pF)
{
    return (false);
}

bool peek_fila(FILA *pF, int *px)
{
    NODO_2 *pS;
    if(isEmpty_fila(pF))
    {
        return (false);
    }
    else
    {
        pS = pF->front;
        (*px) = pS->valor;
        return (true);
    }
}

bool enqueue(FILA *pF, int x)
{
     NODO_2 *Nuevo;
     NODO_2 *pS; // Ultimo nodo
     if(isFull_fila(pF))// NO ES NECESARIO
     {
         return (false);
     }
     else
     {
         Nuevo = (NODO_2*) malloc(sizeof(NODO_2));
         Nuevo->valor = x;
         Nuevo->next = NULL;
         if(pF->rear != NULL)// solo si ya hay nodos, corrige
         {
             pS = pF->rear; // Puntero al ultimo nodo
             pS->next = Nuevo; // Ultimo apunta al nuevo
         }
         else
         {
            pF->front = Nuevo; // Nuevo ultimo
         }
         pF->rear = Nuevo; // Nuevo ultimo
         return (true);
     }
}

bool dequeue(FILA *pF, int *px)
{
    NODO_2 *pS;
    if(isEmpty_fila(pF))
    {
        return (false);
    }
    else
    {
        pS = pF->front; // Guarda puntero al primero
        (*px) = pS->valor; // Toma valor
        pF->front = pS->next; // Actualiza “front”
        if(pS->next==NULL)
        {
            pF->rear = NULL; // No hay mas nodos
        }
        free(pS); // Libera primero
        return (true);
    }
}

void inicializar_fila(FILA *pF)
{
    pF->front = NULL;
    pF->rear = NULL;
}

bool imprimir_fila(FILA pF)
{
    NODO_2 *primero = pF.front;

    if(isEmpty_fila(&pF))
    {
        return (false);
    }
    else
    {
        while(primero != NULL)  ///mientras no esté vacía. Nota: vacía una copia de la fila, no la original
        {
            printf("%d\n", primero->valor);
            primero = primero->next;
        }
        printf("\n");
        return (true);

    }
}

void cargar_fila(FILA *pF)
{
    for(int i = 1; i < 10; i++)
    {
        enqueue(pF, i);
    }

}

///////////////////////////LISTAS///////////////////////////

void liberar_memoria(list *lista) //Libera memoria.
{
    list *pS = lista;
    list *borrar;
    while (pS != NULL)
    {
        borrar = pS;
        pS = pS->next;
        free(borrar);
    }
}

bool isEmpty(list *lista) //Retorna 1 si la lista esta vacía y 0 si no lo está.
{
    if (lista == NULL)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

int length(list *lista) //Retorna la cantidad de nodos en la lista.
{
    list *pS = lista;
    int cnt = 0;
    while (pS != NULL)
    {
        cnt++;
        pS = pS->next;
    }
    return cnt;
}

void insert(list **lista, int pos, int x) //Insertar un elemento en la lista en "pos".
{
    //CNT ES LA CANTIDAD DE LOS NODOS QUE TENGAMOS
    if (pos <= CNT + 1) //Controlamos que existe la posicion pasada, lo hacemos si la posicion es menor o igual que la cantidad de nodos +1
    {                        //El +1 es porque si la lista esta vacia me devuelve 0 y yo quiero insertar en la posicion 1 por ejemplo.
        list *nuevo; //Creo el nuevo nodo
        nuevo = (list*)malloc(sizeof(list)); //Asigno memoria para el nuevo nodo.
        nuevo->value = x;    //Guardo la informacion.
        if (pos == 1)        //Ahora a el nodo lo enlazo en la lista, si lo inserto como primer elemento de la lista, entonces debo reacomodar la lista
        {
            nuevo->next = *lista; //Next apunta ahora al primero de la lista.
            *lista = nuevo;       //Igualamos la lista con la direccion del primer nodo.
        }
        else
            if (pos == CNT + 1) //Si la posicion a la cual voy a asignar un nodo es al final de la lista
            {
                list *pS = *lista; //Creamos un puntero al inicio de la lista
                while (pS->next != NULL) //Vamos avanzando en la lista y recorriendola
                {
                    pS = pS->next;
                }                       //Cuando salimos del while, es porque llegamos al ultimo lugar
                pS->next = nuevo;       //Entonces enlazamos el ultimo nodo de la lista que tiene NULL con el nuevo
                nuevo->next = NULL;     //Como es el ultimo, el siguiente va a ser NULL.
            }
            else                       //Si no ingresamos ni al principio, ni al final el nuevo nodo, entonces estamos en este caso
            {
                list *pS = *lista; //Creamos un nuevo nodo apuntando al primer elemento de la lista
                for (int i = 1; i <= pos - 2; i++) //Recorremos la lista y avanzamos hasta la posicion ANTERIOR a la que vamos a insertar, para engancharlo con el nuevo nodo
                {
                    pS = pS->next;
                }                            //Una vez que termino el for, estamos en la posicion ANTERIOR a la que queremos tener el nuevo nodo.
                list *siguiente = pS->next; //Creamos un puntero que apunte a el nodo siguiente que es donde se va a insertar el nuevo nodo
                pS->next = nuevo;           //Enlazamos el nuevo nodo
                nuevo->next = siguiente;    //Ponemos el nuevo next apuntando a siguiente.
            }
    }
}

bool traverse(list *lista) //Imprime o recorre la lista.
{
    list *pS = lista;
    if(isEmpty(lista))
    {
        return (false);
    }
    else
    {
        while (pS != NULL) //Recorre toda la lista
        {
            printf("%i ",pS->value); //Vamos imprimiendo el tipo de dato entero que es valor.
            pS = pS->next;
        }
        printf("\n");
        return (true);
    }
}


int get(list *lista, int pos) //Extrae la informacion del nodo de la posicion "pos" sin eliminarlo.
{
    if (pos <= length(lista))
    {
        int informacion;
        if (pos == 1) //Si la posicion es el primer valor de la lista
        {
            informacion = lista->value; //Extraemos cuanto vale el numero en la primera posicion de la lista
            lista = lista->next;
        }
        else //Si no es la posicion 1 el nodo que queremos extraer, entonce seguimos
        {
            list *pS = lista; //Creamos un puntero auxiliar que apunta al primer elemento de la lista
            for (int i = 1; i <= pos - 2; i++) //Recorremos la lista hasta el nodo ANTERIOR al que queremos extraer
            {
                pS = pS->next;
            }
            list *prox = pS->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a extraer
            informacion = prox->value; //Asignamos a la informacion el valor del que queremos extraer.
        }
        return informacion;
    }
    else
    {
        return -1; //Codigo de error
    }
}


void deletee(list **lista, int pos) //Elimina el nodo de la posicion "pos" pero sin devolver informacion.
{
    if (pos <= length(*lista)) //Validacion de si existe la posicion que nos pasan.
    {
         list *borrar; //Creamos un puntero a nodo para borrar.
        if (pos == 1)        //Si la posicion es la primera de la lista
        {
            list *aux = *lista;
            borrar = aux;
            aux = aux->next; //Ahora, lista avanza al siguiente nodo como primer elemento.
            *lista = aux;
        }
        else //Si no esta en el primer elemento de la lista, tenemos que buscar donde esta pos
        {
            list *pS = *lista; //Creamos un nodo que apunte al primero de la lista
            for (int i = 1; i <= pos - 2; i++) //Recorremos hasta la posicion anterior a la posicion que nos pasan
            {
                pS = pS->next;
            }
            list *prox = pS->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a borrar
            pS->next = prox->next; //Aca salteamos el que vamos a borrar.
            borrar = prox;         //Asignamos borrar al elemento de la posicion pos
        }
        free(borrar); //Elimina borrar.
    }
}


void intercambiar(list *lista, int pos1, int pos2) //Intercambia las informaciones de los nodos en las posiciones "pos1" con "pos2"
{
    int aux;
    if (pos1 <= length(lista) && pos2 <= length(lista))
    {
        list *pS1 = lista;
        for (int i = 1; i < pos1; i++)
        {
            pS1 = pS1->next;
        }
        list *pS2 = lista;
        for (int i = 1; i < pos2; i++)
        {
            pS2 = pS2->next;
        }
        aux = pS1->value;
        pS1->value = pS2->value;
        pS2->value = aux;
    }
}


int mayor(list *lista) //Retorna el nodo con mayor informacíon.
{
    if (!isEmpty(lista))
    {
        int may = lista->value;
        list *pS = lista->next;
        while (pS != NULL)
        {
            if (pS->value > may)
            {
                may = pS->value;
            }
            pS = pS->next;
        }
        return may;
    }
    else
        return -1;
}


int posMayor(list *lista) //Retorna la posicion del nodo con mayor informacion.
{
    if (!isEmpty(lista))
    {
        int may = lista->value;
        int x = 1;
        int pos = x;
        list *pS = lista->next;
        while (pS != NULL)
        {
            x++;
            if (pS->value > may)
            {
                may = pS->value;
                pos = x;
            }
            pS = pS->next;
        }
        return pos;
    }
    else
    {
        return -1;
    }
}

bool sort(list *lista) //Debe retornar 1 si la lista esta ordenada de menor a mayor, 0 en caso contrario.
{
    if (length(lista) > 1)
    {
        list *pS1 = lista;
        list *pS2 = lista->next;
        while (pS2 != NULL)
        {
            if (pS2->value > pS1->value) //Esta ordenada
            {
                return (true);
            }
            pS2 = pS2->next;
            pS1 = pS1->next;
        }
    }
    return (false); //No esta ordenada
}

bool search(list **lista, int x) //Debe retornar 1 si existe la informacion que llega en el parametro, 0 en caso contrario.
{
    list *pS = *lista;
    while (pS != NULL)
    {
        if (pS->value == x)
        {
            return (true);
        }
        pS = pS->next;
    }
    return (false);
}

void inicializar_lista(list **lista)
{
    *lista = NULL;
}

void cargar_pila(PILA *pS)
{
    for(int i = 0; i < 10; i++)
    {
        push(pS, i);
    }
}
