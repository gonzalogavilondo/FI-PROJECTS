#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu(void)
{
    int opcion = 0;

    do
    {
        system("cls || clear");
        printf("\t||MENU DE OPERACIONES||\t\n\n");
        printf("1) AREA DE UNA CIRCUNFERENCIA.\n");
        printf("2) PERIMETRO DE UNA CIRCUNFERENCIA.\n");
        printf("3) VOLUMEN DE UNA ESFERA.\n");
        printf("4) SALIR.\n");
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);

        if(opcion < 1 || opcion > 4)
        {
            printf("Opcion invalida.\n");
            system("pause");
        }

    }while(opcion < 1 || opcion > 5);


    return opcion;

}
