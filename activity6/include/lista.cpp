#include <iostream>

using namespace std;

/*--------------------------------------------------------------------------+
|  Criação do registro(lista encadeada) que armazenará os dados do veiculo  |
+--------------------------------------------------------------------------*/

typedef struct no_ {
    string dados[12]; //alocação sequencial dos dados do veiculo
    no_* prox;      //ponteiro para o próximo nó da lista encadeada
} no;

/*-------------------------------------------------------------------------------+
|  Criação do registro(pilha/fila) apontará para um elemento da lista encadeada  |
+-------------------------------------------------------------------------------*/
typedef struct lista_ {
    no_* enc;      //ponteiro para o nó da lista encadeada associado 
    lista_* prox;   //ponteiro para o próximo nó da pilha/fila
} lista;

/*-----------------------------------------------+
|  Alocação dinâmica dos nós da lista encadeada  |
+-----------------------------------------------*/
no* inicia_enc() {
    no* tmp = new(no);
    tmp->prox = NULL;
    return tmp;
}

/*-------------------------------------------+
|  Alocação dinâmica dos nós da pilha/filha  |
+-------------------------------------------*/
lista* inicia_lista() {
    lista* tmp = new(lista);
    return tmp;
}

/*----------------------------------------------------------------------------+
|  Função que passa o ponteiro da lista encadeada como parâmetro e encerra-a  |
+----------------------------------------------------------------------------*/
void encerra_enc(no** ptlista) {
    no* ptr1;
    ptr1 = *ptlista;
    while ((*ptlista)->prox != NULL) {
        ptr1 = (*ptlista)->prox;
        delete(*ptlista);
        *ptlista = ptr1;
    }
    delete(*ptlista);
}

/*-----------------------------------------------------------------------+
|  Função que passa o ponteiro da pilha/fila como parâmetro e encerra-a  |
+-----------------------------------------------------------------------*/
void encerra_lista(lista** lista) {
    lista_ *l1; 
    l1 = *lista;
    while ((*lista)->prox != NULL) {
        l1 = (*lista)->prox;
        delete(*lista);
        *lista = l1;
    }
    delete(*lista);
}

/*------------------------------------------------------------------------------------------------------------+
|  Selection Sort Adaptado para a ordenação dos nós da lista encadeada com base na placa do carro(dados[11])  |
+------------------------------------------------------------------------------------------------------------*/
void ordenacao_lista(no** ptr1, no** ptr2, no** ptlista) {
    no *ant;
    int i = 0, j, path;
    for (i = 0; (*ptr1)->prox != NULL; i++) {
        ant = *ptr1;
        path = i;
        for (j = i; (*ptr2)->prox != NULL; j++) {
            if (*((*ptr2)->dados + 11) < *(ant->dados + 11)) {
                path = j;
                ant = *ptr2;
            }
            *ptr2 = (*ptr2)->prox;
        }
        if (*((*ptr2)->dados + 11) < *(ant->dados + 11)) {
            path = j;
            ant = *ptr2;
        }
        
        if (ant != *ptr1) {
            *ptr2 = (*ptr1)->prox;
            for (j = i; j < path; j++) {                                                                                                                                                                                                                                                 
                *ptr2 = (*ptr2)->prox;
                if (j == path - 2) {
                    ant = *ptr2;
                }
            }

            if (ant != *ptr2) {
                ant->prox = *ptr1;
                ant = (ant->prox)->prox;
            } else {
                ant = *ptr1;
            }

            (*ptr1)->prox = (*ptr2)->prox;
            (*ptr2)->prox = ant;

            if (i == 0) {
                *ptlista = *ptr2;
            } else {
                ant = *ptlista;
                for (j = 0; j < i - 1; j++) {
                    ant = ant->prox;
                }     
                ant->prox = *ptr2;
            }
            *ptr1 = (*ptr2)->prox;
        } else *ptr1 = (*ptr1)->prox;

        *ptr2 = (*ptr1)->prox;
    }
    (*ptr1)->prox = NULL;
    *ptr1 = *ptlista;
    *ptr2 = (*ptlista)->prox;
}

/*------------------------------------------------------------------------------------------------------+
|  Função booleana que percorre a lista encadeada para avaliar a existência da dado entrada do usuário  |
+------------------------------------------------------------------------------------------------------*/
bool busca_enc(string dado, no** ptr1, no** ptr2, no** ptlista) {
    int i, j;
    string *p;
    for (i = 0; (*ptr1)->prox != NULL; i++) {
        p = (*ptr1)->dados;
        for (j = 0; j < 12; j++, p++) {
            if (*p == dado) {
                if (i == 0) return true;
                *ptr1 = *ptlista;
                for (j = 0; j < i - 1; j++) {
                    *ptr1 = (*ptr1)->prox;
                }
                *ptr2 = ((*ptr1)->prox)->prox;
                return true;
            }
        }
        *ptr1 = (*ptr1)->prox;
    }

    p = (*ptr1)->dados;
    for (j = 0; j < 12; j++, p++) {
        if (*p == dado) {
            *ptr1 = *ptlista;
            for (j = 0; j < i - 1; j++) {
                *ptr1 = (*ptr1)->prox;
            }
            *ptr2 = (*ptr1)->prox;
            return true;
        }
    }
    return false;
}

