#include "estudiante.h"
#include "empleado.h"
#include "becario.h"
#include "fstream"

int main()
{
    fecha hoy;

    fecha(1,4,2010);
    /***** Objetos de la clase estudiante *****/
    estudiante Pablo("Pablo Marmol", 27879654, hoy, "Electronica", fecha(1, 3, 2014), 6, 7.8),
               Betty;

    Betty.SetName("Betty McBricker");
    Betty.SetDocument(17555444);
    Betty.SetBirthDate(1, 1, 1987);
    Betty.SetCarrera("Mecanica");
    Betty.SetIngreso(01, 03, 2010);
    Betty.SetMaterias(10);
    Betty.SetPromedio(6.5);

    cout << "/***** Estudiantes *****/" << "\n\n";
    cout << "Impresion solo de los datos personales: \n";
    Print(Pablo);
    //cout << Pablo; // Si imprimo esto, no estaria imprimiendo solo los datos personales ya que esta declarado como estudiante.
    cout << "Impresion de todos los datos:\n";
    //vPrint(Pablo);          // Funcion print en clase estudiante.
    cout << Pablo;          // Uso el operador << sobrecargado para estudiante.
    cout << Betty;          // Uso el operador << sobrecargado para estudiante.

    /***** Objetos de la clase empleado *****/
    empleado Roberto("Roberto Hidalgo", 17123456, 29, 1, 1979,  // fecha como 3 enteros
                     "Titular", 1, 5, 1995, 75324.89),          // dd mm aa
             Paula,
             Gonzalo("Gonzalo Gavilondo", 40666672, fecha(23,10,1997), "Ayudante", hoy, 26540.7); //Queria probar poniendo una fecha

    Paula.SetName("Paula Cervellini");
    Paula.SetDocument(39888777);
    Paula.SetBirthDate(15, 6, 1990);
    Paula.SetCategoria("Jefe Trabajos Practicos");
    Paula.SetIngreso(01, 04, 2015);
    Paula.SetSueldo(48895.36);

    cout << "\n\n/***** Empleados *****/" << "\n\n";
    vPrint(Paula);
    cout << Roberto << endl;
    cout << Gonzalo << endl;

    /***** Objetos de la clase becario *****/
    becario Pedro("Pedro Picapiedra", 11222333, fecha(18, 1, 1999),
                  "Computacion", fecha(1, 4, 2014), 15, 8.59,
                  "Becario", fecha(1, 4, 2016), 2345.67,
                  "Estudiante avanzado", 3, "LIVRA", "Juan Carlos"),
            Vilma;

    Vilma.SetName("Vilma Slaghoople");
    Vilma.SetDocument(13456789);
    Vilma.SetBirthDate(fecha(3, 5, 1990));
    Vilma.SetCarrera("Infomatica");
    Vilma.estudiante::SetIngreso(1, 3, 2010);
    Vilma.SetMaterias(4);
    Vilma.SetPromedio(6.02);
    Vilma.SetCategoria("Becario");
    Vilma.empleado::SetIngreso(fecha(1, 3, 2016));
    Vilma.SetSueldo(23.52);
    Vilma.SetTipo("Auxiliar");
    Vilma.SetDuracion(2);
    Vilma.SetLaboratorio("LIC");
    Vilma.SetDirector("Unknown");

    cout << "\n\n/***** Becarios *****/" << "\n\n";
    vPrint(Pedro);
    cout << Vilma << endl << endl;

    ///Escribimos en archivo de texto al becario
    ofstream fout;
    fout.open("Becarios.txt");
    fout << Pedro;
    fout << Vilma;
    fout.close();

    return 0;
}
