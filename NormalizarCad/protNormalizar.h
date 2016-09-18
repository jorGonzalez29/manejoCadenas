#ifndef PROTNORMALIZAR_H_INCLUDED
#define PROTNORMALIZAR_H_INCLUDED
#define esBlanco(X) ((X) == '\t' || (X) == ' ')
#define esMayor(X) ((X) >= 'A' && (X) <= 'Z' ? (X) : (X) - 32)
#define esMenor(X) ((X) >= 'a' && (X) <= 'z' ? (X) : (X) + 32)
void normalizarCadena(const char *cad);
#endif // PROTNORMALIZAR_H_INCLUDED
