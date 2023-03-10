#include<stdio.h>
#include<locale.h>

int main()
{
    int num;

    setlocale(LC_ALL,"spanish");
    printf("\nIngrese un número: ");
    scanf("%i", &num);

    if(num < 0)
    {
        printf("\nNegativo\n");
    }
    else
    {
        if( (num > 10) && (num < 100) )
        {
            printf("\nSi pertenece\n");
        }
        else
        {
            printf("\nNo pertenece\n");
        }
    }

    return 0;
}

/**** eliminar las llaves y ver como se dificulta la lectura del código ****/
