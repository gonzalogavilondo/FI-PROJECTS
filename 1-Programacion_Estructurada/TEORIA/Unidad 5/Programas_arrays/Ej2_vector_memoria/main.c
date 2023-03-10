#include <stdio.h>

int main()
{
    char numeros[] = { '4', '8', '5', '6', '3', '2'};   // char para que queden en bytes contiguos
    int aux;
    int i;

    for(i=0; i<=5; i++)           // se recorren las 6 posiciones del vector
    {
        printf("Elemento %i: %#x\n", i, numeros[i]);
    }

    aux=13;                       // asigno un valor cualquiera

    numeros[6] = 100;             // el índice excede la dimensión ==> INVADE MEMORIA!!! aux = 100 = 0x64
    printf("\nCambio el valor de 'aux' sin saberlo, ahora vale %d\n\n", aux);

    numeros[7] = 10;              // el índice excede la dimensión ==> INVADE MEMORIA!!! aux = 0xa*256 + 100
    printf("\nNuevo valor de 'aux' %d, %#x\n\n", aux, aux);

    for(i=0; i<=7; i++)           // se imprimen mas valores que el tamaño del vector !!!
    {
        printf("numeros[%i] = %3i, en hexa = %02#X, como char = '%c' \n",
               i, numeros[i], numeros[i], numeros[i]);
    }                             // el último caracter es un new line (por eso baja la línea)

    return 0;
}
