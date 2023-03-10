#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototipo.h"

void copia_string(char *, char *);

int main()
{
    triangulo figura1 = { 1, 15, {10, 10}, {10, 100}, {100, 100},  "rectangulo"};
    // Para acceder a memoria pongo &figura1 como si fuese un dato cualquiera.

    /**** se modifican los valores ****/
    figura1.color_linea = 4;
    figura1.color_fondo = 14;
    figura1.verticeA.coorx = 20;
    figura1.verticeA.coory = 20;
    figura1.verticeB.coorx += 50;
    figura1.verticeB.coory += 100;
    figura1.verticeC.coorx *= 2;
    figura1.verticeC.coory *= 2 + 50;       // OJO al orden en que se hacen las operaciones
    strcpy(figura1.tipo, "escaleno");      // si no se usa strcpy hay que hacer una funcion

    copia_string(figura1.tipo, "otro tipo");

    printf("Valores de figura1 modificados: %d, %d, {%d, %d}, {%d, %d}, {%d, %d}, %s\n\n",
           figura1.color_linea, figura1.color_fondo,
           figura1.verticeA.coorx, figura1.verticeA.coory,
           figura1.verticeB.coorx, figura1.verticeB.coory,
           figura1.verticeC.coorx, figura1.verticeC.coory,
           figura1.tipo);

    return 0;
}
