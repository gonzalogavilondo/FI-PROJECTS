#include "Reloj.h"

int main()
{
    Reloj creloj = Reloj(); //Creamos el objeto reloj

    creloj.printReloj();

    cout << creloj << endl;

    creloj.printRelojActualizandose(); //Imprimimos el reloj actualizandose en todo momento

    return 0;
}
