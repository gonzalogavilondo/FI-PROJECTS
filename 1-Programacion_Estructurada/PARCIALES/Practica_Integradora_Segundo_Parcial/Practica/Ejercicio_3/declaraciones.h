#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED


typedef struct
{
    int anio_nac;
    char *nombre;

}datos_persona;

void verificar_apertura(FILE *archivo);
void grabar_datos(datos_persona *persona, FILE *salida);
void liberar_memoria(datos_persona *persona, int cnt_estructuras);
datos_persona *recuperar_datos(datos_persona *persona, char *archivo_entrada, int *cnt_estructuras);

#endif // DECLARACIONES_H_INCLUDED
