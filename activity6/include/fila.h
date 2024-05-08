#ifndef FILA_H
#define FILA_H

#include "fila.cpp"

inline sfila* inicia_fila();

inline void push_(sfila** fim, sfila** l);

inline void imprime_fila(sfila** fim, sfila** inicio);

sfila* fila(int dado1, int dado2, no** ptr1);

#endif /* FILA_H */