#ifndef PROTNORMALIZARCAD_H_INCLUDED
#define PROTNORMALIZARCAD_H_INCLUDED

#define esBlanco(X) ((X) == ' ' || (X) == '\t')
#define capitalize(X) ((X) >= 'a' && (X) <= 'z' ? (X) - 32 : (X))
#define lowercase(X) ((X) >= 'A' && (X) <= 'Z' ? (X) + 32 : (X))

void normalizeString(char *s);

#endif // PROTNORMALIZARCAD_H_INCLUDED
