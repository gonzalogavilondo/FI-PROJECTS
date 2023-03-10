#include <stdio.h>
#include <stdlib.h>

int main()
{
    float d, m, y;
    char barra;
    printf("Ingrese una fecha de la forma dd </> mm </> yyyy: ");
    scanf("%f%c%f%c%f", &d, &barra, &m, &barra, &y);
    printf("Su fecha es: %.f/%.f/%.f", y, m, d);
    return 0;
}


