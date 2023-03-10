#include "ManejadorFiguras.h"

//Constructores y Destructores
ManejadorFiguras::ManejadorFiguras(){

}

ManejadorFiguras::~ManejadorFiguras(){
    for (unsigned i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }
}

//Métodos de acceso al vector
void ManejadorFiguras::addFigura(CFigura* inFigura){
    figuras.push_back(inFigura);
}

CFigura* ManejadorFiguras::getFigura(int pos){
    try {
        return figuras.at(pos);
    }
    catch(std::out_of_range){
        throw std::out_of_range("Posicion fuera de rango.");
    }
    catch(...){
        throw;
    }
}

//Sobrecarga de los operadores de extracción
ostream& operator << (ostream& co, ManejadorFiguras& mf){
    for (unsigned i = 0; i < mf.figuras.size(); i++){
        co << *(mf.figuras[i]) << endl;
    }

    return co;
}

//Métodos de la clase
void ManejadorFiguras::recuperarFiguras(const char* fileName){
    try{
        ifstream fin(fileName);

        while(!fin.eof()){
            if (fin.peek() == '\n') fin.ignore();
            CFigura *newFigura;
            string strTipo;
            std::getline(fin, strTipo, ';');
            tipoFigura t = newFigura->strToTipo(strTipo);

            switch (t){
            case CIRCULO:
                newFigura = new CCirculo();
                break;
            case RECTANGULO:
                newFigura = new CRectangulo();
                break;
            case TRIANGULO:
                newFigura = new CTriangulo();
                break;
            }

            if (t != NINGUNA){
                newFigura->setTipo(strTipo);
                fin >> *newFigura;
                addFigura(newFigura);
            } else {
                fin.ignore(); //Ultimo enter
            }
        }

        fin.close();

    }
    catch(...){
        throw;
    }

}

void ManejadorFiguras::guardarFiguras(const char* fileName){
    try{
        ofstream fout;
        fout.open(fileName, std::ios_base::app);
        for (unsigned i = 0; i < figuras.size(); i++){
            fout << *(figuras[i]);
        }
    }
    catch(...){
        throw;
    }
}

void ManejadorFiguras::agregarFigura(const char* fileName, const char* tipo,
                   CColor foreColor, CColor backColor, float base, float altura){

    try{


    }
    catch(...){
        throw;
    }

}

void ManejadorFiguras::ordenar(const char*, const char*){

}
