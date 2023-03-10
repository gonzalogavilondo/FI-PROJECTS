#include <iostream>
#include <string>

using namespace std;

class Persona
{
    public:
        Persona(string n)
            { nombre = n; }
        virtual void VerNombre() { cout << nombre << endl; }
        virtual ~Persona() { ; }
    protected:
        string nombre;
};

class Empleado : public Persona
{
    public:
        Empleado(string n) : Persona(n) {}
        void VerNombre()
        {
            cout << "Emp: " << nombre << endl;
        }
};

class Estudiante : public Persona
{
    public:
        Estudiante(string n) : Persona(n) {}
        void VerNombre()
        {
            cout << "Est: " << nombre << endl;
        }
};

int main()
{
    Persona *Pepito = new Estudiante("Jose");
    Persona *Carlos = new Empleado("Carlos");

    Carlos->VerNombre();
    Pepito->VerNombre();

    delete Pepito;
    delete Carlos;

    return 0;
}
