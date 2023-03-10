#include <stdio.h>
#include <locale.h>
#include <stdint.h>

void convertir_entero_a_bytes(uint32_t, uint8_t[]);
void mostrar_bytes(const uint8_t[]);
int main()
{
    uint32_t n;
    n = 0xCD485ED8;
    uint8_t bytes[4] = {0};
    convertir_entero_a_bytes(n, bytes);
    mostrar_bytes(bytes);
    return 0;
}

void convertir_entero_a_bytes(uint32_t n, uint8_t bytes[]) //descompone un entero en sus bytes y lo guarda en un arreglo
{
    for(int i = 0; i < 4; i++)
    {
        bytes[i] = (n >> i*8) & 0xFF;
    }
}

void mostrar_bytes(const uint8_t bytes[])
{
    for(int i = 3; i > -1; i--)
    {
        printf("%#X:", bytes[i]);
    }
}
