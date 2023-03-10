#include "Banco.h"
Banco::Banco(){
    //ctor
}

Banco::Banco(string inNombre, unsigned inTelefono, string inDireccion){
    nombre = inNombre;
    telefono = inTelefono;
    direccion = inDireccion;
}

Banco::~Banco(){
    //dtor
}

void Banco::setNombre(string inNombre){
    nombre = inNombre;
}

void Banco::setTelefono(unsigned int inTelefono){
    telefono = inTelefono;
}

void Banco::setDireccion(string inDireccion){
    direccion = inDireccion;
}

string Banco::getNombre(){
    return nombre;
}

unsigned int Banco::getTelefono(){
    return telefono;
}

string Banco::getDireccion(){
    return direccion;
}

vector<string> Banco::getIds(){
    vector<string> ids;
    map<string, Cliente*>::iterator ForIter = clientes.begin();

    while (ForIter != clientes.end()){
        ids.push_back(ForIter->first);
        ForIter++;
    }
    return ids;
}

vector<string> Banco::getCbus(){
    vector<string> cbus;
    map<string, CuentaBancaria*>::iterator ForIter = cuentas.begin();

    while (ForIter != cuentas.end()){
        cbus.push_back(ForIter->first);
        ForIter++;
    }
    return cbus;
}

Cliente* Banco::getCliente(string inIdCliente){
    map<string, Cliente*>::iterator Iter = clientes.find(inIdCliente);
    if (Iter == clientes.end()) return NULL;

    return Iter->second;
}

CuentaBancaria* Banco::getCuenta(string inCbu){
    map<string, CuentaBancaria*>::iterator Iter = cuentas.find(inCbu);
    if (Iter == cuentas.end()) return NULL;

    return Iter->second;
}


map<string, Cliente*> Banco::getMapaClientes(){
    return clientes;
}

map<string, CuentaBancaria*> Banco::getMapaCuentas(){
    return cuentas;
}

void Banco::addCliente(Cliente *inCliente){
    clientes.insert(make_pair(inCliente->getIdCliente(), inCliente));
}

void Banco::addCuenta(CuentaBancaria *inCuenta){
    cuentas.insert(make_pair(inCuenta->getCBU(), inCuenta));
}

unsigned Banco::getSizeClientes(){
    return clientes.size();
}

unsigned Banco::getSizeCuentas(){
    return cuentas.size();
}

string Banco::gen_random(const int len){
    string s;
    static const char alphanum[] =
        "0123456789";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}

string Banco::generadorID(){
    string id = gen_random(10);
    return id;
}

string Banco::generadorCBU(){
    string cbu = gen_random(21);
    return cbu;
}

string Banco::crearCliente(string inNombre, string inMail,
                            unsigned inDNI, unsigned inTelefono,
                            string inProvincia, string inLocalidad,
                            string inDireccion, Fecha inFechaNac,
                            Fecha inFechaIng){

    Cliente *newCliente = new Cliente(inNombre, inMail, inDNI,
                                 inTelefono, inProvincia,
                                 inLocalidad, inDireccion,
                                 inFechaNac, inFechaIng);
    string newIdCliente = generadorID();
    newCliente->setIdCliente(newIdCliente);

    clientes.insert(make_pair(newIdCliente, newCliente));   //agrego el cliente
    return newIdCliente;
}

string Banco::agregarCliente(Cliente *inCliente){
    string newIdCliente = generadorID();
    inCliente->setIdCliente(newIdCliente);

    clientes.insert(make_pair(newIdCliente, inCliente));
    return newIdCliente;
}

string Banco::crearCuenta(string idCliente, tipoDeCuenta tipo){
    CuentaBancaria* newCuenta;

    try{
        switch (tipo){
        case CAJADEAHORRO:
            newCuenta = new CajaDeAhorro();
            break;
        case CUENTACORRIENTE:
            newCuenta = new CuentaCorriente();
            break;
        case CUENTAUNIVERSITARIA:
            newCuenta = new CuentaUniversitaria();
        }
        if(!newCuenta){
            throw(bad_alloc());
        }
    }

    catch (bad_alloc& e){
        cout << "Se ha generado un excepcion: " << e.what() << endl;
    }

    //Genero CBU
    string newCbu = generadorCBU();
    newCuenta->setCBU(newCbu);

    //link de la cuenta al cliente
    newCuenta->addTitular(idCliente);

    cuentas.insert(make_pair(newCbu, newCuenta));

    return newCbu;
}


string Banco::crearYAsignarCuenta(string inIdCliente, tipoDeCuenta tipo){
    Cliente* thisCliente = getCliente(inIdCliente);
    if (thisCliente == NULL) return to_string(SEARCH_ERROR);

    string idCliente = thisCliente->getIdCliente();
    string newCbu = crearCuenta(idCliente, tipo);

    //link del cliente a la cuenta
    thisCliente->addCbu(newCbu);

    return newCbu;
}

bool Banco::asignarCuenta(string inIdCliente, string inCbu){
    Cliente* thisCliente = getCliente(inIdCliente);
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCliente == NULL || thisCuenta == NULL) return false;

    thisCliente->addCbu(inCbu);
    thisCuenta->addTitular(inIdCliente);

    return true;
}

