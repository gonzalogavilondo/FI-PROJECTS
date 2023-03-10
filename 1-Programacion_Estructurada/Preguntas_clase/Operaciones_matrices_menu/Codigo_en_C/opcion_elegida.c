#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

void opcion_proceso(int op, int fils1, int cols1, int fils2, int cols2, const float A[FILSMAX][COLSMAX], const float B[FILSMAX][COLSMAX], float C[FILSMAX][COLSMAX])
{
    switch(op)
    {
        case 1:
            suma_matriz(fils1, cols1, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
            break;

        case 2:
            resta_matriz(fils1, cols1, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
            break;

        case 3:
            multiplicar_matrices(fils1, cols1, fils2, cols2, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX]) B, C);
            break;

        case 4:
            div_escalar(fils1, cols1, (const float (*)[COLSMAX])A, C);
            break;

        case 5:
            multiplicar_filas_matriz(fils1, cols1, (const float (*)[COLSMAX])A, C);
            break;

        case 6:
            traspuesta_matriz(fils1, cols1, (const float (*)[COLSMAX])A, C);
            break;

        /*case 7:
            adjunta_matriz(fils, cols, (const float (*)[COLSMAX])A, B);
            inversa_matriz(fils, cols, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
            break;
         */
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
        system("cls || clear");
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
