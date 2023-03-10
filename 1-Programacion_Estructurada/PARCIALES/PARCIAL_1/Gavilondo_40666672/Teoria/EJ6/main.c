#include <stdio.h>
#include <locale.h>
#include <stdint.h>

int main()
{
    uint8_t a = 0xFE; // Declaracion de una variable de 8 bits, donde el valor es: FE = 254 = 11111110
    uint8_t par = a & 1; //Declaracion de una variable de 8 bits, donde el valor es: a & 1;
    /*

    Como es de 8 bits a --> 1 = 00000001

    ---> a = 11111110
            &
         1 = 00000001
            ----------
             00000000 = 0 --> Como es una instruccion selectiva, al par = 0, se deberia ejecutar la rama verdadera.

            Pero no se ejecuta par = 0, porque en el if, tiene una asignacion y no es un operador logico donde evalua una condicion
            Para que funcione y se ejecute "La variable es par" Deberia cambiar donde dice if (par = 0) por if(par == 0).

    */
    if (par = 0) //Operador de asignacion, por ese motivo no se ejecuta esta instruccion como deberia, se deberia asignar un operador logico (==) para que funcione.
    {
        printf("La variable es par");
    }
    else
    {
        printf("La variable es impar");
    }
    return 0;
}
