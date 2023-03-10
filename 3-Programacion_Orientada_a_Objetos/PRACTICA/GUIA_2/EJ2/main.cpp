#include <iostream>

//using namespace std;

int main()
{
    //cout << "¡Hola, mundo!" << endl;
    std::cout << "¡Hola, mundo!" << std::endl;
    return 0;
}

/**
    El problema era que el cout y el endl son objetos que estan dentro de un namespace llamado "std"
    que no estaba siendo incluido en el programa, el namespace es una zona separada donde se pueden declarar
    y definir objetos, funciones y cualquier identificador de tipo, clase, estructura, etc.;
    al que se asigna un nombre. La clase std entonces, contiene a los metodos cout y endl
    para imprimir por consola. Las posibles soluciones al programa son:

    1) Incluir al namespace utilizando la sentencia de la linea 3: using namespace std;
    2) Antes de poner "cout" y "endl" poner a que clase pertenecen y el operador de resolucion.
       Es decir, std::cout << "¡Hola, mundo!" << ¨std::endl;

**/
