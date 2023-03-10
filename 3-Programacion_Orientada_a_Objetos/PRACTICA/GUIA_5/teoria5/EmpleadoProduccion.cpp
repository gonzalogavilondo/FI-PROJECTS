//
// Created by victoria on 4/10/2021.
//

#include <cstring>
#include "EmpleadoProduccion.h"

EmpleadoProduccion::EmpleadoProduccion(char nombre[], long dni, int
diasVacaciones, double salarioBase, char turno[]) : Asalariado(nombre, dni,
                                                               diasVacaciones, salarioBase) {
    strcpy(this->turno, turno);
}

char *EmpleadoProduccion::getTurno() {
    return this->turno;
}

void EmpleadoProduccion::setTurno(char nuevo_turno[]) {
    strcpy(this->turno, nuevo_turno);
}

double EmpleadoProduccion::getSalario() {
    return Asalariado::getSalario() * (1 + 0.15);
}
