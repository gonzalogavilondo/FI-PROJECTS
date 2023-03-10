#include "Empleado.h"

int main()
{
    //Declaramos las fechas necesarias
    Fecha fechaNA,
          fechaCA,
          fechaNB,
          fechaCB;

    fechaCA.Setfecha(1, 7, 1999);
    fechaNA.Setfecha(31, 10, 1978);
    fechaCB.Setfecha(1, 8, 1999);
    fechaNB.Setfecha(25, 2, 1980);

    //Declaramos el empleado inicializando en el constructor con los valores
    Empleado empA("Juan", "Perez", fechaCA, fechaNA);

    //Declaramos el otro empleado.
    Empleado empB;

    empB.Setapellidos("Lopez");
    empB.Setnombres("Pedro");
    empB.SetfechaContratacion(fechaCB);
    empB.SetfechaNacimiento(fechaNB);


    //Imprimimos los datos
    empA.imprimir();
    empB.imprimir();

    //cout << "El empleado A se contrato en: " << fechaCA.mesLetras(fechaCA.Getmonth()) << endl;

    return 0;
}
