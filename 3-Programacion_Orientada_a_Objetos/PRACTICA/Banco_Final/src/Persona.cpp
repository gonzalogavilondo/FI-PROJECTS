#include "Persona.h"

Persona::Persona(){
    nombre = "";
    mail = "";
    DNI = 0;
    telefono = 0;
    provincia = "";
    localidad = "";
    direccion = "";
    fechaNac = Fecha(0, 0, 0);
}

Persona::Persona(string inNombre, string inMail, int inDNI, int inTelefono,
                 string inProvincia, string inLocalidad, string inDireccion,
                 int dd, int mm, int yy){
        nombre = inNombre;
        mail = inMail;
        DNI = inDNI;
        telefono = inTelefono;
        provincia = inProvincia;
        localidad = inLocalidad;
        direccion = inDireccion;
        fechaNac = Fecha(dd, mm, yy);
}

Persona::Persona(string inNombre, string inMail, int inDNI, int inTelefono,
                 string inProvincia, string inLocalidad, string inDireccion,
                 Fecha inFechaNac){
    nombre = inNombre;
    mail = inMail;
    DNI = inDNI;
    telefono = inTelefono;
    provincia = inProvincia;
    localidad = inLocalidad;
    direccion = inDireccion;
    fechaNac = inFechaNac;
}

Persona::~Persona(){
    //dtor
}

void Persona::setNombre(string inNombre){
    nombre = inNombre;
}

void Persona::setMail(string inMail){
    mail = inMail;
}

void Persona::setDNI(int inDNI){
    DNI = inDNI;
}

void Persona::setTelefono(int inTel){
    telefono = inTel;
}

void Persona::setDireccion(string inDir){
    direccion = inDir;
}

void Persona::setProvincia(string inProv){
    provincia = inProv;
}

void Persona::setLocalidad(string inLoc){
    localidad = inLoc;
}

void Persona::setFechaNac(int dd, int mm, int yy){
    fechaNac = Fecha(dd, mm, yy);
}

void Persona::setFechaNac(Fecha inFecha){
    fechaNac = inFecha;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getMail(){
    return mail;
}

unsigned Persona::getDNI(){
    return DNI;
}

int Persona::getTelefono(){
    return telefono;
}

string Persona::getDireccion(){
    return direccion;
}

string Persona::getProvincia(){
    return provincia;
}

string Persona::getLocalidad(){
    return localidad;
}

Fecha Persona::getFechaNac(){
    return fechaNac;
}

istream& operator >> (istream& ci, Persona& p){
    if(ci.peek() == '\n') ci.ignore();

    getline(ci, p.nombre);
    getline(ci, p.mail);
    ci >> p.DNI;
    ci >> p.telefono;
    ci.ignore();
    getline(ci, p.provincia);
    getline(ci, p.localidad);
    getline(ci, p.direccion);
    ci >> p.fechaNac;

    p.setPersona(ci);

    return ci;
}

ostream& operator << (ostream& co, Persona& p){
//    if(typeid(co) == typeid(cout))
    co << p.nombre << endl
       << p.mail << endl
       << p.DNI << endl
       << p.telefono << endl
       << p.provincia << endl
       << p.localidad << endl
       << p.direccion << endl
       << p.fechaNac << endl;

    p.printPersona(co);

    return co;
}

void Persona::ingresarPersona(){
    cin.ignore();
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    cout << "Ingrese el mail: ";
    getline(cin, mail);
    cout << "Ingrese el DNI: ";
    cin >> DNI;
    cout << "Ingrese el telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese la provincia: ";
    getline(cin, provincia);
    cout << "Ingrese la localidad: ";
    getline(cin, localidad);
    cout << "Ingrese la direccion: ";
    getline(cin, direccion);
    cout << "Ingrese fecha de nacimiento (formato dd/mm/yyyy): ";
    cin >> fechaNac;
}

ostream& Persona::mostrarPersona(ostream& co){
    co << "Nombre: " << nombre << endl;
    co << "Mail: " << mail << endl;
    co << "DNI: " << DNI << endl;
    co << "Telefono: " << telefono << endl;
    co << "Provincia: " << provincia << endl;
    co << "Localidad: " << localidad << endl;
    co << "Direccion: " << direccion << endl;
    co << "Fecha de nacimiento: " << fechaNac << endl;

    return co;
}
