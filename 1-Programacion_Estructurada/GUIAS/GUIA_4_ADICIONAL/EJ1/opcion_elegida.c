#include "declaraciones_funciones_reales.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

void opcion_proceso(int op, int n1, int n2)
{
    int num = 0;
    int res = 0;

    switch(op)
    {
        case 1:
            res = suma(n1, n2);
            printf("%i + %i = ", n1, n2);
            scanf("%i", &num);
            carteles(num, res);
            break;

        case 2:
            res = multiplicacion(n1, n2);
            printf("%i * %i = ", n1, n2);
            scanf("%i", &num);
            carteles(num, res);
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
