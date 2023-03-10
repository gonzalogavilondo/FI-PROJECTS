#include <utility> // std::pair, std::make_pair
#include <iostream> // std::cout
#include <map> // container map

using namespace std;

template <class K, class V> void printMap(map<K, V> mp)
{
    typename map<K, V>::iterator forIter;

    forIter = mp.begin();                       // puntero al primer elemento
    cout << endl;
    while (forIter != mp.end() )                // mientras no sea el último elemento
    {
        cout << forIter->first << "  " << forIter->second << endl;
        forIter++;                              // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    map<int, char> mapAscii;
    map<int, char>::iterator ptr, ptr2;

    // Cargamos el mapa ascii
    for(int i = 0; i < 26; i++)
    {
        mapAscii.insert(make_pair(65 + i, 'A' + i));
    }
    for(int i = 0; i < 26; i++)
    {
        mapAscii.insert(make_pair(97 + i, 'a' + i));
    }

    cout << "MAP ASCII\n\n:";
    printMap(mapAscii);

    cout << "Ingrese un numero entre 65...90 o 97...122: ";
    int key;
    cin >> key;

    if( (key >= 65 && key <= 90) )
    {
        ptr = mapAscii.find(key);
        ptr2 = mapAscii.find(key + 32);
        if( (ptr != mapAscii.end()) && (ptr2 != mapAscii.end()) )
        {
            cout << "Clave: " << key << endl;
            cout << "Mayuscula " << ptr->second << endl;
            cout << "Minuscula " << ptr2->second << endl;
        }
        else
        {
            cout << "Clave no encontrada\n";
        }
    }
    else if( (key >= 97 && key <= 122) )
    {
        ptr = mapAscii.find(key);
        ptr2 = mapAscii.find(key + 32);
        if( (ptr != mapAscii.end()) && (ptr2 != mapAscii.end()) )
        {
            cout << "Clave: " << key << endl;
            cout << "Mayuscula " << ptr->second << endl;
            cout << "Minuscula " << ptr2->second << endl;
        }
        else
        {
            cout << "Clave no encontrada\n";
        }
    }
    else
    {
        cout << "Clave incorrecta\n";
    }

    return 0;
}
