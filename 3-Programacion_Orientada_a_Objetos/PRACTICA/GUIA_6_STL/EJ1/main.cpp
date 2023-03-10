#include <iostream>
#include <string>
#include <list>

using namespace std;

template <class T> void printList(list <T> lista)
{
    typename list<T>::iterator forIter;

    forIter = lista.begin();

    while(forIter != lista.end())
    {
        cout << *forIter++ << "  ";
    }
    cout << endl << endl;
}

int main()
{
    list <string> sList;
    string palabra;

    do
    {
        palabra = "0";
        cout << "Ingrese una frase palabra por palabra, 0 para finalizar: ";
        cin >> palabra;
        if(palabra != "0")
        {
            string palabraInvertida(palabra.rbegin(), palabra.rend()); //Invierto la palabra, utilizando el constructor con los iteradores inversos de la variable de cadena original
            sList.push_back(palabraInvertida);
        }

    }while(palabra != "0");

    system("pause");
    system("cls");

    // Invierto la frase
    sList.reverse();

    cout << "Frase invertida: ";
    printList(sList);

    return 0;
}
