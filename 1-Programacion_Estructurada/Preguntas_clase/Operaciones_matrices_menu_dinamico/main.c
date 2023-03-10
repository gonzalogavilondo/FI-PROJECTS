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
    float **A = NULL;
    float **B = NULL;
    float **C = NULL;

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
            A = reservar_memoria(fils1,cols1);
            B = reservar_memoria(fils2,cols2);
            inicializar_matriz(fils1, cols1, A);
            inicializar_matriz(fils2, cols2, B);
            system("cls || clear");
            if((opcion == 1) || (opcion == 2) || (opcion == 3))
            {
                C = reservar_memoria(fils1, cols2);
                completar_matriz(fils1, cols1, A, a);
                completar_matriz(fils2, cols2, B, b);
                printf("-MATRIZ A-\n\n");
                mostrar_matriz(fils1, cols1, A);
                printf("\n-MATRIZ B-\n\n");
                mostrar_matriz(fils2, cols2, B);
                opcion_proceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
                printf("\n-MATRIZ RESULTANTE-\n\n");
                mostrar_matriz(fils1, cols2, C);
                //Liberamos memoria de C
                for(int i = 0; i < fils1; i++)
                {
                    free(C[i]);
                }

                free(C);
            }
            else
            {
                if(opcion == 6)
                {
                    C = reservar_memoria(cols1, fils1);
                    completar_matriz(fils1, cols1, A, a);
                    printf("-MATRIZ-\n\n");
                    mostrar_matriz(fils1, cols1, A);
                    opcion_proceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
                    printf("\n-MATRIZ RESULTANTE-\n\n");
                    mostrar_matriz(cols1, fils1, C);
                    //Liberamos memoria de C
                    for(int i = 0; i < cols1; i++)
                    {
                        free(C[i]);
                    }

                    free(C);
                }
                else
                {
                    C = reservar_memoria(fils1, cols1);
                    completar_matriz(fils1, cols1, A, a);
                    printf("-MATRIZ-\n\n");
                    mostrar_matriz(fils1, cols1, A);
                    opcion_proceso(opcion, fils1, cols1, fils2, cols2, A, B, C);
                    printf("\n-MATRIZ RESULTANTE-\n\n");
                    mostrar_matriz(fils1, cols1, C);
                    //Liberamos memoria de C
                    for(int i = 0; i < fils1; i++)
                    {
                        free(C[i]);
                    }

                    free(C);

                }
            }
            opcion2 = 0;
            //Libero memoria de A y B

            for(int i = 0; i < fils1; i++)
            {
                free(A[i]);
            }
            for(int i = 0; i < fils2; i++)
            {
                free(B[i]);
            }

            free(A);
            free(B);
        }
        else
        {
            opcion2 = opcion_salida();
        }
        system("pause");

    }while(opcion2 == 0);

    return 0;
}
