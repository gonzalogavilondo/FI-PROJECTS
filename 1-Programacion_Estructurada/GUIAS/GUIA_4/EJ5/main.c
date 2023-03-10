#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float r1 = 0.0, r2 = 0.0, i1 = 0.0, i2 = 0.0, resReal = 0.0, resIm = 0.0;
    char op = '0', simbolo='0';
    printf("Escriba la parte real <+> la parte imaginaria del primer numero: ");
    scanf("%f%c%f", &r1, &simbolo, &i1);
    printf("Escriba la parte real <+> la parte imaginaria del segunda numero: ");
    scanf("%f%c%f", &r2, &simbolo, &i2);
    printf("Elija una opcion:\n(+) SUMA\n(-) RESTA\n(*) MULTIPLICACION\n(/) DIVISION\n");
    fflush( stdin );
    scanf("%c", &op);
    do
    {
        switch (op)
        {
        case '+':
            resReal = r1 + r2;
            resIm = i1 + i2;
            break;
        case '-':
            resReal = r1 - r2;
            resIm = i1 - i2;
            break;
        case '*':
            resReal = (r1*r2)-(i1*i2);
            resIm = (r1*i2)+(r2*i1);
            break;
        case '/':
            if(r2 != 0 && i2 != 0)
            {
                resReal = ((r1*r2)+(i1*i2))/((pow(r2, 2))+(pow(i2, 2)));
                resIm = ((i1*r2)-(r1*i2))/((pow(r2, 2))+(pow(i2, 2)));
            }
            else
            {
                printf("La division por 0 no esta definida. ");
            }
            break;
        default:
            printf("La opcion elegida no es valida. Ingrese nuevamente una opcion: ");
            scanf("%c", &op);
            break;
        }
    }while (op != '+' && op != '-' && op != '*' && op != '/');
    printf("(%.2f+%.2fi) %c (%.2f+%.2fi) = %.2f+%.2fi", r1, i1, op, r2, i2, resReal, resIm);
    return 0;
}




