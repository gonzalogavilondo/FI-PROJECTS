#include "Menu.h"
#include "conio.h"

/**
 * Completa un string.
 * Funcion auxiliar utilizada en validarOpcion.
 */
void _completarOpcion(char **str){
    int i = 0;
    char c = '0';
    while (c != '\r'){
        fflush(stdin);
        c = getch();
        if (c == '\b'){
            if (i > 0){
                i--;
                printf("\b \b");
            }
        } else {
            printf("%c", c);
            *str = (char *)realloc(*str, sizeof(char)*(i + 1));
            (*str)[i] = c;
            i++;
        }
    }

    printf("\n");
}

/**
 * Devuelve una opcion valida en el rango [limInf, limSup].
 * Nota: Está diseñada para evitar errores si el usuario ingresa una opción
 *       que no es entera. Lo único que hay que tener en cuenta a la hora
 *       de usarla es que los límites deben ser números positivos mayores a 0,
 *       ya que atoi() si tiene una palabra que no puede convertir devuelve 0.
 */
int validarOpcion (int limInf, int limSup){
    char *op = NULL;
    int opInt = 0;

    printf("Ingrese una opcion: ");
    _completarOpcion(&op);
    while (atoi(op) < limInf || atoi(op) > limSup)
    {
        printf("Opcion incorrecta. Intente nuevamente: ");
        _completarOpcion(&op);
    }
    printf("\n");
    opInt = atoi(op);
    free(op);
    return opInt;
}

void buscarYMostrarCliente(Banco& banco){
    int inDNI;
    cout << "Ingrese el DNI: ";
    cin >> inDNI;
    cout << endl;
    int pos = banco.buscarClienteDNI(inDNI);
    int id = banco.getCliente(pos).getIdCliente();
    if (pos >= 0){
        banco.mostrarClienteYCuentas(id);
    }
}

void buscarYMostrarCuenta(Banco& banco){
    string inCBU;
    cout << "Ingrese el CBU: ";
    cin >> inCBU;
    cout << endl;
    int pos = banco.buscarCuenta(inCBU);
    if (pos >= 0){
        banco.mostrarCuentaYTitulares(inCBU);
    }

    return ;
}

void operacionesConCuenta(Banco& banco){
    cout << "OPERACIONES" << endl << endl;

    int inDNI;
    cout << "Ingrese el DNI del titular: ";
    cin >> inDNI;
    cout << endl;
    int indexCliente = banco.buscarClienteDNI(inDNI);

    int cantCuentas = banco.getSizeCuentasCliente(indexCliente);

    cout << "El cliente tiene las siguientes cuentas, elija una:  " << endl << endl;
    for (int i = 0; i < cantCuentas; i++){
        cout << "CUENTA " << i + 1 << endl;
        cout << *(banco.getCuentasCliente(indexCliente)[i]) << endl;
    }

    int op = validarOpcion(1, cantCuentas);

    string thisCBU = banco.getCuentasCliente(indexCliente)[op-1]->getCBU();




    int salir = 1;

    do{
        system("cls || clear");
        cout << "CUENTA SELECCIONADA" << endl;
        cout << *(banco.getCuentasCliente(indexCliente)[op-1]) << endl;
        cout << endl << "Elija una opcion" << endl
             << "1) Depositar dinero" << endl
             << "2) Extraer dinero" << endl
             << "3) Consultar saldo" << endl << endl;

        int op2 = validarOpcion(1, 3);
        switch (op2){
        case 1:
            cout << "Deposito" << endl << endl;
            if (!(banco.depositar(thisCBU))){
                cout << "No se ha podido depositar." << endl;
            }
            break;
        case 2:
            cout << "Extraccion" << endl << endl;
            if (!(banco.extraer(thisCBU))){
                cout << "No se ha podido extraer." << endl;
            }
            break;
        case 3:
            cout << "Saldo: " << banco.consultarSaldo(thisCBU) << endl << endl;
        }
        cout << endl;
        cout << "Si desea realizar alguna otra operacion con esta"
             << "cuenta, presione 0. Sino presione cualquier tecla." << endl;

        cin >> salir;
    } while (salir != 0);


}

void guardar(Banco& banco){
    ofstream foutClientes("Clientes.txt", ios::trunc),
             foutCuentas("Cuentas.txt", ios::trunc);
    banco.printClientes(foutClientes);
    banco.printCuentas(foutCuentas);
}

void imprimirMenu(Banco& b){
    cout << "///////////////////////////////////////////" << endl;
    cout << "////                                   ////" << endl;
    cout << "//// " << "Bienvenido al Banco " << b.getNombre() << " ////" << endl;
    cout << "////                                   ////" << endl;
    cout << "///////////////////////////////////////////" << endl << endl << endl;

    cout << "Elija una opcion: " << endl;
    cout << "1) Ver los activos disponibles del Banco." << endl;
    cout << "2) Ver todos los clientes del banco." << endl;
    cout << "3) Cargar un cliente nuevo." << endl;
    cout << "4) Buscar un cliente." << endl;
    cout << "5) Buscar una cuenta." << endl;
    cout << "6) Elegir una cuenta para realizar operaciones." << endl;
    cout << "7) Guardar todo y salir." << endl << endl;
}

void ejecutarMenu(Banco& b){
    int op = 0;
    while(op != 7){
        system("cls || clean");
        imprimirMenu(b);
        op = validarOpcion(1, 7);

        system("cls || clean");
        switch(op){
            case 1:
                cout << "ACTIVO DISPONIBLE: "
                     << b.activoDisponible() << endl << endl;
                break;
            case 2:
                cout << "CLIENTES" << endl << endl;
                b.printClientes(cout);
                break;
            case 3:
                cout << "CARGAR UN CLIENTE NUEVO" << endl << endl;
                b.cargarCliente();
                break;
            case 4:
                cout << "BUSCAR UN CLIENTE" << endl << endl;
                buscarYMostrarCliente(b);
                break;
            case 5:
                cout << "BUSCAR UNA CUENTA" << endl << endl;
                buscarYMostrarCuenta(b);
                break;
            case 6:
                operacionesConCuenta(b);
                break;
            case 7:
                guardar(b);
                printf("Programa finalizado.\n");
        }
        system("pause");

    }
}
