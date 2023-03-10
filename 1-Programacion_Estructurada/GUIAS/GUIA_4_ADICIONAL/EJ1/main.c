#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_menu.h"

int main()
{
    int random1 = 0;
    int random2 = 0;
    int opcion = 0;
    int opcion2 = 0;

    do
    {
        random1 = rand()%100;
        random2 = rand()%100;
        opcion = menu();
        printf("Has elegido la opcion: %i del menu.\n", opcion);
        system("pause");
        system("cls || clear"); //Limpiar pantalla para linux es clear.
        if(opcion != 3)
        {
            opcion_proceso(opcion, random1, random2);
            opcion2 = 0;
        }
        else
        {
            opcion2 = opcion_salida();
        }
        system("pause");

    }while(opcion2 == 0);

    return 0;
}
