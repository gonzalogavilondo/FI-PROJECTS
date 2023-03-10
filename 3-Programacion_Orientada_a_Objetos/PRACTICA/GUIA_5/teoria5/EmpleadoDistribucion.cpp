#include <cstring>
#include "EmpleadoDistribucion.h"
EmpleadoDistribucion::EmpleadoDistribucion(char nombre[], long dni, int
diasVacaciones, double salarioBase, char region[]): Asalariado (nombre, dni,
diasVacaciones, salarioBase){
    strcpy (this->region, region);
}

char * EmpleadoDistribucion::getRegion (){
    return this->region;
}

void EmpleadoDistribucion::setRegion (char nueva_region[]){
    strcpy (this->region, nueva_region);
}

double EmpleadoDistribucion::getSalario (){
    return Asalariado::getSalario() * (1 + 0.10);
}
