#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "header_vehiculo.h"

int main()
{
    Vehiculo miAuto = NewVehiculo();
    miAuto->setMarca(miAuto, "Peugeot");
    setPuertas(miAuto, 4);
    setKilometraje(miAuto, 1000.2);
    setCilindrada(miAuto, 1600);

    printf("La marca del vehiculo es: %s\n", miAuto->getMarca(miAuto));
    printf("La cantidad de puertas del vehiculo es: %d\n", getPuertas(miAuto));
    printf("El kilometraje del vehiculo es: %f\n", getKilometraje(miAuto));
    printf("La cilindrada del vehiculo es: %d\n", getCilindrada(miAuto));

    destruirVehiculo(miAuto);
    return 0;
}
