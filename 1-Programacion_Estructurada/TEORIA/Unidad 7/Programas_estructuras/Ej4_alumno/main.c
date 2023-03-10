#include <stdio.h>
#include <stdlib.h>

#include "prototipos.h"

void copia_string(char *, char *);

int main()
{
    struct alumno Paula;

    copia_string(Paula.nombre,"Paula Perez");

    Paula.matricula = 2002;

    Paula.fecha_nac.dia = 22;
    Paula.fecha_nac.mes = 05;
    Paula.fecha_nac.anio = 1993;

    Paula.info.tel.pais = 54;
    Paula.info.tel.ciudad = 223;
    Paula.info.tel.numero = 4816600;
    copia_string(Paula.info.correo,"paula_perez@fi.mdp.edu.ar");

    copia_string(Paula.colegio.nombre,"Comercial No 2");
    Paula.colegio.recibido.dia = 30;
    Paula.colegio.recibido.mes = 11;
    Paula.colegio.recibido.anio = 2001;
    Paula.colegio.promedio = 9.88;

    // CALCULAR EL SIZE DE LA ESTRUCTURA!!!!  VERIFICAR
    printf("\nEspacio para la estructura: %d\n\n", sizeof(Paula));// = 136  -  comprobar también el tamaño de un campo particular, por ejemplo telefono

    return 0;
}

/**************************
fecha:  int  int  int                          12 bytes = 4 + 4 + 4

telefono:  int  int  long                       12 bytes = 4 + 4 + 4

contacto:  struct telefono  char [50]           64 bytes = 12 + 50

colegio:  char [20]  struct fecha  float        36 bytes = 20 + 12 + 4

alumno:  char [20]  struct fecha  int  struct contacto  struct colegio   136 = 20 + 12 + 4 + 64 + 36
*********************/
