#include "declaraciones_funciones_reales.h"
#include "declaraciones_funciones.h"
#include "declaraciones_menu.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion = 0;
    int opcion2 = 0;
    int fils1 = 0;
    int cols1 = 0;
    int fils2 = 0;
    int cols2 = 0;
    char a = 'A';
    char b = 'B';
    float A[FILSMAX][COLSMAX] = {{0.0}};
    float B[FILSMAX][COLSMAX] = {{0.0}};
    float C[FILSMAX][COLSMAX] = {{0.0}};

    do
    {
        opcion = menu();
        printf("Has elegido la opcion: %i del menu.\n", opcion);
        system("pause");
        system("cls || clear"); //Limpiar pantalla para linux es clear.
        if(opcion != 7)
        {
            cargar_filas_columnas(&fils1, &cols1);
            condicion_opcion(opcion, &fils1, &cols1, &fils2, &cols2);
            inicializar_matriz(fils1, cols1, A);
            inicializar_matriz(fils2, cols2, B);
            system("cls || clear");
            if((opcion == 1) || (opcion == 2) || (opcion == 3))
            {
                completar_matriz(fils1, cols1, A, a);
                completar_matriz(fils2, cols2, B, b);
                opcion_proceso(opcion, fils1, cols1, fils2, cols2, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
                printf("-MATRIZ A-\n\n");
                mostrar_matriz(fils1, cols1, (const float (*)[COLSMAX])A);
                printf("\n-MATRIZ B-\n\n");
                mostrar_matriz(fils2, cols2, (const float (*)[COLSMAX])B);
                printf("\n-MATRIZ RESULTANTE-\n\n");
                mostrar_matriz(fils1, cols2, (const float(*)[COLSMAX])C);

            }
            else
            {
                if(opcion == 6)
                {
                    completar_matriz(fils1, cols1, A, a);
                    opcion_proceso(opcion, fils1, cols1, fils2, cols2, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
                    printf("-MATRIZ-\n\n");
                    mostrar_matriz(fils1, cols1, (const float (*)[COLSMAX])A);
                    printf("\n-MATRIZ RESULTANTE-\n\n");
                    mostrar_matriz(cols1, fils1, (const float(*)[COLSMAX])C);
                }
                else
                {
                    completar_matriz(fils1, cols1, A, a);
                    printf("-MATRIZ-\n\n");
                    mostrar_matriz(fils1, cols1, (const float (*)[COLSMAX])A);
                    opcion_proceso(opcion, fils1, cols1, fils2, cols2, (const float (*)[COLSMAX])A, (const float (*)[COLSMAX])B, C);
                    printf("\n-MATRIZ RESULTANTE-\n\n");
                    mostrar_matriz(fils1, cols1, (const float(*)[COLSMAX])C);

                }
            }
            opcion2 = 0;
        }

        else
        {
            opcion2 = opcion_salida();
        }
        system("pause");

    }while(opcion2 == 0);

    return 0;
}
