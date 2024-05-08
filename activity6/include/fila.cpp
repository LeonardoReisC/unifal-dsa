#include <iostream>

#include "lista.h"

using namespace std;

typedef lista sfila;

inline sfila* inicia_fila() {
    return inicia_lista();
}

inline void push_(sfila** fim, sfila** l) {
    insere_fim(&(*fim), &(*l));
}

inline void imprime_fila(sfila** fim, sfila** inicio) {
    cout << "                                             RESULTADO DA BUSCA EM FILA" << endl;
    return imprime_lista(&(*fim), &(*inicio));
}

/*----------------------------------------------------------------------------------------------------------------------------------+
|  Função que realiza a busca dos veículos em relação às opções apresentadas pelo usuário e armazena-os numa fila para a impressão  | 
+----------------------------------------------------------------------------------------------------------------------------------*/
sfila* fila(int dado1, int dado2, no** ptr1) {
    sfila *inicio = inicia_lista(), *fim = inicio, *l;
    string word1, word2;
    int i = 0;
    fim->prox = NULL;

    if (dado2 == -1) {
        dado1--;

        cout << "+---------------------------------+" << endl;
        cout << "|    Informe o primeiro filtro    |" << endl;
        cout << "+---------------------------------+" << endl;
        cin >> word1;

        while ((*ptr1)->prox != NULL) {
            if (*((*ptr1)->dados + dado1) == word1) {
                fim->enc = *ptr1;
                push_(&fim, &l);
                l = fim;
                fim = fim->prox;
                i++;
            }
            *ptr1 = (*ptr1)->prox;
        }
        if (*((*ptr1)->dados + dado1) == word1) {
            fim->enc = *ptr1;
            push_(&fim, &l);
            l = fim;
            fim = fim->prox;
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
                    fim->enc = *ptr1;
                    push_(&fim, &l);
                    l = fim;
                    fim = fim->prox;
                    i++;
                }
            }
            *ptr1 = (*ptr1)->prox;
        }
        if (*((*ptr1)->dados + dado1) == word1) {
            if (*((*ptr1)->dados + dado2) == word2) {
                fim->enc = *ptr1;
                push_(&fim, &l);
                l = fim;
                fim = fim->prox;
                i++;
            }
        }
    }

    if (i != 0) {
        l->prox = NULL;
        fim = l;
        imprime_fila(&fim, &inicio);
        return inicio;
    }
    cout << "| Veiculo(s) nao encontrado(s)" << endl;
    cout << "| Redirecionando para o Menu..." << endl << endl;
    delete(inicio);
    return NULL;
    //encerra_fila(&fim, &l, &inicio);
}