#include <stdio.h>
#include <locale.h>
#define PI 3.14159265358979323846

int main()
{
    const double pi = 3.14159265358979323846;
    (pi - PI) ? printf("pi es != PI \n") : printf("pi es = PI");

    /*
    pi != PI
    Imprime esto, ya que el operador ? es una estructura de control selectiva.
    donde compara 2 opciones, si pi != PI o si pi = PI

    ¿Por que no lo es?

    Porque double tiene una presicion de hasta 15 decimales, y donde esta declarado tiene mas de 15
    entonces al restarlo con una directiva al compilador como define PI que almacena todos los valores
    no van a ser iguales.

    */
    return 0;
}
