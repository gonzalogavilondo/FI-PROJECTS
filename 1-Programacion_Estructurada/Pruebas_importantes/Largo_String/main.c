#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdint.h>

int main()
{
    uint8_t c = 0, i = 0;
    char *ptrc;
    ptrc = &c;
    uint8_t dim = 1000;
    printf("Ingrese LO QUE QUIERA.\n");
    int i = 0;
    ptrc = c;
    while (i != dim || c == 'n')
    {
        c = getch();
        if (c == '\b')
        {
            i--;
            printf("\b \b");
        }
        else
        {
            printf("%c", c);
            *(ptrc+i) = c;
            i++;
        }
    }
    int cantidad = ptrc-c;

    printf("\n%i", cantidad);
    return 0;
}
