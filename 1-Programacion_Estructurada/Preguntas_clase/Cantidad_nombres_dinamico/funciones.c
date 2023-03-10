#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declaraciones_funciones.h"

char** reservar_memoria_personas(int cantidad_personas)
{
    char **cadenas = NULL;
    //Reservamos memoria para el puntero doble, que seria la cantidad de personas, que a su vez este va a apuntar a el nombre de cada persona.
    cadenas = (char**)malloc(cantidad_personas*sizeof(char*));
    if(cadenas == NULL)
    {
        printf("No se ha podido reservar espacio en memoria.\n");
        exit(0);
    }

    return cadenas;
}
