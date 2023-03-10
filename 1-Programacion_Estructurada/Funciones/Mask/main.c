#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void convertir_entero_a_bytes (uint32_t elemento, uint8_t vector[]);

int main()
{
    void convertir_entero_a_bytes(uint32_t elemento, uint8_t vector[]) //descompone un entero en sus bytes y lo guarda en un arreglo
    {
        uint8_t mask = 0xFF;
        for (int i = 0; i < 4; i++)
        {
            vector[i] = ((elemento >> i*8) & mask);
        }
    }

    return 0;
}
