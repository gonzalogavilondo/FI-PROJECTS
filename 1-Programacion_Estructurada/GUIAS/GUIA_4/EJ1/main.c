#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Escriba un caracter: ");
    scanf("%c", &c);
    switch ( c )
    {
        case 'A':
            return 1;
            break;
        case 'B':
            return 2;
            break;
        case 'C':
            return 3;
            break;
        case 'D':
            return 4;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}
