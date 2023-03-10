#include <stdio.h>

int main()
{
    int i = 59;
    char c = 'A';
    float f = 378.123456789;
    double d = 378.123456789;
    char s[20] = "Mi mensaje";

    printf("%c, %c\n\n", c, 65);                   /*A, A*/

    printf("%d, %i, %i\n\n", i, -i, c);            /*59, -59, 65*/

    printf("%d, %u (ERROR), %u\n\n", -i, -i, i);   /*-59, 4294967237 (ERROR), 59*/

    printf("%.4d, %.1d\n\n", i, i);                /*0059, 59*/

    printf("%10d\n\n", i, i);                      /*        59*/

    printf("%010d\n\n", i, i);                     /*0000000059*/

    printf("%dNuevo\n\n", i);                      /*59Nuevo*/

    printf("%-10dNuevo\n\n", i);                   /*59        Nuevo*/

    printf("%d, %d, %+d, %+d\n\n", 3, -3, 3, -3);  /*3, -3, +3, -3*/

    printf("% d\n% d\n\n", -i, i);                 /* -59 */
                                                   /*  59 */

    printf("%d, %o (OJO!), %#o\n\n", i, i, i);     /*59, 73 (OJO!), 073*/

    printf("%d, %x, %#x, %X\n\n", i, i-3, i-3, i); /*59, 38, 0x38, 3B*/

    printf("%f, %f\n\n", f, d);                    /*378.123444, 378.123457*/

    printf("%4.2f, %3.1f\n%10.3f\n\n", f, f, f);   /*378.12, 378.1*/
                                                   /*   378.123*/

    printf("%4.2E, %3.1E\n\n", f, f);              /*3.78E+002, 3.8E+002*/

    printf("%e, %E\n%20.10E\n\n", f, d, d);        /*3.781234e+002, 3.781235E+002*/
                                                   /*   3.7812345679E+002*/

    printf("%g, %G, %g, %.2G\n\n",                 /*1.23e-005, 0.00123, 1230, 1.23E+003*/
           1.23e-5, 1.23e-3, 1.23e3, 1.23e3);

    printf("Descuento %d%%\n\n", 10);              /*Descuento 10%*/

    printf("%2s, %.4s\n%18s\n", s, s, s);          /*Mi mensaje, Mi m*/
                                                   /*        Mi mensaje*/
    printf("%18.5s\n%-18.5s\n\n", s, s);           /*             Mi me*/
                                                   /*Mi me             */

    printf("i esta en: 0X%p\n\n", &i);             /* i esta en 0X0028fefc*/

    return 0;
}
