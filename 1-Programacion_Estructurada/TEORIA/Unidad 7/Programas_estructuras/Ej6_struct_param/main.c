#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

int main()
{
    datos_alumno alumnos[3] = { {"Jose Perez", 1000, { {"Algebra A", {30, 11, 2014}, 6.25},
                                                       {"Matematica B", {15, 07, 2014}, 8.02},
                                                       {"Fisica A", {1, 03, 2015}, 4.50} } },    // alumno 0
                                {"Anibal Fernandez", 100, { {"Algebra A", {30, 07, 2005}, 4.25},
                                                     {"Dibujo", {15, 07, 2010}, 6.02},
                                                     /*{"Fisica A", {1, 03, 2014}, 4.50}*/ } }   // alumno 1
                                 };    // fin de ingreso de datos

    /**** para facilitar el ingreso paso el vector completo y el indice a modificar ****/
    ingresa_datos(alumnos, 2);

    /**** imprimo el listado ****/
    imprime_datos(alumnos, 3);

    return 0;
}
