#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "declaraciones.h"

void ingreso_datos(datos_calle calles[CANTIDAD])
{
    char aux[LONGMAX];

    for(int i = 0; i < CANTIDAD; i++)
    {
        printf("Ingrese el nombre de la %i%c calle: ", i+1, 167);
        fflush(stdin);
        fgets(aux, LONGMAX, stdin);
        //Copiamos el string
        strcpy(calles[i].nombre_calle, aux);

        for(int j = 0; j < CANTIDAD; j++)
        {
            printf("\nIngrese la altura de la %i%c casa: ", j+1, 167);
            scanf("%i", &calles[i].casa.numero);
            printf("Ingrese la planta de la %i%c casa: ", j+1, 167);
            scanf("%i", &calles[i].casa.planta);

        }
        printf("\n\n-----------------------------------------\n\n");

    }

    //Pausa y borrado de pantalla
    system("pause");
    system("cls || clear");

}
void impresion_datos(const datos_calle calles[CANTIDAD])
{
    for(int i = 0; i < CANTIDAD; i++)
    {
        printf("Nombre de la %i%c calle: %s", i+1, 167, calles[i].nombre_calle);

        for(int j = 0; j < CANTIDAD; j++)
        {
            printf("\n\nLa altura de la %i%c casa: %i\n\n", j+1, 167, calles[i].casa.numero);
            printf("La planta de la %i%c casa: %i", j+1, 167, calles[i].casa.planta);
        }
        printf("\n\n-----------------------------------------\n\n");
    }


}
