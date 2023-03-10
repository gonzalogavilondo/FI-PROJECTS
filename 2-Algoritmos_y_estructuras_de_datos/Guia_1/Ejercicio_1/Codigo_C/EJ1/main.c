#include "declaraciones.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    int b;
    int res_s;
    int res_m;

    printf("Introduzca el primer entero: ");
    scanf("%i", &a);
    printf("Introduzca el segundo entero: ");
    scanf("%i", &b);
    res_s = suma(a, b);
    res_m = multiplicacion(a, b);
    system("cls || clear");
    printf("El resultado de la suma es: %i\n", res_s);
    printf("El resultado de la multiplicacion es: %i ", res_m);

    return 0;
}
