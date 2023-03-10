#include <stdio.h>

#define VALOR  378.123456789

int main()
{
    float fValor = VALOR;
    double dValor = VALOR;
    int iSize;
    long double ldValor;

    printf("Diferencia = %0.10f\n", fValor-VALOR);
    printf("Diferencia = %0.10f\n", dValor-VALOR);

    iSize = sizeof(char);
    printf("Size of char = %d\n", iSize);
    iSize = sizeof(int);
    printf("Size of int = %d\n", iSize);
    iSize = sizeof(short int);
    printf("Size of short int = %d\n", iSize);
    iSize = sizeof(long int);
    printf("Size of long int = %d\n", iSize);
    iSize = sizeof(float);
    printf("Size of float = %d\n", iSize);
    iSize = sizeof(double);
    printf("Size of double = %d\n", iSize);
    iSize = sizeof(long double);
    printf("Size of long double = %d\n", iSize);

    ldValor = VALOR*1.18e300;          // ver posiciones de memoria: hay 12 posiciones hasta iSize

    fValor = 1.45e-3;                  // verificar con el formato IEEE-754

    return 0;
}
