#include "CCuentaCorriente.h"

/***
    Constructor
***/
CCuentaCorriente::CCuentaCorriente(int _numero, double _saldo, double _porcentajeDeInteres,
                                   double _cuotaMantenimiento, double _topeGire) :
//Llamo al constructor de la clase base para inicializarla con los valores correspondientes pasados por parametro
CCuenta(_numero, _saldo, _porcentajeDeInteres)
{
    //Inicializo los valores de la propia clase de CCuentaCorriente
    cuotaMantenimiento = _cuotaMantenimiento;
    topeGire = _topeGire;
}

/***
    Constructor virtual
***/
CCuentaCorriente* CCuentaCorriente::Nuevo()
{
    return new CCuentaCorriente; //Invoca al constructor de CCuentaCorriente
}

/***
    Constructor de copia virtual
***/
CCuentaCorriente* CCuentaCorriente::Clonar()
{
    return new CCuentaCorriente(*this);
}

/***
    Destructor
***/
CCuentaCorriente::~CCuentaCorriente()
{
    //dtor
}

/***
    Setters
***/
bool CCuentaCorriente::SetCuotaMantenimiento(double val)
{
    if(val >= 0)
    {
        cuotaMantenimiento = val;
        return true;
    }
    else
    {
        cerr << "Error: cantidad negativa" << endl;
        return false;
    }
}

bool CCuentaCorriente::SetTopeGire(double val)
{
    if(val >= 0)
    {
        topeGire = val;
        return true;
    }
    else
    {
        cerr << "Error: cantidad negativa" << endl;
        return false;
    }
}

/***
    Getters
***/
double CCuentaCorriente::GetCuotaMantenimiento()
{
     return cuotaMantenimiento;
}

double CCuentaCorriente::GetTopeGire()
{
    return topeGire;
}

/***
    Sobrecarga de operadores
***/
CCuentaCorriente& CCuentaCorriente::operator= (const CCuentaCorriente& c)
{
    numero = c.numero;
    saldo = c.saldo;
    cuotaMantenimiento = c.cuotaMantenimiento;
    topeGire = c.topeGire;

    return (*this);
}

ostream& operator<< (ostream& co, const CCuentaCorriente& c)
{
    c.print(co);

    return co;
}

/***
    Metodos de la propia clase CCuentaCorriente
***/
void CCuentaCorriente::Reintegro(double cantidad)
{
    //Tope de gire pactado para cada cliente.
    if(saldo + topeGire >= cantidad)
    {
        saldo -= cantidad;
    }
    else
    {
        cerr << "No puede girar mas dinero en descubierto. " << endl;
    }
}

double CCuentaCorriente::Comisiones()
{
    //Se aplican mensualmente por el mantenimiento de la cuenta
    Reintegro(cuotaMantenimiento);

    return cuotaMantenimiento; //Devuelvo el valor de la cuota de mantenimiento por si acaso.
}

double CCuentaCorriente::Intereses()
{
    //Acumular los intereses por mes sólo los días 1 de cada mes
    double interesProducido = 0.0;
    //Si tiene menos de $10000 en el banco no hay interes.
    if(GetSaldo() <= 10000)
    {
        interesProducido = 0.0;
    }
    else
    {
        interesProducido = ( GetSaldo() * GetTipoDeInteres() / 100 );
    }
    Ingreso(interesProducido);
    // Devolver el interés mensual por si fuera necesario
    return interesProducido;
}

void CCuentaCorriente::print(ostream& co) const
{
    co << "Numero de cuenta = " << numero << endl
       << "Saldo = " << "$" << saldo << endl
       << "Porcentaje de interes (Si su saldo es > 10000) = " << porcentajeDeInteres << "%" << endl
       << "Cuota de mantenimiento = " << "$" << cuotaMantenimiento << endl
       << "Tope de gire en descubierto de la cuenta = " << topeGire << endl;
}
