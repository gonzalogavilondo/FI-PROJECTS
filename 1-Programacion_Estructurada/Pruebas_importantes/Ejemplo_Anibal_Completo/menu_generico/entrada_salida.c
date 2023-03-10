#include <stdio.h>
#include <stdlib.h>
#include "entrada_salida.h"

unsigned char leer_stdin()
{
    unsigned char c;
    int seguir = 0;
    do
    {
        c = getchar();
        if (c == EOF)
        {
            seguir = 1;
        }
    } while (seguir);
    vaciar_stdin();
    return c;
}

void vaciar_stdin()
{
    unsigned char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void borrar_stdout()
{
    //funciona tanto para linux como para windows
    system("cls||clear");
}
