#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void imprimir_resultados(char *nombre, int nacimiento, float cantidad, char nacion, int identificador)
{
    printf("\n\nEl nombre del %i%c empleado es: %s", identificador, 248, nombre);
    printf("La fecha de nacimiento del %i%c empleado es: %i\n",identificador, 248, nacimiento);
    printf("La cantidad del %i%c empleado es: %f\n", identificador, 248, cantidad);
    printf("La nacionalidad del empleado %i%c es: %c\n", identificador, 248, nacion);
}

