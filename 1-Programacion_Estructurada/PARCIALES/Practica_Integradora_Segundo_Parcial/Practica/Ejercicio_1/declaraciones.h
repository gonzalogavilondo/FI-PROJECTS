#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

typedef struct
{
    int long_linea;
    char *oracion;

}datos_oracion;

void verificar_apertura(FILE *informacion);
datos_oracion *recuperar_datos(datos_oracion *oracion, char *nombre_entrada, int *cnt_lineas);
datos_oracion * recuperar_datos_binario(datos_oracion *oracion, int *cnt_lineas);
int linea_menor(datos_oracion *oracion, int cnt_lineas);
void grabar_datos(const datos_oracion *oracion, int cnt_lineas, int long_min, FILE *salida);
void grabar_datos_binario(const datos_oracion *oracion, int cnt_lineas, int long_min);
void liberar_memoria(int cnt_lineas, datos_oracion *oracion);

#endif // DECLARACIONES_H_INCLUDED
