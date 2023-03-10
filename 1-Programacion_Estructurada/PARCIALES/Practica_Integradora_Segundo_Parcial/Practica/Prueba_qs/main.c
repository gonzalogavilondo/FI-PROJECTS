#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comparar_datos(const void *p, const void *q);

int main()
{
    int oraciones[] = {1, 4, 3};
    int cnt_oraciones = sizeof(oraciones)/sizeof(int);

    qsort(&oraciones, cnt_oraciones, sizeof(char*), &comparar_datos);
    for(int cnt = 0; cnt < cnt_oraciones; cnt++)
    {
        printf("%d", oraciones[cnt]);
    }


    return 0;
}
int comparar_datos(const void *p, const void *q)
{
    int x;
    int y;

    x = *(int*)p; //A lo que hay en p, pero primero convertimos p en puntero de enteros.
    y = *(int*)q; //A lo que hay en q, pero primero convertimos q en puntero de enteros.

    if(x > y)
    {
        return -1;
    }
    else
    {
        if(x == y)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

}
