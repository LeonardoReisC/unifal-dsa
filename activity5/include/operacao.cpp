#include <iostream>
#include <fstream>
#include "operacao.h"

using namespace std;

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−---------------------------------------−−--+
| Função chamada dentro das outras funções que imprime a matriz resultado |
|                      em um arquivo de saída "Imagem"                    |
+------------------------------------------------------------------------*/
void write_file(int *r, int lin, int col, int tom, string ext) {
    int i, j;
    ext = "saida/imagem.pgm" + ext;
    ofstream arq2;
    arq2.open(ext);
    if (arq2.is_open()) {
        arq2 << "P2\n";
        arq2 << col << " " << lin << "\n";
        arq2 << tom << "\n";
        for (i = 0; i < lin; i++) {
            for (j = 0; j < col; j++) {
                arq2 << *r << " ";
                r++;
            }
            arq2 << "\n";
        }
        arq2.close();
    } else {
        cout << "Unable to open file";
    }
}

/*−−−−−−−−−−−−−−−−−−---------−−−−−−−−−−--+
| Inversão negativa da imagem de entrada |
+---------------------------------------*/
void inv_neg(int *q, int lin, int col, int tom, string ext) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            *q = tom - *q;
            q++;
        }
    }
    q -= (lin * col);
    write_file(q, lin, col, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------+
|      Inversão vertical da imagem de entrada       |
| $ Processo:                                       |
| . é criado uma variável de ponteiro para a mesma  |
|   matriz "m", passada por parâmetro em "*q",      |
|   aonde "q" e "s" percorrem as linhas em colunas  |
|   opostas da matriz até que se chegue à metade    |
|   da coluna da matriz, determinada pela sequência |
|                da variável inteira i              |
+--------------------------------------------------*/

void inv_vert(int *q, int lin, int col, int tom, string ext) {
    int *s = NULL, i, j, aux;
    s = q; 
    s += (col - 1);
    for (i = 0; i < col/2; i++, q -= (lin * col - 1), s -= (lin * col + 1))             {
        for (j = 0; j < lin; j++, q += col, s += col) {
            aux = *s;
            *s = *q;
            *q = aux;
        }   
    }
    q -= col/2;
    write_file(q, lin, col, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−-------------------+
|     Inversão horizontal da imagem de entrada      |
| $ Processo:                                       |
| . é criado uma variável de ponteiro para a mesma  |
|   matriz "m", passada por parâmetro em "*q",      |
|   aonde "q" e "s" percorrem as colunas em linhas  |
|   opostas da matriz até que se chegue à metade    |
|   da linha da matriz, determinada pela sequência  |
|                da variável inteira i              |
+--------------------------------------------------*/

void inv_horiz(int *q, int lin, int col, int tom, string ext) {
    int *s = NULL, i, j, aux;
    s = q;
    s += col*(lin - 1);
    for (i = 0; i < lin/2; i++, s -= 2*col) {
        for (j = 0; j < col; j++, q++, s++) {
            aux = *s;
            *s = *q;
            *q = aux;
        }
    }
    q -= col*(lin/2);
    write_file(q, lin, col, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−---−−−--------------------+
|        Rotação da imagem de entrada à direita         |
| $ Processo:                                           |
| . é criado uma outra matriz "n" na qual, ao passo     |
|   que é apontada pela variável "s", recebe os         |
|   valores de "*q" que é percorrido verticalmente para |   
|   cima sendo o último elemento da primeira coluna o   | 
|                    ponto de origem                    |
+------------------------------------------------------*/
void right_rot(int *q, int lin, int col, int tom, string ext) {
    int *s = NULL, i, j, n[col][lin];
    s = &n[0][0];
    q += col*(lin - 1);
    for (i = 0; i < col; i++, q += lin * col + 1) {
        for (j = 0; j < lin; j++, q -= col, s++) {
            *s = *q;
        }
    }
    s -= lin * col;
    write_file(s, col, lin, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−---−−−--------------------+
|        Rotação da imagem de entrada à direita         |
| $ Processo:                                           |
| . é criado uma outra matriz "n" na qual, ao passo     |
|   que é apontada pela variável "s", recebe os         |
|   valores de "*q" que é percorrido verticalmente para |   
|   baixo sendo o primeiro elemento da ultima coluna o  | 
|                    ponto de origem                    |
+------------------------------------------------------*/

void left_rot(int *q, int lin, int col, int tom, string ext) {
    int *s = NULL, i, j, n[col][lin];
    s = &n[0][0];
    q += col - 1;
    for (i = 0; i < col; i++, q -= (lin * col + 1)) {
        for (j = 0; j < lin; j++, q += col, s++) {
            *s = *q;
        }
    }
    s -= (lin *col);
    write_file(s, col, lin, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−---−−−---------------------+
|      Escurecimento de bordas da imagem de entrada      |
| $ Processo:                                            |
| . é criado uma outra matriz "n" na qual, ao passo      |
|   que é apontada pela variável "s", recebe  os valores |
|   de "*q" subtraído do fator. A cada ciclo, a área de  |
|   "n" diminui e transcreve os valores previamente      |
|             preenchidos da região interna              |
+-------------------------------------------------------*/

void darken_edge(int *q, int lin, int col, int tom, int fator, int taxa, string ext) {
    int *s = NULL, n[lin][col], i, j, k = 0;
    s = &n[0][0];
    do {
        for (i = 0; i < lin - k; i++, q += k, s += k) {
            for (j = 0; j < col - k; j++, q++, s++) {
                if (*q < fator) {
                    *s = 0;
                } else *s = *q - fator;    
            }
        }
        q -= col*(lin - k - 1) - 1;
        s -= col*(lin - k - 1) - 1;
        k += 2;
        fator -= 10;
    } while ((lin - k != -1) && (lin - k != 0) && (col - k != -1) && (col - k != 0) && (fator > 0));
    s = &n[0][0];
    write_file(s, lin, col, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−---−−−----------------------+
|  Escurimento parcial ou completo da imagem de entrada   |
| $ Processo:                                             |
| . os pixels da imagem que são determinados pelos        |
|   elementos da matriz imagem são escurecidos em         |
|   (porc * 100)% à medida que é passado para a imagem de |
|       saída somente (1 - porc) do valor do pixel        |      
+--------------------------------------------------------*/
void darken(int *q, int lin, int col, int tom, float porc, string ext) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++, q++) {
            *q *= (1 - porc);
        }
    }
    q -= lin * col;
    write_file(q, lin, col, tom, ext);
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−---−−−----------------------+
|   Clareamento parcial ou completo da imagem de entrada  |
| $ Processo:                                             |
| . os pixels da imagem que são determinados pelos        |
|   elementos da matriz imagem são clareadoss em          |
|   (porc * 100)% à medida que é passado para a imagem de |
|       saída somente (1 + porc) do valor do pixel        |      
+--------------------------------------------------------*/

void whiten(int *q, int lin, int col, int tom, float porc, string ext) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++, q++) {
            *q *= (1 + porc);
            if (*q > tom) 
                *q = tom;
        }
    }
    q -= lin * col;
    write_file(q, lin, col, tom, ext);
}