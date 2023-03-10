#include "ManejadorFiguras.h"
using namespace std;

int main()
{
    try{
        ManejadorFiguras mf;

        mf.recuperarFiguras("figuras_entrada.txt");

        cout << mf << endl << endl;

        mf.guardarFiguras("figuras_salida.txt");
        mf.agregarFigura("figuras_salida.txt", "Circulo", 0xFF0000, 0xFF00, 3.1);
        mf.agregarFigura("figuras_salida.txt", "Rectangulo", 0xFF, 0xFFFF00, 4.5, 6.7);
        mf.agregarFigura("figuras_salida.txt", "Triangulo", 0xFF000, 0xF0F00, 7.5, 9.7);

        cout << mf << endl << endl;

        mf.ordenar("figuras_area.txt", "area");
        mf.ordenar("figuras_perimetro.txt", "perimetro");
    }
    catch(std::runtime_error){
        cout << "Hola" << endl;
//        cout << "Error archivo." << end;
    }
    catch(...){
        cout << "Ha ocurrido un error inesperado." << endl;
    }

    return 0;
}

/**     PARTE TEORICA   **/
///Parte te�rica

///1) �Qu� utilidad tiene un constructor de una clase abstracta, si no se pueden crear objetos de la misma?
///
/// Sirve para inicializar todos los valores por default o con par�metros
/// los argumentos que tienen en com�n todas las clases hijas.
///

///2) �Cu�les son los tipos de enlace que se pueden establecer en C++ entre la declaraci�n y la definici�n de un m�todo?  y �Qu� relaci�n existe con el polimorfismo?
///
/// Din�micos (en tiempo de ejecuci�n) o est�ticos (en tiempo de compilaci�n)
/// Los enlaces din�micos se utilizan en el polimorfismo para que en tiempo
/// de ejecuci�n se determine a cu�l de las subclases llamar.
///

///3) �Explique brevemente con sus palabras que es un Template (Planilla) de C++ y cuando es apropiado utilizarlo?
///
/// Se utiliza para declarar funciones o contenedores gen�ricos. Es apropiado
/// cuando queremos realizar una funci�n gen�rica que funciona para cualquier
/// tipo de dato, generalmente se utiliza para armar librer�as.
///

///4) �Qu� es una excepci�n y como se maneja en C++? Ejemplifique.
///
/// Es cuando se da una situaci�n que produce que se termine abruptamente
/// un programa. Son sucesos especiales que se manejan con bloques de
/// try/catch. Por ejemplo, si se divide por 0, se producir� una excepcion.
///

///5) �Cu�les son las diferencias entre una clase abstracta y una interface?
///
/// Una interface puede definir s�lo m�todos abstractos, ninguno puede tener
/// implementaci�n. Y en otros lenguajes, como java, la interfaz puede "heredar"
/// de varias interfaces mientras que una clase abstracta solo puede heredar de una.
///
