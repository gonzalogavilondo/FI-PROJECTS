#include <stdio.h>

int main()
{
    int cnt,
        acum;

    for(cnt=0, acum=0; cnt<=20; cnt+=2)   /* suma a pasos de 2 */
    {
        acum+= cnt;
        printf("%d %d\n", cnt, acum);
    }

    cnt = 1;
    acum = 0;
    while(cnt <= 100)                  /* suma los primeros 100 números 1-100 */
    {
        acum+= cnt++;
    }
    printf("\n\nSuma de 1 a 100 = %d\n", acum);

    cnt = 1;
    acum = 0;
    do
    {
        acum+= cnt++;
    }while(cnt <= 100);
    printf("\n\nSuma de 1 a 100 = %d\n\n", acum);

   return 0;
}

