#include <stdio.h>
//#include <stdlib.h>
#include <malloc.h>

int vec[10];
int vec2[5];
float f = 3.14;     // 0x 40 48 F5 C3
char ch = 'A';
int vec3[2] = {20, 21};

int main()
{
    int v2[100];
    int *ptri;
    char *ptr;
    float *ptrf;
    char ch2[10];
    float f2;
    char ch3 = 'B';

    ptr=(char *)malloc(10*sizeof(char));
    ptri=(int *)malloc(25*sizeof(int));
    ptrf=(float *)malloc(12*sizeof(float));

    /***** inicializo todos los vectores y punteros para evitar warnings *****/
    f2 = 25.58;    // 0x 41 CC A3 D7
    *ptrf=f2;

    for(int cnt=0; cnt<10; cnt++)
        vec[cnt] = cnt;
    for(int cnt=0; cnt<5; cnt++)
        vec2[cnt] = 2*cnt;
    for(int cnt=0;cnt<100;cnt++)
    {
        v2[cnt] = 100 - cnt;
        printf("v2[%d] = %d\n", cnt, v2[cnt]);
    }
    for(int cnt=0; cnt<10; cnt++)
    {
        ch2[cnt] = ch3 + cnt;
        printf("ch2[%d] = %c\n", cnt, ch2[cnt]);
    }
    for(int cnt=0; cnt<25; cnt++)
    {
        *(ptri+cnt) = cnt;
        printf("puntero(%d) = %d\n", cnt, *(ptri+cnt));
    }
    for(int cnt=0; cnt<10; cnt++)
    {
        *(ptr+cnt) = 'A' + cnt;
        printf("puntero(%d) = %c\n", cnt, *(ptr+cnt));
    }

    return 0;
}
