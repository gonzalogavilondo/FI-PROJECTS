#include <header.h>
int main()
{
    float v = 0.0, r = 0.0, i = 0.0;
    char pyc = '0';
    printf("Escriba los valores de tension < ; > y resistencia: ");
    scanf("%f%c%f", &v, &pyc, &r);
    corriente(v, r, &i);
    printf("La corriente es: %.2f", i);

    return 0;
}
