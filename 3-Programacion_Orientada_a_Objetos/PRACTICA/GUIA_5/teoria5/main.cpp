#include <iostream>
#include <cstdlib>
#include "Asalariado.h"
#include "EmpleadoProduccion.h"
#include "EmpleadoDistribucion.h"

using namespace std;

int main (){
    // Que es el polimorfismo

    // Ingredientes para hablar de polimorfismo: herencia y redefinicion de metodos.

    // Ejemplo

//    Asalariado empl1 ("Manuel Cortina", 12345678, 28, 1200);
//    EmpleadoProduccion empl2 ("Juan Mota", 55333222, 30, 1200, "noche");
//
//    empl1 = empl2;
//
//    cout << "El nombre del empleado 1 es " << empl1.getNombre() << endl;
//    cout << "Su salario es " << empl1.getSalario() << endl;
//    //La siguiente invocación produciría un error de compilación:
//    //cout << "El turno del empleado 1 es " << empl1.getTurno() << endl;
//    cout << "El nombre del empleado 2 es " << empl2.getNombre() << endl;
//    cout << "El turno del empleado 2 es " << empl2.getTurno() << endl;
//    cout << "Su salario es " << empl2.getSalario() << endl;

    // Analizar la salida del programa y explicar por que es esa
    // Agregar en Asalariado el modificador "virtual" al metodo getSalario.

    // Volver a analizar la salida.

    // Modificar el ejemplo para usar memoria dinamica
//    Asalariado * punt_empl1 = new Asalariado("Manuel Cortina", 12345678, 28, 1200);
//    EmpleadoProduccion * punt_empl2 = new EmpleadoProduccion ("Juan Mota",
//     55333222, 30, 1200, "noche");
//
//    punt_empl1 = punt_empl2;
//
//
//    cout << "El nombre del empleado 1 es " << punt_empl1->getNombre() << endl;
//    cout << "Su salario es " << punt_empl1->getSalario() << endl;
//    //La siguiente invocación produciría un error de compilación:
//    //cout << "El turno del empleado 1 es " << punt_empl1->getTurno() << endl;
//    cout << "El nombre del empleado 2 es " << punt_empl2->getNombre() << endl;
//    cout << "El turno del empleado 2 es " << punt_empl2->getTurno() << endl;
//    cout << "Su salario es " << punt_empl2->getSalario() << endl;


//1. Los métodos redefinidos deben ser declarados como "virtual" en el
//correspondiente fichero de cabeceras
//2. Los objetos desde los que se invoca al método redefinido deben ser
//alojados en memoria por medio de referencias o punteros

// Polimorfismo de metodos trabajando sobre estructuras de datos
// Ej 1
//    Asalariado * punt_empl1 = new Asalariado ("Manuel Cortina", 12345678, 28,
//    1200);
//    EmpleadoProduccion * punt_empl2 = new EmpleadoProduccion ("Juan Mota",
//    55333222, 30, 1200, "noche");
//    punt_empl1 = punt_empl2;
//
//    cout << "El nombre del empleado 1 es " << punt_empl1->getNombre() << endl;
//    cout << "Su salario es " << punt_empl1->getSalario() << endl;
//    cout << "El nombre del emplead2 es " << punt_empl2->getNombre() << endl;
//    cout << "Su salario es " << punt_empl2->getSalario() << endl;
//
//    Asalariado array_empl [5];
//    array_empl [0] = (* punt_empl1);
//    array_empl [1] = (* punt_empl2);
//
//    for (int i = 0; i <= 1; i++){
//        cout << "El salario del empleado " << i << " es " << array_empl[i].getSalario()
//        << endl;
//    }


// Ej 2


    Asalariado * punt_empl1 = new Asalariado ("Manuel Cortina", 12345678, 28, 1200);
    EmpleadoProduccion * punt_empl2 = new EmpleadoProduccion ("Juan Mota",
    55333222, 30, 1200, "noche");
    punt_empl1 = punt_empl2;

    cout << "El nombre del empleado 1 es " << punt_empl1->getNombre() << endl;
    cout << "Su salario es " << punt_empl1->getSalario() << endl;
    cout << "El nombre del empleado 2 es " << punt_empl2->getNombre() << endl;
    cout << "Su salario es " << punt_empl2->getSalario() << endl;

    Asalariado* array_empl [5];
    array_empl [0] = punt_empl1;
    array_empl [1] = punt_empl2;

    for (int i = 0; i <= 1; i++){
        cout << "El salario del empleado " << i << " es " << array_empl[i]->getSalario() << endl;
    }

// Ver el comportamiento cuando un tipo Asalariado pasa por parametro.....

    system ("PAUSE");
    return 0;
}
