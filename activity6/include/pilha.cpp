#include <iostream>

#include "lista.h"

using namespace std;

typedef lista spilha;

inline spilha* inicia_pilha() {
    return inicia_lista();
}

inline void encerra_pilha(spilha** topo) {
    encerra_lista(&(*topo));
}

inline void push(spilha** p1, spilha** p2) {
    insere_fim(&(*p1), &(*p2));
}

inline void imprime_pilha(spilha** p1, spilha** topo) {
    cout << "                                              RESULTADO DA BUSCA EM PILHA" << endl;
    imprime_lista(&(*p1), &(*topo));
    *p1 = *topo;
}

/*-----------------------------------------------------------------------------------------------------------------------------------+
|  Função que realiza a busca dos veículos em relação às opções apresentadas pelo usuário e armazena-os numa pilha para a impressão  | 
+-----------------------------------------------------------------------------------------------------------------------------------*/
spilha* pilha(int dado1, int dado2, no** ptr1) {
    spilha* topo = inicia_pilha();
    spilha *p1 = topo, *p2;
    string word1, word2;
    int i = 0;
    p1->prox = NULL;

    if (dado2 == -1) {
        dado1--;
        cout << "+---------------------------------+" << endl;
        cout << "|    Informe o primeiro filtro    |" << endl;
        cout << "+---------------------------------+" << endl;
        cin >> word1;

        while ((*ptr1)->prox != NULL) {
            if (*((*ptr1)->dados + dado1) == word1) {
                p1->enc = *ptr1;
                push(&p1, &p2);
                p2 = p1;
                p1 = p1->prox;
                i++;
            }
            *ptr1 = (*ptr1)->prox;
        }   
        if (*((*ptr1)->dados + dado1) == word1) {
            p1->enc = *ptr1;
            push(&p1, &p2);
            p2 = p1;
            p1 = p1->prox;
            i++;
        }
    } else {
        dado1--; dado2--;
        cout << "+---------------------------------+" << endl;
        cout << "|    Informe o primeiro filtro    |" << endl;
        cout << "+---------------------------------+" << endl;
        cin >> word1;

        cout << "+---------------------------------+" << endl;
        cout << "|     Informe o segundo filtro    |" << endl;
        cout << "+---------------------------------+" << endl;
        cin >> word2;
        while ((*ptr1)->prox != NULL) {
            if (*((*ptr1)->dados + dado1) == word1) {
                if (*((*ptr1)->dados + dado2) == word2) {
                    p1->enc = *ptr1;
                    push(&p1, &p2);
                    p2 = p1;
                    p1 = p1->prox;
                    i++;
                }
            }
            *ptr1 = (*ptr1)->prox;
        }   
        if (*((*ptr1)->dados + dado1) == word1) {
            if (*((*ptr1)->dados + dado2) == word2) {
                p1->enc = *ptr1;
                push(&p1, &p2);
                p2 = p1;
                p1 = p1->prox;
                i++;
            }
        }
    }
    if (i != 0) {
        p2->prox = NULL;
        imprime_pilha(&p1, &topo);
        return topo;
    }
    cout << "| Veiculo(s) nao encontrado(s)" << endl;
    cout << "| Redirecionando para o Menu..." << endl;
    delete topo;
    return NULL;
}