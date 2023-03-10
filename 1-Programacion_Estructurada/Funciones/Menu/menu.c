#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu(void)
{
    int opcion = 0;

    do
    {
        printf("\t||MENU DE OPERACIONES||\t\n\n");
        printf("1) INSTRUCCION1.\n");
        printf("2) INSTRUCCION2.\n");
        printf("3) INSTRUCCION3.\n");
        printf("4) INSTRUCCION4.\n");
        printf("5) SALIR.\n");
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);

        if(opcion < 1 || opcion > 5)
        {
            printf("Opcion invalida.\n");
        }

    }while(opcion < 1 || opcion > 5);


    return opcion;

}
