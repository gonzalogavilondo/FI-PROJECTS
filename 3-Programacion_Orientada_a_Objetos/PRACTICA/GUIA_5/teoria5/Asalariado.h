//
// Created by victoria on 4/10/2021.
//

#ifndef POLIMORFISMO_ASALARIADO_H
#define POLIMORFISMO_ASALARIADO_H


class Asalariado {
//Atributos de instancia
private:
    char nombre [30];
    long dni;
    int diasVacaciones;
    double salarioBase;
public:
    //Constructor
    Asalariado(char nombre[] = "pepe", long dni = 11111111, int diasVacaciones = 15, double
salarioBase = 1200);
    //Métodos de instancia:
    char * getNombre ();
    void setNombre (char[]);
    long getDni ();
    void setDni (long);
    int getDiasVacaciones ();
    void setDiasVacaciones (int);
    virtual double getSalario ();
};


#endif //POLIMORFISMO_ASALARIADO_H
