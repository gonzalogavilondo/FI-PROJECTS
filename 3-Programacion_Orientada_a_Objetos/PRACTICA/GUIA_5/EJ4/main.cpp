#include "ReciboDePago.h"
//Inicializo las variables estaticas.
int Factura::numFactura = 0;

int main() {
    ReciboDePago recibo;

    try {
        recibo.levantarDatos();
        //Menu.ejecutarMenu(recibo);
        recibo.guardarDatos();
    }
    catch (invalid_argument& e) { //Clase de excepcion más especifica (derivada de logic_error que a su vez, ésta es derivada de "excepcion")
        cout << "Se ha generado una excepcion: " << e.what() << endl;
    }
    catch(runtime_error& e) { //Clase de excepcion derivada de "excepcion"
        cout << "Se ha generado una excepcion: " << e.what() << endl;
    }
    catch(...) {
        cout << "Ocurrio un error inesperado." << endl;
    }

    return 0;
}
