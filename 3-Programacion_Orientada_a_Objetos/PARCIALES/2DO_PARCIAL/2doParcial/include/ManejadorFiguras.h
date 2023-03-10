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
        //Constructores y Destructores
        ManejadorFiguras();
        virtual ~ManejadorFiguras();

        //Métodos de acceso al vector
        void addFigura(CFigura*);
        CFigura* getFigura(int);

        //Sobrecarga de los operadores de extracción
        friend ostream& operator << (ostream&, ManejadorFiguras&);

        //Métodos de la clase
        void recuperarFiguras(const char*);
        void guardarFiguras(const char*);
        void agregarFigura(const char*, const char*,
                           CColor, CColor, float, float altura = 0);
        void ordenar(const char*, const char*);

    private:
        vector<CFigura*> figuras;
};

#endif // MANEJADORFIGURAS_H
