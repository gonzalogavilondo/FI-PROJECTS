#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    float n;
    printf("Ingrese la nota de la asignatura: ");
    scanf("%f", &n);
    condicion_final(n);

    return 0;
}
