#ifndef DECLARACIONES_MENU_H_INCLUDED
#define DECLARACIONES_MENU_H_INCLUDED

int menu(void);
int opcion_salida(void);
void opcion_proceso(int op, int fils1, int cols1, int fils2, int cols2, const float A[FILSMAX][COLSMAX], const float B[FILSMAX][COLSMAX], float C[FILSMAX][COLSMAX]);

#endif // DECLARACIONES_MENU_H_INCLUDED
