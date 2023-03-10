#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    string cadena;
    //cin >> cadena;
    getline(cin, cadena);
    cout << "La cadena ingresada es: " << cadena << endl;

    return 0;
}

/**
    El error en el programa es que uso dos formas de leer la cadena de caracteres,
    utilizando "cin" vamos a poder leer una primera parte de la cadena, ya que la
    lectura se interrumpe al encontrar un carácter '\0', ' ' ó '\n', a partir de ahi
    ya no lee nada mas y lo que sigue lo lee el getline y lo almacena en el string "cadena"
    sobreescribiendola, entonces si escribimos por ejemplo "Pedro Picapiedras".
    En la consola va a salir: "Picapiedras".
    La solucion es borrar la linea 9 y que lea toda la cadena utilizando el getline.
**/
