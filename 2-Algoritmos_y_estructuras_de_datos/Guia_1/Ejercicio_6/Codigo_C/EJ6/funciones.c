#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int completar_vector(int vector[COLSMAX])
{
    int elementos = 0;
    int j;

    for(j = 0; j < COLSMAX; j++)
    {
        printf("\t-COMPLETE EL VECTOR:-\n\n");
        printf("Digite un valor para el elemento[%i]: ", j+1);
        scanf("%i", &vector[j]);
        system("cls || clear"); //Para que funcione tambien en linux el "clear"
        if(vector[j] == 0)
        {
            elementos = j;
            imprimir_vector(vector, elementos, 1);
            completar_vector_2(vector, elementos);
            exit(0);

        }

    }

    return 1;

}
void imprimir_vector(int vector[COLSMAX], int elementos, int num_vec)
{
    printf("\t\t-VECTOR %i:-\n\n", num_vec);
    printf("|\t");
    for(int j = 0; j < elementos; j++)
    {
        printf("%i\t", vector[j]);
    }
    printf("|\n\n");

}

void completar_vector_2(int vector[COLSMAX], int elementos)
{
    int vector2[COLSMAX] = {0};
    for(int j = 0; j < elementos; j++)
    {
        vector2[j] = vector[elementos-1-j]; //Aca es donde almaceno el vector 1 al vector 2 de forma inversa.
    }
    imprimir_vector(vector2, elementos, 2);

}

