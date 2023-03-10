#include "vehiculo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getMarca(Vehiculo this)
{
    char* marca;
    marca = this->m_marca;
    return marca;
}

int getPuertas(Vehiculo this)
{
    int value = 0;
    value = this->m_puertas;
    return value;
}

int getKilometraje(Vehiculo this)
{
    int value = 0;
    value = this->m_kilometraje;
    return value;
}

float getCilindrada(Vehiculo this)
{
    int value = 0;
    value = this->m_cilindrada;
    return value;
}

void setMarca(Vehiculo this, const char* marca)
{
    strcpy(this->m_marca, marca);
}

void setPuertas(Vehiculo this, int puertas)
{
    this->m_puertas = puertas;
}

void setKilometraje(Vehiculo this, int kilometros)
{
    this->m_kilometraje = kilometros;
}

void setCilindrada(Vehiculo this, float cilindrada)
{
    this->m_cilindrada = cilindrada;
}


void encenderVehiculo(Vehiculo this)
{
    //TODO: mostrar algun atributo del vehiculo en cuestion, por ejemplo patente.
    printf("El vehiculo está encendido!! \n");
}

void apagarVehiculo(Vehiculo this)
{
    printf("El vehiculo está apagado!! \n");
}

void acelerarVehiculo(Vehiculo this)
{
    printf("Acelerando el %s \n", this->get_marca(this));
}

void frenarVehiculo(Vehiculo this)
{
    printf("Frenando el %s \n", this->get_marca(this));
}


// Constructor & Destructor //
Vehiculo crearVehiculo(const char* marca, int puertas, int kilometros, float cilindrada)
{
    Vehiculo nuevoVehiculo;
    nuevoVehiculo = (Vehiculo) malloc(sizeof(struct Vehiculo));
    // Inicializacion de atributos
    nuevoVehiculo->m_marca = (char*) malloc(strlen(marca)*sizeof(char));
    strcpy(nuevoVehiculo->m_marca, marca);
    nuevoVehiculo->m_puertas = puertas;
    nuevoVehiculo->m_kilometraje = kilometros;
    nuevoVehiculo->m_cilindrada = cilindrada;
    // Vinculacion de funciones a punteros
    nuevoVehiculo->set_marca = setMarca;
    nuevoVehiculo->get_marca = getMarca;
    nuevoVehiculo->set_puertas = setPuertas;
    nuevoVehiculo->get_puertas = getPuertas;
    nuevoVehiculo->set_kilometraje = setKilometraje;
    nuevoVehiculo->get_kilometraje = getKilometraje;
    nuevoVehiculo->set_cilindrada = setCilindrada;
    nuevoVehiculo->get_cilindrada = getCilindrada;

    nuevoVehiculo->encender = encenderVehiculo;
    nuevoVehiculo->apagar = apagarVehiculo;
    nuevoVehiculo->acelerar = acelerarVehiculo;
    nuevoVehiculo->frenar = frenarVehiculo;

    return nuevoVehiculo;
}

void destruirVehiculo(Vehiculo this)
{
    //free(this->getMarca(this));
    free(this->m_marca);
    free(this);
}
