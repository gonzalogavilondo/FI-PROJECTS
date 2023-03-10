#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main()
{
    string s("A piece of text"),
           tag;
    cout << "Ingrese un string: ";
    getline(cin, tag);
    s.insert(8, tag + ' ');
    assert(s == "A piece $tag$ of text");
    int start = s.find(tag);
    assert(start == 8);
    assert(tag.size() == 5);
    s.replace(start, tag.size(), "hello there");
    assert(s == "A piece hello there of text");

    return 0;
}
/*****************************************************
Explicacion de cada metodo de la clase string

    -insert: Para a�adir otra cadena en cualquier parte de la cadena indicando la posici�n inicial
    -find: Devuelve el �ndice m�s bajo en el que se encuentre el substring sub en el bloque str[start:end].
    Si el substring sub no se encuentra, devuelve el valor -1. Si no se especifican los argumentos start o end,
    se toman como valores por defecto el comienzo y el final del string
    -size: Permite conocer la longitud de string:
    length() y size(). Ambos son equivalentes y se invocan sin par�metros.
    -replace: M�todo que nos permite cambiar un car�cter por otro dentro de una cadena

Palabra reservada general
    -assert: Sirve para aseverar que en un determinado momento del c�digo una determinada condici�n debe ser cierta.
    Si no es cierta, corta el programa. Si es cierta, no hace nada.
*****************************************************/
