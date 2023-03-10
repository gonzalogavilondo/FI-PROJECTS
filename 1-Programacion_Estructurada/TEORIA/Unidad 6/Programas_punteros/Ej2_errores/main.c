#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char a = 255;  // 255 = 0xFF
    unsigned int b = 269,   // 269 = 0x010D, mas de 8 bits!!
                 c;
    char *p1;               // p1 es un puntero a signed char

    unsigned char *p2;      // unsigned char son 8 bits!!

    p1 = (char *)&a;        // cast para que no lance un warning. // char tiene un max de 127 y aca es 255.
    printf("%d, '%c'", *p1, *p1); // -1, ' ' (–1 no es un caracter)

    p2 = (unsigned char *)&b;     // p2 sólo toma 8 de los 9 bit
    c = *p2;                // c almacena los 8 bits menos significativos de b
    printf("\n\nValor = %u\n", c);  // muestra el valor 13 en vez de 269

    return 0;
}
