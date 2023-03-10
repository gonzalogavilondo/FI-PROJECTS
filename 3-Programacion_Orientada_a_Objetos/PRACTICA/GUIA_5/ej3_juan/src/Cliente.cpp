#include "Cliente.h"

Cliente::Cliente(){
    generadorID();
}

Cliente::Cliente(string inNombre, string inMail, int inDNI,
                 int inTelefono, string inProvincia,
                 string inLocalidad, string inDireccion,
                 int ddNac, int mmNac, int yyNac, int ddIng,
                 int mmIng, int yyIng) :
    Persona(inNombre, inMail, inDNI, inTelefono, inProvincia,
            inLocalidad, inDireccion, ddNac, mmNac, yyNac){

    fechaIng = Fecha(ddIng, mmIng, yyIng);
}

Cliente::Cliente(string inNombre, string inMail, int inDNI,
                 int inTelefono, string inProvincia,
                 string inLocalidad, string inDireccion,
                 Fecha inFechaNac, Fecha inFechaIng) :
    Persona(inNombre, inMail, inDNI, inTelefono, inProvincia,
            inLocalidad, inDireccion, inFechaNac){

    fechaIng = inFechaIng;
}

Cliente::~Cliente(){
    //dtor
}

void Cliente::setIdCliente(int inId){
    idCliente = inId;
}

void Cliente::setFechaIng(int dd, int mm, int yy){
    fechaIng = Fecha(dd, mm, yy);
}

void Cliente::setFechaIng(Fecha f){
    fechaIng = f;
}

int Cliente::getIdCliente(){
    return idCliente;
}

Fecha Cliente::getFechaIng(){
    return fechaIng;
}

void Cliente::ingresarCliente(){
    this->ingresarPersona();
    cout << "Ingrese fecha de ingreso (formato dd/mm/yyyy): ";
    cin >> fechaIng;
}

void Cliente::mostrarCliente(ostream& co){
    this->mostrarPersona(co);
    co << "ID Cliente: " << idCliente << endl;
    co << "Fecha de nacimiento: " << fechaIng << endl;
}

void Cliente::setPersona(istream& ci){
    ci >> fechaIng;
}

void Cliente::printPersona(ostream& co){
    co << idCliente << endl;
    co << fechaIng << endl;
}

void Cliente::generadorID(){
    idCliente = rand();
}
