#include <iostream>
#include <vector>

using namespace std;

/***
    Modificar el programa del ejercicio 3 para que la salida ahora sea 100 9 2 8 6 3, si
    los valores ingresados son los mismos.

    PREGUNTAR ENUNCIADO
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
