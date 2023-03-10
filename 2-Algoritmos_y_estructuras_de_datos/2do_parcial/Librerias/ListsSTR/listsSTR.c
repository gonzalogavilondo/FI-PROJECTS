#include <stdio.h>
#include <stdlib.h>
#include "header_listsSTR.h"

dNodeS *createDNodeS(char *x){
    dNodeS *newNode = (dNodeS*) malloc(sizeof(dNodeS));
    newNode->value = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/**************************************************************/
/*                     LISTA DE ENTEROS                       */
/**************************************************************/

/**
 *  Retorna el size de la lista.
 */
int getSizeListS(listS *l){
    if (!l) return -1;
    return l->size;
}

/**
 *  Settea el size de la lista.
 */
void setSizeListS(listS *l, int size){
    if (!l) return;
    l->size = size;
}

/**
 *  Crea una lista con punteros a NULL y size 0.
 */
listS *createListS(){
    listS *l = (listS *) malloc(sizeof(listS));
	l->first = NULL;
	l->last = NULL;
	setSizeListS(l, 0);
	return l;
}

/**
 *  Retorna si una lista está vacía.
 */
int isEmptyListS(listS *l){
    if (!l) return 1;
    return (getSizeListS(l) == 0);
}

/**
 *  Inserta un elemento en una lista vacía. Retorna si la inserción fue exitosa.
 */
int insertEmptyListS(listS *l, char *x){
    if (!l) return 0;

    dNodeS *newNode = createDNodeS(x);
    l->first = newNode;
    l->last = newNode;
    setSizeListS(l, getSizeListS(l) + 1);
    return 1;
}

/**
 *  Inserta un elemento al principio de una lista.
 *  Retorna si la inserción fue exitosa.
 */
int insertFirstListS(listS *l, char *x){
    if (!l) return 0;

    if (isEmptyListS(l)){
        insertEmptyListS(l, x);
    } else {
        dNodeS *newNode = createDNodeS(x);
        dNodeS *first = l->first;

        newNode->next = l->first;
        first->prev = newNode;

        l->first = newNode;     //Update al first
        setSizeListS(l, getSizeListS(l) + 1);;
    }
    return 1;
}

/**
 *  Inserta un elemento al final de una lista.
 *  Retorna si la inserción fue exitosa.
 */
int insertLastListS(listS *l, char *x){
    if (!l) return 0;

    if (isEmptyListS(l)){
        insertEmptyListS(l, x);
    } else {
        dNodeS *newNode = createDNodeS(x);
        dNodeS *last = l->last;

        newNode->prev = l->last;

        last->next = newNode;
        l->last = newNode;      //Update al last
        setSizeListS(l, getSizeListS(l) + 1);;
    }
    return 1;
}


/**
 *  Inserta un elemento en una posición de la lista.
 *  Retorna si la inserción fue exitosa.
 */
int insertPosListS(listS *l, int pos, char *x){
    if (!l) return 0;
    if (pos > getSizeListS(l) || pos < 0) return 0;

    int result;

    if (pos == 0 || pos == getSizeListS(l)){
            if (pos == 0){
                result = insertFirstListS(l, x);
            } else {
                result = insertLastListS(l, x);
            }
    } else {
        dNodeS *newNode = createDNodeS(x);
        dNodeS *current = l->first;
        dNodeS *aux;

        for (int i = 0; i < pos; i++){   //se posiciona en el elemento actual
            current = current->next;
        }

        newNode->next = current;       //el actual se vuelve el siguiente
        newNode->prev = current->prev; //el anterior del actual se vuelve el anterior del nodo nuevo

        aux = current->prev;        //guardo la ref. del anterior al actual
        current->prev = newNode;    //el anterior al actual es el nuevo
        aux->next = newNode;          //el sig. del anterior es nuevo


        setSizeListS(l, getSizeListS(l) + 1);;
        result = 1;
    }

    return result;
}

/**
 *  Elimina el primer elemento de una lista.
 *  Retorna si la eliminación fue exitosa.
 */
int deleteFirstListS(listS **l){
    if (!l) return 0;
    if (isEmptyListS(*l)) return 0;

    if (getSizeListS(*l) == 1){ //si tiene un elemento me devuelve una lista vacia
        *l = createListS();
    } else {
        dNodeS *first = (*l)->first;
        dNodeS *next = first->next;

        (*l)->first = next;   //actualizo el first
        next->prev = NULL;   //al ser el primero queda el prev apuntando a NULL

        setSizeListS((*l), getSizeListS((*l)) - 1);;
        free(first);
    }
    return 1;
}

/**
 *  Elimina el último elemento de una lista.
 *  Retorna si la eliminación fue exitosa.
 */
int deleteLastListS(listS **l){
    if (!l) return 0;
    if (isEmptyListS(*l)) return 0;

    if (getSizeListS((*l)) == 1){ //si tiene un elemento me devuelve una lista vacia
        *l = createListS();
    } else {
        dNodeS *last = (*l)->last;
        dNodeS *prev = last->prev;

        (*l)->last = prev;   //actualizo el last
        prev->next = NULL;   //al ser el ultimo queda el next apuntando a NULL

        setSizeListS((*l), getSizeListS((*l)) - 1);
        free(last);
    }
    return 1;
}

/**
 *  Elimina un elemento en una posición de la lista.
 *  Retorna si la eliminación fue exitosa.
 */
int deletePosListS(listS **l, int pos){
    if (!l) return 0;
    if (pos >= getSizeListS((*l)) || pos < 0) return 0;

    int result = 0;

    if (pos == 0 || pos == getSizeListS((*l)) - 1){
            if (pos == 0){
                result = deleteFirstListS(l);
            } else {
                result = deleteLastListS(l);
            }
    } else {
        dNodeS *current = (*l)->first;
        dNodeS *aux;

        for (int i = 0; i < pos; ++i){ //se posiciona en el nodo actual
            current = current->next;
        }

        aux = current->prev;        //apunto el anterior del actual, al siguiente del actual
        aux->next = current->next;

        aux = current->next;     //apunto el siguiente del actual, al anterior del actual
        aux->prev = current->prev;

        free(current);   //libero el nodo actual
        setSizeListS((*l), getSizeListS((*l)) - 1);
        result = 1;
    }

    return result;
}

/**
 *  Recupera el valor en una posición de una lista y lo retorna.
 *  En caso de error retorna ECL(definido en la cabecera).
 */
char *getValueListS(listS *l, int pos)
{
    if (!l) return NULL;
    if (pos >= getSizeListS(l) || pos < 0) return NULL;

    dNodeS *current = l->first;
    for (int i = 0; i < pos; i++){   ///se posiciona en el nodo actual
        current = current->next;
    }

    return current->value;
}

/**
 *  Settea un valor en la lista en una posición.
 */
 int setValueListS(listS *l, int pos, char *x){
    if (!l) return 0;
    if (pos >= getSizeListS(l)) return 0;

    dNodeS *current = l->first;
    for (int i = 0; i < pos; i++){   //se posiciona en el elemento actual
        current = current->next;
    }

    current->value = x;
    return 1;

}

/**
 *  Imprime una lista.
 */
int printListS(listS *l){
    if (!l) return 0;
    if (isEmptyListS(l)) return 0;

    dNodeS *current = l->first;
    for (int i = 0; i < getSizeListS(l); i++){
        printf(" %s ", current->value);
        current = current->next;
    }
    printf("\n");
    return 1;
}



