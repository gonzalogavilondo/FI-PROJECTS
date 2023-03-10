#include "Interfaz.h"

//Constructores y Destructores
Interfaz::Interfaz(){
    //La fecha y hora se settean por defecto a las actuales.

    //Reservamos memoria para los 4 backups e inicializamos con su nombre.
    backups.resize(4);
    backups[BANCO] = Backup("BackupBanco.txt");
    backups[CUENTAS] = Backup("BackupCuentas.txt");
    backups[CLIENTES] = Backup("BackupClientes.txt");
    backups[LOGS] = Backup("BackupMovimientos.txt");
}

Interfaz::~Interfaz(){

}

//Métodos de la clase
void Interfaz::inicializarSistema(){

    //Setteo la semilla para generar lo que necesite lo más aleatorio posible.
    srand(time(NULL));

    //Levanto el Banco
    levantarDatos();

    //Setteo el Menu
    string cartel =
    "///////////////////////////////////////////\n"s +
    "////                                   ////\n"s +
    "//// " + "Bienvenido al Banco "s + banco.getNombre() + " ////\n"s +
    "////                                   ////\n"s +
    "///////////////////////////////////////////\n\n"s +
    bufferToStr(fecha);

    vector<string> ops = {
        "Ver los activos disponibles del Banco.",
        "Ver todos los clientes del banco.",
        "Ver todas las cuentas del banco.",
        "Cargar un cliente nuevo.",
        "Buscar un cliente.",
        "Buscar una cuenta.",
        "Elegir una cuenta para realizar operaciones.",
        "Guardar todo y salir."
    };
    menu = Menu(cartel, ops);

    //Punteros a función que utilizará el Menú
    void (Interfaz::*funciones[])(ostream&) = {
      mostrarActivos,
      mostrarClientes,
      mostrarCuentas,
      cargarNuevoCliente,
      buscarYMostrarCliente,
      buscarYMostrarCuenta,
      operacionesConCuenta,
      guardarSistema
    };

    unsigned length = sizeof(funciones)/(2*sizeof(void*));

    menu.ejecutarMenu(funciones, 1, length, cout, *this);
}

void Interfaz::mostrarActivos(ostream& co){
    vector<float> activosPorCuenta = banco.getActivoDisponiblePorCuenta();
    float activosTotales = banco.getActivoDisponibleTotal();

    co << "ACTIVO TOTALES: $" << activosTotales << endl << endl;
    for (unsigned i = 0; i < activosPorCuenta.size(); i++){
        switch (i){
        case CAJADEAHORRO:
            co << "Cajas De ahorro: $";
            break;
        case CUENTACORRIENTE:
            co << "Cuentas Corrientes: $";
            break;
        case CUENTAUNIVERSITARIA:
            co << "Cuentas Universitarias: $";
        }
        co << activosPorCuenta[i] << endl;
    }
    co << endl;
}

void Interfaz::mostrarClientes(ostream& co){
    banco.printClientes(co);
}

void Interfaz::mostrarCuentas(ostream& co){
    banco.printCuentas(co);
}

void Interfaz::cargarNuevoCliente(ostream& co){
    banco.cargarCliente();
}

void Interfaz::buscarYMostrarCliente(ostream& co){
    unsigned inDni;
    co << "Ingrese el DNI: ";
    cin >> inDni;
    co << endl;

    string idCliente = banco.buscarClienteDNI(inDni);
    if (!banco.mostrarClienteYCuentas(idCliente)){
        co << "No existe ese cliente." << endl;
    }
}

void Interfaz::buscarYMostrarCuenta(ostream& co){
    string inCbu;
    co << "Ingrese el CBU: ";
    cin >> inCbu;
    co << endl;

    if (!banco.mostrarCuentaYTitulares(inCbu)){
        co << "La cuenta seleccionada no existe." << endl;
    }
}

void Interfaz::operacionesConCuenta(ostream& co){
    Menu aux;   //Para poder usar sus métodos

    //Busco el cliente
    cout << "OPERACIONES" << endl << endl;
    unsigned inDni;
    cout << "Ingrese el DNI del titular: ";
    cin >> inDni;
    cout << endl;

    string idCliente = banco.buscarClienteDNI(inDni);///verificar que lo encontro!!!

    //Lo muestro con sus cuentas
    if(!banco.mostrarClienteYCuentas(idCliente)){
        cout << "No existe un cliente asociado con ese Dni." << endl << endl;
        return;
    }

    cout << "Elija una de todas las cuentas." << endl;
    Cliente *thisCliente = banco.getCliente(idCliente);
    unsigned opCuenta = aux.ingresarOpcion(1, thisCliente->getSizeCbus());

    string thisCbu = thisCliente->getCbu(opCuenta - 1);
    CuentaBancaria* thisCuenta = banco.getCuenta(thisCbu);



    int salir = 1;

    aux.addOpcionStr("Depositar dinero");
    aux.addOpcionStr("Extraer dinero");
    aux.addOpcionStr("Consultar saldo");
    aux.addOpcionStr("Salir");
    do{
        stringstream buffer;
        system("cls || clear");
        buffer << "CUENTA SELECCIONADA" << endl << endl;
        thisCuenta->mostrarCuenta(buffer);
        buffer << endl;
        string cartel = buffer.str();
        aux.setCartel(cartel);

        aux.imprimirMenu();
        unsigned op = aux.ingresarOpcion(1, 4);

        switch (op){
        case 1:
            cout << "Deposito" << endl << endl;
            if (!(banco.depositar(thisCbu))){
                cout << "No se ha podido depositar." << endl;
            }
            break;
        case 2:
            cout << "Extraccion" << endl << endl;
            if (!(banco.extraer(thisCbu))){
                cout << "No se ha podido extraer." << endl;
            }
            break;
        case 3:
            cout << "Saldo: " << banco.consultarSaldo(thisCbu) << endl << endl;
        case 4:
            salir = 0;
        }
        if (op != 4){
            cout << endl;
            cout << "Si desea realizar alguna otra operacion con esta "
                 << "cuenta, presione 0. Sino presione cualquier tecla." << endl;
            cin.ignore();
            salir = getch() - 48;
        }
    } while (salir != 0);

}

