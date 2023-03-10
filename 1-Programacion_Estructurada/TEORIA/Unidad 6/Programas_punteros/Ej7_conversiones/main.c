#include "myInclude.h"

int main()
{
    char sValor[20];                         // almaceno 20 caracteres
                                             // termina mal
    enteros();

    flotantes();

    sprintf(sValor, "%d", 123);              // ver los valores en Watches
    sprintf(sValor, "%.5f", 3.1415927);
    //sprintf(sValor, "Valor entero = %d, flotante = %.5f", -1800, 27.5869785);

    printf("\nsValor = %s\n\n", sValor);     // sValor[20]
    return 0;
}
