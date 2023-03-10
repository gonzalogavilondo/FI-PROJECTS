#include <stdio.h>
#include <stdlib.h>

void returnMain (void);
int main()
{
    char letras[4] = {'0','0','0','0'};
    printf("Escriba tres caracteres, separados por comas: ");
    scanf("%c,%c,%c", &letras[1], &letras[2], &letras[3]);
    for (int i = 3; i > 1; i--)
    {
        if (letras[i] < letras[i-1])
        {
            char aux = letras[i-1];
            letras[i-1] = letras[i];
            letras[i] = aux;
        }
        if (letras[i+1] < letras[i] && i==2)
        {
            i=4;
        }
    }
    printf("%c,%c,%c\n", letras[1], letras[2], letras[3]);
    return 0;
}
