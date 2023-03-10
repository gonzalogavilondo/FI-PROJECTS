#include <stdio.h>
#include <locale.h>

void copiar (char *, const char *);
int main()
{
    char cadena1[10] = "Hola Mundo";
    char cadena2[10] = {"blab blaba"};
    char *orig;
    char *dest;
    orig = cadena1;
    dest = cadena2;
    copiar(dest, orig);
    /*for (int i = 0; i < 10; i++)
    {
        printf("%c", *(dest+i));
    }*/
    return 0;
}

void copiar (char *dest, const char *orig)
{
    if (orig && dest)
    {
        do
        {
            *dest++ = *orig++;
            printf("%c|\n", *dest);
        }while(*orig);
    }
}
