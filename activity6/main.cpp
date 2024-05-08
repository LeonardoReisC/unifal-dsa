/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTAÇAO.
* Trabalho...........: Gerenciador de Busca de Carros, Vans e Utilitários
* Disciplina.........: Programação
* Professor..........: Paulo Alexandre Bressan
* Aluno..............: Leonardo Reis Coimbra
* Registro Acadêmico.: 2021.1.08.013
* Data...............: 29/03/2022
+------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "include/pilha.h"
#include "include/fila.h"

using namespace std;

int main() {
    /*----------------------------------------------------------------------+
    |                         Declaração de Variáveis                       |
    |  . *ptlista: ponteiro da lista encadeada                              |
    |  . *ptr1, *ptr2: ponteiro que percorrem a lista encadeada             |
    |  . i, aux, aux2: inteiros para selecionar as operações implementadas  | 
    |  . *lista: ponteiro para a pilha/filha em busca de encerrá-la         |
    |  . line: lê o arquivo de entrada                                      |      
    -----------------------------------------------------------------------*/ 
    no *ptlista, *ptr1, *ptr2;
    string* p; 
    int i = 0, aux, aux2 = 0;
    lista* lista = NULL;
    string line;
    string filename;

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−----+
    | Menu de escolha de arquivo de entrada |
    +--------------------------------------*/
    cout << "+--------------------------------+" << endl;
    cout << "|  Informe o arquivo de entrada  |" << endl;
    cout << "+--------------------------------+" << endl;
    cin >> filename;
    cout << endl;

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------+
    |  Leitura do arquivo de entrada                 |
    |  Tradução do arquivo para uma lista encadeada  |
    +-----------------------------------------------*/
    ifstream arq(filename);
    if (!arq.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    ptlista = inicia_enc();
    ptr1 = ptlista;
    ptr2 = inicia_enc();
    while (!arq.eof()) {
        p = ptr1->dados;
        for (; p < (ptr1->dados + 12); p++) {
            arq >> *p;
        }
        ptr1->prox = ptr2;
        ptr1 = ptr2;
        if (p != (ptr1->dados + 11)) {
            ptr2 = inicia_enc();
        }
        i++;    
    }
    ptr1 = ptlista;
    ptr2 = ptr1->prox;
    
    for (aux = 0, i -= 2; aux < i; aux++) {
        ptr1 = ptr1->prox;
    }
    ptr1->prox = NULL;
    ptr1 = ptlista;

    /*−−−−−−−−−−−−−−−−−−−−−−−-−−−----+
    |  Ordenação da lista encadeada  |
    +-------------------------------*/
    ordenacao_lista(&ptr1, &ptr2, &ptlista);


    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−------------+
    |  Menu de escolha das operações implementadas  |
    +----------------------------------------------*/
    do
    {
        cout << "+-------------------------------------+" << endl;
        cout << "|           Menu do Usuario           |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|  1  |   Inclusao de veiculo         |" << endl;
        cout << "|  2  |   Remocao de veiculo          |" << endl;
        cout << "|  3  |   Busca de veiculo(s)         |" << endl;
        cout << "|  4  |   Relatorios Geral            |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|  0  |   Sair                        |" << endl;
        cout << "+-------------------------------------+" << endl; 
        cin >> i;
        cout << endl;
        while (i < 0 || i > 4) {
            cout << "| Entrada Invalida" << endl;
            cout << "| Insira novamente" << endl;
            cin >> i;
            cout << endl;
        }
        
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-----------+
        |  Identificações da operação escolhida        |
        |  Chamada da(s) função(ões) correpondente(s)  |
        +---------------------------------------------*/
        switch (i) {
        case 0:
            i = 100;
            break;
        case 1: 
            cout << "+----------------------------------------------------------+" << endl;
            cout << "|      Informe a placa do veiculo que deseja registrar     |" << endl;
            cout << "+----------------------------------------------------------+" << endl;
            cout << "|  0  |   Voltar para o Menu                               |" << endl;
            cout << "+----------------------------------------------------------+" << endl;
            cin >> line;
            cout << endl;
            if (line == "0") break;

            while (busca_enc(line, &ptr1, &ptr2, &ptlista) && line != "0") {
                cout << "| Veiculo ja registrado" << endl;
                cout << "| Insira a placa de um veiculo nao existente" << endl;
                cin >> line;
                cout << endl;

                ptr1 = ptlista;
                ptr2 = ptlista->prox;
            }
            if (line == "0") break;

            ptr1 = ptlista;
            ptr2 = ptlista->prox;

            insere_enc(line, &ptr1, &ptr2, &ptlista);
            break;
        case 2:
            cout << "+----------------------------------------------------------+" << endl;
            cout << "|       Informe a placa do veiculo que deseja remover      |" << endl;
            cout << "+----------------------------------------------------------+" << endl;
            cout << "|  0  |   Voltar para o Menu                               |" << endl;
            cout << "+----------------------------------------------------------+" << endl;
            cin >> line;
            cout << endl;
            if (line == "0") break;

            while (!busca_enc(line, &ptr1, &ptr2, &ptlista) && line != "0") {
                cout << "| Veiculo nao encontrado" << endl;
                cout << "| Insira a placa de um veiculo existente" << endl;
                cin >> line;
                cout << endl;

                ptr1 = ptlista;
                ptr2 = ptlista->prox;
            }
            if (line == "0") break;

            remove_enc(&ptr1, &ptr2, &ptlista);
            break;
        case 3: 
            if (lista != NULL) encerra_lista(&lista);

            cout << "+-------------------------------------------+" << endl;
            cout << "|     Selecione os filtros para a busca     |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|   1  |   Modelo                           |" << endl;
            cout << "|   2  |   Marca                            |" << endl;
            cout << "|   3  |   Tipo                             |" << endl;
            cout << "|   4  |   Ano                              |" << endl;
            cout << "|   5  |   Quilometragem                    |" << endl;
            cout << "|   6  |   Potencia do Motor                |" << endl;
            cout << "|   7  |   Combustivel                      |" << endl;
            cout << "|   8  |   Cambio                           |" << endl;
            cout << "|   9  |   Direcao                          |" << endl;
            cout << "|  10  |   Cor                              |" << endl;
            cout << "|  11  |   Numero de portas                 |" << endl;
            cout << "|  12  |   Placa                            |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cout << "|  -1  |   Segunda opcao vazia              |" << endl;
            cout << "|   0  |   Voltar para o Menu               |" << endl;
            cout << "+-------------------------------------------+" << endl;
            cin >> i >> aux;  
            cout << endl;

            while (i < 0 || i > 12) {
                cout << "| Primeira opcao invalida" << endl;
                cout << "| Insira novamente" << endl;
                cin >> i;
                cout << endl;
            }
            if (i == 0) {
                lista = NULL;
                break;
            }

            while (aux < -1 || aux > 12 || aux == i) {
                if (aux == i) {
                    cout << "| Esta opcao ja foi marcada" << endl;
                    cout << "| Insira novamente" << endl;
                    cin >> aux;
                    cout << endl;
                } else {
                    cout << "| Segunda opcao invalida" << endl;
                    cout << "| Insira novamente" << endl;
                    cin >> aux;
                    cout << endl;
                }
            }
            if (aux == 0) {
                lista = NULL;
                break;
            }

            cout << "+---------------------------------------+" << endl;
            cout << "|     Em qual formato deseja buscar     |" << endl;
            cout << "+---------------------------------------+" << endl;
            cout << "|  1  |   Pilha                         |" << endl;
            cout << "|  2  |   Fila                          |" << endl;
            cout << "+---------------------------------------+" << endl;
            cout << "|  0  |   Voltar para o Menu            |" << endl;
            cout << "+---------------------------------------+" << endl;
            cin >> aux2;
            cout << endl;

            while (aux2 < 0 || aux2 > 2) {
                cout << "| Entrada Invalida" << endl;
                cout << "| Insira novamente" << endl;
                cin >> aux2;
                cout << endl;
            }

            if (aux2 == 1) {
                lista = pilha(i, aux, &ptr1);
            } else if (aux2 == 2) {
                lista = fila(i, aux, &ptr1);
            }
            break;
        case 4: 
            imprime_enc(&ptr1, &ptlista);
            break;
        }
        ptr1 = ptlista;
        ptr2 = ptlista->prox;
        cout << endl;
    } while (i != 100);

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−---------------+
    |  Escrita da lista encadeada final em um arquivo  |
    +-------------------------------------------------*/

    ofstream arq2;
    arq2.open(filename);
    if (!arq2.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    while (ptr1->prox != NULL) {
        p = ptr1->dados;
        for (; p < (ptr1->dados + 12); p++) {
            arq2 << *p << " ";
        }
        arq2 << endl;
        ptr1 = ptr1->prox;
    }
    p = ptr1->dados;
    for (; p < (ptr1->dados + 12); p++) {
        arq2 << *p << " ";
    }
    ptr1 = ptlista;

    arq.close();
    arq2.close();
    encerra_enc(&ptlista);
    return 0;
}