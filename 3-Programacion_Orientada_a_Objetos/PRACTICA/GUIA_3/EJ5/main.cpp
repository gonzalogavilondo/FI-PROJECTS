#include "CRacional.h"

int main()
{
    CRacional a(4), b(3, 7), c(-1), d(3);

    cout << "-VALORES-" << endl << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl << endl;

    cout << endl << "-OPERACIONES ARITMETICAS-" << endl << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl << endl;
    cout << "-a = " << -a << endl << endl;

    cout << "a += b : " << (a += b) << endl;
    cout << "a -= b : " << (a -= b) << endl << endl;

    cout << "++a = " << ++a << endl;
    cout << "--a = " << --a << endl;
    cout << "a++ = " << a++ << ". Luego: a = " << a << endl;
    cout << "a-- = " << a-- << ". Luego: a = " << a << endl << endl;
    cout << "a + 2 = " << a + 2 << endl;
    cout << "2 + a = " << 2 + a << endl;


    cout << endl << "-OPERACIONES DE COMPARACION-" << endl << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a < b : " << (a < b) << endl;
    cout << "a > b : " << (a > b) << endl;
    cout << "a <= b : " << (a <= b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
    cout << "!a : " << (!a) << endl;

    return 0;
}
