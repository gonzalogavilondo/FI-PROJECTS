#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

int main()
{
    struct informacion_celda Pedro={"perico cualquiera",5,6,0x22334455};;
    Pedro.identificador = 5;
    struct informacion_celda a;
    struct informacion_celda *b;
    struct informacion_celda *ptr1, *ptr2;
    struct informacion_operador *i1, *i2;

    printf("El tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(Pedro));
    printf("\nEl tama%co en bytes de la variable unsigned int es: %i", 164, sizeof(Pedro.identificador));
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(a));
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(b));
    //printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(*b));
    /*
    Si pongo asi, marcaria 112 bytes, ya que estoy apuntando a el contenido de "b" que es la direccion
    de memoria donde esta guardada la estructura que en este caso ocupa 112 bytes.
    */
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(ptr1));
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(ptr2));
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(i1));
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(i2));




    return 0;
}

/**************************************************************************
A)
    informacion_celda:

    char [100]  unsigned_int  float    struct informacion_operador *(puntero)

     100      +    4     +     4     +      4(puntero) =  112 bytes.


B)
    La que ocupa mas espacio en memoria de:
    1º)struct informacion_celda a;
    2º)struct informacion_celda *b;

    Es la 1º, ya que la segunda ocupa el espacio de un puntero, que son 4 bytes, en cambio la segunda ocupa
    toda la estructura de informacion_celda, es decir que "a" ocupa 112 bytes y "b" es un puntero a estructura
    que guarda una direccion de memoria, entonces para guardar direcciones de memoria ocupa un espacio de
    4 bytes.

    ----> a = 112 bytes > b = 4 bytes.

C)

    El tamaño de las variables:
    struct informacion_celda *ptr1, *ptr2;
    struct informacion_operador *i1, *i2;

    Todas ocupan 4 bytes, por lo mencionado anteriormente, es un puntero a estructura... como todo puntero
    almacenan direcciones de memoria que en este caso son donde estan almacenadas las estructuras, si quisiera
    saber cuanto ocupa en bytes cada estructura, deberia usar el operador indireccion (*) y con un printf
    donde este involucrado el sizeof lo se, ya que estoy apuntando al contenido de esa direccion de memoria
    quedando de esta manera por ej:
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(*i2));
    marcaria 112 bytes(Lo que ocupa la estructura), y si pongo:
    printf("\nEl tama%co en bytes de la variable struct informacion_celda es: %i", 164, sizeof(i2));
    Debe marcar 4 bytes(Lo que ocupa un puntero).

D)

    Si una variable de tipo struct esta almacenada en la posicion 100 de memoria, la direccion de cada uno de sus campos
    depende de lo que ocupe cada uno, por ejemplo si hay un char[1] va a ocupar 1 posicion, van a ser "saltos" de 1 en 1
    (aunque la forma de guardar en memoria es con numeros pares, no le gusta que sea impar los bytes almacenados en memoria
     entonces por ejemplo si los bytes reservados son 55, generalmente nos va a reservar 56, como pasa en el programa("estructura_vehiculo_dinamico)
    Entonces si por ejemplo la proxima variable que seria por ejemplo char * (puntero, que ocupa 4 bytes) estaria en la posicion "101"
    y ocuparia 4 bytes, es decir que la proxima variable o campo definido por ejemplo un float(4 bytes) estaria almacenado
    en la posicion 105.

    En memoria:
    char[1] = 100 (1BYTE)
    char* = 101 102 103 104 (4BYTES)
    float = 105 106 107 108 (4bytes)

    Aclarado esto: En este caso en la estructura informacion_celda estan los siguientes campos:

    char nombre[SIZE];   =  Como SIZE = 100, ocupara 100 bytes en memoria --> esta en la posicion 100 y ocupa 100bytes
    unsigned int identificador;  =  Esta ubicado en la posicion 199 de memoria y ocupa 4 bytes.
    int calidad_senal;   =  Esta ubicado en la posicion 202 de memoria y ocupa 4 bytes.
    struct informacion_operador *ptr_operador;   =   Esta ubicado en la posicion 206 y ocupa 4 bytes.

E)








**************************************************************************/
