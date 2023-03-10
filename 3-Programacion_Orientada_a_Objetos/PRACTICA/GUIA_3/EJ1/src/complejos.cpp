// fichero complejos.cpp
// funciones y operadores de la clase complejo

#include "complejos.h"

// Constructor general
complejo::complejo(double r, double i)
{
    real = r;
    imag = i;
}

// Setters
void complejo::SetData(void)
{
    cout << "Introduzca el valor real del complejo: ";
    cin >> real;
    cout << "Introduzca el valor imaginario del complejo: ";
    cin >> imag;
}

void complejo::SetReal(double r)
{
    real = r;
}

void complejo::SetImag(double i)
{
    imag = i;
}

// Getters
double complejo::GetReal(void)
{
    return real;
}

double complejo::GetImag(void)
{
    return imag;
}

// Sobrecarga del operador de extraccion y de insercion
ostream& operator<< (ostream& co, const complejo &cmp)
{
    ios_base::fmtflags fl;

    co << cmp.real;
    fl = co.setf(ios::showpos);
    co << cmp.imag << "i";
    co.flags(fl);

    return co;
}

istream& operator>> (istream& ci, complejo& cmp)
{
    cout << "Parte real: ";
    ci >> cmp.real;
    cout << "Parte imaginaria: ";
    ci >> cmp.imag;

    return ci;
}

// Operadores miembro sobrecargados
complejo complejo::operator+ (const complejo &cmp)
{
    complejo suma;

    suma.real = real + cmp.real;
    suma.imag = imag + cmp.imag;

    return suma;
}

complejo complejo::operator- (const complejo &cmp)
{
    complejo resta;

    resta.real = real - cmp.real;
    resta.imag = imag - cmp.imag;

    return resta;
}

complejo complejo::operator* (const complejo &cmp)
{
    complejo producto;

    producto.real = real*cmp.real - imag*cmp.imag;
    producto.imag = real*cmp.imag + imag*cmp.real;

    return producto;
}

complejo complejo::operator/ (const complejo &cmp)
{
    complejo cociente;
    double deno;

    deno = cmp.real*cmp.real + cmp.imag*cmp.imag;
    cociente.real = (real*cmp.real + imag*cmp.imag) / deno;
    cociente.imag = (-real*cmp.imag + imag*cmp.real) / deno;

    return cociente;
}

complejo complejo::operator- () const //El const es porque yo no quiero que el objeto con el que estoy llamando se modifique.
{                                     //(cambie de signo en este caso) Sino que yo quiero que me devuelva
    complejo aux;                     //el objeto cambiado de signo pero que no se modifique en si el objeto "original".

    aux.real = (-1)*real;
    aux.imag = (-1)*imag;

    return aux;
}

complejo& complejo::operator+= (const complejo &cmp)
{
    real+= cmp.real;
    imag+= cmp.imag;

    return (*this);
}

complejo& complejo::operator-= (const complejo &cmp)
{
    real-= cmp.real;
    imag-= cmp.imag;

    return (*this);
}

complejo& complejo::operator++()
{
    real++;
    imag++;

    return (*this);
}

complejo complejo::operator++ (int dummy)          // post-incremento
{
    complejo aux(*this);

    ++(*this);

    return (aux);
}

complejo& complejo::operator-- ()
{
    real--;
    imag--;

    return (*this);
}

complejo complejo::operator-- (int dummy)
{
    complejo aux(*this);

    --(*this);

    return (aux);
}

complejo complejo::operator+ (double num)
{
    complejo suma(*this);

    suma.real = this->real + num;
    suma.imag = this->imag;

    return suma;
}

complejo operator+ (double num, const complejo &cmp)
{
    complejo suma(cmp);

    suma.real = cmp.real + num;
    suma.imag = cmp.imag;

    return suma;
}

// Sobrecarga del operador de asignación
complejo& complejo::operator= (const complejo &cmp)
{
    real = cmp.real;
    imag = cmp.imag;

    return (*this);
}

// Sobrecarga de operadores de comparación
bool complejo::operator== (const complejo& cmp)
{
    if ( (real == cmp.real) && (imag == cmp.imag) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator!= (const complejo& cmp1, const complejo& cmp2)
{
    if ( (cmp1.real != cmp2.real) && (cmp1.imag != cmp2.imag) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
