//
// Created by Gonza on 22/11/2021.
//

#include "ReciboDePago.h"

/**
 * Constructor
 */
ReciboDePago::ReciboDePago() {
    //ctor
}

/**
* Setters
*/
void ReciboDePago::setRecibo(map<string, Contribuyente *> val) {
    recibo = val;
}

/**
* Getters
*/
map<string, Contribuyente*> ReciboDePago::getRecibo() {
    return recibo;
}

vector <string> ReciboDePago::getIds() {
    vector<string> ids;
    map<string, Contribuyente*>::iterator ForIter = recibo.begin();

    while (ForIter != recibo.end()) {
        ids.push_back(ForIter->first);
        ForIter++;
    }
    return ids;
}

Contribuyente* ReciboDePago::getContribuyente(string idContribuyente) {
    map<string, Contribuyente*>::iterator Iter = recibo.find(idContribuyente);
    if (Iter == recibo.end()) return nullptr;

    return Iter->second;
}

/**
* Sobrecarga de operadores
*/



/**
* Metodos propios de la clase ReciboDePago
*/

void ReciboDePago::levantarContribuyentes(const char * inputName) {
    try{
        ifstream fin(inputName);
        if (!fin.good()) {
            throw(runtime_error("No se pudo leer el archivo.\n"));
        }

        unsigned int cnt;
        fin >> cnt;
        for (unsigned int i = 0; i < cnt; i++) {
            int tipo;
            Contribuyente *thisContribuyente;

            fin >> tipo;
            switch (tipo) {
                case LIMITADO:
                    thisContribuyente = new Limitado();
                    break;
                case COMPLETO:
                    thisContribuyente = new Completo();
                    break;
                case EXTENDIDO:
                    thisContribuyente = new Extendido();
            }

            fin >> *thisContribuyente;
            string id = thisContribuyente->getId();
            if(recibo.insert(make_pair(id, thisContribuyente)).second == 0) {
                throw invalid_argument("No se pudo realizar la insercion.\n"); //Esta excepcion es por si se ingresó una clave repetida.
            }
        }
        fin.close();
    }
    catch(runtime_error&) {
        throw;
    }
}

void ReciboDePago::levantarDatos() {
    try{
        levantarContribuyentes("BackupContribuyentes.txt");
    }
    catch(runtime_error&){
        throw;
    }
}

void ReciboDePago::guardarContribuyentes(const char * outputName) {
    try {
        const char *auxFileName = "Recibos.temp";
        ofstream fout(auxFileName);
        if (!fout.good()) {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }
        typename map<string, Contribuyente *>::iterator ForIter;
        ForIter = recibo.begin();

        //fout << recibo.size() << endl;
        while (ForIter != recibo.end()) {
            //fout << int((ForIter->second)->getTipoDeContribuyente()) << endl;
            fout << *(ForIter->second);
            ForIter++;
        }

        //Si llego hasta acá y no hubo ningún problema borro el
        //original y renombro el temporal.
        fout.close();
        remove(outputName);
        rename(auxFileName, outputName);
    }
    catch(runtime_error&) {
        throw;
    }

}

void ReciboDePago::guardarDatos() {
    try {
        guardarContribuyentes("Recibos.txt");
    }
    catch(runtime_error&) {
        throw;
    }
}

string ReciboDePago::nombreDelContribuyente() {
    return "Carlos";
}

float ReciboDePago::montoTotal() {

    return 10.0;
}

float ReciboDePago::montoFijo() {

    return 5.0;
}

float ReciboDePago::montoVariable() {

    return 5.0;
}

Factura ReciboDePago::primeraFacturaConsiderada() {
    Factura factura = Factura();

    return factura;
}

Factura ReciboDePago::ultimaFacturaConsiderada() {
    Factura factura = Factura();

    return factura;
}

/**
* Metodos privados de la clase ReciboDePago
*/
string ReciboDePago::gen_random(const int len) {
    string s;
    static const char alphanum[] =
            "0123456789";

    for (int i = 0; i < len; ++i) {
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}

string ReciboDePago::generadorID() {
    string id = gen_random(10);
    return id;
}