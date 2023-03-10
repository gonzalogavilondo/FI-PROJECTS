#include "declaraciones.h"

int main()
{
    // Cambiar el nro para ejecutar la prueba.
    int nro = 4;

    void (*prueba[])() = {
        test_ejercicio0,  // nro=0
        test_ejercicio1,  // nro=1
        test_ejercicio2,  // nro=2
        test_ejercicio3,  // nro=3
        test_ejercicio4   // nro=4
    };

    (*prueba[nro])();
}
