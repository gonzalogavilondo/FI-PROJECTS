#include "CBanco.h"
#include "CFecha.h"
#include "Menu.h"

int CBanco::cntClientes = 0;
int CBanco::cntCuentas = 0;

enum tipoCuenta
{
    CCUENTAAHORRO, CCUENTACORRIENTE

};

/*********** test 01 ***********/
int main()
{
    CBanco banco("Santander Rio", "4106700", "Belgrano 3182");
    vector <int> idCliente(20,0); //Identificador de cada cliente.

    //Levantamos los clientes de un archivo txt.
    banco.LevantarClientes(idCliente);

    //Creamos las cuentas de cada cliente, pasando el nombre del titular y nos devuelve su numero de cuenta
    int numeroCuentaA = banco.CrearCuenta(CCUENTAAHORRO);
    int numeroCuentaCC = banco.CrearCuenta(CCUENTACORRIENTE);
    int numeroCuentaC = banco.CrearCuenta(CCUENTACORRIENTE);

    //Vinculamos cada cuenta con su cliente respectivo (linkeamos)
    banco.AsignarCuenta(idCliente[0], numeroCuentaA);
    banco.AsignarCuenta(idCliente[0], numeroCuentaCC);
    banco.AsignarCuenta(idCliente[1], numeroCuentaC);

    //Operaciones posibles en cada cuenta
    banco.Operaciones(idCliente[0], numeroCuentaA);
    banco.Operaciones(idCliente[0], numeroCuentaCC);
    banco.Operaciones(idCliente[1], numeroCuentaC);

    //Activo disponible del banco
    banco.ActivoDisponible();

    //Actualizo la cantidad de clientes para la proxima vez.
    banco.ActualizarCntClientes();

    Menu(&banco);

    return 0;
}

