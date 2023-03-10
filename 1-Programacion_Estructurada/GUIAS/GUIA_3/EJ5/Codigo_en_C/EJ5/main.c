#include <header.h>

int main()
{
    char n1[20], n2[20], n3[20], sp = (char)37; /* variables para los nombres de los vendedores, sp significa signo porcentaje y es el num 37 en la tabla ASCII */
    float v1 = 0.0, v2 = 0.0, v3 = 0.0, s1 = 0.0, s2 = 0.0, s3 = 0.0, t = 0.0, p1 = 0.0, p2 = 0.0, p3 = 0.0 ;
    printf("Escriba el nombre del primer vendedor <ESPACIO> y su venta: ");
    scanf("%s%f", &n1, &v1);
    printf("Escriba el nombre del segundo vendedor <ESPACIO> y su venta: ");
    scanf("%s%f", &n2, &v2);
    printf("Escriba el nombre del tercer vendedor <ESPACIO> y su venta: ");
    scanf("%s%f", &n3, &v3);

    s1 = sueldoVendedor (v1);
    s2 = sueldoVendedor (v2);
    s3 = sueldoVendedor (v3);

    printf("El sueldo de %s es de: $%.2f\n", n1, s1);
    printf("El sueldo de %s es de: $%.2f\n", n2, s2);
    printf("El sueldo de %s es de: $%.2f\n", n3, s3);

    t = montoTotalDeVentas(v1, v2, v3);
    p1 = porcentajeDeVentas(v1, t);
    p2 = porcentajeDeVentas(v2, t);
    p3 = porcentajeDeVentas(v3, t);

    printf("El porcentaje de ventas de %s es de: %.2f%c\n", n1, p1, sp);
    printf("El porcentaje de ventas de %s es de: %.2f%c\n", n2, p2, sp);
    printf("El porcentaje de ventas de %s es de: %.2f%c\n", n3, p3, sp);

    return 0;
}
