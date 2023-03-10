#include "CBanco.h"
#include "Menu.h"
#include "CCuentaCorriente.h"
#include "CCuentaAhorro.h"

/***
    Constructor
***/
CBanco::CBanco(string _nombre, string _telefono, string _direccion, double _activoDisponible)
{
    // Reservar espacio para 100 elementos (elementos iniciales cero)
    clientes.reserve(100);
    nombre = _nombre;
    telefono = _telefono;
    direccion = _direccion;
    activoDisponible = _activoDisponible;
}
/***
    Destructor
***/
CBanco::~CBanco()
{
    //Eliminar los objetos CCuenta o de sus derivadas
    for(size_t i = 0; i < LongitudCuenta(); i++)
    {
        delete cuentas[i];
    }
}

/***
    Setters
***/
void CBanco::SetActivoDisponible(double val)
{
    activoDisponible = val;
}

bool CBanco::SetNombre(string val)
{
    if(val.length() != 0)
    {
        nombre = val;
        return true;
    }
    else
    {
        cerr << "Error: cadena vacia" << endl;
        return false;
    }
}

bool CBanco::SetTelefono(string val)
{
    if(val.length() != 0)
    {
        telefono = val;
        return true;
    }
    else
    {
        cerr << "Error: cadena vacia" << endl;
        return false;
    }
}

bool CBanco::SetDireccion(string val)
{
    if(val.length() != 0)
    {
        direccion = val;
        return true;
    }
    else
    {
        cerr << "Error: cadena vacia" << endl;
        return false;
    }
}

/***
    Getters
***/
double CBanco::GetActivoDisponible()
{
    return activoDisponible;
}

string CBanco::GetNombre()
{
    return nombre;
}

string CBanco::GetTelefono()
{
    return telefono;
}

string CBanco::GetDireccion()
{
    return direccion;
}

/***
    Sobrecarga de operadores
***/
CCuenta* CBanco::operator[] (size_t i) const
{
    //Devolver la referencia al objeto i de la matriz
    if(i >= 0 && i < LongitudCuenta())
    {
        return cuentas[i];
    }
    else
    {
        cerr << "error: índice fuera de límites" << endl;
        return 0;
    }
}

ostream& operator<< (ostream& co, const CBanco& c)
{
    for(size_t i = 0; i < c.clientes.size(); i++)
    {
        co << c.clientes[i];
        cout << endl;
    }
    co << "Activo disponible = " << "$" << c.activoDisponible << endl;

    return co;
}

/***
    Metodos de la propia clase CBanco
***/

///CLIENTE

void CBanco::LevantarClientes(vector <int> idCliente)
{
    try
    {
        ifstream fin("EjemploCliente.txt", ios::in); //Abrimos el archivo en modo lectura.
        if(!fin.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }
        int cntClientesInTxt = 0;
        fin >> cntClientesInTxt;
        for(int i = 0; i < cntClientesInTxt; i++)
        {
            CCliente aux;
            fin >> aux;
            idCliente[i] = this->CrearCliente(aux.GetNombre(), aux.GetDni(), aux.GetTelefono());
        }
        fin.close();
    }
    catch (runtime_error& e)
    {
        cout << "Atajada excepcion: " << e.what() << endl;
    }
}

int CBanco::CrearCliente(string _nombre, string _dni, string _telefono)
{
    clientes.push_back(CCliente(_nombre, _dni, _telefono));

    cntClientes++;

    return (cntClientes - 1);
}


///CUENTAS
int CBanco::CrearCuenta(int tipoDeCuenta)
{
    try
    {
        if(tipoDeCuenta == 0) //CCUENTAAHORRO
        {
            CCuentaAhorro* aux = new CCuentaAhorro(cntCuentas, 0.0, 35, 100); //cntCuentas es el numero de la cuenta.
            if(!aux)
            {
                throw(bad_alloc());
            }
            AnyadirCuenta(aux);
        }
        else if(tipoDeCuenta == 1) //CCUENTACORRIENTE
        {
            CCuentaCorriente* aux = new CCuentaCorriente(cntCuentas, 0.0, 25, 1000);
            if(!aux)
            {
                throw(bad_alloc());
            }
            AnyadirCuenta(aux);
        }
    }
    catch (bad_alloc& e)
    {
        cout << "Atajada excepcion: " << e.what() << endl;
    }

    cntCuentas++; //cntCuentas seria el numero de cuenta, que funciona como contador
    return (cntCuentas - 1); //Devuelvo el numero de la cuenta seteada actualmente.
}

