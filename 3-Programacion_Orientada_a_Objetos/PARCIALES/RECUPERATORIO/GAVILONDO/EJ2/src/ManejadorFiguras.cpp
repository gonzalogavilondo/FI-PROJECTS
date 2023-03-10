#include "ManejadorFiguras.h"

/***
    Constructor
***/
ManejadorFiguras::ManejadorFiguras()
{
    //ctor
}

/***
    Destructor
***/
ManejadorFiguras::~ManejadorFiguras()
{
    for (unsigned i = 0; i < figuras.size(); i++)
    {
        delete figuras[i];
    }
}

/***
    Sobrecarga de operadores
***/
ostream& operator << (ostream& co, ManejadorFiguras& mF)
{
    for (unsigned i = 0; i < mF.figuras.size(); i++)
    {
        co << *(mF.figuras[i]) << endl;
    }

    return co;
}

/***
    Metodos propios de la clase
***/
void ManejadorFiguras::recuperarFiguras(const char* inputName)
{
    try
    {
        ifstream fin(inputName);
        if (!fin.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }

        while(!fin.eof())
        {
            if (fin.peek() == '\n')
            {
                fin.ignore();
            }
            string stringTipo;
            getline(fin, stringTipo, ';'); //Agarro hasta encontrar un ";"
            CFigura *figura;

            if(stringTipo == "Rectangulo")
            {
                figura = new CRectangulo;
            }
            else if(stringTipo == "Circulo")
            {
                figura = new CCirculo;
            }
            else
            {
                figura = new CTriangulo;
            }
            ///Hago esta validacion porque antes me agarraba uno mas vacio
            if(stringTipo == "Rectangulo" || stringTipo == "Circulo" || stringTipo == "Triangulo")
            {
                ///Seteo todo en figura
                figura->setTipo(stringTipo);
                fin >> (*figura);

                ///Lo agrego al vector
                figuras.push_back(figura);

            }

        }
        ///Cierro el archivo de entrada
        fin.close();

    }
    catch(runtime_error& e)
    {
        cout << "Se lanzo la excepcion: " << e.what();
    }

}

void ManejadorFiguras::guardarFiguras(const char* outputName){
    try
    {
        ofstream outFile;
        outFile.open(outputName, ios::app); //Agrega al final del archivo.
        if (!outFile.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }
        for (unsigned i = 0; i < figuras.size(); i++)
        {
            outFile << *(figuras[i]);
        }

    }
    catch(runtime_error& e)
    {
        cout << "Se lanzo la excepcion: " << e.what();
    }
}

void ManejadorFiguras::agregarFigura(const char* outputName, string tipo, CColor foreColor, CColor backColor, float base, float altura)
{
    try
    {
        CFigura *figura = NULL;

        if(tipo == "Rectangulo")
        {
            figura = new CRectangulo;
        }
        else if(tipo == "Circulo")
        {
            figura = new CCirculo;
        }
        else
        {
            figura = new CTriangulo;
        }


        ///Seteo a la nueva figura
        figura->setTipo(tipo);
        figura->setForeColor(foreColor);
        figura->setBackColor(backColor);
        figura->setBase(base);
        figura->setAltura(altura);

        ///Agrego al vector
        figuras.push_back(figura);

        ofstream outFile;
        outFile.open(outputName, ios::app); //Agrega al final del archivo.
        if (!outFile.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }
        outFile << *figura;

    }
    catch(runtime_error& e)
    {
        cout << "Se lanzo la excepcion: " << e.what();
    }

}

void ManejadorFiguras::_ordenar(vector<CFigura*> &v, string tipo)
{
    typename vector<CFigura*>::iterator ForIter = v.begin();
    vector<CFigura*> aux;

    while (ForIter != v.end() )
    {
//        if(tipo == "area")
//        {
//            for(size_t i = 0; i < v.size(); i++)
//            {
//                if(v[i]->calcularArea() > v[i+1]->calcularArea())
//                {
//                    aux[i] = v[i+1];
//                    v[i+1] = v[i];
//                    v[i] = aux[i];
//                }
//            }
//        }
//        else if(tipo == "perimetro")
//        {
//            for(size_t i = 0; i < v.size(); i++)
//            {
//                if(v[i]->calcularPerimetro() > v[i+1]->calcularPerimetro())
//                {
//                    aux[i] = v[i+1];
//                    v[i+1] = v[i];
//                    v[i] = aux[i];
//                }
//            }
//        }

        ForIter++;
    }
}
void ManejadorFiguras::ordenar(const char* outputName, string tipo)
{
    ofstream outFile;

    outFile.open(outputName, ios::app);

    if(tipo == "area")
    {
        //Ordeno
        _ordenar(figuras, tipo);
        //Guardo en archivo de salida
        guardarFiguras(outputName);
    }
    else if(tipo == "perimetro")
    {
        //Ordeno
        _ordenar(figuras, tipo);
        //Guardo en archivo de salida
        guardarFiguras(outputName);
    }

    outFile.close();
}
