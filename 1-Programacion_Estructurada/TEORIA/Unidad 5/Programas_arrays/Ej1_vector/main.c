#include <stdio.h>

int main()
{
    char s[]="mensaje";
    int val[]={0, 1, 2, 3, 4, 5};

    // verificar los valores en las posiciones especificas de memoria
    val[0] = 23;
    val[3] = val[0] + 5;

    // los elementos deben imprimirse de a uno
    for(int i=0; i<6; i++)
    {
        printf("val[%d] = %3d, guardado en %p\n", i, val[i], &val[i]);
    }
    puts("\n");

    // el tamaño del vector incluye '\0' (caracter de finalización)
    printf("longitud de %s = %d (tiene 7 caracteres)\n\n", s, sizeof(s));
}
