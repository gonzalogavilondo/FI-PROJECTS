#include "polar.h"

int main()
{
    complejo comp1(3.1, 4.2),
             comp2;

    polar pol1(8.5, 6.0),
          pol2(9.0, 45.0, true),
          pol3(comp1),
          pol4, suma, resta, multiplicacion, division;

    double producto = 5.50;

    pol4.SetReal(6);
    pol4.SetImag(-6);
    pol4.ToPolar();

    cout << "\t\t -NUMEROS COMPLEJOS-" << endl << endl;
    cout << "pol1 = " << (complejo)pol1 << ", "
         << "\tpol2 = " << pol2 << ", "
         << "\tpol3 = " << (complejo)pol3 << ", "
         << "\tpol4 = " << (complejo)pol4 << endl << endl;


    suma = pol1 + pol2;

    cout << "\t\t -SUMA-" << endl;
    cout << "Forma rectangular: pol1 + pol2 = " << (complejo)suma << endl;
    cout << "Forma polar: pol1 + pol2 = " << suma << endl;

    resta = pol1 - pol2;

    cout << endl << "\t\t -RESTA-" << endl;
    cout << "Forma rectangular: pol1 - pol2 = " << (complejo)resta << endl;
    cout << "Forma polar: pol1 - pol2 = " << resta << endl;

    multiplicacion = pol1 * pol4;

    cout << endl << "\t\t-MULTIPLICACION-" << endl;
    cout << "Forma rectangular: pol1 * pol4 = " << (complejo)multiplicacion << endl;
    cout << "Forma polar: pol1 * pol4 = " << multiplicacion << endl;

    division = pol1 / pol4;

    cout << endl << "\t\t-DIVISION-" << endl;
    cout << "Forma rectangular: pol1 / pol4 = " << (complejo)division << endl;
    cout << "Forma polar: pol1 / pol4 = " << division << endl;

    pol1 += pol2;
    pol4 *= producto;

    cout << endl << "\t\t-OTRAS OPERACIONES-" << endl;
    cout << "pol1 += pol2: " << pol1 << endl;
    cout << "pol4 *= " << producto << ": " << pol4 << endl;
    cout << "pol1 == pol2: " << (pol1 == pol2) << endl;
    cout << "pol1 != pol2: " << (pol1 != pol2) << endl;

    ///Escribimos en archivo de texto
    ofstream fout;
    fout.open("polares.txt");
    fout << "pol1 = " << (complejo)pol1 << ", "
         << "pol2 = " << pol2 << ", "
         << "pol3 = " << (complejo)pol3 << "\n\n";
    fout.close();


    return 0;
}
