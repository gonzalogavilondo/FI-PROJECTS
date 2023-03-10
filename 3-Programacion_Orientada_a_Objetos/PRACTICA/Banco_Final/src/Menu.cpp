#include "Menu.h"

Menu::Menu(){
    //ctor
}

Menu::Menu(string inCartel, vector<string> opcionesStr){
    cartel = inCartel;
    for (unsigned i = 0; i < opcionesStr.size(); i++){
        opciones.insert(make_pair(i+1, opcionesStr[i]));
    }
}

Menu::~Menu(){
    //dtor
}

void Menu::imprimirMenu(ostream& co){
    co << cartel << endl << endl;
    map<unsigned, string>::iterator ForIter = opciones.begin();
    co << "Elija una opcion: " << endl << endl;

    while (ForIter != opciones.end()){
        co << ForIter->first << "- " << ForIter->second << endl;
        ForIter++;
    }

    co << endl;
}


/**
 *  Función que verifica si la opción ingresada es
 *  un número entero que cae en el rango.
 */
bool Menu::validarOpcion(unsigned limInf, unsigned limSup, unsigned op){
    bool opcionValida = true;
    if (op < limInf || op > limSup){
        opcionValida = false;
    }

    return opcionValida;
}

/**
 *  Función que se encarga de controlar el ingreso de una
 *  opción y retornarla.
 */
unsigned Menu::ingresarOpcion(unsigned limInf, unsigned limSup){
    string op;
    unsigned op_i = 0;
    bool exitFlag = false;

    while (!exitFlag){
        cout << "Ingrese una opcion: ";
        cin >> op;

        try{
            op_i = stoi(op);
            if (!validarOpcion(limInf, limSup, op_i)){
                throw("Opcion incorrecta.");
            } else {
                exitFlag = true;
            }
        }
        catch(std::invalid_argument&){
            cout << "Ingreso incorrecto. Por favor ingrese un numero." << endl;
        }
        catch(const char *mensaje){
            cout << mensaje << " Intente nuevamente. "
                 << "(Recuerde que debe estar entre "
                 << limInf << " y " << limSup << ")" << endl;
        }
        catch(...){
            throw;
        }

    }
    cout << endl;
    return op_i;
}

//void Menu::ejecutarMenu(void (*funciones[])(ostream&), unsigned limInf, unsigned limSup, ostream& co){
//
//
//    unsigned op = 0;
//    while(op != limSup){
//        system("cls || clean");
//        imprimirMenu();
//
//        op = ingresarOpcion(limInf, limSup);
//
//        system("cls || clean");
//
//        (*funciones[op - 1])(co);
//
//        system("pause");
//
//    }
//}

void Menu::setCartel(string inCartel){
    cartel = inCartel;
}

void Menu::addOpcionStr(string newOpcion){
    unsigned newKey = opciones.size() + 1;
    opciones.insert(make_pair(newKey, newOpcion));
}
