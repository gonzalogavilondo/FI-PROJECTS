#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "declaraciones_funciones.h"

int main()
{
    int elementos = 0;
    printf("Ingrese la cantidad de vehiculos: ");
    scanf("%i", &elementos);
    //Declaracion de la estructura
    datos_vehiculo vehiculos[LONGMAX];
    //Llamada a las funciones requeridas
    ingreso_datos(vehiculos, elementos);
    impresion_datos(vehiculos, elementos);


    return 0;
}
