#ifndef DECLARACIONES_H_INCLUDED
#define DECLARACIONES_H_INCLUDED

#define FILSMAX 4
#define COLSMAX 3
void completar_matriz (float matriz[FILSMAX][COLSMAX]);
void mostrar_matriz (const float matriz[FILSMAX][COLSMAX]);
void suma_cols(float matriz[FILSMAX][COLSMAX], float suma[FILSMAX]);
float valor_max(float suma[COLSMAX], float matriz[FILSMAX][COLSMAX]);
#endif // DECLARACIONES_H_INCLUDED
