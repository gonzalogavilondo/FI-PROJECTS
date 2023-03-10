//
// Created by victoria on 4/10/2021.
//

#include <cstring>
#include "Asalariado.h"

using namespace std;

Asalariado::Asalariado(char nombre[], long dni, int diasVacaciones, double
salarioBase){
    strcpy (this->nombre, nombre);
    this->dni = dni;
    this->diasVacaciones = diasVacaciones;
    this->salarioBase = salarioBase;
}

char * Asalariado::getNombre (){
    return this->nombre;
}
void Asalariado::setNombre (char nuevo_nombre[]){
    strcpy (this->nombre, nuevo_nombre);
}

long Asalariado::getDni (){
    return this->dni;
}

void Asalariado::setDni (long nuevo_dni){
    this->dni = nuevo_dni;
}

int Asalariado::getDiasVacaciones (){
    return this->diasVacaciones;
}

void Asalariado::setDiasVacaciones (int nuevo_diasVacaciones){
    this->diasVacaciones = nuevo_diasVacaciones;
}

//double Asalariado::getSalario (){
//    return this->salarioBase;
//}
