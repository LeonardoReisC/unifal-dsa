#ifndef PILHA_H
#define PILHA_H

#include "pilha.cpp"

inline spilha* inicia_pilha();

inline void encerra_pilha(spilha** topo);

inline void push(spilha** p1, spilha** p2);

inline void imprime_pilha(spilha** p1, spilha** topo);

spilha* pilha(int dado1, int dado2, no** ptr1);

#endif /* PILHA_H */