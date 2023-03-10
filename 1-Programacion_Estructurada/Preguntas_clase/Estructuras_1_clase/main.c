#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"
int main()
{
    /*
    Primera forma de inicializar (inicializando todos los campos como si fuese un vector de
                                 diferentes tipos de datos)

    persona empleado = {1965, "Juan Jacinto Jimenez", 12345.67, 'A'};

    */

    //Segunda forma de inicializar(Campo a campo)
    persona empleado = {0};
    persona empleado2 = {0};

    empleado.nombre = (char*)malloc(LONGMAX*sizeof(char));
    //empleado.nombre = "Juan Jacinto Jimenez"; (No se puede copiar un string en el campo)

    //Inicializamos campo a campo del primer empleado
    printf("Ingrese el nombre del 1%c empleado: ", 248);
    fgets(empleado.nombre, LONGMAX, stdin);
    empleado.nacimiento = 1965;
    empleado.cantidad = 12345.67;
    empleado.nacion = 'A';

    //Imprimir resultados del primer empleado:

    imprimir_resultados(empleado.nombre, empleado.nacimiento, empleado.cantidad, empleado.nacion, 1);

    //Copiamos una estructura a otra

    empleado2 = empleado;

    //Ahora hago como si empleado y empleado 2 no se pudiesen llamar igual ¡Que hago?

    empleado2 = empleado;
    empleado2.nombre = (char*)malloc(LONGMAX*sizeof(char));
    printf("\n\nIngrese el nombre del 2%c empleado: ", 248);
    fgets(empleado2.nombre, LONGMAX, stdin);

    //Imprimimos resultados del segundo empleado:

    imprimir_resultados(empleado2.nombre, empleado2.nacimiento, empleado2.cantidad, empleado2.nacion, 2);

    //Liberamos memoria

    free(empleado.nombre);
    free(empleado2.nombre);

    return 0;
}
