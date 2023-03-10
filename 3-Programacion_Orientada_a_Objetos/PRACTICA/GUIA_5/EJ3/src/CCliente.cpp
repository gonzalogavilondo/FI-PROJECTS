#include "CCliente.h"

/***
    Constructor
***/
CCliente::CCliente(string _nombre, string _dni, string _telefono)
{
    nombre = _nombre;
    dni = _dni;
    telefono = _telefono;
}

/***
    Destructor
***/
CCliente::~CCliente()
{
    //dtor
}

/***
    Setters
***/
bool CCliente::SetNombre(string val)
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

bool CCliente::SetDni(string val)
{
    if(val.length() != 0)
    {
        dni = val;
        return true;
    }
    else
    {
        cerr << "Error: cadena vacia" << endl;
        return false;
    }
}

bool CCliente::SetTelefono(string val)
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

/***
    Getters
***/
string CCliente::GetNombre()
{
    return nombre;
}

string CCliente::GetDni()
{
    return dni;
}

string CCliente::GetTelefono()
{
    return telefono;
}

vector <CCuenta*> CCliente::GetCuentas()
{
    return cuentas;
}

/***
    Sobrecarga de operadores
***/
ostream& operator<< (ostream& co, const CCliente& c)
{
    co << "Nombre = " << c.nombre << endl
       << "Dni = " << c.dni << endl
       << "Telefono = " << c.telefono << endl;
//       for(size_t i = 0; i < c.cuentas.size(); i++)
//       {
//           co << endl << "/****Cuenta " << i + 1 << "****/" << endl;
//           co << *c.cuentas[i];
//       }

    return co;
}

istream& operator>> (istream& ci, CCliente& c)
{
    ci.ignore();
    getline(ci, c.nombre);
    getline(ci, c.dni);
    getline(ci, c.telefono);

    return ci;
}


/***
    Metodos propios de la clase CCliente para manejar cuentas
***/
void CCliente::AnyadirCuenta(CCuenta* obj)
{
    //A�adir un objeto a la matriz

//    cuentas.push_back(new CCuenta(*obj));

    /***
    Analizando el c�digo anterior observamos que lo que se crea es un nuevo objeto de la clase CCuenta,
    cuando lo m�s seguro es que el objeto pasado como argumento sea de alguna de sus clases derivadas.
    Por lo tanto, lo que hay que hacer es invocar al constructor copia de su clase, informaci�n (la clase del objeto)
    que no podemos conocer a trav�s del puntero. Aunque, si utilizamos un m�todo virtual
    que simule al constructor copia de la clase base y de sus derivadas, el problema estar� resuelto.
    Este m�todo, que denominaremos "Clonar", lo declararemos virtual en la clase base CCuenta y lo redefiniremos
    en todas sus derivadas
    ***/

    //Despues de que a�adi todos los metodos de clonar en todas las clases, el metodo seria asi:
    cuentas.push_back(obj->Clonar()); //A�ade el objeto al final de cuentas.

    /***
    �ste es un caso evidente de lo �til que resulta el mecanismo definido como
    polimorfismo. Esto es, el m�todo clonar que se invoca para cada cuenta depende
    del tipo del objeto referenciado por obj
    ***/
}

bool CCliente::EliminarCuenta(int cuenta)
{
    //Buscar la cuenta y eliminar el objeto
    int i = BuscarCuenta(cuenta);
    if(i != -1) //Si es -1 significa que no encontro esa posicion y no se pudo eliminar. Pero si es distinto a -1, encontro la posicion.
    {
        delete cuentas[i]; //Elimina el puntero que va desde la clase base a la clase derivada.
        cuentas.erase(cuentas.begin() + i); //Elimina el elemento del vector "cuentas" en la posicion i, que es el puntero a CCuenta de esa posicion.
        return true;
    }
    return false;
}

int CCliente::BuscarCuenta(int num, int pos) const
{
    //Buscar un objeto y devolver su posici�n
    int _numero;

    //Validacion num y pos
    if(num < 0)
    {
        return -1;
    }
    if(pos < 0)
    {
        pos = 0;
    }
    for(size_t i = pos; i < cuentas.size(); i++)
    {
        //Buscar por la cuenta
        _numero = cuentas[i]->GetNumero();
        if(_numero < 0)
        {
            continue;
        }
        //�num es el numero de la cuenta?
        if (num == _numero)
        {
            return i;
        }
    }
    return -1;
}

size_t CCliente::LongitudCuenta() const
{
    return cuentas.size();
}
