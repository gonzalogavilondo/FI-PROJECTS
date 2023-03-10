#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

void string_to_int (uint8_t const [], uint32_t *,  uint32_t);
int main()
{
    uint8_t cadena_num[] = "1111111111"; //Si se ingresan más de 10 números, se pasa la capacidad representativa para 32 bits.
    uint32_t entero = 0;
    uint32_t cant_elem = (sizeof(cadena_num)/sizeof(uint8_t))-1;
    string_to_int(cadena_num, &entero,  cant_elem);
    printf("El numero es: %i", entero);
    return 0;
}

void string_to_int (const uint8_t cadena_num[], uint32_t * entero, uint32_t cant_elem)
{
    uint8_t mask = 0xF;
    for (int i = 0; i < cant_elem; i++)
    {
        *entero += (cadena_num[cant_elem-1-i] & mask)*(float)pow(10, i);
    }
}
