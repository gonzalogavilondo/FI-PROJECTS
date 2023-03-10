#include "header_menu.h"

void impresion_menu (void)
{
    printf("Elija una opcion: \n");
    printf("1) Cargar el vector.\n");
    printf("2) Imprimir el vector.\n");
}

uint8_t opcion_elegida (void)
{
    uint8_t opcion = 0;
    uint8_t salir = 0;
    do
    {
        system("cls || clean");
        impresion_menu();
        scanf("%u", &opcion);
        if (opcion < 1 || opcion > 2)
        {
            printf("OPCION INCORRECTA.\n");
            system("pause");
        }
        else
        {
            salir = 1;
        }
    }while(salir == 0);
    return opcion;
}


