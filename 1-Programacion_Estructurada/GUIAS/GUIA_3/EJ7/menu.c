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
        printf("1) Calcular la raiz cuadrada de un numero.\n");
        printf("2) Calcular el logaritmo natural de un numero.\n");
        printf("3) Calcular el logaritmo en base 10 de un numero.\n");
        printf("4) Calcular un numero elevado a la 5.\n");
        printf("5) Calcular 'e' elevado a un numero.\n");
        printf("6) Calcular el valor absoluto de un numero\n");
        printf("7) SALIR.\n\n");
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
