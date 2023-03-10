#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

typedef struct
{
    int lng_palabra;
    char *palabra;

}palabras_t;

void  verificar_apertura(FILE *archivo);
palabras_t *recuperar_datos(palabras_t *palabras, char *nombre_entrada, int *cnt_palabras);
palabras_t *invertir_palabra(palabras_t *palabras, int cnt_palabras);
void grabar_datos(palabras_t *palabras,int cnt_palabras, FILE *salida);
void liberar_memoria(palabras_t *palabras, int cnt_palabras);
void invertir_palabras(palabras_t *palabras, int cnt_palabras);
int comparar(palabras_t *ptr1, palabras_t *ptr2);

#endif // DECLARACIONES_H_INCLUDED
