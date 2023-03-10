#include "listas.h"

void liberar_memoria() //Libera memoria.
{
    NODO *pS = LISTA;
    NODO *borrar;
    while (pS != NULL)
    {
        borrar = pS;
        pS = pS->next;
        free(borrar);
    }
}

bool isEmpty() //Retorna 1 si la lista esta vacía y 0 si no lo está.
{
    if (LISTA == NULL)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

int length() //Retorna la cantidad de nodos en la lista.
{
    NODO *pS = LISTA;
    int cnt = 0;
    while (pS != NULL)
    {
        cnt++;
        pS = pS->next;
    }
    return cnt;
}

void insert(int pos) //Insertar un elemento en la lista en "pos".
{
    if (pos <= length() + 1)
    {
        NODO *nuevo;
        nuevo = (NODO*)malloc(sizeof(NODO));
        nuevo = cargar_alumno(pos);
        if (pos == 1) //Ahora a el nodo lo enlazo en la lista, si lo inserto como primer elemento de la lista, entonces debo reacomodar la lista
        {
            nuevo->next = LISTA; //Ahora next apunta al primer elemento de la lista
            LISTA = nuevo;       //Igualamos la lista con la direccion del primer nodo
        }
        else
            if (pos == length() + 1) //Este es el caso si el nodo lo inserto al final de la lista
            {
                NODO *pS = LISTA; //Creamos un puntero al inicio de la lista
                while (pS->next != NULL) //Vamos avanzando en la lista y recorriendola
                {
                    pS = pS->next;
                }                       //Cuando salimos del while, es porque llegamos al ultimo lugar
                pS->next = nuevo;       //Entonces enlazamos el ultimo nodo de la lista que tiene NULL con el nuevo
                nuevo->next = NULL;     //Como es el ultimo, el siguiente va a ser NULL.
            }
            else                        //Si no ingresamos ni al principio, ni al final el nuevo nodo, entonces estamos en este caso
            {
                NODO *pS = LISTA; //Creamos un nuevo nodo apuntando al primer elemento de la lista
                for (int i = 1; i <= pos - 2; i++) //Recorremos la lista y avanzamos hasta la posicion ANTERIOR a la que vamos a insertar, para engancharlo con el nuevo nodo
                {
                    pS = pS->next;
                }                                 //Una vez que termino el for, estamos en la posicion ANTERIOR a la que queremos tener el nuevo nodo.
                NODO *siguiente = pS->next;       //Creamos un puntero que apunte a el nodo siguiente que es donde se va a insertar el nuevo nodo
                pS->next = nuevo;                 //Enlazamos el nuevo nodo
                nuevo->next = siguiente;          //Ponemos el nuevo next apuntando a siguiente.
            }
    }
}

void traverse(CARRERA informacion) //Imprime o recorre la lista.
{
    //Imprimimos la informacion del libro
    puts("----------------------------------------------------");
    printf("Nombre: %s\n", informacion.nombre);
    printf("Numero de matricula: %d\n", informacion.matricula);
    printf("Porcentaje de materias aprobadas: %d\n", informacion.porcentaje_materias_ap);
    puts("----------------------------------------------------");
}


CARRERA get(int pos) //Extrae la informacion del nodo de la posicion "pos" sin eliminarlo.
{
    CARRERA informacion;
    if (pos <= length())
    {
        if (pos == 1) //Si la posicion es el primer valor de la lista
        {
            informacion = LISTA->alumno; //Extraemos la informacion en la primera posicion de la lista
        }
        else
        {
            NODO *aux = LISTA;    //Creamos un puntero auxiliar que apunta al primer elemento de la lista
            for (int i = 1; i <= pos - 2; i++)//Recorremos la lista hasta el nodo ANTERIOR al que queremos extraer
            {
                aux = aux->next;
            }
            NODO *prox = aux->next; //Cuando sale del for, definimos el nuevo puntero que apunte al siguiente nodo, que es el que vamos a extraer
            informacion = prox->alumno; //Asignamos a la informacion todo lo que queremos extraer.
        }
    }
    return informacion;
}

void deletee(int pos) //Elimina el nodo de la posicion "pos" pero sin devolver informacion.
{
    if (pos <= length()) //Validacion de la posicion.
    {
        NODO *borrar;
        if (pos == 1)   //Si el nodo que queremos eliminar esta en la primera posicion.
        {
            borrar = LISTA;
            LISTA = LISTA->next;
        }
        else
        {
            NODO *pS = LISTA;
            for (int i = 1; i <= pos - 2; i++)
            {
                pS = pS->next;
            }                       //Cuando terminamos este for estamos una posicion antes de la que tenemos que borrar
            NODO *prox = pS->next; //Nos paramos donde tenemos que borrar.
            pS->next = prox->next; //Salteamos el que vamos a borrar
            borrar = prox; //Lo borramos
        }
        free(borrar);
    }
}

bool sort() //Debe retornar 1 si la lista esta ordenada de menor a mayor, 0 en caso contrario.
{
    int cnt = 1;
    if (length() > 1)
    {
        NODO *pS1 = LISTA;
        NODO *pS2 = LISTA->next;
        while (pS2 != NULL)
        {
            if(pS1->alumno.matricula < pS2->alumno.matricula)
            {
                //Estan bien ordenados.
            }
            else
            {
                intercambiar(cnt, cnt+1); //Si no esta ordenado, intercambiamos
            }
            cnt++;
            pS1 = pS1->next;
            pS2 = pS2->next;
        }
    }
    return (true);
}

void intercambiar(int pos1, int pos2) //Intercambia las informaciones de los nodos en las posiciones "pos1" con "pos2"
{
    char aux1[LONGMAX];
    int aux2, aux3;
    if (pos1 <= length() && pos2 <= length())
    {
        NODO *pS1 = LISTA;
        for (int i = 1; i < pos1; i++)
        {
            pS1 = pS1->next;
        }
        NODO *pS2 = LISTA;
        for (int i = 1; i < pos2; i++)
        {
            pS2 = pS2->next;
        }
        //Intercambiamos los datos con el metodo Bubble sort

        //Nombre
        strcpy(aux1, pS1->alumno.nombre);
        strcpy(pS1->alumno.nombre, pS2->alumno.nombre);
        strcpy(pS2->alumno.nombre, aux1);
        //Numero de matricula
        aux2 = pS1->alumno.matricula;
        pS1->alumno.matricula = pS2->alumno.matricula;
        pS2->alumno.matricula = aux2;
        //Porcentaje de materias aprobadas
        aux3 = pS1->alumno.porcentaje_materias_ap;
        pS1->alumno.porcentaje_materias_ap = pS2->alumno.porcentaje_materias_ap;
        pS2->alumno.porcentaje_materias_ap = aux3;
    }
}
