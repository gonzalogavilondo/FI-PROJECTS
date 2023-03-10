#include "declaraciones_menu.h"
#include "declaraciones_pasajes.h"
#include <stdio.h>

void decimal_a_hexadecimal (int numero)
{
    printf("El numero %i en hexadecimal es: %X \n", numero, numero);
}

void hexadecimal_a_decimal (int numero)
{
    printf("El numero %X en decimal es: %d \n", numero, numero);
}

void decimal_a_ASCII (int numero)
{
    char c;
    c = (char)numero;
    printf("El numero %d en ASCII es: %c \n", numero, c);
}
