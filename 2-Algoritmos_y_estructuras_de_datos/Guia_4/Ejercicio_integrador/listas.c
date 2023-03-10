#include "listas.h"

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

void insert(NODO **lista, int pos) //Insertar un elemento en la lista en "pos".
{
    if (pos <= CNT_LIBROS + 1)//Controlamos que existe la posicion pasada, lo hacemos si la posicion es menor o igual que la cantidad de nodos +1
    {                       //El +1 es porque si la lista esta vacia me devuelve 0 y yo quiero insertar en la posicion 1 por ejemplo.
        NODO *nuevo; //Creo el nuevo nodo
        nuevo = (NODO*)malloc(sizeof(NODO)); //Asigno memoria para el nuevo nodo.
        nuevo = cargar_libro(pos); //Guardo la informacion.
        if (pos == 1) //Ahora a el nodo lo enlazo en la lista, si lo inserto como primer elemento de la lista, entonces debo reacomodar la lista
        {
            nuevo->next = *lista; //next apunta ahora al primero de la lista.
            *lista = nuevo;       //Igualamos la lista con la direccion del primer nodo.
        }
        else
        {
            if (pos == CNT_LIBROS + 1) //Este es el caso si el nodo lo inserto al final de la lista
            {
                NODO *pS = *lista; //Creamos un puntero al inicio de la lista
                while (pS->next != NULL) //Vamos recorriendo en la lista
                {
                    pS = pS->next;
                }                       //Cuando salimos del while, es porque llegamos al ultimo lugar
                pS->next = nuevo;       //Entonces enlazamos el ultimo nodo de la lista que tiene NULL con el nuevo
                nuevo->next = NULL;     //Como es el ultimo, el siguiente va a ser NULL.
            }
            else                         //Si no ingresamos ni al principio, ni al final el nuevo nodo, entonces estamos en este caso
            {
                NODO *pS = *lista; //Creamos un nuevo nodo apuntando al primer elemento de la lista
                for (int i = 1; i <= pos - 2; i++) //Recorremos la lista y avanzamos hasta la posicion ANTERIOR a la que vamos a insertar, para engancharlo con el nuevo nodo
                {
                    pS = pS->next;
                }                               //Una vez que termino el for, estamos en la posicion ANTERIOR a la que queremos tener el nuevo nodo.
                NODO *siguiente = pS->next;  //Creamos un puntero que apunte a el nodo siguiente que es donde se va a insertar el nuevo nodo
                pS->next = nuevo;            //Enlazamos el nuevo nodo
                nuevo->next = siguiente;     //Ponemos el nuevo next apuntando a siguiente
           }
        }
    }

}

void traverse(CARACT informacion) //Imprime o recorre la lista.
{
    //Imprimimos la informacion del libro
    puts("----------------------------------------------------");
    printf("Nombre: %s\n", informacion.nombre);
    printf("Genero literario: %s\n", informacion.genero_literario);
    printf("Cantidad de paginas: %d\n", informacion.cnt_paginas);
    printf("Cantidad de capitulos: %d\n", informacion.cnt_capitulos);
    printf("Posicion: %d\n", informacion.posicion);
    puts("----------------------------------------------------");
}


CARACT get(NODO *lista, int pos) //Extrae la informacion del nodo de la posicion "pos" sin eliminarlo.
{
    CARACT informacion;
    if (pos <= length(lista))
    {
        if (pos == 1) //Si no es la posicion 1 el nodo que queremos extraer, entonce seguimos
        {
            informacion = lista->libro; //Extraigo la informacion de la primera posicion.
        }
        else
        {
            NODO *aux = lista;
            for (int i = 1; i <= pos - 2; i++)
            {
                aux = aux->next;
            }                          //Cuando termine el for, voy a estar en la posicion ANTERIOR a lo que quiero extraer
            NODO *prox = aux->next;    //Me paro en la posicion que quiero extraer.
            informacion = prox->libro; //Asigno el contenido en informacion.
        }
    }
    return informacion;
}

