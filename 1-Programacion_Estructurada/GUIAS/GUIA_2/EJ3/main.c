#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, x;
    float j;
    printf("Digite valores para cada variable:\n");
    scanf("%d %f %d",&i, &x, &j);
    printf("\nLos valores para 'i' 'x' y 'j' son: %i %i %e\n", i, x, j);

    /*
    El usuario ingresa: 10.3 5 6
    Imprime 10, 1050253722 y 7.006 e -045

    �Por que imprime eso? �Por que el scanf no toma los 3 numeros?... tengo que hacer un
    check point en el ultimo printf y ver en memoria:

    Por el formato del scanf, primero busca un entero, despu�s un flotante y despu�s un entero nuevamente. Entonces:
    i = 10;
    x = 0.3;
    j = 5;

    El primer numero imprime 10, porque el usuario quiere scanear un flotante o real en una variable que declaro de tipo entero, se van
    los digitos despues de la coma porque scanf cuando quiere leer enteros lee solo numeros, cuando hay un punto frena.
    Por lo cual queda como i = 10.

    Luego del 10 sigue el .3  y el scanf lo lee como flotante, el scanf cuando quiere leer flotantes lee puntos, numeros, signos "+" "-" y exponenciales tambien...
    Primero utiliza el standard IEEE-754 para convertir el 0.3 a float.
    Se guarda en memoria como 0x9A99993E (En memoria se guarda al rev�s por byte, 0x3E99999A).
     Una vez hecho eso, como x no es de tipo float, ese n�mero lo pasa a decimal (que es lo que vemos en watches y la calculadora) y este se guarda en la variable x.
    Por lo cual x = 1050253722.

    Despues del .3 corto en el espacio y en la proxima hay un 5.
    Nuevamente utiliza el standard IEEE-754 para convertir 5 a float. Se guarda en memoria como: 0x05000000 (En memoria se guarda al rev�s por byte, 00000005).
    Una vez hecho eso, ese valor hexadecimal pasado a float se guarda en j.
    Por lo cual, j = 7.00649232e -045.

    Una vez asignados todos los valores, despues de los 2 puntos:
    Imprime un espacio.
    Imprime i en formato decimal: 10
    Imprime espacio.
    Imprime x en formato decimal: 1050253722
    Imprime espacio.
    Imprime j en formato exponencial: 7.00649232e -045(no imprime todos los decimales porque es de tipo float y no tiene tanta precisi�n).

    En el buffer quedo un espacio y el 6, que no se utilizo por todo lo explicado anteriormente.

    */


    return 0;
}
