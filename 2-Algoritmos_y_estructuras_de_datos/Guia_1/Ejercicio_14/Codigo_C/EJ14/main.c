#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    //Declaracion de variables
    int cnt = 0;

    //Declaracion de la estructura
    datos_personales clientes[MAXCLIENTES];

    //Llamada a las funciones que realizan el proceso
    cnt = ingreso_datos(clientes);

    //Impresion de resultados
    system("cls || clear");
    printf("\nHa decidido salir del programa.\n");
    printf("\n\nDatos de los clientes guardados:");
    printf("\n\n-----------------------------------------\n\n");
    impresion_datos(clientes, cnt);

}
