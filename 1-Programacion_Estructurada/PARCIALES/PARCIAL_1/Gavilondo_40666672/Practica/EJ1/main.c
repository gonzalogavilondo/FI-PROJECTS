#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "declaraciones_funciones.h"

int main()
{

    /*1.Realice un programa en lenguaje C que intercambie los nibbles (grupo 4 bits) del byte 0xA1;
     por lo que la salida producida debe ser 26.

     Para que sea 26 = 1A = 00011010 (8bits).
     Como A1 = 10100001 (8bits)
     ENTONCES
     num = 0xA1 = 10100001
                 ^
                  10111011 = MASCARA = BB ---> NUM ^ MASCARA = 26.
                 ----------
     26 =  0X1A = 00011010


    */
    uint8_t num = 0xA1; // Declaracion de la variable num de 1 byte = 161 = 10100001
    uint8_t bytes[ELEMENTOS] = {0}; //Declaracion del vector bytes, que contiene elementos de 1 byte.
    uint8_t entero = 0x00;
    entero_a_bytes(num, bytes);
    printf("-Numero entero expresado en 4 bytes- \n\n"); //Los imprimo al reves de como esta en memoria.
    mostrar_bytes(bytes);
    aplicar_mascara(bytes);
    entero = bytes_a_entero(num, bytes);
    printf("-Numero entero expresado en forma decimal-\n\n %i \n", entero);

    return 0;
}
