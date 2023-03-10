#include <iostream>
#include "complejos.h"
using namespace std;

int main()
{

    complejo c1(2, 4), c2(1, -1);

    cout << "El complejo 1 es: " << c1 << endl;
    cout << "El complejo 2 es: " << c2 << endl << endl;

    cout << "-OPERACIONES ARITMETICAS-" << endl << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    cout << "c1 * c2 = " << c1 * c2 << endl;
    cout << "c1 / c2 = " << c1/c2 << endl;
    cout << "-c1 + c2 = " << -c1 + c2 << endl << endl;

    cout << endl;
    c1 += c2;
    cout << "c1 += c2 : " << c1 << endl;
    c1 -= c2;
    cout << "c1 -= c2 : " << c1 << endl << endl;

    cout << "++c1 = " << ++c1 << endl;
    cout << "--c1 = " << --c1 << endl;
    cout << "c1++ = " << c1++ << ". Luego: c1 = " << c1 << endl;
    cout << "c1-- = " << c1-- << ". Luego: c1 = " << c1 << endl << endl;

    cout << "5 + c1 = " << 5 + c1 << endl;
    cout << "c1 + 5 = " << c1 + 5 << endl << endl;

    cout << "-OPERACIONES DE COMPARACION-" << endl << endl;
    cout << "c1 == c2 : " << (c1 == c2) << endl;
    cout << "c1 != c2 : " << (c1 != c2) << endl;


    return 0;
}
