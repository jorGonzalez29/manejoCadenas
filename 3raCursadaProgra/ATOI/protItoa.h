#ifndef PROTITOA_H_INCLUDED
#define PROTITOA_H_INCLUDED

#define esBlanco(X) ((X) == ' ' || (X) == '\t')
#define esDigito(X) ((X)>= '0' && (X) <= '9')

int a_toi(const char *s);
#endif // PROTITOA_H_INCLUDED
