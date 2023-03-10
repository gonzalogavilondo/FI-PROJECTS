#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

#define LONGMAX 20

typedef struct
{
    float peso;
    int capacidad_pasajeros;
    int ruedas;
    float potencia;

}tipo;

typedef struct
{
    int dia;
    int mes;
    int anio;

}fecha;

typedef struct
{
    char letras[5];
    int numero;
    fecha ult_transferencia;

}patente;

typedef struct
{
    fecha fabricacion;
    char *color;

}modelo;

typedef struct
{
    char *nombre;
    tipo t_vehiculo;
    modelo m_vehiculo;
    patente p_vehiculo;

}datos_vehiculo;

void ingreso_datos(datos_vehiculo vehiculos[LONGMAX], int indice);
void impresion_datos(datos_vehiculo vehiculos[LONGMAX], int dimension);


#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
