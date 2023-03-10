#include <header.h>

float sueldoVendedor (float venta)
{
    float sueldo;
    sueldo = (venta*(float)1/10);
    return sueldo;
}

float montoTotalDeVentas(float ventasDe1, float ventasDe2, float ventasDe3)
{
    float total;
    total = ventasDe1+ventasDe2+ventasDe3;
    return total;
}

float porcentajeDeVentas (float venta, float total)
{
    float porcentaje;
    porcentaje = ((venta*100)/total);
    return porcentaje;
}
