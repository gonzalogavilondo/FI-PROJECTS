#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <typename> class Vector; //declaracion previa para el proximo template
template <class T> ostream& operator<< (ostream&, Vector<T>&);

template <typename T> class Vector //Declaracion
{
    private:
        T* vec; // puntero al primer elemento
        size_t nElementos; // numero de elementos
        T* asignarMemoria(int);
        void liberarMemoria();

    public:
        /// Constructores
        Vector(int ne = 10); //crea un Vector con ne elementos

        /// Constructores de copia
        Vector(const Vector<T>&); //Crea un Vector desde otro

        /// Destructor
        ~Vector(); // destructor

        /// Sobrecarga de operadores
        friend ostream& operator << <> (ostream&, Vector<T>&);
        Vector& operator= (const Vector&); // copia de un Vector en otro
        T operator= (T); //iniciar un vector
        T& operator[] (size_t) const;

        /// Otras funciones
        int longitud() const;
        void redimensionar(int);
        void copiarVector(const Vector<T>&);

        /***
        Este codigo define la plantilla Vector, a través de la cual el
        compilador podrá generar una colección de clases Vector<T>.
        Por ejemplo, la clase Vector<double>, Vector<complex<double>>, etc.
        ***/

};

#include "Vector.h_c.txt"

#endif // VECTOR_H_INCLUDED
