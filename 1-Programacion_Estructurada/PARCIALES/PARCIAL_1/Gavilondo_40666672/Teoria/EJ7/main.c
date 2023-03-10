#include <stdio.h>
#include <locale.h>
#include <stdint.h>

int main()
{
    uint8_t array[10]; //Declaracion de un vector de 10 elementos de 8 bits.
    uint8_t value = 127; //Declaracion de una variable de 8 bits con el valor de 127.
    for (int i = 0; i <= 10 ; i++) //Recorre el vector hasta que sea 10.
    {
        array[i] = i;
    }
    printf("La variable valor es = %d \n", value);
    /*
    El bucle for recorre el vector hasta que sea el contador(i) = 10 y arranca en 0, entonces va a recorrer
    una posicion de mas, esa ultima posicion es donde esta guardada la variable "value", ya que las variables
    se guardan en posiciones sucesivas de memoria.
    ENTONCES:
    Cuando i = 10, este numero se va a guardar en la variable "value" que esta guardada luego de los 10 elementos del vector.
    Por este motivo, el valor de value = 10  y lo muestra por pantalla.
    */

    return 0;
}
