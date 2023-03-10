#include "listas.h"
/*
Enunciado: Suponga que usted va a la biblioteca a ver que libros hay, ve las caracteristicas
de los libros ordenados alfabeticamente y de acuerdo a sus gustos u objetivos, debe decidir
si llevar o no un libro a su casa. Esto se ve representado en dos situaciones:
Situacion 1) Si lleva un libro, debe quitarlo de la biblioteca.
Situacion 2) Si decide no llevarlo, entonces el libro se quedara ahi.
Muestre en pantalla la situacion final de la biblioteca.

*/
int main()
{
    ///Declaracion de variables a utilizar
    int pos;
    CARACT informacion; //Estructura donde voy a guardar la informacion
    NODO *lista; //lista es un puntero a nodo.
    lista = (NODO *)malloc(sizeof(NODO));

    /*Primero tenemos que cargar los libros disponibles
    Vamos a cargar 4 libros, habia hecho un menu, donde el usuario ingresaba la cantidad de libros que quiera
    con sus caracteristicas, pero iban a tener que ingresar a mano cada libro, entonces lo hice solamente
    con 4 libros para facilitar al momento de debuggear.*/
    ///Inicializo la lista
    inicializar_lista(&lista);

    ///Inserto 4 libros
    for(int i = 1; i < CNT_LIBROS + 1; i++)
    {
        insert(&lista, i);
    }

    ///Ordenamos los libros alfabeticamente
    sort(lista);

    ///Una vez que los libros esten ordenados, buscamos el libro que el usuario quiera leer
    pos = leer(lista); //Me devuelve la posicion del libro en la biblioteca

    ///Ahora, extraemos las caracteristicas del libro sin eliminarlas, ya que queremos simplemente saber si nos interesa el libro.
    informacion = get(lista, pos);
    traverse(informacion);

    ///Ahora, le preguntamos al usuario si le interesa el libro, o si desea sacarlo de la biblioteca.
    sacar_libro(&lista, pos);

    ///Verificamos que el libro no esta mas viendo que libros hay en la biblioteca
    ver_biblioteca(lista);

    ///Liberamos memoria
    liberar_memoria(lista);

    return 0;
}
