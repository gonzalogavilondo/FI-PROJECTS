#include <stdio.h>
#include <locale.h>
#include "vehiculo.h"

int main()
{
    setlocale(LC_ALL, "spanish");

    Vehiculo auto1 = crearVehiculo("Fiat", 4, 115200, 1.6);
    Vehiculo auto2 = crearVehiculo("Zanella", 2, 10000, 0.250);

    printf("El número de puertas del auto1 es: %d \n", auto1->get_puertas(auto1));
    printf("El número de puertas del auto2 es: %d \n", auto2->get_puertas(auto2));

    auto1->acelerar(auto1);
    auto2->frenar(auto2);

    destruirVehiculo(auto1);
    destruirVehiculo(auto2);

    return 0;
}
