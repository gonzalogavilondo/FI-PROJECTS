#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void opcion_proceso(int op, float num)
{
    float res = 0.0;

    switch(op)
    {
        case 1:
            res = sqrt(num);
            printf("La raiz cuadrada de %.2f es: %.2f\n", num, res);
            break;

        case 2:
            res = log(num);
            printf("El logaritmo natural de %.2f es: %.2f\n", num, res);
            break;

        case 3:
            res = log10(num);
            printf("El logaritmo en base 10 de %.2f es: %.2f\n", num, res);
            break;

        case 4:
            res = pow(num, 5);
            printf("%.2f elevado a la 5 es: %.2f\n", num, res);
            break;

        case 5:
            res = exp(num);
            printf("e elevado a la %.2f es: %.2f\n", num, res);
            break;

        case 6:
            res = fabs(num);
            printf("El valor absoluto de %.2f es: %.2f\n", num, res);
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
