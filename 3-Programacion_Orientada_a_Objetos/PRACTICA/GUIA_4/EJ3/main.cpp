#include "MesaRedonda.h"

int main()
{
    Circulo Circulo1,
            Circulo2(0.7),
            Circulo3 = Circulo(2.8);

    Mesa mesa1,
         mesa2(1.1),
         mesa3(1.0, 1);

    MesaRedonda mesaredonda1,
                mesaredonda2(2),
                mesaredonda3(3, 0.9);

    cout << "/******CIRCULOS******/" << endl << endl;
    cout << "-CIRCULO 1- " << endl << Circulo1 << endl;
    cout << "-CIRCULO 2- " << endl << Circulo2 << endl;
    cout << "-CIRCULO 3- " << endl << Circulo3 << endl;

    cout << endl << "/******MESAS******/" << endl << endl;
    cout << endl << "-MESA 1- " << endl << mesa1;
    cout << endl << "-MESA 2- " << endl << mesa2;
    cout << endl << "-MESA 3- " << endl << mesa3;

    cout << endl << "/******MESAS REDONDAS******/" << endl << endl;
    cout << "-MESA REDONDA 1-" << endl << mesaredonda1;
    cout << "-MESA REDONDA 2-" << endl << mesaredonda2;
    cout << "-MESA REDONDA 3-" << endl << mesaredonda3;

    return 0;
}
