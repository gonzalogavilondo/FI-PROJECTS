#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

typedef struct
{
    int red;
    int green;
    int blue;
    unsigned long suma;

}pantalla_color;

void verificar_apertura(FILE *archivo);
void grabar_datos(pantalla_color *matriz, FILE *salida);
pantalla_color *suma_componentes(pantalla_color *matriz, int cnt_elementos);
pantalla_color *recuperar_datos(pantalla_color *matriz, char *nombre_entrada, int *cnt_elementos);

#endif // DECLARACIONES_H_INCLUDED
