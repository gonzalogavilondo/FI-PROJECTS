#ifndef MENU_C_INCLUDED
#define MENU_C_INCLUDED

#include "declaraciones_funciones_reales.h"
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
        printf("1) SUMA.\n");
        printf("2) MULTIPLICACION.\n");
        printf("3) SALIR.\n");
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);

        if(opcion < 1 || opcion > 3)
        {
            printf("Opcion invalida.\n");
            system("pause");
        }


    }while(opcion < 1 || opcion > 3);


    return opcion;

}

#endif // MENU_C_INCLUDED
