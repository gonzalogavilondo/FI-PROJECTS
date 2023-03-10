#ifndef MANEJADORFIGURAS_H
#define MANEJADORFIGURAS_H
#include <iostream>
#include <vector>
#include <fstream>
#include "CFigura.h"
#include "CCirculo.h"
#include "CRectangulo.h"
#include "CTriangulo.h"
#include "CColor.h"


class ManejadorFiguras
{
    public:

        ///Constructor
        ManejadorFiguras();

        ///Destructor
        virtual ~ManejadorFiguras();

        ///Sobrecarga de operadores
        friend ostream& operator << (ostream&, ManejadorFiguras&);

        ///Metodos de la propia clase
        void recuperarFiguras(const char*);
        void guardarFiguras(const char*);
        void agregarFigura(const char*, string, CColor, CColor, float, float altura = 0);
        void ordenar(const char*, string);
        void _ordenar(vector<CFigura*> &vec, string tipo);

    private:
        vector<CFigura*> figuras;
};

#endif // MANEJADORFIGURAS_H
