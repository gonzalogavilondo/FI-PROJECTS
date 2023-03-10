#include "listas.h"
///////////////////////////LISTAS///////////////////////////

void liberar_memoria(NODO *lista) //Libera memoria.
{
    NODO *pS = lista;
    NODO *borrar;
    while (pS != NULL)
    {
        borrar = pS;
        pS = pS->next;
        free(borrar);
    }
}

bool isEmpty(NODO *lista) //Retorna 1 si la lista esta vacía y 0 si no lo está.
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

int length(NODO *lista) //Retorna la cantidad de nodos en la lista.
{
    NODO *pS = lista;
    int cnt = 0;
    while (pS != NULL)
    {
        cnt++;
        pS = pS->next;
    }
    return cnt;
}

void insert(NODO **lista, int pos, int x) //Insertar un elemento en la lista en "pos".
{
    //CNT ES LA CANTIDAD DE LOS NODOS QUE TENGAMOS
    if (pos <= CNT + 1) //Controlamos que existe la posicion pasada, lo hacemos si la posicion es menor o igual que la cantidad de nodos +1
    {                        //El +1 es porque si la lista esta vacia me devuelve 0 y yo quiero insertar en la posicion 1 por ejemplo.
        NODO *nuevo; //Creo el nuevo nodo
        nuevo = (NODO*)malloc(sizeof(NODO)); //Asigno memoria para el nuevo nodo.
        nuevo->valor = x;    //Guardo la informacion.
        if (pos == 1)        //Ahora a el nodo lo enlazo en la lista, si lo inserto como primer elemento de la lista, entonces debo reacomodar la lista
        {
            nuevo->next = *lista; //Next apunta ahora al primero de la lista.
            *lista = nuevo;       //Igualamos la lista con la direccion del primer nodo.
        }
        else
            if (pos == CNT + 1) //Si la posicion a la cual voy a asignar un nodo es al final de la lista
            {
                NODO *pS = *lista; //Creamos un puntero al inicio de la lista
                while (pS->next != NULL) //Vamos avanzando en la lista y recorriendola
                {
                    pS = pS->next;
                }                       //Cuando salimos del while, es porque llegamos al ultimo lugar
                pS->next = nuevo;       //Entonces enlazamos el ultimo nodo de la lista que tiene NULL con el nuevo
                nuevo->next = NULL;     //Como es el ultimo, el siguiente va a ser NULL.
            }
            else                       //Si no ingresamos ni al principio, ni al final el nuevo nodo, entonces estamos en este caso
            {
                NODO *pS = *lista; //Creamos un nuevo nodo apuntando al primer elemento de la lista
                for (int i = 1; i <= pos - 2; i++) //Recorremos la lista y avanzamos hasta la posicion ANTERIOR a la que vamos a insertar, para engancharlo con el nuevo nodo
                {
                    pS = pS->next;
                }                            //Una vez que termino el for, estamos en la posicion ANTERIOR a la que queremos tener el nuevo nodo.
                NODO *siguiente = pS->next; //Creamos un puntero que apunte a el nodo siguiente que es donde se va a insertar el nuevo nodo
                pS->next = nuevo;           //Enlazamos el nuevo nodo
                nuevo->next = siguiente;    //Ponemos el nuevo next apuntando a siguiente.
            }
    }
}

bool traverse(NODO *lista) //Imprime o recorre la lista.
{
    NODO *pS = lista;
    if(isEmpty(lista))
    {
        return (false);
    }
    else
    {
        while (pS != NULL) //Recorre toda la lista
        {
            printf("%i ",pS->valor); //Vamos imprimiendo el tipo de dato entero que es valor.
            pS = pS->next;
        }
        printf("\n");
        return (true);
    }
}


