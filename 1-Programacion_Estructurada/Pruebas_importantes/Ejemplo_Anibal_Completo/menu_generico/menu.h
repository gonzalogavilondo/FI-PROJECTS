#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define MENU_OPERACION_FIN 0
#define MENU_LARGO_TEXTO 30

extern unsigned int menu_cant_elems;

extern unsigned int menu_opcion_salir;

extern const char menu_textos[][MENU_LARGO_TEXTO];

extern const char menu_opciones[];

extern const int menu_operaciones[];

void menu_mostrar();
int menu_index_operacion(unsigned char c);
int menu_confirmar_salida();
int menu_operacion();


#endif // MENU_H_INCLUDED
