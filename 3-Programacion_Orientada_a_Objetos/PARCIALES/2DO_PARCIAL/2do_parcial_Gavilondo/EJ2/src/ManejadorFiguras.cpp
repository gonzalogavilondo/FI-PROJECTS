#include "ManejadorFiguras.h"

ManejadorFiguras::ManejadorFiguras()
{
    //ctor
}

ManejadorFiguras::~ManejadorFiguras()
{
    manejador.erase(manejador.begin(), manejador.end());
}

/***
    Getters y setters
***/
vector <CFigura*> ManejadorFiguras::getManejador()
{
    return manejador;
}

void ManejadorFiguras::setManejador(vector <CFigura*> val)
{
    manejador = val;
}

/***
    Sobrecarga operador de insercion
***/
ostream& operator << (ostream& co, ManejadorFiguras& mf)
{
    for(size_t i = 0; i < mf.manejador.size(); i++)
    {
        co << mf.manejador[i];
    }
    return co;
}

/***
    Metodos propios de la clase
***/

void ManejadorFiguras::recuperarFiguras(const char *inputName)
{
    try
    {
        ifstream fin(inputName);
        if (!fin.good())
        {
            throw(runtime_error("No se pudo abrir el archivo.\n"));
        }

        string auxTipo;
        uint32_t auxFore_color;
        uint32_t auxBack_color;
        float auxBase;
        float auxAltura;
        float auxRadio;
        CFigura* auxFigura;
        int opc = 0;

        //getline(cin, “nombre de la variable”, ´caracter delimitador´)
        while(fin.eof())
        {
            getline(fin, auxTipo, ';');
            if(auxTipo == "Rectangulo") {
                opc = 0;
            }
            else if(auxTipo == "Circulo") {
                opc = 1;
            }
            else {
                opc = 2;
            }
            switch(opc)
            {
                case 0:
                    auxFigura = new CRectangulo();
                    fin >> auxFore_color;
                    fin.ignore();
                    auxFigura->setFore_color(auxFore_color);
                    fin >> auxBack_color;
                    fin.ignore();
                    auxFigura->setBack_color(auxBack_color);
                    fin >> auxBase;
                    fin.ignore();
                    auxFigura->setBase(auxBase);
                    fin >> auxAltura;
                    auxFigura->setAltura(auxAltura);
                    break;
                case 1:
                    auxFigura = new CCirculo();
                    fin >> auxFore_color;
                    fin.ignore();
                    auxFigura->setFore_color(auxFore_color);
                    fin >> auxBack_color;
                    fin.ignore();
                    auxFigura->setBack_color(auxBack_color);
                    fin >> auxRadio;
                    auxFigura->setBase(auxRadio);
                    break;
                case 2:
                    auxFigura = new CTriangulo();
                    fin >> auxFore_color;
                    fin.ignore();
                    auxFigura->setFore_color(auxFore_color);
                    fin >> auxBack_color;
                    fin.ignore();
                    auxFigura->setBack_color(auxBack_color);
                    fin >> auxBase;
                    fin.ignore();
                    auxFigura->setBase(auxBase);
                    fin >> auxAltura;
                    auxFigura->setAltura(auxAltura);
            }
            manejador.push_back(auxFigura);

        }
        fin.close();
    }
    catch(runtime_error& e)
    {
        cout << "Se lanzo la excepcion: " << e.what();
    }

}
