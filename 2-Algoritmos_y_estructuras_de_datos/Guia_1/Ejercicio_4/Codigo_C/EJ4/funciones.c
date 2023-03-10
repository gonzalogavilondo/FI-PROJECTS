#include "declaraciones.h"

void condicion_final(float n)
{

    while((n < 0) || (n > 10))
    {
        printf("ERROR: Nota incorrecta.\n");
        system("pause");
        system("cls || clear");
        printf("Ingrese la nota de la asignatura nuevamente: ");
        scanf("%f", &n);
    }
    system("cls || clear");
    if(n >= 5)
    {
        printf("APROBADO\n");
    }
    else
    {
        printf("SUSPENDIDO\n");
    }
}