void Interfaz::guardarBanco(){
    try{
        backups[BANCO].saveFile(bufferToStr((this->banco)));
    }
    catch(runtime_error&){
        throw;
    }
}

void Interfaz::guardarClientes(){

    try{
        stringstream data;
        map<string, Cliente*> mapaCli = banco.getMapaClientes();
        map<string, Cliente*>::iterator ForIter = mapaCli.begin();

        data << mapaCli.size() << endl;

        while (ForIter != mapaCli.end()){
            data << *(ForIter->second);
            ForIter++;
        }

        backups[CLIENTES].saveFile(bufferToStr(data.str()));
    }
    catch(...){
        throw;
    }
}

void Interfaz::guardarCuentas(){
    try{
        stringstream data;
        map<string, CuentaBancaria*> mapaCuentas = banco.getMapaCuentas();
        map<string, CuentaBancaria*>::iterator ForIter = mapaCuentas.begin();

        data << mapaCuentas.size() << endl;

        while (ForIter != mapaCuentas.end()){
            data << int((ForIter->second)->getTipo()) << endl;
            data << *(ForIter->second);
            ForIter++;
        }
        backups[CUENTAS].saveFile(bufferToStr(data.str()));
    }
    catch(...){
        throw;
    }
}

//void Interfaz::guardarMovimientos(string inCbu, float inMonto, bool tipo){
//    try{
//        const char *outputName = "BackupMovimientos.txt";
//        const char *auxFileName = "BackupMovimientos.temp";
//        ofstream fout(outputName, std::ios::app);
//        if (!fout.good()){
//            throw(runtime_error("No se pudo abrir el archivo.\n"));
//        }
//        fout << inCbu;
//
//        if(tipo == true){
//            fout << " + " << inMonto;
//        }
//        else{
//            fout << " - " << inMonto;
//        }
//        fout << "\n";
//
//        Si llego hasta acá y no hubo ningún problema borro el
//        original y renombro el temporal.
//        fout.close();
//        remove(outputName);
//        rename(auxFileName, outputName);
//    }
//    catch(runtime_error&){
//        throw;
//    }
//}


void Interfaz::levantarBanco(){
    try{
        stringstream data = backups[BANCO].readFile();
        data >> banco;
    }
    catch(...){
        throw;
    }
}

///guardarCliente cuando se crea
void Interfaz::levantarClientes(){
    try{
        stringstream data = backups[CLIENTES].readFile();

        unsigned int cant;
        data >> cant;
        for (unsigned int i = 0; i < cant; i++){
            Cliente *thisCliente = new Cliente();
            data >> *thisCliente;

            banco.addCliente(thisCliente);
        }
    }
    catch(...){
        throw;
    }
}

void Interfaz::levantarCuentas(){
    try{
        stringstream data = backups[CUENTAS].readFile();

        unsigned int cant;
        data >> cant;

        for (unsigned int i = 0; i < cant; i++){
            int tipo;
            CuentaBancaria *thisCuenta;

            data >> tipo;
            switch (tipo){
            case CAJADEAHORRO:
                thisCuenta = new CajaDeAhorro();
                break;
            case CUENTACORRIENTE:
                thisCuenta = new CuentaCorriente();
                break;
            case CUENTAUNIVERSITARIA:
                thisCuenta = new CuentaUniversitaria();
            }

            data >> *thisCuenta;

            banco.addCuenta(thisCuenta);
        }
    }
    catch(...){
        throw;
    }
}

//void Banco::levantarMovimientos(const char *inputName){
//    try{
//        ifstream fin(inputName);
//        if (!fin.good()){
//            throw(runtime_error("No se pudo abrir el archivo.\n"));
//        }
//        string auxCbu;
//        char auxChar;
//        float auxMonto;
//
//        fin >> auxCbu;
//        fin >> auxChar;
//        fin >> auxMonto;
//        if(auxChar == '+'){
//            getCuenta(auxCbu)->deposito(auxMonto); //Deposita en la cuenta.
//        }
//        else{
//            getCuenta(auxCbu)->extraccion(auxMonto); //Utilizo polimorfismo y va al metodo extraer dependiendo de el tipo de cuenta
//        }
//        fin.close();
//    }
//    catch(runtime_error&){
//        throw;
//    }
//}

void Interfaz::levantarDatos(){
    try{
        levantarBanco();
        levantarClientes();
        levantarCuentas();
    }
    catch(runtime_error&){
        throw;
    }
    catch(...){
        throw;
    }
}

//void Banco::destruirMovimientos(const char *inputName){
//    try{
//        ifstream fin(inputName);
//        if (!fin.good()){
//            throw(runtime_error("No se pudo abrir el archivo.\n"));
//        }
//        fin.close();
//        remove(inputName);
//    }
//    catch(runtime_error&){
//        throw;
//    }
//}
//
void Interfaz::guardarSistema(ostream& co){

    try{
        guardarBanco();
        guardarClientes();
        guardarCuentas();
    }
    catch(runtime_error&){
        throw;
    }
}
