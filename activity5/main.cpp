/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTAÇAO.
* Trabalho...........: Processamento de Imagens com Ponteiros
* Disciplina.........: Programação
* Professor..........: Paulo Alexandre Bressan
* Aluno..............: Leonardo Reis Coimbra
* Registro Acadêmico.: 2021.1.08.013
* Data...............: 21/12/2021
+------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "include/operacao.cpp"

using namespace std;

int main(void) {
    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−------------------------+
    |           Inicialização de algumas variáveis              |
    | . line: extensão do arquivo                               |
    | . *ext: ponteiro para "line"                              |
    | . lin: quantidade de linha da imagem de entrada           |
    | . col: quantidade de coluna da imagem de entrada          |
    | . tom: quantidade de tons de cinza da imagem de entrada   |
    | . i: índice da operação escolhida pelo usuário            |
    | . i, j: varíaveis sequenciais                             |
    | . porc: porcentagem escolhia pelo usuário que irá clarear |
    |          ou escurecer a imagem                            |
    +----------------------------------------------------------*/
    string line;
    char *pointer = NULL;
    int lin, col, tom, i, j;
    float porc;
    pointer = &line[0];

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−----+
    | Menu de escolha de arquivo de entrada |
    +--------------------------------------*/
    cout << "+-----------------------------------------------+" << endl;
    cout << "| Informe o arquivo da imagem que deseja alterar|" << endl;
    cout << "+-----------------------------------------------+" << endl;
    cin >> line;

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−---------+
    | Leitura do cabeçalho do arquivo de entrada |
    | para a coleta do número de linhas, colunas |
    |              e tons de cinza               |
    +-------------------------------------------*/
    ifstream arq(line);
    if (arq.is_open()) {
        string skip;
        getline(arq, line);
        getline(arq, skip);
        arq >> col;
        arq >> lin;
        arq >> tom;
    }
    
    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------+
    |    Inicialização das outras variáveis    |
    | . m: matriz imagem do arquivo de entrada |
    | . *p: ponteiro para a matriz imagem "m"  |
    +-----------------------------------------*/
    int m[lin][col], *p = NULL;
    p = &m[0][0];

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−------------------+
    | Leitura do corpo da imagem de entrada para a matriz |
    |                      imagem "m"                     |
    +----------------------------------------------------*/
    if (arq.is_open()) {
        cout << lin << " " << col << endl;
        while (!arq.eof()) {    
            for (i = 0; i < lin; i++) {
                for (j = 0; j < col; j++) {
                    arq >> *p;
                    p++;
                }
            }
        }

        arq.close();    
    } else {
        cout << "Unable to open file" << endl;
        return 0;
    }
    p = &m[0][0];

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−--+
    | Identificação do tipo de arquivo |
    +---------------------------------*/
    for (i = 0; *pointer != '.' && *pointer != '\0'; i++, pointer++);
    line = "";
    for (j = 0; *pointer != '\0'; j++, pointer++) {
        line += *pointer;
    }

    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−--------------+
    | Menu de escolha operação implementada na imagem |
    +------------------------------------------------*/
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "|    Selecione uma operacao a ser implementada na imagem    |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "|  1  |                Inversao negativa                    |" << endl;
    cout << "|  2  |                Inversao vertical                    |" << endl;
    cout << "|  3  |                Inversao horizontal                  |" << endl;
    cout << "|  4  |                Rotacao a direita                    |" << endl;
    cout << "|  5  |                Rotacao a esquerda                   |" << endl; 
    cout << "|  6  |                Escurecimento de bordas              |" << endl;
    cout << "|  7  |                Escurecimento de imagem              |" << endl;
    cout << "|  8  |                Clareamento de imagem                |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cout << "|  0  |                        Sair                         |" << endl;
    cout << "+-----------------------------------------------------------+" << endl;
    cin >> i;
    while (i < 0 || i > 8) {
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|                      Entrada Invalida                     |" << endl;
        cout << "|           Informe novamente a operacao desejada           |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|  1  |                Inversao negativa                    |" << endl;
        cout << "|  2  |                Inversao vertical                    |" << endl;
        cout << "|  3  |                Inversao horizontal                  |" << endl;
        cout << "|  4  |                Rotacao a direita                    |" << endl;
        cout << "|  5  |                Rotacao a esquerda                   |" << endl; 
        cout << "|  6  |                Escurecimento de bordas              |" << endl;
        cout << "|  7  |                Escurecimento de imagem              |" << endl;
        cout << "|  8  |                Clareamento de imagem                |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cout << "|  0  |                        Sair                         |" << endl;
        cout << "+-----------------------------------------------------------+" << endl;
        cin >> i;
    }
    
    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−----------------------+
    |   Identificação da operação escolhida pelo usuário e    |
    |     a chamada das funções implementadas, onde são       |
    |                 passados por parâmetro:                 |              
    | . p: ponteiro da matriz imagem "m"                      |
    | . lin: quantidade de linhas da matriz imagem "m"        |
    | . col: quantidade de coluna da matriz imagem "m"        |
    | . tom: quantidade de tons de cinza da matriz imagem "m" |
    | . line: extensão do arquivo de entrada que será a mesma |
    |         de saída na função write_file que será chamada  |
    |         dentros das funções de operação da matriz       |
    |         imagem "m"                                      |
    +--------------------------------------------------------*/
    switch (i) {
    case 0:
        return 0;
        break;
    case 1:
        inv_neg(p, lin, col, tom, line);
        break;
    case 2:
        inv_vert(p, lin, col, tom, line);
        break;
    case 3:
        inv_horiz(p, lin, col, tom, line);
        break;
    case 4:
        right_rot(p, lin, col, tom, line);
        break;
    case 5:
        left_rot(p, lin, col, tom, line);
        break;
    case 6:
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| Informe o valor do fator que sera diminuido da matriz imagem |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "|  0  |                         Sair                           |" << endl;            
        cout << "+--------------------------------------------------------------+" << endl;
        cin >> i;
        if (i == 0) return 0;
        while (i < 0) {
            cout << "+---------------------------+" << endl;
            cout << "| O fator deve ser positivo |" << endl;
            cout << "|    Digite-o novamente     |" << endl;
            cout << "+---------------------------+" << endl;
            cout << "|  0  |        Sair         |" << endl;
            cout << "+---------------------------+" << endl;
            cin >> i; 
            if (i == 0) return 0;;
        }
        cout << "+-------------------------------------------------------+" << endl;
        cout << "| Informe a taxa de decaimento do fator escolhido acima |" << endl;
        cout << "+-------------------------------------------------------+" << endl;
        cout << "|  0  |                     Sair                        |" << endl;
        cout << "+-------------------------------------------------------+" << endl;
        cin >> j;
        if (j == 0) return 0;
        while (j < 0) {
            cout << "+--------------------------+" << endl;
            cout << "| A taxa deve ser positiva |" << endl;
            cout << "|    Digite-a novamente    |" << endl;
            cout << "+--------------------------+" << endl;
            cout << "|  0  |        Sair        |" << endl;
            cout << "+--------------------------+" << endl;
            cin >> j;
            if (j == 0) return 0; 
        }  
        darken_edge(p, lin, col, tom, i, j, pointer);
        break;
    case 7:
        cout << "+--------------------------------------------------+" << endl;
        cout << "| Informe a porcentagem da imagem a ser escurecida |" << endl;
        cout << "+--------------------------------------------------+" << endl;
        cout << "|  0  |                   Sair                     |" << endl;
        cout << "+--------------------------------------------------+" << endl;
        cin >> porc;
        if (porc == 0) return 0;
        while (porc < 0 || i > 100) {
            cout << "+---------------------------------+" << endl;
            cout << "|        Entrada Invalida         |" << endl;
            cout << "| O valor deve ser entre 0 e 100% |" << endl;
            cout << "|       Digite-o novamente        |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "|  0  |           Sair            |" << endl;
            cout << "+---------------------------------+" << endl;
            cin >> porc; 
            if (porc == 0) return 0;;
            
        }
        porc /= 100;
        darken(p, lin, col, tom, porc, pointer);
        break;
    
    case 8:
        cout << "+------------------------------------------------+" << endl;
        cout << "| Informe a porcentagem da imagem a ser clareada |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cout << "|  0  |                  Sair                    |" << endl;
        cout << "+------------------------------------------------+" << endl;
        cin >> porc;
        if (porc == 0) return 0;
        while (porc < 0 || i > 100) {
            cout << "+---------------------------------+" << endl;
            cout << "|        Entrada Invalida         |" << endl;
            cout << "| O valor deve ser entre 0 e 100% |" << endl;
            cout << "|       Digite-o novamente        |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "|  0  |           Sair            |" << endl;
            cout << "+---------------------------------+" << endl;
            cin >> porc; 
            if (porc == 0) return 0;;
        }
        porc /= 100;
        whiten(p, lin, col, tom, porc, pointer);
        break;
    }
    return 0;
}