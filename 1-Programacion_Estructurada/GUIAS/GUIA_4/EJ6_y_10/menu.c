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
        printf("1) AREA DE UN CUADRADO.\n");
        printf("2) AREA DE UN CIRCULO.\n");
        printf("3) AREA DE UN TRIANGULO EQUILATERO.\n");
        printf("4) SALIR.\n");
        printf("\nElija una opcion: ");
        scanf("%i", &opcion);

        if(opcion < 1 || opcion > 4)
        {
            printf("Opcion invalida.\n");
            system("pause");
        }

    }while(opcion < 1 || opcion > 4);


    return opcion;

}