void CBanco::AnyadirCuenta(CCuenta* obj)
{
    //Añadir un objeto a la matriz

//    cuentas.push_back(new CCuenta(*obj));

    /***
    Analizando el código anterior observamos que lo que se crea es un nuevo objeto de la clase CCuenta,
    cuando lo más seguro es que el objeto pasado como argumento sea de alguna de sus clases derivadas.
    Por lo tanto, lo que hay que hacer es invocar al constructor copia de su clase, información (la clase del objeto)
    que no podemos conocer a través del puntero. Aunque, si utilizamos un método virtual
    que simule al constructor copia de la clase base y de sus derivadas, el problema estará resuelto.
    Este método, que denominaremos "Clonar", lo declararemos virtual en la clase base CCuenta y lo redefiniremos
    en todas sus derivadas
    ***/

    //Despues de que añadi todos los metodos de clonar en todas las clases, el metodo seria asi:
    cuentas.push_back(obj->Clonar()); //Añade el objeto al final de cuentas.

    /***
    Éste es un caso evidente de lo útil que resulta el mecanismo definido como
    polimorfismo. Esto es, el método clonar que se invoca para cada cuenta depende
    del tipo del objeto referenciado por obj
    ***/
}

void CBanco::AsignarCuenta(int idCliente, int numeroCuenta)
{
    //Buscamos la posicion de la cuenta con ese numeroCuenta DENTRO DEL BANCO.
    int pos = BuscarCuenta(numeroCuenta);

    //Añadimos a la cuenta del cliente, la cuenta que contiene el numeroCuenta pasado por parametro.
    clientes[idCliente].AnyadirCuenta(cuentas[pos]);

}

bool CBanco::EliminarCuenta(int numero)
{
    //Buscar la cuenta y eliminar el objeto
    int i = BuscarCuenta(numero);
    if(i != -1) //Si es -1 significa que no encontro esa posicion y no se pudo eliminar. Pero si es distinto a -1, encontro la posicion.
    {
        delete cuentas[i]; //Elimina el puntero que va desde la clase base a la clase derivada.
        cuentas.erase(cuentas.begin() + i); //Elimina el elemento del vector "cuentas" en la posicion i, que es el puntero a CCuenta de esa posicion.
        return true;
    }
    return false;
}

int CBanco::BuscarCuenta(int num, int pos) const
{
    //Buscar un objeto y devolver su posición
    int _numero = -1;

    //Validacion num y pos
    if(num < 0)
    {
        return -1;
    }
    if(pos < 0)
    {
        pos = 0;
    }
    for(size_t i = pos; i < LongitudCuenta(); i++)
    {
        _numero = cuentas[i]->GetNumero();
        if(_numero < 0)
        {
            continue;
        }
        //¿num es el numero de la cuenta?
        if (num == _numero)
        {
            return i;
        }
    }
    return -1;
}

size_t CBanco::LongitudCuenta() const
{
    return cuentas.size();
}

bool CBanco::Ingreso(int idCliente, int numeroCuenta, double cantidad)
{
    if(cantidad > 0)
    {
        int pos = clientes[idCliente].BuscarCuenta(numeroCuenta);
        clientes[idCliente].GetCuentas()[pos]->Ingreso(cantidad);
        return true;
    }
    else
    {
        cerr << "Cantidad ingresada erronea." << endl;
        return false;
    }

}

bool CBanco::Reingreso(int idCliente, int numeroCuenta, double cantidad)
{
    if(cantidad > 0)
    {
        int pos = clientes[idCliente].BuscarCuenta(numeroCuenta);
        clientes[idCliente].GetCuentas()[pos]->Reintegro(cantidad);
        return true;
    }
    else
    {
        cerr << "Cantidad ingresada erronea." << endl;
        return false;
    }

}

double CBanco::ConsultarSaldo(int idCliente, int numeroCuenta)
{
    int pos = clientes[idCliente].BuscarCuenta(numeroCuenta);

    return clientes[idCliente].GetCuentas()[pos]->GetSaldo();
}

void CBanco::ActivoDisponible()
{
    for(size_t i = 0; i < clientes.size(); i++) //Cantidad de clientes
    {
        for(size_t j = 0; j < clientes[i].LongitudCuenta(); j++) //Cantidad de cuentas por cada cliente
        {
            activoDisponible += clientes[i].GetCuentas()[j]->GetSaldo();
            //activoDisponible es un acumulador de lo que hay en cada saldo de cada cuenta
        }
    }
}

double CBanco::CobrarComisiones(int idCliente, int numeroCuenta)
{
    //CFecha hoy = CFecha();
    CFecha hoy = CFecha(1, 10, 2021);
    if(hoy.GetDay() == 1)
    {
        int pos = clientes[idCliente].BuscarCuenta(numeroCuenta);
        return ( clientes[idCliente].GetCuentas()[pos]->Comisiones() ); // Devuelve la cantidad de las comisiones cobradas.
    }
    else
    {
        return 0.0; //No es dia de cobrar las comisiones.
    }

}

double CBanco::PagarIntereses(int idCliente, int numeroCuenta)
{
    //CFecha hoy = CFecha();
    CFecha hoy = CFecha(1, 10, 2021); //Test
    if(hoy.GetDay() == 1)
    {
        int pos = clientes[idCliente].BuscarCuenta(numeroCuenta);
        return ( clientes[idCliente].GetCuentas()[pos]->Intereses() );
    }
    else
    {
        return 0.0; //No es dia de cobrar las comisiones.
    }
    /***
        Nota: La CCUENTAAHORRO tiene 35% de interes del saldo actual, mientras que CCUENTACORRIENTE
        tiene el 25% del saldo actual.
    ***/

}

