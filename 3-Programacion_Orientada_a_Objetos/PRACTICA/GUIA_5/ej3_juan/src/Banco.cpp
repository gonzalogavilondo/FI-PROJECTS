#include "Banco.h"
Banco::Banco(){
    //ctor
}

Banco::Banco(string inNombre, int inTelefono, string inDireccion){
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

Cliente& Banco::getCliente(int index){
    return clientes[index].getCliente();
}

CuentaBancaria* Banco::getCuentaBancaria(int index){
    return cuentasBancarias[index].getCuenta();
}

int Banco::getSizeClientes() const{
    return clientes.size();
}

int Banco::getSizeCuentas() const{
    return cuentasBancarias.size();
}

vector <CuentaBancaria*> Banco::getCuentasCliente(int index){
    return clientes[index].getCuentas();
}

vector <Cliente*> Banco::getClientesCuenta(string CBU){
    int index = buscarCuenta(CBU);
    return cuentasBancarias[index].getTitulares();
}

int Banco::getSizeCuentasCliente(int index) const{
    return clientes[index].getSizeCuentasBancarias();
}

int Banco::getSizeClientesCuenta(int index) const{
    return cuentasBancarias[index].getSizeTitulares();
}



int Banco::buscarCuenta(string inCBU){
    bool flag = false;
    unsigned int i = 0;

    while(flag == false && i < cuentasBancarias.size()){
        CuentaBancaria *thisCuenta = cuentasBancarias[i].getCuenta();
        if (thisCuenta->getCBU() == inCBU){
            flag = true;
            i--;
        }
        i++;
    }
    return flag ? i : -1;
}

CuentaBancaria *Banco::buscarCuenta(string inCBU, int dummy){
    int pos = buscarCuenta(inCBU);
    if (pos == -1){
        return NULL;
    }
    return cuentasBancarias[pos].getCuenta();
}

int Banco::buscarCliente(int inIdCliente){
    bool flag = false;
    unsigned int i = 0;

    while(flag == false && i < clientes.size()){
        Cliente thisCliente = clientes[i].getCliente();
        if (thisCliente.getIdCliente() == inIdCliente){
            flag = true;
            i--;
        }
        i++;
    }
    return flag ? i : -1;
}

Cliente *Banco::buscarCliente(int inIdCliente, int dummy){
    int pos = buscarCliente(inIdCliente);
    if (pos == -1){
        return NULL;
    }
    return &(clientes[pos].getCliente());
}

int Banco::buscarClienteDNI(int inDNI){
    bool flag = false;
    unsigned int i = 0;

    while(flag == false && i < clientes.size()){
        Cliente thisCliente = clientes[i].getCliente();
        if (thisCliente.getDNI() == inDNI){
            flag = true;
            i--;
        }
        i++;
    }
    return flag ? i : -1;
}

void Banco::levantarClientes(vector <int> idCliente)
{
    try
    {
        ifstream fin("ejemploCliente.txt", ios::in); //Abrimos el archivo en modo lectura.
        if(!fin.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }
//        int cntClientesInTxt = 0;
//        fin >> cntClientesInTxt;
        for(int i = 0; i < 3; i++)
        {
            Cliente aux;
            fin >> aux;
            idCliente[i] = this->crearCliente(aux);
            cout << idCliente[i] << endl;
        }
        fin.close();
    }
    catch (runtime_error& e)
    {
        cout << "Atajada excepcion: " << e.what() << endl;
    }
}

int Banco::crearCliente(string inNombre, string inMail,
                        int inDNI, int inTelefono,
                        string inProvincia, string inLocalidad,
                        string inDireccion, Fecha inFechaNac,
                        Fecha inFechaIng){

    bLinkCliente newCliente;
    Cliente auxCliente = Cliente(inNombre, inMail, inDNI,
                                 inTelefono, inProvincia,
                                 inLocalidad, inDireccion,
                                 inFechaNac, inFechaIng);
    newCliente.setCliente(auxCliente);

    clientes.push_back(newCliente); //agrego el cliente
    return auxCliente.getIdCliente();
}

int Banco::crearCliente(Cliente& inCliente){
    bLinkCliente auxCliente(inCliente);
    clientes.push_back(auxCliente);

    return auxCliente.getCliente().getIdCliente();
}

string Banco::asignarCuenta(int inIdCliente, tipoDeCuenta tipo){

    bLinkCuenta newCuenta;

    switch (tipo){
    case CAJADEAHORRO:
        newCuenta.setCuenta(new CajaDeAhorro());
        break;
    case CUENTACORRIENTE:
        newCuenta.setCuenta(new CuentaCorriente());
        break;
    case CUENTAUNIVERSITARIA:
        newCuenta.setCuenta(new CuentaUniversitaria());
    }

    int posCliente = buscarCliente(inIdCliente);
    //link de la cuenta al cliente
    newCuenta.addTitular(getCliente(posCliente));
    cuentasBancarias.push_back(newCuenta);

    //link del cliente a la cuenta
    clientes[posCliente].addCuentaBancaria(newCuenta.getCuenta());

    return newCuenta.getCuenta()->getCBU();
}

bool Banco::depositar(string inCBU){
    CuentaBancaria* thisCuenta = buscarCuenta(inCBU, 0);
    float inMonto;
    bool res = true;

    if (thisCuenta == NULL){
        res = false;
    } else {
        cout << "Ingrese el monto: ";
        cin >> inMonto;
        res = thisCuenta->deposito(inMonto);
    }
    return res;
}

bool Banco::depositar(string inCBU, float inMonto){
    CuentaBancaria* thisCuenta = buscarCuenta(inCBU, 0);
    bool res = true;

    if (thisCuenta == NULL){
        res = false;
    } else {
        res = thisCuenta->deposito(inMonto);
    }
    return res;
}

bool Banco::extraer(string inCBU){
    CuentaBancaria* thisCuenta = buscarCuenta(inCBU, 0);
    float inMonto;
    bool res = true;

    if (thisCuenta == NULL){
        res = false;
    } else {
        cout << "Ingrese el monto: ";
        cin >> inMonto;
        res = thisCuenta->extraccion(inMonto);
    }

    return res;
}

bool Banco::extraer(string inCBU, float inMonto){
    CuentaBancaria* thisCuenta = buscarCuenta(inCBU, 0);
    bool res = true;

    if (thisCuenta == NULL){
        res = false;
    } else {
        res = thisCuenta->extraccion(inMonto);
    }

    return res;
}

float Banco::consultarSaldo(string inCBU){
    CuentaBancaria* thisCuenta = buscarCuenta(inCBU, 0);
    return thisCuenta->getSaldo();
}

float Banco::activoDisponible(){
    float suma = 0;
    for (unsigned int i = 0; i < cuentasBancarias.size(); i++){
        CuentaBancaria* thisCuenta = cuentasBancarias[i].getCuenta();
        suma += thisCuenta->getSaldo();
    }
    return suma;
}

void Banco::printClientes(ostream& co){
    for (unsigned int i = 0; i < clientes.size(); i++){
        clientes[i].getCliente().mostrarCliente(co);
        co << endl;
    }
}

void Banco::printCuentas(ostream& co){
    for (unsigned int i = 0; i < cuentasBancarias.size(); i++){
        co << *(cuentasBancarias[i].getCuenta()) << endl;
        co << "Titulares:" << endl;
        for (int j = 0; j < cuentasBancarias[i].getSizeTitulares(); j++){
            Cliente aux = cuentasBancarias[i].getTitular(j);
            co << aux.getNombre() << endl
               << aux.getDNI() << endl
               << aux.getIdCliente() << endl << endl;
        }

    }
}

void Banco::cargarCliente(){
    Cliente nuevoCliente;
    nuevoCliente.ingresarCliente();
    crearCliente(nuevoCliente);
}

void Banco::mostrarClienteYCuentas(int inIdCliente){
    int pos = buscarCliente(inIdCliente);
    bLinkCliente thisCliente = clientes[pos];

    cout << thisCliente.getCliente() << endl << endl;

    cout << "CUENTAS" << endl << endl;
    for (int i = 0; i < thisCliente.getSizeCuentasBancarias(); i++){
        cout << *thisCliente.getCuentaBancaria(i) << endl;
    }
}

void Banco::mostrarCuentaYTitulares(string inCBU){
    int pos = buscarCuenta(inCBU);
    bLinkCuenta thisCuenta = cuentasBancarias[pos];

    cout << *thisCuenta.getCuenta() << endl << endl;

    cout << "TITULARES" << endl << endl;
    for (int i = 0; i < thisCuenta.getSizeTitulares(); i++){
        cout << thisCuenta.getTitular(i) << endl;
    }
}