string Banco::buscarClienteDNI(unsigned inDni){
    map<string, Cliente*>::iterator ForITer = clientes.begin();
    string idCliente = to_string(SEARCH_ERROR);

    while (ForITer != clientes.end() && idCliente == to_string(SEARCH_ERROR)){
        Cliente *thisCliente = ForITer->second;
        if (thisCliente->getDNI() == inDni){
            idCliente = thisCliente->getIdCliente();
        }
        ForITer++;
    }

    return idCliente;
}

bool Banco::depositar(string inCbu){
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCuenta == NULL) return false;

    float inMonto;
    cout << "Ingrese el monto: ";
    cin >> inMonto;

    return thisCuenta->deposito(inMonto);
}

bool Banco::depositar(string inCbu, float inMonto){
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCuenta == NULL) return false;

    ///actualizar log operaciones

    return thisCuenta->deposito(inMonto);
}

bool Banco::extraer(string inCbu){
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCuenta == NULL) return false;

    float inMonto;
    cout << "Ingrese el monto: ";
    cin >> inMonto;

    return thisCuenta->extraccion(inMonto);
}

bool Banco::extraer(string inCbu, float inMonto){
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCuenta == NULL) return false;

    return thisCuenta->extraccion(inMonto);
}

float Banco::consultarSaldo(string inCbu){
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCuenta == NULL) return SEARCH_ERROR;

    return thisCuenta->getSaldo();
}

vector<float> Banco::getActivoDisponiblePorCuenta(){
    vector<float> suma(3, 0);
    map<string, CuentaBancaria*>::iterator ForIter = cuentas.begin();

    for (unsigned int i = 0; i < cuentas.size(); i++){
        CuentaBancaria* thisCuenta = ForIter->second;
        tipoDeCuenta thisCuentaTipo = thisCuenta->getTipo();

        suma[thisCuentaTipo] += thisCuenta->getSaldo();

        ForIter++;
    }

    return suma;
}

float Banco::getActivoDisponibleTotal(){
    vector<float> sumaCuentas = getActivoDisponiblePorCuenta();
    return accumulate(sumaCuentas.begin(), sumaCuentas.end(), 0.0);
}

istream& operator >> (istream& ci, Banco& b){
    if(ci.peek() == '\n') ci.ignore();

    getline(ci, b.nombre);
    ci >> b.telefono;
    ci.ignore();
    getline(ci, b.direccion);

    return ci;
}

ostream& operator << (ostream& co, Banco& b){
    co << b.nombre << endl
       << b.telefono << endl
       << b.direccion << endl;

    return co;
}

void Banco::printClientes(ostream& co){
    map<string, Cliente*>::iterator ForIter = clientes.begin();
    for (unsigned int i = 0; i < clientes.size(); i++){
        (ForIter->second)->mostrarCliente(co);
        co << endl;
        ForIter++;
    }
}

void Banco::printCuentas(ostream& co){
    map<string, CuentaBancaria*>::iterator ForIter = cuentas.begin();
    for (unsigned int i = 0; i < cuentas.size(); i++){
        CuentaBancaria *thisCuenta = ForIter->second;
        thisCuenta->mostrarCuenta(co);

        cout << "Titulares: ";
        for (unsigned j = 0; j < thisCuenta->getSizeTitulares(); j++){
            string idActual = thisCuenta->getTitular(j);
            Cliente *thisCliente = getCliente(idActual);
            cout << thisCliente->getNombre() << ", ";
        }
        co << endl << endl << endl;
        ForIter++;
    }
}

///VERIFICAR QUE NO ESTA REPETIDO
string Banco::cargarCliente(){
    Cliente *nuevoCliente = new Cliente();
    nuevoCliente->ingresarCliente();

    return agregarCliente(nuevoCliente);
}

bool Banco::mostrarClienteYCuentas(string inIdCliente, ostream& co){
    Cliente* thisCliente = getCliente(inIdCliente);
    if (thisCliente == NULL) return false;

    thisCliente->mostrarCliente(co);
    co << endl;
    if (thisCliente->getSizeCbus() == 0){
        co << "El cliente no tiene cuentas." << endl;
    } else {
        co << "CUENTAS" << endl << endl;
        for (unsigned i = 0; i < thisCliente->getSizeCbus(); i++){
            co << "Cuenta " << i + 1 << endl;
            string thisCbu = thisCliente->getCbu(i);
            CuentaBancaria* thisCuenta = getCuenta(thisCbu);
            thisCuenta->mostrarCuenta(co);
            co << endl;
        }
    }
    co << endl;
    return true;
}

bool Banco::mostrarCuentaYTitulares(string inCbu, ostream& co){
    CuentaBancaria* thisCuenta = getCuenta(inCbu);
    if (thisCuenta == NULL) return false;

    thisCuenta->mostrarCuenta(co);
    co << endl;

    co << "Titulares" << endl << endl;
    for (unsigned i = 0; i < thisCuenta->getSizeTitulares(); i++){
        string thisId = thisCuenta->getTitular(i);
        Cliente* thisCliente = getCliente(thisId);
        thisCliente->mostrarCliente(co);
        co << endl;
    }
    co << endl;

    return true;
}
