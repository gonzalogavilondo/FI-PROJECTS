#include <iostream>
#include <map>
#include <utility> // std::pair, std::make_pair

using namespace std;

/***
    Escribir un programa que permita almacenar el primer apellido y el nombre
    de los empleados de una empresa: lógicamente los apellidos y nombres pueden
    estar repetidos. Luego de ingresar los datos, el programa debe solicitar el
    apellido de los empleados a buscar, y mostrar todos aquellos cuyo apellido sea
    igual al ingresado. Si no hay empleados con ese apellido se debe informar al
    usuario.
***/

template <class K, class V> void printMap(map<K, V> mp)
{
    typename map<K, V>::iterator forIter;

    forIter = mp.begin();                       // puntero al primer elemento
    cout << endl;
    while (forIter != mp.end() )                // mientras no sea el último elemento
    {
        cout << forIter->first << "  " << forIter->second << endl;
        forIter++;                              // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    map<string, string> empleados;

    string valor = "0",
           nombre,
           apellido;

    // Agregamos a los empleados
    do
    {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el apellido: ";
        cin >> apellido;

        empleados.insert(make_pair(apellido, nombre)); // La clave tiene que ser el apellido

        cout << endl << "Desea agregar otro empleado? <1:Si/ 0:No>: ";
        cin >> valor;
        cout << endl;

    }while(valor != "0"); //El operador de comparacion != esta sobrecargado en la clase string.

    system("pause");
    system("cls");

    // Imprimimos los empleados
    cout << "Empleados: " << endl;
    printMap(empleados);

    // Busqueda de algun empleado por el apellido como clave.
    do
    {
        cout << "Ingrese el apellido del empleado que quiera buscar: ";
        cin >> apellido;

        if(empleados.find(apellido)->second)// ME FALTA PONER LA CONDICION. PREGUNTAR COMO SERIA.
        //Retorna un iterador a la clave k. Si no se encuentra
        //se retorna un iterador al final del map
        {
            cout << "La persona con apellido: " << apellido << " es: " << empleados.find(apellido)->second << endl;
        }
        else
        {
            cout << "No se ha encontrado al empleado con ese apellido." << endl;
        }

        cout << endl << "Desea buscar otro empleado? <1:Si/ 0:No>: ";
        cin >> valor;
        cout << endl;

    }while(valor != "0"); //El operador de comparacion != esta sobrecargado en la clase string.

    return 0;
}
