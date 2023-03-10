#include "declaraciones_funciones_reales.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

void opcion_proceso(int op)
{
    float l = 0.0;
    float r = 0.0;
    float res = 0.0;

    switch(op)
    {
        case 1:
            printf("Escriba cuanto mide el lado del cuadrado: ");
            scanf("%f", &l);
            res = area_cuadrado(l);
            printf("El area del cuadrado es de: %.2f\n", res);
            break;

        case 2:
            printf("Escriba cuanto mide el radio del circulo: ");
            scanf("%f", &r);
            res = area_circulo(r);
            printf("El area del circulo es de: %.2f\n", res);
            break;

        case 3:
            printf("Escriba cuanto mide el lado del triangulo: ");
            scanf("%f", &l);
            res = area_triangulo(l);
            printf("El area del triangulo es de: %.2f\n", res);
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
