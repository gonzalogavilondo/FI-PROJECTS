#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_menu.h"

int main()
{
    float n1 = 0.0;
    float n2 = 0.0;
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
            printf("Ingrese el valor del primer numero real: ");
            scanf("%f", &n1);
            printf("Ingrese el valor del segundo numero real: ");
            scanf("%f", &n2);
            opcion_proceso(opcion, n1, n2);
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
