#include "Menu.h"

void Menu(CBanco* B)
{
    const char* opciones[] = {"Todas", "Cuentas de ahorro", "Cuentas corrientes", "Activo Disponible", "Salir"};
    const int num_opciones = sizeof(opciones) / sizeof(char*);
    int opcion = 0;

    do
    {
        opcion = CrearMenu(opciones, num_opciones);
        switch(opcion)
        {
            case 1: // todas
                CBanco::VisualizarCuentas(*B, "Todas");
                system("pause");
                break;
            case 2: // de ahorro
                CBanco::VisualizarCuentas(*B, "CCuentaAhorro");
                system("pause");
                break;
            case 3: // corrientes
                CBanco::VisualizarCuentas(*B, "CCuentaCorriente");
                system("pause");
                break;
            case 4: // corrientes
                cout << endl << "Activo disponible del banco: " << B->GetActivoDisponible() << endl << endl;
                system("pause");
                break;
            case num_opciones: // salir
                break;
        }
    }while(opcion != num_opciones);
}

int CrearMenu(const char* opMenu[], int num_opciones)
{
    int opcion;
    system("cls");

    do
    {
        cout << "Elija una opcion:\n" << endl;

        for (int i = 0; i < num_opciones; i++)
        {
            cout << "\t" << setw(2) << i + 1 << ". " << opMenu[i] << endl;
        }

        cout << ">> ";
        cin >> opcion;
        cin.ignore(numeric_limits<int>::max(), '\n');
        if (opcion < 1 || opcion > num_opciones)
        {
            cerr << "Opcion incorrecta. " << endl;
            system("pause");
            system("cls || clear");
        }

    }while(opcion < 1 || opcion > num_opciones);

    return opcion;
}
