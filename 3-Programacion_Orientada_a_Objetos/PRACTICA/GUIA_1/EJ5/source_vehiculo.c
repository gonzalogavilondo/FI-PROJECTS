#include "header_vehiculo.h"


Vehiculo NewVehiculo()
{
    Vehiculo v = (Vehiculo) malloc(sizeof(struct vehiculo_t));
    v->marca = NULL;
    v->puertas = 0;
    v->kilometraje = 0;
    v->cilindrada = 0;
    v->getMarca = getMarca;
    v->setMarca = setMarca;
    v->getPuertas = getPuertas;
    return v;
}

void destruirVehiculo(Vehiculo v)
{
    free(v->marca);
    free(v);
}

char *getMarca(Vehiculo v)
{
    return v->marca;
}

void setMarca (Vehiculo v, char *marca)
{
    int length = strlen(marca);
    v->marca = (char *)realloc(v->marca, sizeof(char)*(length+1));
    strcpy(v->marca, marca);
    return;
}

int getPuertas(Vehiculo v)
{
    return v->puertas;
}

void setPuertas(Vehiculo v, int p)
{
    v->puertas = p;
}

float getKilometraje(Vehiculo v)
{
    return v->kilometraje;
}

void setKilometraje(Vehiculo v, float k)
{
    v->kilometraje = k;
}

int getCilindrada(Vehiculo v)
{
    return v->cilindrada;
}

void setCilindrada(Vehiculo v, int c)
{
    v->cilindrada = c;
}

//void acelerar(Vehiculo);
//void frenar(Vehiculo);
//void prender(Vehiculo);
//void apagar(Vehiculo);
