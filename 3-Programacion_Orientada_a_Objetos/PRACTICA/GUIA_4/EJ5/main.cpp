#include "Empresa.h"

int main()
{
    Empresa empresa;
    Empleado empleado;
    Permanente perm;

    cout << "-EMPRESA-" << endl;
    empresa.SetEmpresa(empresa);
    cout << empresa;

    cout << endl << endl << "-EMPLEADO-" << endl;
    empresa.ContratarEmpleado(empleado);
    cout << empleado;

    perm = Permanente(empleado);

    return 0;
}
