#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fvalor = 2.3;      // 0x40133333 ---> 33 33 13 40 (En memoria)
    short hvalor = 255;      // 0x00FF     ---> FF 00 (En memoria)
    char ccar = 'A';         // 65 = 0x41  ---> 41 (En memoria)

    float *ptrf = NULL;      //En memoria: 00 00 00 00
    short *ptrh;
    char *ptrc;

    /*Cuando se declara un puntero se reserva memoria para almacenar una dirección de memoria (4bytes en este caso),
    pero no para almacenar el dato al que apunta el puntero.Esta reserva es independiente del tipo de
    dato ocupado(float,char,int, etc).
    */

    printf("\nfvalor esta en la posicion %p", &fvalor);
    printf("\nhvalor esta en la posicion %p", &hvalor);
    printf("\nccar esta en la posicion   %p", &ccar);

    printf("\n\nel puntero a float apunta a la posicion %p", ptrf);
    printf("\nel puntero a short apunta a la posicion %p", ptrh);
    printf("\nel puntero a char apunta a la posicion  %p", ptrc);

    ptrf = &fvalor;
    ptrh = &hvalor;
    ptrc = &ccar;

    printf("\n\nel puntero a float apunta a la posicion %p", ptrf);
    printf("\nel puntero a short apunta a la posicion %p", ptrh);
    printf("\nel puntero a char apunta a la posicion  %p", ptrc);

    hvalor = 5;               // modifico directamente (en memoria = 0x0005  = 05 00)
    *ptrh = 579;              // cambio el contenido de ptrh 579 = 0x0243 = 43 02
    *ptrc = 'C';              // cambio el contenido de ptrc C = 67 = 0x43 = 43
    *ptrf = 2.7E-3;           // cambio el contenido de ptrf = 0x3B30F27C = 7C F2 30 3B
    hvalor = (*ptrh) + 5;     // cambio el contenido de hvalor = 579 + 5 = 584 = 0x0248 = 48 02

    printf("\n\nfvalor = %f (valor); \t%f (contenido de puntero)", fvalor, *ptrf);
    printf("\nhvalor = %d (valor); \t%d (contenido de puntero)", hvalor, *ptrh);
    printf("\nccar = '%c' (valor); \t'%c' (contenido de puntero)\n\n", ccar, *ptrc);

    return 0;
}
