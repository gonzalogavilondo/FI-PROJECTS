#ifndef MANEJADORFIGURAS_H
#define MANEJADORFIGURAS_H

#include <vector>
#include <string>
#include "CFigura.h"
#include "CTriangulo.h"
#include "CRectangulo.h"
#include "CCirculo.h"

class ManejadorFiguras
{
    public:

        ///Constructor
        ManejadorFiguras();

        ///Destructor
        virtual ~ManejadorFiguras();

        ///Getters y setters
        vector <CFigura*> getManejador();
        void setManejador(vector <CFigura*> val);

        ///Sobrecargar operador de insercion
        friend ostream& operator << (ostream&, ManejadorFiguras&);

        ///Metodos propios de la clase
        void recuperarFiguras(const char *inputName);
        void agregarFigura();
        void ordenar();

    private:
        vector <CFigura*> manejador;
};

#endif // MANEJADORFIGURAS_H
