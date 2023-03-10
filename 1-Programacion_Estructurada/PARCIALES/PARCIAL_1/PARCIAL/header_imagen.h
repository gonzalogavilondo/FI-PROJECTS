#ifndef HEADER_IMAGEN_H_INCLUDED
#define HEADER_IMAGEN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

void obtener_matriz_componentes_color (const uint32_t [], uint32_t,  uint32_t, uint32_t [][4]);
void get_bytes_by_colores (uint32_t, uint32_t[]);
void mostrar_vector_como_matriz(const uint32_t [], uint32_t, uint32_t);
void mostrar_matriz (const uint32_t [][4], uint32_t, uint32_t);
void mostrar_matrices_color (const uint32_t [][4], uint32_t, uint32_t);
void transformar_niveles_gris (uint32_t components_color_img[][4], uint32_t color_gris_mat[], uint32_t colors_count);

#endif // HEADER_IMAGEN_H_INCLUDED
