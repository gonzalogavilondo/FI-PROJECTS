#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    //Declaracion de la estructura
    datos_calle calles[CANTIDAD];
    //Llamada a las funciones requeridas
    ingreso_datos(calles);
    impresion_datos(calles);


    return 0;
}
