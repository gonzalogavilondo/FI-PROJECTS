#include <iostream>
#include "header.h"

using namespace std;

int main(void)
{
    int a = 3, b = 1;

    int *aptr = &a; //Una forma de declarar un puntero asignandole la direccion de la variable "a"
    int *bptr = NULL; //Otra forma de declarar un puntero asignandole la direccion NULL (Cosa que no podemos hacer con una referencia)
    bptr = &b; //Le asignamos a bptr la direccion de memoria de la variable "b"
    int &aref = a; //Unica forma de declarar una variable de tipo referencia (Tiene que ser asignada cuando se declara)
    int &bref = b;

    permutarREF(aref, bref); //Permutamos utilizando referencias (utilizamos el nombre del "alias" siempre)
    cout << "El valor de a es: " << aref << " y el de b: " << bref << endl; //Siempre con el nombre del alias
    permutarPTR(aptr, bptr); //Permutamos nuevamente utilizando punteros
    cout << "El valor de a es: " << *aptr << " y el de b: " << *bptr << endl; //Tenemos que utilizar el operador (*)

    if(&aref == &a)
    {
        cout << "Comparte la misma direccion de memoria" << endl;
    }
    else
    {
        cout << "No comparte la misma direccion de memoria" << endl;
    }

    return 0;
}
/**********************************************************************************************************

DIFERENCIAS ENTRE UNA VARIABLE DE TIPO REFERENCIA Y UN PUNTERO

    -Cuando declaramos un PUNTERO podemos no estar apuntando a nada, o apuntando a NULL.
    Mientras que si declaramos una variable de tipo REFERENCIA si o si tenemos que hacer la asignacion
    de la referencia a alguna variable, ya que va a ser el nuevo "alias" de esa variable y a su vez ese
    mismo alias no se puede cambiar a otra variable como si se puede hacer con punteros, ya que pueden ser
    re-asignados cualquier numero de veces.

    -La referencia comparte la dirección en memoria con la variable a la que refiere, esto en los punteros no ocurre.
    Ya que los punteros son variables que almacenan direcciones de memoria que estan guardadas en otra
    direccion de memoria, mientras que la referencia solo es un alias de una variable y si pedimos
    la direccion de memoria de la referencia, nos va a dar la direccion de memoria del objeto al cual esta
    siendo referenciado.

    -No se puede utilizar aritmética de punteros con una referencia. Por ejemplo, no se puede recorrer un
    vector utilizando el operador de indice con una referencia, ya que no se puede cambiar el objeto al que
    apunta una vez creada.


¿CUANDO USAR UNA VARIABLE DE TIPO REFERENCIA Y CUANDO USAR UNA DE TIPO PUNTERO?

    -Si necesitas apuntar a más de un objeto, o necesitas indicar que no se apunta a nada (valor NULL), o
    precisas utilizar aritmética de punteros, entonces no podemos utilizar referencias.

    -Las referencias fueron inventadas, de hecho, para no tener que utilizar punteros cuando se realiza un
    paso por referencia (y para las devoluciones por referencia), es decir, cuando se desea que los cambios
    realizados dentro de la función llamada al objeto apuntado repercutan en la función llamadora.

**********************************************************************************************************/
