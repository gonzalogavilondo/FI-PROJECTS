#include "myInclude.h"

#define   CANT_ALUM    3

int main()
{
    datos_alumno *alumno[CANT_ALUM];
    int dimension = CANT_ALUM,
        longitud,
        status;

    printf("Ingrese la longitud maxima para los campos nombre y apellido: ");
    scanf("%d", &longitud);

    status = reserva_memoria(&alumno[0], dimension, longitud);

    system("cls");

    if(status)
    {
        printf("\n\nLos vectores no se pueden almacenar...");
        return -1;
    }

    imprime_datos(&alumno[0], dimension);

    libera_memoria(&alumno[0], dimension);

    puts("\n\n");

    return 0;
}

