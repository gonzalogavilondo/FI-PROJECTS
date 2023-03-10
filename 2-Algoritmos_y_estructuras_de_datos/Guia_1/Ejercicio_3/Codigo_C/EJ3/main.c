#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    int n;
    printf("Ingrese un numero del 1 al 12: ");
    scanf("%i", &n);
    system("cls || clear");
    mes(n);

    return 0;
}
