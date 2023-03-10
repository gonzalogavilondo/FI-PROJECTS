#ifndef DECLARACIONES_FUNCIONES_H_INCLUDED
#define DECLARACIONES_FUNCIONES_H_INCLUDED
#define ELEMENTOSMAX 4
#define BYTES 4
void entero_a_bytes(uint32_t num, uint8_t bytes[]);
void mostrar_bytes(const uint8_t bytes[], uint32_t elementos);
int cargar_tipo_de_dato(uint32_t tipo_de_dato);
int bytes_a_entero(uint32_t num, const uint8_t bytes[], uint32_t elementos);

#endif // DECLARACIONES_FUNCIONES_H_INCLUDED
