#include "Vehiculo.h"
#include <stdio.h>

Vehiculo::Vehiculo(const char* marca, int puertas, int kilometraje, float cilindrica)
{
    //ctor
    this->Setmarca(marca);
    //m_marca = marca;
    m_puertas = puertas;
    m_kilometraje = kilometraje;
    m_cilindrada = cilindrica;
}

Vehiculo::~Vehiculo()
{
    //dtor
}

void Vehiculo::acelerar()
{
    printf("Acelerando el vehículo %s \n", this->Getmarca());
}

void Vehiculo::frenar()
{
    printf("Frenando el vehículo %s \n", this->Getmarca());
}

float Vehiculo::valor_patente = 1597.65;
