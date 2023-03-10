#include <stdio.h>
#include <stdlib.h>
#include "declaraciones_funciones.h"

int main()
{
    int num = 0;
    int tablas[DIM][DIM] = {{0}};
    carga_tablas(tablas);
    printf("Indique que tabla quiere: ");
    scanf("%i", &num);
    system("cls || clear");
    printf("TABLA DEL %i\n\n", num);
    mostrar_una_tabla(tablas, num);
    return 0;
}
