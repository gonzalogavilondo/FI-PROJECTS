#include "ManejadorFiguras.h"

int main()
{

    ManejadorFiguras mf;

    mf.recuperarFiguras("figuras_entrada.txt");

    cout << mf << endl << endl;
//
//    mf.guardarFiguras("figuras_salida.txt");
//    mf.agregarFigura("figuras_salida.txt", "Circulo", 0xFF0000, 0xFF00, 3.1);
//    mf.agregarFigura("figuras_salida.txt", "Rectangulo", 0xFF, 0xFFFF00, 4.5, 6.7);
//    mf.agregarFigura("figuras_salida.txt", "Triangulo", 0xFF000, 0xF0F00, 7.5, 9.7);
//
//    cout << mf << endl << endl;
//
//    mf.ordenar("figuras_area.txt", "area");
//    mf.ordenar("figuras_perimetro.txt", "perimetro");

    return 0;
}
