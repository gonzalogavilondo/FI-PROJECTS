#include "declaraciones_funciones_reales.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

int menu(void)
{
    int opcion = 0;

    do
    {
        printf("\t||MENU DE OPERACIONES||\t\n\n");
        printf("1) SUMA.\n");
        printf("2) RESTA.\n");
        printf("3) MULTIPLICACION.\n");
        printf("4) DIVISION.\n");
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
