#include "myInclude.h"

void enteros(void)
{
    int iValor;
    long lValor;
    char sValor[20];
    char *end;

    iValor = atoi("512");         // ver los resultados en Watches
    iValor = atoi("524.035");
    iValor = atoi("  5120.089");
    iValor = atoi("   512+34");
    iValor = atoi("   1024 2 bottles of beer on the wall");
    iValor = atoi("does not work: 512" );     // i = 0

    lValor = atol("  2024.0001");

    printf("\nUltimos valores de iValor = %d, lValor = %d\n", iValor, lValor);

    itoa(34, sValor, 10);                // base 10
    printf("\nEl string contiene = %s\n", sValor);
    itoa(34, sValor, 8);                 // base 8
    printf("\nAhora el string contiene = %s (octal)\n", sValor);
    itoa(34, sValor, 16);                // base 16
    printf("\nAhora el string contiene = %s (hexa)\n", sValor);

    ltoa(123456789L, sValor, 10);        // base 10
    printf("\nPara el long el string contiene = %s\n", sValor);

    end = (char *)malloc(20);
    lValor = strtol("255 y mas", &end, 16);
    printf("\nValor convertido = %d. En end queda: %s\n\n", lValor, end);

    free(end);
}

void flotantes(void)
{
    double fValor;
    int dec, sign;
    char sValor[20];
    char *end;
    char *ptr;

    fValor = atof(" 2.3E-6 number");
    fValor = atof("3.4E+8");
    fValor = atof(" e 3.8E+6 number");

    printf("\nUltimo valor de fValor = %g\n", fValor);

    gcvt(-3.1415927, 3, sValor);
    ptr = ecvt(-35.141592787654, 5, &dec, &sign);  // tengo que formatear la salida: en ptr guarda
                                                   // los 5 dígitos (total), en dec la cantidad de
                                                   // digitos enteros y en sign el signo (0 ó 1)
    printf("\nContenido del puntero = %s, dec = %d, sign = %d\n", ptr, dec, sign);
    ptr = fcvt(-35.141592787654, 5, &dec, &sign);  // almacena 5 digitos DECIMALES
    printf("\nContenido del puntero = %s, dec = %d, sign = %d\n", ptr, dec, sign);

    end = (char *)malloc(20);
    fValor = strtod("3.1415927 y sigue", &end);
    printf("\nValor convertido = %f. En end queda: %s\n\n", fValor, end);

    free(end);
}
