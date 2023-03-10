#include "Vehiculo.h"

Vehiculo::Vehiculo()
{
    Marca = "";
    Puertas = 0;
    Kilometraje = 0.0;
    Cilindrada = 0;
}

/**
    Metodos de la clase
**/

std::string Vehiculo::GetMarca()
{
     return Marca;
}

void Vehiculo::SetMarca(std::string val)
{
    Marca = val;
}

float Vehiculo::GetKilometraje()
{
    return Kilometraje;
}

void Vehiculo::SetKilometraje(float val)
{
     Kilometraje = val;
}

int Vehiculo::GetPuertas()
{
    return Puertas;
}

void Vehiculo::SetPuertas(int val)
{
     Puertas = val;
}

int Vehiculo::GetCilindrada()
{
      return Cilindrada;
}

void Vehiculo::SetCilindrada(int val)
{
      Cilindrada = val;
}
