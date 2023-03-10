#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

void opcion_proceso(int op)
{

    switch(op)
    {
        case 1:
            printf("Instruccion1.\n");
            break;

        case 2:
            printf("Instruccion2.\n");
            break;

        case 3:
            printf("Instruccion3.\n");
            break;
    }

}
int opcion_salida(void)
{
    int si_no = 0;
    int interrogacion = 168;
    char c = '0';

    c = (char)interrogacion;
    do
    {
        system("cls || clear"); // clear es para borrar pantalla en linux
        printf("%cSeguro desea salir? <Si = 1 / No = 0>: ", c);
        scanf("%i", &si_no);

        switch(si_no)
        {
            case 0:
                printf("Has decidido volver al menu.\n");
                break;

            case 1:
                printf("Has decidido salir del programa.\n");
                break;

            default:
                printf("Opcion invalida.\n");
                system("pause");
        }

    }while(si_no < 0 || si_no > 1);

    return si_no;
}
