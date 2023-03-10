// ordena 3 flotantes de mayor a menor

#include<stdio.h>

int main()
{
    float p,
          s,
          r;

    printf("\nIngrese 3 flotantes (separados por ','): ");
    scanf("%f", &p);
    scanf("%*c");         // para no leer la ','
    scanf("%f", &s);
    scanf("%*c");         // para no leer la ','
    scanf("%f", &r);

    if(p > s)
    {
        if(p > r)
        {
            if(s > r)
            {
                printf("\n%f > %f > %f\n", p, s, r);
            }
            else
            {
                printf("\n%f > %f > %f\n", p, r, s);
            }
        }
        else
        {
            printf("\n%f > %f > %f\n", r, p, s);
        }
    }
    else
    {
        if(s > r)
        {
            if(p > r)
            {
                printf("\n%f > %f > %f\n", s, p, r);
            }
            else
            {
                printf("\n%f > %f > %f\n", s, r, p);
            }
        }
        else
        {
            printf("\n%f > %f > %f\n", r, s, p);
        }
    }

    return 0;
}
