#include <iostream>
#include "Fecha.h"

int main()
{

    Fecha fechaA,
          fechaB,
          *fechaC;

    fechaA.SetFecha(10, 7, 2021);
    fechaB.SetFecha(23, 10, 1997);
    fechaC = new Fecha();

    cout << "La fecha A es: ";
    fechaA.Imprimir_la();
    cout << "La fecha B es: ";
    fechaB.Imprimir_us();
    cout << "La fecha C es: ";
    fechaC->Imprimir_la();

    cout << "El mes es de fecha A es: " << fechaA.MesLetras(fechaA.GetMonth()) << endl;

    cout << "El mes es de fecha B es: " << fechaB.MesLetras(fechaB.GetMonth()) << endl;

    cout << "El mes es de fecha C es: " << fechaC->MesLetras(fechaC->GetMonth()) << endl;

    delete(fechaC);

    return 0;
}
