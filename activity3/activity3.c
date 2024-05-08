/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTAÇAO.
* Trabalho..: Atividade 3
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Leonardo Reis Coimbra
* Data......: 26/08/2021
+------------------------------------------------------------*/

#include <stdio.h>

void leSudoku(int n, int sudoku[16][16]) 
{
    char s[2];
    int i, j, dim = n * n;
    for  (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            scanf("%s", s);
            if (s[0] >= '1' && s[0] <= '9')
                sudoku[i][j] = s[0] - '0';
            if (s[0] >= 'A' && s[0] <= 'G')
                sudoku[i][j] = s[0] - 'A' + 10;
        }
    }
}

void imprimeLinha(int n) 
{
    int i, j;
    for (i = 0; i < n; i++) {
        printf("+");
        for  (j = 0; j < n; j++)
            printf("---");
    }
    printf("+\n");
}

void imprimeSudoku(int n, int sudoku[16][16])
{
    int i, j, dim = n * n;
    imprimeLinha(n);
    for ( i = 0; i < dim; i++) {
        printf("|");
        for (j = 0; j < dim; j++){
            int num = sudoku[i][j];
            if (num <= 9)
                printf("%2d ", num);
            else   
                printf("%2c ", num - 10 + 'A');
            if ((j + 1) % n == 0)
                printf("|");
        }
        printf("\n");
        if ((i + 1) % n == 0)
            imprimeLinha(n);
    }
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
* Função que testa uma solução da Sudoku
* Parâmetros:
*   n = dimensão das regiões
*   sudoku - jogo preenchido
*   lin - linha do erro (se houver)
*   col - coluna do erro (se houver)
* Retorna:
*   1 - se a matriz é uma solução do sudoku
*   0 - caso contrário, modificando os parâmetros 
*       lin e col para indicar a linha e coluna onde 
*       foi detectado o problema.
+------------------------------------------------------------*/
int sudokuOk(int n, int sudoku[16][16], int *lin, int *col)
{   
    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
    * Declaração de variáveis:
    * i = coordenada-linha que fixa o elemento para a comparação.
    * j = coordenada-coluna que fixa o elemento para a comparação.
    * l = coordenada-linha que varia e seleciona o elemento para
    *     comparar com o sujeito fixo por i e j.
    * k = coordenada-coluna que varia e seleciona o elemento para
    *     comparar com o sujeito fixo por i e j.
    * faixai = valor dado à partição dos blocos no eixo de i.
    * faixaj = valor dado à partição dos blocos no eixo de j.
    +------------------------------------------------------------*/
    int i = 0, j = 0, k, l, faixai = 1, faixaj = 1, dim = n * n;
    for (i = 0; i < dim; i++) {
        if (i == n * faixai) 
            faixai++;
        for (j = 0; j < dim; j++) {
            if (j == n * faixaj)
                faixaj++;
            /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
            * Comparação do elemento(i,j) com os outros do bloco em que    
            * ele pertence.
            +------------------------------------------------------------*/
            for (l = n * (faixai - 1); l < n * faixai; l++) {   
                for (k = n * (faixaj - 1); k < n * faixaj; k++) {
                    if (sudoku[l][k] == sudoku[i][j] && (k != j || l != i)) {
                        *col = k;
                        *lin = l;
                        return 0;
                    }
                }
            }
            /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
            * Comparação do elemento (i,j) com os outros da linha em que
            * ele pertence.
            +------------------------------------------------------------*/
            for (k = 0; k < dim; k++) {
                if (sudoku[i][k] == sudoku[i][j] && k != j) {
                    *col = k;
                    *lin = i;
                    return 0;
                }
            }
            /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
            * Comparação do elemento(i,j) com os outros da coluna em que
            * ele pertence.
            +------------------------------------------------------------*/
            for (l = 0; l < dim; l++) {
                if (sudoku[l][j] == sudoku[i][j] && l != i) {
                    *lin = l;
                    *col = j;
                    return 0;
                }
            }
        }
        faixaj = 0;
    }
    return 1;
}

int main(void)
{
    int n, nlin, ncol, ok;
    int sudoku[16][16];
    scanf("%d", &n);
    leSudoku(n, sudoku);
    imprimeSudoku(n, sudoku);
    ok = sudokuOk(n, sudoku, &nlin, &ncol);
    if (ok)
        puts("Sudoku Ok!");
    else
        printf("Erro na posicao (%d, %d)\n", nlin, ncol);
    return 0;
}