void deletee(NODO **lista, int pos) //Elimina el nodo de la posicion "pos" pero sin devolver informacion.
{
    if (pos <= length(*lista))
    {
        NODO *borrar;
        if (pos == 1)
        {
            NODO *aux = *lista;
            borrar = aux;
            aux = aux->next; //Ahora, lista avanza al siguiente nodo como primer elemento.
            *lista = aux;
        }
        else
        {
            NODO *pS = *lista;
            for (int i = 1; i <= pos - 2; i++)
            {
                pS = pS->next;
            }                       //Estamos en la posicion ANTERIOR a la que queremos borrar
            NODO *prox = pS->next; //Nos paramos donde tenemos que borrar.
            pS->next = prox->next; //Salteamos el que vamos a borrar.
            borrar = prox; //Lo borramos
        }
        free(borrar);
    }
}

bool sort(NODO *lista) //Debe retornar 1 si la lista esta ordenada de menor a mayor, 0 en caso contrario.
{
    int cnt = 1;
    if (length(lista) > 1)
    {
        NODO *pS1 = lista;
        NODO *pS2 = lista->next;

        while (pS2 != NULL)
        {
            /*strcmp compara lexicográficamente dos cadenas strcmp(palabra1, palabra2).
            -Si palabra1<palabra2 devuelve un número negativo.
            -Si palabra1>palabra2 devuelve un numero positivo.
            -Si palabra1=palabra2 devuelve 0*/
            if(strcmp(pS1->libro.nombre, pS2->libro.nombre) < 0)
            {
                //Libros ordenados correctamente.
            }
            else
            {
                intercambiar(lista, cnt, cnt+1); //Si no esta ordenado, intercambiamos
            }
            pS1 = pS1->next;
            pS2 = pS2->next;
            cnt++;
        }
    }
    return (true);
}

bool search(NODO *lista, int *pos, char aux[LONGMAX]) //Debe retornar 1 si existe la informacion que llega en el parametro, 0 en caso contrario.
{
    NODO *pS = lista;
    while (pS != NULL)
    {
        /*strcmp compara lexicográficamente dos cadenas strcmp(palabra1, palabra2).
        -Si palabra1<palabra2 devuelve un número negativo.
        -Si palabra1>palabra2 devuelve un numero positivo.
        -Si palabra1=palabra2 devuelve 0*/
        if(strcmp(pS->libro.nombre, aux) == 0)
        {
            return (true);
        }
        pS = pS->next;
        *pos = *pos + 1;
    }
    return (false);
}

void intercambiar(NODO *lista, int pos1, int pos2) //Intercambia las informaciones de los nodos en las posiciones "pos1" con "pos2"
{
    char aux[LONGMAX];
    int aux2;
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

        ///Intercambiamos los datos con el metodo Bubble sort

        ///Nombre
        strcpy(aux, pS1->libro.nombre);
        strcpy(pS1->libro.nombre, pS2->libro.nombre);
        strcpy(pS2->libro.nombre, aux);

        ///Genero literario
        strcpy(aux, pS1->libro.genero_literario);
        strcpy(pS1->libro.genero_literario, pS2->libro.genero_literario);
        strcpy(pS2->libro.genero_literario, aux);

        ///Cantidad de capitulos
        aux2 = pS1->libro.cnt_capitulos;
        pS1->libro.cnt_capitulos = pS2->libro.cnt_capitulos;
        pS2->libro.cnt_capitulos = aux2;

        ///Cantidad de paginas
        aux2 = pS1->libro.cnt_paginas;
        pS1->libro.cnt_paginas = pS2->libro.cnt_paginas;
        pS2->libro.cnt_paginas = aux2;

        ///Posicion
        aux2 = pS1->libro.posicion;
        pS1->libro.posicion = pS2->libro.posicion;
        pS2->libro.posicion = aux2;
    }
}
void inicializar_lista(NODO **lista)
{
    *lista = NULL;
}
