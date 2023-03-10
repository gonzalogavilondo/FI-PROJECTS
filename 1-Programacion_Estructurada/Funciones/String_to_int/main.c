#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void get_int_by_bytes (uint32_t *, uint8_t []);
int main()
{
    uint8_t cadena1[5] = "hola"; //1752132705 = 0x686F6C61
    uint8_t cadena2[5] = {0x00, 0xED, 0x43, 0x12, 0x00}; //15549202 = 0x00ED4312
    uint32_t entero1 = 0;
    uint32_t entero2 = 0;
    get_int_by_bytes(&entero1, cadena1);
    get_int_by_bytes(&entero2, cadena2);
    printf("El entero de la cadena 1 es: %i\n", entero1);
    printf("El entero de la cadena 2 es: %i\n", entero2);
    return 0;
}

void get_int_by_bytes (uint32_t *entero, uint8_t cadena[])
{
    for (int i = 0; i < 4; i++)
    {
        *entero += cadena[3-i]<<8*i;
    }
}

