#include "Vector.h"

int main()
{
    /// Declaro dos vectores con elementos de tipo double
    Vector<double> vec1(5),
                   vec2(10);

    /// Inicializo vec1
    vec1 = 0.0;

    /// Asigno valores a los elementos de vec1
    for (int i = 0; i < vec1.longitud(); i++)
    {
        vec1[i] = i + 1;
    }

    /// Imprimo por pantalla vec1.
    cout << vec1;

    /// Redimenciono el vec2 para poder igualarlo a vec1
    vec2.redimensionar(5);

    /// Igualo vec2 a vec1
    vec2 = vec1;

    /// Imprimo por pantalla vec2
    cout << vec2;

//        /// Creo otro vector a partir de vec2
//        Vector<int> vec3(vec2);
//
//        /// Imprimo vec3
//        cout << vec3;


    return 0;
}
