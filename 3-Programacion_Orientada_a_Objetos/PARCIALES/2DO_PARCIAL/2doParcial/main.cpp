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
///Parte teórica

///1) ¿Qué utilidad tiene un constructor de una clase abstracta, si no se pueden crear objetos de la misma?
///
/// Sirve para inicializar todos los valores por default o con parámetros
/// los argumentos que tienen en común todas las clases hijas.
///

///2) ¿Cuáles son los tipos de enlace que se pueden establecer en C++ entre la declaración y la definición de un método?  y ¿Qué relación existe con el polimorfismo?
///
/// Dinámicos (en tiempo de ejecución) o estáticos (en tiempo de compilación)
/// Los enlaces dinámicos se utilizan en el polimorfismo para que en tiempo
/// de ejecución se determine a cuál de las subclases llamar.
///

///3) ¿Explique brevemente con sus palabras que es un Template (Planilla) de C++ y cuando es apropiado utilizarlo?
///
/// Se utiliza para declarar funciones o contenedores genéricos. Es apropiado
/// cuando queremos realizar una función genérica que funciona para cualquier
/// tipo de dato, generalmente se utiliza para armar librerías.
///

///4) ¿Qué es una excepción y como se maneja en C++? Ejemplifique.
///
/// Es cuando se da una situación que produce que se termine abruptamente
/// un programa. Son sucesos especiales que se manejan con bloques de
/// try/catch. Por ejemplo, si se divide por 0, se producirá una excepcion.
///

///5) ¿Cuáles son las diferencias entre una clase abstracta y una interface?
///
/// Una interface puede definir sólo métodos abstractos, ninguno puede tener
/// implementación. Y en otros lenguajes, como java, la interfaz puede "heredar"
/// de varias interfaces mientras que una clase abstracta solo puede heredar de una.
///
