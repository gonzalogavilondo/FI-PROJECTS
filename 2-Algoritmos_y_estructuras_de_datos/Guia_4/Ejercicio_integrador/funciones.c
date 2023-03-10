#include "listas.h"

NODO *cargar_libro(int pos)
{
    if(pos == 1)
    {
        char aux1[LONGMAX] = "Fundamentos de programacion";
        char aux2[LONGMAX] = "Didactico";
        //Declaramos un puntero a nodo y lo igualamos a lista
        NODO *libro;
        //Reservamos memoria para el nuevo nodo
        libro = (NODO*)malloc(sizeof(NODO));

        //Cargamos el libro
        strcpy(libro->libro.nombre, aux1);
        strcpy(libro->libro.genero_literario, aux2);
        libro->libro.cnt_paginas = 690;
        libro->libro.cnt_capitulos = 18;
        libro->libro.posicion = pos;
        return libro;
    }
    else if(pos == 2)
    {
        char aux1[LONGMAX] = "Crepusculario";
        char aux2[LONGMAX] = "Lirico";
        //Declaramos un puntero a nodo y lo igualamos a lista
        NODO *libro;

        //Reservamos memoria para el nuevo nodo
        libro = (NODO*)malloc(sizeof(NODO));

        //Cargamos el libro
        strcpy(libro->libro.nombre, aux1);
        strcpy(libro->libro.genero_literario, aux2);
        libro->libro.cnt_paginas = 400;
        libro->libro.cnt_capitulos = 9;
        libro->libro.posicion = pos;
        return libro;
    }
    else if(pos == 3)
    {
        char aux1[LONGMAX] = "Mitologia Griega";
        char aux2[LONGMAX] = "Narrativo";
        NODO *libro;

        //Reservamos memoria para el nuevo nodo
        libro = (NODO*)malloc(sizeof(NODO));

        //Cargamos el libro
        strcpy(libro->libro.nombre, aux1);
        strcpy(libro->libro.genero_literario, aux2);
        libro->libro.cnt_paginas = 890;
        libro->libro.cnt_capitulos = 23;
        libro->libro.posicion = pos;
        return libro;
    }
    else
    {
        char aux1[LONGMAX] = "Romeo y Julieta";
        char aux2[LONGMAX] = "Dramatico";
        //Declaramos un puntero a nodo y lo igualamos a lista
        NODO *libro;

        //Reservamos memoria para el nuevo nodo
        libro = (NODO*)malloc(sizeof(NODO));

        //Cargamos el libro
        strcpy(libro->libro.nombre, aux1);
        strcpy(libro->libro.genero_literario, aux2);
        libro->libro.cnt_paginas = 700;
        libro->libro.cnt_capitulos = 20;
        libro->libro.posicion = pos;
        return libro;
    }
}

int leer(NODO* lista)
{
    int pos;
    int existe;
    char aux[LONGMAX];

    do
    {
        pos = 1;
        //Vemos la biblioteca
        ver_biblioteca(lista);
        printf("Ingrese el nombre del libro que desea llevar: ");
        fflush(stdin);
        scanf("%[^\n]", aux);
        //Ahora, tenemos que buscar el libro, llamamos a la funcion search para corroborar si existe
        existe = search(lista, &pos, aux);
        if(existe == 1)
        {
            printf("El libro existe y esta en la posicion: %d.\n", pos);
        }
        else
        {
            printf("El libro que ha escrito no existe.\n");
        }
        system("pause");
        system("cls || clear");

    }while(existe != 1);

    return pos;

}

void sacar_libro(NODO **lista, int pos)
{
    int opcion = 0;
    do
    {
        printf("%cDesea quitar el libro de la biblioteca? <SI = 1/NO = 2>: ", 168);
        scanf("%d", &opcion);
        if(opcion == 1)
        {
            deletee(lista, pos);
            printf("El libro de la posicion %d se ha quitado de la biblioteca.\n", pos);
        }
        else if(opcion == 2)
        {
            printf("Se ha dejado el libro en la posicion %d\n", pos);
        }
        else
        {
            printf("Opcion invalida.\n");
        }
        system ("pause");
        system("cls || clear");

    }while(opcion != 1 && opcion != 2);
}

void ver_biblioteca(NODO *lista)
{
    CARACT informacion;

    printf("\t\t  -BIBLIOTECA-\n");
    for(int i = 1; i <= length(lista); i++)
    {
        informacion = get(lista, i);
        traverse(informacion);
    }
}
