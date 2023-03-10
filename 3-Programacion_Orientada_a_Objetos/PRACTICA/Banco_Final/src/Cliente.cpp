#include "Cliente.h"

Cliente::Cliente() : Persona(){
    //ctor
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

void Cliente::setIdCliente(string inId){
    idCliente = inId;
}

void Cliente::setFechaIng(int dd, int mm, int yy){
    fechaIng = Fecha(dd, mm, yy);
}

void Cliente::setFechaIng(Fecha f){
    fechaIng = f;
}

void Cliente::addCbu(string inCbu){
    cbus.push_back(inCbu);
}

string Cliente::getIdCliente(){
    return idCliente;
}

Fecha Cliente::getFechaIng(){
    return fechaIng;
}

string Cliente::getCbu(int index){
    return cbus[index];
}

vector<string> Cliente::getCbus(){
    return cbus;
}

unsigned Cliente::getSizeCbus(){
    return cbus.size();
}

void Cliente::ingresarCliente(){
    ingresarPersona();
    cout << "Ingrese fecha de ingreso (formato dd/mm/yyyy): ";
    cin >> fechaIng;
}

ostream& Cliente::mostrarCliente(ostream& co){
    mostrarPersona(co);
    co << "ID Cliente: " << idCliente << endl;
    co << "Fecha de nacimiento: " << fechaIng << endl;

    return co;
}

void Cliente::setPersona(istream& ci){
    int cantCuentas = 0;

    getline(ci, idCliente);
    ci >> fechaIng;
    ci >> cantCuentas;
    ci.ignore();
    for (int i = 0; i < cantCuentas; i++){
        string auxCbu;
        getline(ci, auxCbu);
        cbus.push_back(auxCbu);
    }
}

void Cliente::printPersona(ostream& co){
    unsigned sizeCbus = getSizeCbus();
    co << idCliente << endl;
    co << fechaIng << endl;
    co << sizeCbus << endl;
    for (unsigned i = 0; i < sizeCbus; i++){
        co << cbus[i] << endl;
    }
}
