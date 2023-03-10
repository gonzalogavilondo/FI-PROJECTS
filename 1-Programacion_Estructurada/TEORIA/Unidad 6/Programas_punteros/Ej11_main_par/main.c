#include <stdio.h>
#include <conio.h>

// Project --> Set programs' argument: fija los parámetros para llamar el programa

int main(int argc, char *argv[])
{
    printf("Nombre del programa: %s\n", argv[0]);

    for (int cnt = 1; cnt < argc; cnt++)
    {
        printf("Parametro_%d: %s\n", cnt, argv[cnt]);
    }

    puts("\n\nPresione una tecla para continuar");
    getch();

    return 0;
}
