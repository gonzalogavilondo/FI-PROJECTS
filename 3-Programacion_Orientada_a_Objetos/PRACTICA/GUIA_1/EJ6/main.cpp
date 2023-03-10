#include <iostream>
#include "Vehiculo.h"

using namespace std;

int main()
{
    Vehiculo miAuto1,
             *miAuto2;

/***************
    Estático
***************/

    ///Seteamos los valores
    miAuto1.SetMarca("Peugeot");
    miAuto1.SetKilometraje(50000);
    miAuto1.SetCilindrada(1600);
    miAuto1.SetPuertas(4);

    ///Imprimimos los valores
    cout << "La marca del auto es: " << miAuto1.GetMarca() << endl;
    cout << "El kilometraje del auto es: " << miAuto1.GetKilometraje() << endl;
    cout << "La cilindrada auto es: " << miAuto1.GetCilindrada() << endl;
    cout << "Las puertas del auto son: " << miAuto1.GetPuertas() << endl;

/**************
    Dinámico
**************/

    ///Creamos el vehiculo con su reserva de memoria
    miAuto2 = new Vehiculo();

    ///Seteamos los valores
    miAuto2->SetMarca("Renault");
    miAuto2->SetKilometraje(75000);
    miAuto2->SetCilindrada(2000);
    miAuto2->SetPuertas(4);

    ///Imprimimos los valores
    cout << endl << "La marca del auto es: " << miAuto2->GetMarca() << endl;
    cout << "El kilometraje del auto es: " << miAuto2->GetKilometraje() << endl;
    cout << "La cilindrada auto es: " << miAuto2->GetCilindrada() << endl;
    cout << "Las puertas del auto son: " << miAuto2->GetPuertas() << endl;

    ///Destruimos el auto (liberamos la memoria)
    delete(miAuto2);

    return 0;
}
