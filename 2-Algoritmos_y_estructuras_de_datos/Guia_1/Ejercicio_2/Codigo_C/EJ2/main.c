#include <stdio.h>
#include <stdlib.h>
#include "declaraciones.h"

int main()
{
    char letra;
    printf("Ingrese una letra: ");
    scanf("%c", &letra);
    system("cls || clear");
    vocal(letra);

    return 0;
}
