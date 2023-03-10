#include "Tiempo.h"

int main()
{
    //Declaramos el timeA
    Tiempo timeA;

    //Seteamos TimeA
    timeA.setDatos(18, 34, 40);

    //Imprimimos TimeA
    timeA.muestra_fmt_estandard();

    //Declaramos el timeB inicializandolo con el otro constructor
    Tiempo timeB(15, 39, 50);

    //Imprimimos el timeB
    timeB.muestra_fmt_estandard();

    return 0;
}
