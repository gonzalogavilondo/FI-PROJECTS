#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

typedef struct
{
    double distancia;
    int coorx1;
    int coorx2;
    int coory1;
    int coory2;

}punto;

punto *recuperar_datos(punto *coordenada, char *archivo_entrada, int *cnt_pares);
void verificar_apertura(FILE *archivo);
punto *distancia(punto *coordenada, int cnt_pares);
double mayor_distancia(punto *coordenada, int cnt_pares);
void imprimir(punto *coordenada, int cnt_pares, FILE *salida);



#endif // DECLARACIONES_H_INCLUDED
