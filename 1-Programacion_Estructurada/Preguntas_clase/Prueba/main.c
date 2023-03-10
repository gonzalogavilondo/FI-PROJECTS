#include <stdio.h>
#include <locale.h>
#include <stdint.h>

int main()
{
    uint8_t a = 0x41;
    uint8_t b = 0x3F;
    uint8_t resultado = 0x00;
    /*
    El 41 en hexa es el 65 en decimal y en binario es = 1000001 7 bits.

    1000001
    |
    0111111
    -------
    1111111  = 7F = 127
    ==>
    */

    resultado = (a | b);
    printf("Ahora a tiene el valor de: %i", resultado); /* Deberia dar 127 pero imprime 1????.
                                                        Estaba usando el operador OR lógico (||) en vez del operador OR bit a bit (|).
                                                        */

    return 0;
}
