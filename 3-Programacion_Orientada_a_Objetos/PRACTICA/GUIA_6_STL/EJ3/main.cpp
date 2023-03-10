#include <iostream>
#include <vector>

using namespace std;

/***
    Implementar un programa utilizando el contenedor vector que permita
    ingresar una serie de números hasta que el usuario introduzca 0 y que al final
    muestre los valores introducidos.
    Ejemplo:
        Ingrese un número (fin=0) 3
        Ingrese un número (fin=0) 6
        Ingrese un número (fin=0) 8
        Ingrese un número (fin=0) 2
        Ingrese un número (fin=0) 9
        Ingrese un número (fin=0) 100
        Ingrese un número (fin=0) 0
        Valores ingresados:
        3 6 8 2 9 100
***/

template <class T> void printVec(vector<T> v)
{
    typename vector<T>::iterator forIter;

    forIter = v.begin();                        // puntero al primer elemento
    cout << endl;
    while (forIter != v.end() )                 // mientras no sea el último elemento
    {
        cout << *forIter++ << "  ";              // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    vector <string> vec;
    string valor = "0";

    do
    {
        cout << "Ingrese un numero (fin = 0): ";
        cin >> valor;
        vec.push_back(valor);

    }while(valor != "0"); //El operador de comparacion != esta sobrecargado en la clase string.

    cout << endl << "Valores ingresados: " << endl;
    printVec(vec);

    return 0;
}
