#include "declaraciones.h"

void vocal(char letra)
{
    if(letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U')
    {
        printf("La letra ingresada es una vocal");
    }
    else
    {
        printf("La letra ingresada no es una vocal");
    }
}
