#include "Abtree.h"

int main()
{
    // Cambiar el nro para ejecutar la prueba.
    int nro = 3;

    void (*prueba[])() =
    {
      pruebaArbolBinario, // nro=0
      pruebaArbolBinarioDeBusqueda,// nro=1
      pruebaEliminaEnABB, // nro=2
      pruebaAVL // nro=3
    };

    (*prueba[nro])();

}
