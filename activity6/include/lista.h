#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "lista.cpp"

using namespace std;

no* inicia_enc();

lista* inicia_lista();

void encerra_enc(no** ptlista);

void encerra_lista(lista** lista);

void ordenacao_lista(no** ptr1, no** ptr2, no** ptlista); 

bool busca_enc(string dado, no** ptr1, no** ptr2, no** ptlista); 

void insere_enc(string placa, no** ptr1, no** ptr2, no** ptlista); 

void remove_enc(no** ptr1, no** ptr2, no** ptlista); 

void imprime_enc(no** ptr1, no** ptlista);

#endif /* LISTA_H */

