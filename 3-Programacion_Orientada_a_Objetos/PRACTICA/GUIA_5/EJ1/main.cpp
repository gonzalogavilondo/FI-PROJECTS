#include <iostream>
#include <fstream>
#include "Vehiculo.h"
#include "Auto.h"
#include "Camioneta.h"
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    ifstream finC("pruebaCamioneta.txt", ios::in);
    ifstream finA("pruebaAuto.txt", ios::in);

    int cant = 2;
    Vehiculo* listaVehiculos[cant];

    listaVehiculos[0] = new Auto();
    finA >> *(listaVehiculos[0]);

    listaVehiculos[1] = new Camioneta();
    finC >> *(listaVehiculos[1]);

    for (int i = 0; i < cant; i++){
        cout << endl << "VEHICULO " << (i+1) << endl << endl;
        cout << *(listaVehiculos[i]);
    }

    for (int i = 0; i < cant; i++){
        delete listaVehiculos[i];
    }

    return 0;
}

/**********************************************************/
/**                    CUESTIONES                        **/
/**********************************************************/

// De qué sirve un arreglo de vehículos si no puedo almacenar
// autos o camiones?

// Lo solucioné generando funciones que se sobrecargan (print y set),
// no pude poner virtual a la sobrecarga de los operadores, así
// que tuve que hacer eso.
// Donde se guardan esos atributos que sobrepasan el tamaño de
// vehículo?
