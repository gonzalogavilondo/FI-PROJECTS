#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

void entero_a_bytes(uint8_t num, uint8_t bytes[]) //Descompone un entero en sus bytes y lo guarda en un arreglo de 4 bytes, donde cada elemento ocupa 1 byte, en este caso num = 000000A1.
{
    uint8_t mask = 0xFF;
    for(int i = (BYTES-1); i > -1; i--)  //Como BYTES = 4, y el arreglo empieza desde el elemento 0 al 3... si yo arranco desde 4 que seria BYTES entonces estaria parado en una posicion que no existe o que si lo hace, pero podria ser otro arreglo por ejemplo, ya que las variables se guardan en posiciones sucesivas de memoria.
    {
        bytes[BYTES-1-i] = ((num >> i*8) & mask);
    }
}

int bytes_a_entero(uint8_t num, const uint8_t bytes[])
{
    uint8_t entero = 0x00;
    for (int i = 0; i < BYTES; i++)
    {
        entero += bytes[i] << ((BYTES-1-i)*8);//Como el conteo de la posicion de cada elemento del arreglo comienza desde 0, le resto 1 y lo multiplico por 8 (bits), para ir corriendo byte a byte.
    }

    return entero;
}

void mostrar_bytes(const uint8_t bytes[])
{
    for(int i = 0; i < BYTES; i++)
    {
        printf("%X  ", bytes[i]);
    }
    puts("\n");
}

void aplicar_mascara(uint8_t bytes[]) //intercambian los bytes i-esimos de dos enteros de dos vectores, en la posicion i-ésima
{
    uint8_t mask = 0xBB;
    for(int i = (BYTES-1); i > -1; i--)  //Como BYTES = 4, y el arreglo empieza desde el elemento 0 al 3... si yo arranco desde 4 que seria BYTES entonces estaria parado en una posicion que no existe o que si lo hace, pero podria ser otro arreglo por ejemplo, ya que las variables se guardan en posiciones sucesivas de memoria.
    {
        bytes[BYTES-1-i] = (bytes[BYTES-1-i] ^ mask); // Lo que hace es comparar con una operacion logica OR EXCLUSIVO( Quita la combinacion 1 1 = 1) a nivel bit recorriendo el vector bytes.
    }
}
