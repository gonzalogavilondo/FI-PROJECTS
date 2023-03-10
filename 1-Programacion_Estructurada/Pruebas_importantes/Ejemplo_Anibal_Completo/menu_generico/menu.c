#include <stdio.h>
#include <ctype.h> //uso de tolower:
#include "menu.h"
#include "entrada_salida.h"

#define MENU_INDEX_OPERACION_INCORRECTA -1

void menu_mostrar()
{
    for (int i = 0; i < menu_cant_elems ; i++)
    {
        printf("[%c] %s\n", menu_opciones[i], menu_textos[i]);
    }
}

int menu_index_operacion(unsigned char c)
{
    int mapea = 0;
    int i = 0;
    while ( ! mapea && i < menu_cant_elems )
    {
        if (c == menu_opciones[i])
        {
            mapea = 1;
        }
        else
        {
            i++;
        }
    }
    if(mapea)
    {
        return i;
    }
    return -1;
}

int menu_confirmar_salida()
{
    unsigned char s;
    printf("¿Confirma Salir? 's' para sí ");
    s = leer_stdin();
    s = tolower(s);
    return s == 's';
}

int menu_operacion()
{
    unsigned char c;
    int index_operacion;
    do
    {
        borrar_stdout();
        menu_mostrar();
        printf("Ingrese una opción: ");
        c = leer_stdin();
        index_operacion = menu_index_operacion(c);
        if(index_operacion == MENU_INDEX_OPERACION_INCORRECTA)
        {
            printf("Opción incorrecta!\n");
            getchar();
        }

    }while(index_operacion == MENU_INDEX_OPERACION_INCORRECTA
           || (menu_operaciones[index_operacion] == MENU_OPERACION_FIN && ! menu_confirmar_salida()));
    return menu_operaciones[index_operacion];
}


