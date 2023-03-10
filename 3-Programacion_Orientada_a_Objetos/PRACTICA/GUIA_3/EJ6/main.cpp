#include "CCadena.h"

int main()
{
    CCadena a("Juan"),
            b(a),
            c("Pedro Garcia"),
            d;

    cout << "-CADENAS-" << endl;
    cout << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl << "d: " << d << endl << endl;

    cout << endl << "-CONCATENACION-" << endl;
    cout << "a + b" << " es: " << (d = a + b) << " y su longitud es: " << d.GetN_long() << endl;
    cout << "c + b" << " es: " << (d = c + b) << " y su longitud es: " << d.GetN_long() << endl;
    cout << "a + c" << " es: " << (d = a + c) << " y su longitud es: " << d.GetN_long() << endl;

    cout << endl << "-ASIGNACION-" << endl;
    cout << "d = c" << " es: " << (d = c) << " y su longitud es: " << d.GetN_long() << endl;

    cout << endl << "-CONCATENACION + ASIGNACION-" << endl;
    cout << "d += a" << " es: " << (d += a) << " y su longitud es: " << d.GetN_long() << endl;


    cout << endl << "-COMPARACION-" << endl;
    if(a == b) cout << "a == b" <<  endl;
    if(a == c) cout << "a == c" <<  endl;
    if(a == d) cout << "a == d" <<  endl;

    if(a != b) cout << "a != b" << endl;
    if(a != c) cout << "a != c" << endl;
    if(a != d) cout << "a != d" << endl;

    if(a > b) cout << "a > b" << endl;
    if(a > c) cout << "a > c" << endl;
    if(a > d) cout << "a > d" << endl;

    if(a < b) cout << "a < b" << endl;
    if(a < c) cout << "a < c" << endl;
    if(a < d) cout << "a < d" << endl;

    cout << endl << "-ASIGNACION E INDEXACION" << endl;
    cout << "Ingrese una cadena: ";
    cin >> c;

    cout << "Cadenas:" << endl;
    cout << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl << "d: " << d << endl << endl;

    cout << "d = c: " << (d = c) << endl;
    cout << "d[4]: " << d[4] << endl;


    return 0;
}