void CBanco::Operaciones(int idCliente, int numeroCuenta)
{
    //Algunos metodos como ingreso, reingreso y consultar saldo que debe saber hacer el banco y en algunos metodos
    //devuelve si la operacion fue exitosa o no.

    system("cls");
    cout << "CLIENTE " << idCliente << endl;
    cout << "NUMERO DE CUENTA: " << numeroCuenta << endl;
    system("pause");
    const char* opciones[] = {"Ingresar dinero", "Retirar dinero", "Consultar saldo", "Salir"};
    const int num_opciones = sizeof(opciones) / sizeof(char*);
    int opcion = 0;
    do
    {
        opcion = CrearMenu(opciones, num_opciones);
        switch(opcion)
        {
            case 1:
            {
                int cntDinero = 0;
                cout << "Ingrese la cantidad de dinero: ";
                cin >> cntDinero;
                bool exitoIngreso = this->Ingreso(idCliente, numeroCuenta, cntDinero);
                if(!exitoIngreso)
                {
                    cout << "No se ha podido ingresar $" << cntDinero << " a la cuenta." << endl;
                }
                system("pause");
            }
                break;
            case 2:
            {
                int cntDinero = 0;
                cout << "Ingrese la cantidad de dinero: " << endl;
                cin >> cntDinero;
                bool exitoReingreso = this->Reingreso(idCliente, numeroCuenta, cntDinero);
                if(!exitoReingreso)
                {
                    cout << "No se ha podido retirar $" << cntDinero << " de la cuenta." << endl;
                }
                system("pause");
            }
                break;
            case 3:
            {
                double consultarSaldo = this->ConsultarSaldo(idCliente, numeroCuenta);
                cout << "Saldo = " << "$" << consultarSaldo << endl;
                system("pause");
            }
                break;
            case num_opciones: // salir
            break;
        }
    }while(opcion != num_opciones);

    //Estos metodos se van a ejecutar si es dia 1 de algun mes.
    double interesesBanco = this->PagarIntereses(idCliente, numeroCuenta);
    cout << "Intereses = " << interesesBanco << endl;

    double comisionBanco = this->CobrarComisiones(idCliente, numeroCuenta);
    cout << "Comisiones = " << comisionBanco << endl;

}

void CBanco::ActualizarCntClientes() //Aca tengo que modificar la cantidad de clientes para la proxima apertura.
{
    try
    {
        ofstream fout("EjemploCliente.txt", ios::out); //Abrimos el archivo en modo escritura.
        if(!fout.good())
        {
            throw(std::runtime_error("No se pudo abrir el archivo.\n"));
        }
        fout.close();
    }
    catch (runtime_error& e)
    {
        cout << "Atajada excepcion: " << e.what() << endl;
    }
}

void CBanco::VisualizarCuentas(CBanco& banco, string tipoCuenta)
{
    try
    {
        string str = tipoCuenta + ".txt"; //Dependiendo el tipo de cuenta, abro un archivo u otro
        ofstream fout(str, ios::out); //Abrimos el archivo en modo escritura.
        if(!fout.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }

        fout << tipoCuenta << ":" << endl << endl;
        for (size_t i = 0; i < banco.clientes.size(); ++i)
        {
            for(size_t j = 0; j < banco.clientes[i].LongitudCuenta(); j++)
            {
                if ( (tipoCuenta == "Todas" ) || (TipoCuenta(banco.clientes[i].GetCuentas()[j]) == tipoCuenta) )
                {
                    fout << banco.clientes[i] << endl; //Imprimo el cliente
                    fout << *(banco.clientes[i].GetCuentas()[j]) << endl; //Imprimo las cuentas del cliente
                }
            }
        }
        fout.close();
    }
    catch (runtime_error& e)
    {
        cout << "Atajada excepcion: " << e.what() << endl;
    }

    /***
    La función VisualizarCuentas tiene dos parámetros: el objeto CBanco del
    cual queremos mostrar sus cuentas y el tipo de cuentas que se desean mostrar; este
    segundo parámetro, tipoCuenta, tendrá como valor un string: “” (todas las cuentas), “CCuentaAhorro” y “CCuentaCorriente”.
    Después, una simple iteración sobre los elementos banco[i] del objeto CBanco permitirá mostrar los datos requeridos de
    las cuentas del tipo especificado
    ***/
}

string CBanco::TipoCuenta(CCuenta* cuenta)
{
    string tipo = "";
    if (dynamic_cast<CCuentaAhorro*>(cuenta))
    {
        tipo = "CCuentaAhorro";
    }
    else if (dynamic_cast<CCuentaCorriente*>(cuenta))
    {
        tipo = "CCuentaCorriente";
    }
    return tipo;
    /***
    Este método utiliza el operador dynamic_cast para obtener durante la ejecución el tipo del objeto referenciado
    por el puntero cuenta.
    Se interpreta como la pregunta ¿Es el objeto apuntado por cuenta de tipo CCuentaAhorro o de un tipo
    derivado de CCuentaAhorro? En el primer caso.
    ***/
}