/*---------------------------------------------------------------------------------------------------------------+
|  Função que percorre a lista encadeada até encontar a posição correta onde o novo veículo deve ser registrado  |
+---------------------------------------------------------------------------------------------------------------*/
void insere_enc(string placa, no** ptr1, no** ptr2, no** ptlista) {
    no* pont;
    string *p;
    int i = 0;
    *ptr2 = inicia_enc();
    p = (*ptr2)->dados;
    cout << "Modelo: "; cin >> *p; p++;
    cout << "Marca: "; cin >> *p; p++;
    cout << "Tipo: "; cin >> *p; p++;
    cout << "Ano: "; cin >> *p; p++;
    cout << "Quilometragem: "; cin >> *p; p++;
    cout << "Potencia do Motor: "; cin >> *p; p++;
    cout << "Combustivel: "; cin >> *p; p++;
    cout << "Cambio: "; cin >> *p; p++;
    cout << "Direcao: "; cin >> *p; p++;
    cout << "Cor: "; cin >> *p; p++;    
    cout << "Numero de portas: "; cin >> *p; p++;
    *p = placa;  
    
    while ((*ptr1)->prox != NULL && *((*ptr1)->dados + 11) < placa) {
        i++;
        if (*(((*ptr1)->prox)->dados + 11) > placa) break;
        *ptr1 = (*ptr1)->prox;   
    }

    if ((*ptr1)->prox == NULL) {         //cenário ao qual o novo veículo deve ser registrado na última posição
        (*ptr1)->prox = *ptr2;
        (*ptr2)->prox = NULL;
    }else if (i == 0) {                  //cenário ao qual o novo veículo deve ser registrado na primeira posição
        (*ptr2)->prox = *ptr1;
        *ptlista = *ptr2;
    } else {
        (*ptr2)->prox = (*ptr1)->prox;   //cenário onde o novo veículo deve ser registrado em um posição central
        (*ptr1)->prox = *ptr2;
    }
}

/*------------------------------------------------------------------------------------------------------------------+
|  Função que percorre a lista encadeada até encontar a posição correta onde o veículo informado deve ser removido  |
+------------------------------------------------------------------------------------------------------------------*/
void remove_enc(no** ptr1, no** ptr2, no** ptlista) {
    if (*ptr2 == (*ptlista)->prox) {       //cenário onde o primeiro nó deve ser removido        
        *ptlista = *ptr2;  
    } else if (*ptr2 == (*ptr1)->prox) {   //cenário onde o último nó deve ser removido
        (*ptr1)->prox = NULL;
    } else { 
        (*ptr1)->prox = *ptr2;             //cenário onde um nó central deve ser removido
    }
}

/*--------------------------------------------------+
|  Função que insere um nó no início da pilha/fila  |
+--------------------------------------------------*/
void insere_inicio(lista** l1, lista** l2, lista** lista) {
    *l2 = inicia_lista();
    *lista = *l2;
    (*l2)->prox = *l1;
}

/*-----------------------------------------------+
|  Função que insere um nó no dim da pilha/fila  |
+-----------------------------------------------*/
void insere_fim(lista** l1, lista** l2) {
    *l2 = inicia_lista();
    (*l1)->prox = *l2;
    (*l2)->prox = NULL;
}

/*--------------------------------------------------+
|  Função que remove um nó no início da pilha/fila  |
+--------------------------------------------------*/
void remove_inicio(lista** lista) {
    *lista = (*lista)->prox;
}

/*------------------------------------------------------------------+
|  Função que imprime na saída a lista encadeada de forma ordenada  |
+------------------------------------------------------------------*/
void imprime_enc(no** ptr1, no** ptlista) {
    *ptr1 = *ptlista;
    int i;
    cout << "                                          RELATORIO GERAL DOS CLIENTES" << endl;
    cout << "+--------------------------------------------------------------------------------------------------------------------+" << endl;
    while ((*ptr1)->prox != NULL) {
        cout << "|  ";
        for (i = 0; i < 12; i++) {
            cout << *((*ptr1)->dados + i) << "  ";
        }
        cout << endl << "+--------------------------------------------------------------------------------------------------------------------+" << endl;
        *ptr1 = (*ptr1)->prox;
    }
    cout << "|  ";
    for (i = 0; i < 12; i++) {
        cout << *((*ptr1)->dados + i) << " ";
    }
    cout << endl << "+--------------------------------------------------------------------------------------------------------------------+" << endl;
}

/*--------------------------------------------------------------+
|  Função que imprime na saída a pilha/lista de forma ordenada  |
+--------------------------------------------------------------*/
void imprime_lista(lista** l1, lista** lista) {
    *l1 = *lista;
    cout << "+--------------------------------------------------------------------------------------------------------------------+" << endl;
    while ((*l1)->prox != NULL) {
        cout << "|  ";
        for (int i = 0; i < 12; i++) {
            cout << *(((*l1)->enc)->dados + i) << "  ";
        }
        cout << endl << "+--------------------------------------------------------------------------------------------------------------------+" << endl;
        *l1 = (*l1)->prox;
    }
    cout << "|  ";
    for (int i = 0; i < 12; i++) {
        cout << *(((*l1)->enc)->dados + i) << "  ";
    }
    cout << endl << "+--------------------------------------------------------------------------------------------------------------------+" << endl;
}


