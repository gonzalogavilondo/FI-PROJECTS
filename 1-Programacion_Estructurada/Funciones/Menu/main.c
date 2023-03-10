#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_menu.h"

int main()
{
    int opcion = 0;
    int opcion2 = 0;

    do
    {
        system("cls || clear");
        opcion = menu();
        printf("Has elegido la opcion: %i del menu.\n", opcion);
        system("pause");
        system("cls || clear"); //Limpiar pantalla para linux es clear.
        if(opcion != 5)
        {
            opcion_proceso(opcion);
            system("pause");
            system("cls || clear");
            opcion2 = 0;

        }
        else
        {
            opcion2 = opcion_salida();
            system("pause");
        }

    }while(opcion2 == 0);

    return 0;
}
