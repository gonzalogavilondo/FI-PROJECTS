#include "header_rec.h"

int main()
{
    uint32_t v_1[FILAS] = {0x0a1a2a3a, 0x4a5a6a7a, 0x8a9aaaba, 0xcadaeafa, 0x0a1a2a3a};
    uint32_t v_2[FILAS] = {0x0b1b2b3b, 0x4b5b6b7b, 0x8b9babbb, 0xcbdbebfb, 0x0b1b2b3b};
    uint8_t mascara[FILAS][COLUMNAS] = {{0, 0, 1, 0}, {0, 1 ,0, 1}, {0, 1, 1, 0}, {1, 1, 1, 1} , {1, 0, 0, 0}};
    printf("\t\tARREGLOS ANTES DE APLICAR LA MASCARA \n\n");
    mostrar_vector(v_1, 1);
    mostrar_vector(v_2, 2);
    aplicar_mascara(v_1, v_2, (const uint8_t (*)[COLUMNAS])mascara);
    printf("\n\t\tARREGLOS DESPUES DE APLICAR LA MASCARA \n\n");
    mostrar_vector(v_1, 1);
    mostrar_vector(v_2, 2);

    return 0;
}
