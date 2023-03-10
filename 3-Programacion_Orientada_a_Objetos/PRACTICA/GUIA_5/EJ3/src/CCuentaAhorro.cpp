#include "CCuentaAhorro.h"

/***
    Constructor
***/
CCuentaAhorro::CCuentaAhorro(int _numero, double _saldo, double _porcentajeDeInteres,
                            double _importePorTrans, int _transExentas) :
//Inicializamos llamando al constructor de CCuenta sus parametros
CCuenta(_numero, _saldo, _porcentajeDeInteres)
{
    //Inicializamos los propios atributos de CCuentaAhorro
    transacciones = 0;
    importePorTrans = _importePorTrans;
    transExentas = _transExentas;
    cntExtracciones = 0;
}

/***
    Constructor virtual
***/
CCuentaAhorro* CCuentaAhorro::Nuevo()
{
    return new CCuentaAhorro; //Invoca al constructor de CCuentaAhorro
}

/***
    Constructor de copia virtual
***/
CCuentaAhorro* CCuentaAhorro::Clonar()
{
    return new CCuentaAhorro(*this);
}

/***
    Destructor
***/
CCuentaAhorro::~CCuentaAhorro()
{
    //dtor
}

/***
    Setters
***/
bool CCuentaAhorro::SetTransacciones(int val)
{
    if(val >= 0)
    {
        transacciones = val;
        return true;
    }
    else
    {
        cerr << "Error: cantidad negativa" << endl;
        return false;
    }
}

bool CCuentaAhorro::SetImportePorTrans(double val)
{
    if(val >= 0)
    {
        importePorTrans = val;
        return true;
    }
    else
    {
        cerr << "Error: cantidad negativa" << endl;
        return false;
    }
}

bool CCuentaAhorro::SetTransExentas(int val)
{
    if(val >= 0)
    {
        transExentas = val;
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
int CCuentaAhorro::GetTransacciones()
{
     return transacciones;
}

double CCuentaAhorro::GetImportePorTrans()
{
     return importePorTrans;
}

int CCuentaAhorro::GetTransExentas()
{
     return transExentas;
}

/***
    Sobrecarga de operadores
***/
CCuentaAhorro& CCuentaAhorro::operator=(const CCuentaAhorro& c)
{
    numero = c.numero;
    saldo = c.saldo;
    transacciones = c.transacciones;
    importePorTrans = c.importePorTrans;
    transExentas = c.transExentas;

    return (*this);
}

ostream& operator<< (ostream& co, const CCuentaAhorro& c)
{
    c.print(co);

    return co;
}

/***
    Metodos propios de la clase CCuentaAhorro
***/

void CCuentaAhorro::DecrementarTransacciones()
{
    transacciones--;
}

void CCuentaAhorro::Ingreso(double cantidad)
{
    CCuenta::Ingreso(cantidad);
    transacciones++;
}

void CCuentaAhorro::Reintegro(double cantidad)
{
    // Se aplican mensualmente por el mantenimiento de la cuenta
    CFecha hoy = CFecha(); //Llamo al constructor de fecha que inicializa los atributos con el dia de hoy.
    //CFecha hoy = CFecha(1, 2, 2021); //Esta linea es para probar que todo ande bien
    int dia = hoy.GetDay();

    if(dia == 1) cntExtracciones = 0; //Actualizo la cantidad de extracciones todos los dias "1" de cada mes.

    if(cntExtracciones <= MAXEXT)
    {
        if((saldo - cantidad) < 0)
        {
            cerr << "Error: no dispone de saldo. " << endl;
        }
        else
        {
            saldo -= cantidad;
            cntExtracciones++;
            transacciones++;
        }
    }
    else
    {
        cerr << "Error: Usted ha superado el limite de extracciones mensuales. " << endl;
    }
}

double CCuentaAhorro::Comisiones()
{
    // Se aplican mensualmente por el mantenimiento de la cuenta
    double comisiones = 0.0;
    int n = transacciones - transExentas;
    if (n > 0)
    {
        comisiones = (n * importePorTrans);
        Reintegro(comisiones);
        cntExtracciones--; //Este reintegro del banco no tiene que ser contado como una extraccion del cliente.
    }
    //Seteo en 0 las transacciones de nuevo porque ya las cobro el banco
    transacciones = 0;

    return comisiones; //Retorno la cantidad de la comision para que el cliente o el banco sepa.
}

double CCuentaAhorro::Intereses()
{

    // Acumular los intereses por mes sólo los días 1 de cada mes
    double interesProducido = 0.0;
    interesProducido = GetSaldo() * GetTipoDeInteres() / 100; //TipoDeInteres es el procentaje de interes de acuerdo al sueldo en ese momento
    Ingreso(interesProducido);

    //Este ingreso no debe incrementar las transacciones
    DecrementarTransacciones();

    return interesProducido;
}

void CCuentaAhorro::print(ostream& co) const
{
    co << "Numero de cuenta = " << numero << endl
       << "Saldo = " << "$" << saldo << endl
       << "Porcentaje de interes = " << porcentajeDeInteres << "%" << endl
       << "Cantidad de transacciones = " << transacciones << endl
       << "Importe por transaccion = " << importePorTrans << endl
       << "Cantidad de transacciones gratuitas = " << transExentas << endl
       << "Cantidad de extracciones realizadas en el mes = " << cntExtracciones << endl;

}
