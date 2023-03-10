#include <iostream>
#include <string>
using namespace std;

int main()
{
    string bigNews("I saw Elvis in a UF0. ");
    cout << bigNews << endl;
    //How much data have we actually got? (¿Cuántos datos tenemos realmente?)
    cout << "Size = " << bigNews.size() << endl;
    //How much can we store without reallocating? (¿Cuánto podemos almacenar sin reasignar?)
    cout << "Capacity = " << bigNews.capacity() << endl;
    //Insert this string in bigNews immediately (Inserte esta cadena en bigNews inmediatamente)
    //before bigNews(1):
    bigNews.insert(1, "thought I");
    cout << bigNews << endl;
    cout << "Size = " << bigNews.size() << endl;
    cout << "Capacity = " << bigNews.capacity() << endl;
    //Make sure that there will be this much space (Asegúrate de que haya tanto espacio)
    bigNews.reserve(500);
    //Add this to the end of the string: (Agregue esto al final de la cadena: )
    bigNews.append("I've been working too hard.");
    cout << bigNews << endl;
    cout << "Size = " << bigNews.size() << endl;
    cout << "Capacity = " << bigNews.capacity() << endl;

    return 0;
}
