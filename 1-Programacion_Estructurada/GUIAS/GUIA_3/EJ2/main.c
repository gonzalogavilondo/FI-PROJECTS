#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_menu.h"

int main()
{
    const float PI = 3.1416;
    int opcion = 0;
    int opcion2 = 0;
    float radio = 0.0;

    do
    {
        opcion = menu();
        printf("Has elegido la opcion: %i del menu.\n", opcion);
        system("pause");
        system("cls || clear"); //Limpiar pantalla para linux es clear.
        if(opcion != 4)
        {
            printf("Ingrese el valor del radio: ");
            scanf("%f", &radio);
            opcion_proceso(opcion, radio, PI);
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
