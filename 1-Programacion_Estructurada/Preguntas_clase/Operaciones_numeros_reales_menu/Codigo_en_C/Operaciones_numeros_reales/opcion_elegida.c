#include "declaraciones_funciones_reales.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

void opcion_proceso(int op, float n1, float n2)
{
    float res = 0.0;

    switch(op)
    {
        case 1:
            res = suma(n1, n2);
            printf("La suma entre %.2f y %.2f es: %.2f\n", n1, n2, res);
            break;

        case 2:
            res = resta(n1, n2);
            printf("La resta entre %.2f y %.2f es: %.2f\n", n1, n2, res);
            break;

        case 3:
            res = multiplicacion(n1, n2);
            printf("La multiplicacion entre %.2f y %.2f es: %.2f\n", n1, n2, res);
            break;

        case 4:
            if(n2 == 0)
            {
                printf("La division por '0' no esta definida.\n");
            }
            else
            {
                res = division(n1, n2);
                printf("La division entre %.2f y %.2f es: %.2f\n", n1, n2, res);
            }
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
