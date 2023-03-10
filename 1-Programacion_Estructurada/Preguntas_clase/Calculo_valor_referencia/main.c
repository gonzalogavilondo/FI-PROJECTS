#include <stdio.h>
#include <locale.h>
#include "declaraciones_funciones.h"

int main()
{
    float n1 = 0.0;
    float n2 = 0.0;
    float suma = 0.0;
    float mult = 0.0;

    printf("Digite el primer numero real: ");
    scanf("%f", &n1);
    printf("Digite el primer numero real: ");
    scanf("%f", &n2);
    suma = calculo(n1, n2, &mult);
    printf("El resultado de la suma es: %.2f\n", suma);
    printf("El resultado de la multiplicacion es: %.2f\n", mult);

    return 0;
}
