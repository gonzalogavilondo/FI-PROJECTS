#include "calculadora.h"
#include "complejos.h"

int main()
{
    CCalculadora<complejo> Calculadora;

    Calculadora.SetearObjetos();

    system("pause");

    Calculadora.Menu();

    return 0;
}

/***
        Nota: Falta con strings. Preguntar si entiendo bien la diferencia entre especializacion de funcion y
              sobrecarga de funcion.

              Preguntar como hacer resta, multiplicacion y division de strings.

              ej:

              template<typename T> T menor(T a, T b) // plantilla general
              {
                  return (a < b) ? a : b;
              }

              char* menor(char* a, char* b)
              {
                  return (strcmp(a, b) < 0) ? a : b;
              }
              int main()
              {
                  cad3 = menor(cad1, cad2); //La hace bien.
                  cad3 = menor<char*>(cad1, cad2); -> Esta llamada va a ser que se siga haciendo mal no?
              }

              -> La solucion para la segunda llamada seria hacer una ESPECIALIZACION DE FUNCION cierto????

              template<typename> char* menor(char* a, char* b)
              {
                  return (a < b) ? a : b;
              }
    ***/
