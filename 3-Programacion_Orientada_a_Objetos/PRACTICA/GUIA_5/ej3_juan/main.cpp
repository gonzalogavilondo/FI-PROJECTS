#include <iostream>
#include <fstream>
#include "Banco.h"
#include "Menu.h"
using namespace std;

int main()
{
    Banco banco("Santander Rio", 4942468, "Independencia 2222");
    vector <int> idCliente(20,0); //Identificador de cada cliente.

//    banco.levantarClientes(idCliente); // NO LE GUSTA QUE LE PASE IDCLIENTE POR PARAMETRO, POR ESO SE ROMPE.
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
            idCliente[i] = banco.crearCliente(aux);
        }
        fin.close();
    }
    catch (runtime_error& e)
    {
        cout << "Atajada excepcion: " << e.what() << endl;
    }

    banco.asignarCuenta(idCliente[0], CAJADEAHORRO);
    banco.asignarCuenta(idCliente[0], CUENTACORRIENTE);
    banco.asignarCuenta(idCliente[0], CUENTAUNIVERSITARIA);
    banco.asignarCuenta(idCliente[1], CUENTACORRIENTE);
    banco.asignarCuenta(idCliente[1], CAJADEAHORRO);
    banco.asignarCuenta(idCliente[2], CUENTAUNIVERSITARIA);

    imprimirMenu(banco);
    ejecutarMenu(banco);
//
//    ifstream fin("ejemploCliente.txt", ios::in);
//    Cliente c1;
//    fin >> c1;
//    Banco banco("Santander Rio", 4942468, "Independencia 2222");
//
//    int idCliente = banco.crearCliente(c1);
//    string CBU_CA = banco.asignarCuenta(idCliente, CAJADEAHORRO);
//
//    bool exitoDepo = banco.depositar(CBU_CA, 100);
//    bool exitoExtr = banco.extraer(CBU_CA, 5000);
//
//    float consSaldo = banco.consultarSaldo(CBU_CA);
//    banco.mostrarClienteYCuentas(idCliente);
    return 0;
}
