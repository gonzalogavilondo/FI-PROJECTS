#include "header_ops.h"

int main()
{
    system("color 8f");
    uint8_t mask[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    uint32_t vec_1[4] = {0x0a1a2a3a, 0x4a5a6a7a, 0x8a9aaaba, 0xcadaeafa};
    uint32_t vec_2[4] = {0x0b1b2b3b, 0x4b5b6b7b, 0x8b9babbb, 0xcbdbebfb};
    printf("VALORES DE LOS VECTORES ANTES DE APLICARLES LA MASCARA.\n\n");
    imprimir_vector(vec_1, 1);
    imprimir_vector(vec_2, 2);
    aplicar_mascara(vec_1, vec_2, (const uint8_t (*)[COLS])mask); //intercambian los bytes i-esimos de dos vectores
    printf("VALORES DE LOS VECTORES DESPUES DE APLICARLES LA MASCARA.\n\n");
    imprimir_vector(vec_1, 1);
    imprimir_vector(vec_2, 2);
    return 0;
}
