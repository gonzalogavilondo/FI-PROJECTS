#include "Vehiculo.h"

//Constructores y Destructores
Vehiculo::Vehiculo(){
    dueno = "NN";
    marca = "NN";
    patente = "NN";
    cantPuertas = 0;
    kilometraje = 0;
    cilindrada = 0;
}

Vehiculo::~Vehiculo(){
    //dtor
}

Vehiculo::Vehiculo(string pDueno, string pMarca, string pPatente, int pPuertas,
         float pKil, int pCil){
    dueno = pDueno;
    marca = pMarca;
    patente = pPatente;
    cantPuertas = pPuertas;
    kilometraje = pKil;
    cilindrada = pCil;
}

//Setters y Getters
void Vehiculo::setDueno(string d){
    dueno = d;
}

void Vehiculo::setMarca(string m){
    marca = m;
}

void Vehiculo::setPatente(string p){
    patente = p;
}

void Vehiculo::setCantPuertas(int p){
    cantPuertas = p;
}

void Vehiculo::setKilometraje(float k){
    kilometraje = k;
}

void Vehiculo::setCilindrada(int c){
    cilindrada = c;
}

string Vehiculo::getDueno(){
    return dueno;
}

string Vehiculo::getMarca(){
    return marca;
}

string Vehiculo::getPatente(){
    return patente;
}

int Vehiculo::getCantPuertas(){
    return cantPuertas;
}

float Vehiculo::getKilometraje(){
    return kilometraje;
}

int Vehiculo::getCilindrada(){
    return cilindrada;
}

//Sobrecarga de los operandores de extracción e inserción
istream& operator >> (istream& ci, Vehiculo& v){
    ci.ignore();
    getline(ci, v.dueno);
    getline(ci, v.marca);
    getline(ci, v.patente);
    ci >> v.cantPuertas;
    ci >> v.kilometraje;
    ci >> v.cilindrada;
    v.setVehiculo(ci);
    return ci;
}

ostream& operator << (ostream& co, const Vehiculo& v){
    co << "Dueño: " << v.dueno << endl;
    co << "Marca del vehiculo: " << v.marca << endl;
    co << "Patente del vehiculo: " << v.patente << endl;
    co << "Cantidad de puertas del vehiculo: " << v.cantPuertas << endl;
    co << "Kilometraje del vehiculo: " << v.kilometraje << endl;
    co << "Cilindrada del vehiculo: " << v.cilindrada << endl;
    v.printVehiculo(co);

    return co;
}

//Métodos de "Vehículo"
void Vehiculo::caracteristicas(){
    cout << "Características de vehículo." << endl;
}
