#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

FILE *carlos;

int main()
{
    char carlitos[] = "C:\\Users\\Yo\\Desktop\\Backup\\prueba\\Carlitos.txt";
    carlos = fopen(carlitos, "w");
    if(carlos == NULL)
    {
        printf("No se puede abrir a carlos\n");
        exit(1);
    }
    else
    {
        printf("Se pudo abrir a carlos y su ubicacion es: %s", carlitos);
        fprintf(carlos, "Hola, soy carlos");
    }



    return 0;
}
