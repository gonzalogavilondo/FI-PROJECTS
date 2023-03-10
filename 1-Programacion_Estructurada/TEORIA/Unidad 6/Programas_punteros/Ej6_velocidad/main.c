#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main()
{
    char *ptr;
    ptr = (char *)malloc(100000*sizeof(char));
    LARGE_INTEGER t_ini, t_fin;
    double secs1, secs2;

    for(int cnt=1000; cnt<=100000; cnt*=10)
    {
        QueryPerformanceCounter(&t_ini);
        for(int i=0; i<cnt; i++)
            ptr[i] = 0;
        QueryPerformanceCounter(&t_fin);
        secs1 = performancecounter_diff(&t_fin, &t_ini);
        printf("for(%d) tardo = %.3g microsegundos\n", cnt, secs1 * 1e6);

        QueryPerformanceCounter(&t_ini);
        memset(ptr,0,cnt);
        QueryPerformanceCounter(&t_fin);
        secs2 = performancecounter_diff(&t_fin, &t_ini);
        printf("memset(%d) tardo = %.3f microsegundos\n", cnt, secs2 * 1e6);
        printf("%f veces mas rapido\n\n", secs1/secs2);
    }
    free(ptr);
    return 0;
}


