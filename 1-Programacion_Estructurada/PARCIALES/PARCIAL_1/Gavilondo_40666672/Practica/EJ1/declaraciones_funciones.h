#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED

#define BYTES 4
#define ELEMENTOS 4
void entero_a_bytes(uint8_t num, uint8_t bytes[]);
void mostrar_bytes(const uint8_t bytes[]);
int bytes_a_entero(uint8_t num, const uint8_t bytes[]);
void aplicar_mascara(uint8_t bytes[]);


#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
