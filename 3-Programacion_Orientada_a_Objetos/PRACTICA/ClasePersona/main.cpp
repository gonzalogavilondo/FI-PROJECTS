#include "Persona.h"

int main()
{
    Persona ped("Pedro", "Picapiedras", 1234, Fecha(21, 10, 2000)),
            pab("Pablo", "Marmol", 1122, Fecha(15, 1, 2005)),
            vil("Vilma", "Nose", 2341, Fecha(31, 01, 1999));

    cout << ped << endl;
    cout << pab << endl;
    cout << vil << endl;


    return 0;
}
