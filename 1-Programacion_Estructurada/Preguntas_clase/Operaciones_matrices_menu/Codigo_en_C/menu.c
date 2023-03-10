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
        printf("\t||MENU DE OPERACIONES CON MATRICES||\t\n\n");
        printf("1) SUMA.\n");
        printf("2) RESTA.\n");
        printf("3) MULTIPLICACION.\n");
        printf("4) DIVISION POR ESCALAR.\n");
        printf("5) MULTIPLICACION DE FILAS.\n");
        printf("6) TRASPUESTA.\n");
        printf("7) SALIR.\n");
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);

        if(opcion < 1 || opcion > 7)
        {
            printf("Opcion invalida.\n");
            system("pause");
        }


    }while(opcion < 1 || opcion > 7);


    return opcion;

}
