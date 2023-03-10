#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "declaraciones.h"

int ingreso_datos(datos_personales clientes[MAXCLIENTES])
{
    int i = 0;
    int opcion = 1;
    char aux[LONGMAX];

    while(opcion != 0 && i < MAXCLIENTES)
    {
        printf("Ingrese el nombre del %i%c cliente: ", i+1, 167);
        fflush(stdin);
        fgets(aux, LONGMAX, stdin);
        //Copiamos el string
        strcpy(clientes[i].nombre, aux);
        printf("\nIngrese los apellidos: ");
        fflush(stdin);
        fgets(aux, LONGMAX, stdin);
        strcpy(clientes[i].apellidos, aux);
        printf("\nIngrese el mail: ");
        fflush(stdin);
        fgets(aux, LONGMAX, stdin);
        strcpy(clientes[i].mail, aux);
        printf("\nIngrese el telefono: ");
        scanf("%i", &clientes[i].telefono);
        printf("\n\n-----------------------------------------\n\n");
        printf("%cDesea continuar agregando datos de clientes? <NO> = <0>: ", 168);
        scanf("%i", &opcion);
        printf("\n\n-----------------------------------------\n\n");

        i++;
    }

    //Pausa y borrado de pantalla
    system("pause");
    system("cls || clear");

    return i;
}

void impresion_datos(const datos_personales clientes[MAXCLIENTES], int contador)
{
    for(int i = 0; i < contador; i++)
    {
        printf("Nombre del %i%c cliente: %s", i+1, 167, clientes[i].nombre);
        printf("\nApellidos: %s", clientes[i].apellidos);
        printf("\nMail: %s", clientes[i].mail);
        printf("\nTelefono: %i", clientes[i].telefono);
        printf("\n\n-----------------------------------------\n\n");
    }

}
