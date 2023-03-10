#ifndef HEADER_VEHICULO_H_INCLUDED
#define HEADER_VEHICULO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
/*
Implementar un TDA llamado Veh�culo, organizando la definici�n en un
archivo de cabecera y su implementaci�n en un archivo .c. Utilice una estructura
que contenga campos para representar los atributos del Veh�culo: marca,
puertas, kilometraje y cilindrada y punteros a funciones: �getters� y �setters�
para acceder a los atributos antes mencionados y algunas acciones que puede
realizar el Veh�culo: acelerar, frenar, prender, apagar. Adem�s, son necesarias
dos funciones encargadas de reservar y liberar memoria de forma din�mica:
crearVeh�culo y destruirVeh�culo.
*/
typedef struct vehiculo_t *Vehiculo;

struct vehiculo_t
{
    char *marca;
    int puertas;
    float kilometraje;
    int cilindrada;
    char * (*getMarca)(Vehiculo);
    void (*setMarca) (Vehiculo, char *);
    int (*getPuertas)(Vehiculo);
    void (*setPuertas) (Vehiculo, int);
    float (*getKilometraje)(Vehiculo);
    void (*setKilometraje) (Vehiculo, float);
    int (*getCilindrada)(Vehiculo);
    void (*setCilindrada) (Vehiculo, int);
    void (*acelerar) (Vehiculo);
    void (*frenar) (Vehiculo);
    void (*prender) (Vehiculo);
    void (*apagar) (Vehiculo);
};

Vehiculo NewVehiculo();
void destruirVehiculo(Vehiculo);
char *getMarca(Vehiculo);
void setMarca (Vehiculo, char *);
int getPuertas(Vehiculo);
void setPuertas(Vehiculo, int);
float getKilometraje(Vehiculo);
void setKilometraje(Vehiculo, float);
int getCilindrada(Vehiculo);
void setCilindrada(Vehiculo, int);
void acelerar(Vehiculo);
void frenar(Vehiculo);
void prender(Vehiculo);
void apagar(Vehiculo);






#endif // HEADER_VEHICULO_H_INCLUDED