int get(NODO *lista, int pos) //Extrae la informacion del nodo de la posicion "pos" sin eliminarlo.
{
    if (pos <= length(lista))
    {
        int informacion;
        if (pos == 1) //Si la posicion es el primer valor de la lista
        {
            informacion = lista->valor; //Extraemos cuanto vale el numero en la primera posicion de la lista
            lista = lista->next;
        }
        else //Si no es la posicion 1 el nodo que queremos extraer, entonce seguimos
        {
            NODO *pS = lista; //Creamos un puntero auxiliar que apunta al primer elemento de la lista
            for (int i = 1; i <= pos - 2; i++) //Recorremos la lista hasta el nodo ANTERIOR al que queremos extraer
            {
                pS = pS->next;
            }
            NODO *prox = pS->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a extraer
            informacion = prox->valor; //Asignamos a la informacion el valor del que queremos extraer.
        }
        return informacion;
    }
    else
    {
        return -1; //Codigo de error
    }
}


void deletee(NODO **lista, int pos) //Elimina el nodo de la posicion "pos" pero sin devolver informacion.
{
    if (pos <= length(*lista)) //Validacion de si existe la posicion que nos pasan.
    {
         NODO *borrar; //Creamos un puntero a nodo para borrar.
        if (pos == 1)        //Si la posicion es la primera de la lista
        {
            NODO *aux = *lista;
            borrar = aux;
            aux = aux->next; //Ahora, lista avanza al siguiente nodo como primer elemento.
            *lista = aux;
        }
        else //Si no esta en el primer elemento de la lista, tenemos que buscar donde esta pos
        {
            NODO *pS = *lista; //Creamos un nodo que apunte al primero de la lista
            for (int i = 1; i <= pos - 2; i++) //Recorremos hasta la posicion anterior a la posicion que nos pasan
            {
                pS = pS->next;
            }
            NODO *prox = pS->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a borrar
            pS->next = prox->next; //Aca salteamos el que vamos a borrar.
            borrar = prox;         //Asignamos borrar al elemento de la posicion pos
        }
        free(borrar); //Elimina borrar.
    }
}


void intercambiar(NODO *lista, int pos1, int pos2) //Intercambia las informaciones de los nodos en las posiciones "pos1" con "pos2"
{
    int aux;
    if (pos1 <= length(lista) && pos2 <= length(lista))
    {
        NODO *pS1 = lista;
        for (int i = 1; i < pos1; i++)
        {
            pS1 = pS1->next;
        }
        NODO *pS2 = lista;
        for (int i = 1; i < pos2; i++)
        {
            pS2 = pS2->next;
        }
        aux = pS1->valor;
        pS1->valor = pS2->valor;
        pS2->valor = aux;
    }
}


int mayor(NODO *lista) //Retorna el nodo con mayor informacíon.
{
    if (!isEmpty(lista))
    {
        int may = lista->valor;
        NODO *pS = lista->next;
        while (pS != NULL)
        {
            if (pS->valor > may)
            {
                may = pS->valor;
            }
            pS = pS->next;
        }
        return may;
    }
    else
        return -1;
}


int posMayor(NODO *lista) //Retorna la posicion del nodo con mayor informacion.
{
    if (!isEmpty(lista))
    {
        int may = lista->valor;
        int x = 1;
        int pos = x;
        NODO *pS = lista->next;
        while (pS != NULL)
        {
            x++;
            if (pS->valor > may)
            {
                may = pS->valor;
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

bool sort(NODO *lista) //Debe retornar 1 si la lista esta ordenada de menor a mayor, 0 en caso contrario.
{
    if (length(lista) > 1)
    {
        NODO *pS1 = lista;
        NODO *pS2 = lista->next;
        while (pS2 != NULL)
        {
            if (pS2->valor > pS1->valor) //Esta ordenada
            {
                return (true);
            }
            pS2 = pS2->next;
            pS1 = pS1->next;
        }
    }
    return (false); //No esta ordenada
}

bool search(NODO **lista, int x) //Debe retornar 1 si existe la informacion que llega en el parametro, 0 en caso contrario.
{
    NODO *pS = *lista;
    while (pS != NULL)
    {
        if (pS->valor == x)
        {
            return (true);
        }
        pS = pS->next;
    }
    return (false);
}

void inicializar_lista(NODO **lista)
{
    *lista = NULL;
}

