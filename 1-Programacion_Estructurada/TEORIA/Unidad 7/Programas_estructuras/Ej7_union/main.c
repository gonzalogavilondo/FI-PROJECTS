#include <stdio.h>
#include <stdlib.h>

union hold
{
    int digit;
    float bigfl;
    char letter;
};

typedef union
{
    float fvalor;
    char mem[4];
} explora;

int main()
{
    union hold valA,                       // tamaño = 4 bytes (float)
               valB = {88},                // inicializa el miembro digit
               valC = {.bigfl = 118.2},    // inicializa el miembro bigfl
               valD = valC;                // copia la union
    explora memoria;
    int size;

    size = sizeof(valA);                   // 4 bytes
    printf("Tamano de union = %d\n\n", size);

    printf("Campo digit en valB = %d\n", valB.digit);
    printf("Campo float en valC = %f\n", valC.bigfl);
    printf("Campo digit en valD = %f\n", valD.digit);

    valA.digit = 735;                       // 2 bytes = df 02 00 00

    valA.letter = 'A';                      // 1 byte  = 41 02 00 00
    printf("\nLetra = %c",valA.letter);     // toma sólo 1 byte, ignora 02
    printf("\nDigito = %d",valA.digit);     // 577 = 0x241

    valA.bigfl = 2.3;                       // 4 bytes = 33 33 13 40
    printf("\nLetra = %c",valA.letter);

    valA.letter+= 1;
    printf("\nLetra = %c",valA.letter);     // '4' en vez de 'B'

    memoria.fvalor = 2.3;
    printf("\n\nEl valor %.2f se almacena en memoria = %x %x %x %x\n\n", memoria.fvalor,
           memoria.mem[0], memoria.mem[1], memoria.mem[2], memoria.mem[3]);

    return 0;
}
