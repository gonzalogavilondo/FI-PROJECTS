#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Interfaz.h"

using namespace std;

///VER HORA DEL ARCHIVO PARA LEVANTAR
int main()
{
    try{
        Interfaz i;
        i.inicializarSistema();
    }
    catch(runtime_error& e){
        cout << e.what() << endl;
    }
    catch(bad_alloc& e){
        cout << e.what() << endl;
    }
    catch(...){
        cout << "Ocurrio un error inesperado." << endl;
    }

    return 0;
}
