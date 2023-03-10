#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_menu.h"
#include "declaraciones_pasajes.h"
int main()
{
    int opcion = 0;
    int opcion2 = 0;

    do
    {
        opcion = menu();
        printf("Has elegido la opcion: %i del menu.\n", opcion);
        system("pause");
        system("cls || clear"); //Limpiar pantalla para linux es clear.
        if(opcion != 4)
        {
            opcion_proceso(opcion);
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
