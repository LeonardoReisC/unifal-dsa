/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTAÇAO.
* Trabalho..: Atividade 2
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Leonardo Reis Coimbra
* Data......: 30/07/2021
+------------------------------------------------------------*/

#include <stdio.h>

int main(void)
{
    int i, j, piso[20][20];
    for (i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            piso[i][j] = 0;
    }   }
    /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
    * declaração de variáveis
    * inicialização da posição, direção e sentido da tartaruga
    +------------------------------------------------------------*/
    int caneta = 0, n, sentido = 1, auxi, auxj;
    char comando, direcao = 'h';
    i = 0, j = 0;
    
    do
    {   
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * leitura do comando
        +------------------------------------------------------------*/
        scanf("%c", &comando);
        switch(comando) {
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * definição dos movimentos da caneta          
        * caneta = 1 ---> Caneta abaixada
        * caneta = 0 ---> Caneta levantada            
        +------------------------------------------------------------*/
        case 'u': 
            caneta = 0;
            break;
        case 'd':
            caneta = 1;
            break;
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * declaração da direção e sentido da tartaruga         
        * direção = h ---> Direção horizontal
        * direção = v ---> Direção vertical
        * sentido = 1 ---> Sentido para a direita(h)/baixo(v)
        * sentido = 0 ---> Sentido para a esquerda(h)/cima(v)
        +------------------------------------------------------------*/
        case 'r': 
            if (direcao == 'h') {
                direcao = 'v';

            } else {
                direcao = 'h';
                if (sentido == 1) {
                    sentido = 0;
                } else {
                    sentido = 1;
            }   }
            break;
        case 'l':
            if (direcao == 'h') {
                direcao = 'v';
                if (sentido == 1) {
                    sentido = 0;
                } else {
                    sentido = 1;
                }
            } else {
                direcao = 'h';
            }
            break;
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * descrição do deslocamento da tartaruga
        * leva em conta o valor de caneta, direcao e sentido
        +------------------------------------------------------------*/        
        case 'w':
            scanf("%d", &n);
            if (direcao == 'h') {
                if (sentido == 1) {             //deslocamento para a direita
                    n += j;
                    for (; j < n; j++) {
                        if (caneta == 1){
                            piso[i][j] = 1;
                        } else {
                            piso[i][j] = 0;
                    }   }
                    j -= 1;
                } else {                        // deslocamento para a esquerda
                    n -= j;
                    for (; j > -n; j--) {
                        if (caneta == 1){
                            piso[i][j] = 1;
                        } else {
                            piso[i][j] = 0;
                    }   }
                    j += 1;
                }
            } else {                            
                if (sentido == 1) {             //deslocamento para baixo
                    n += i;
                    for (; i < n; i++) {
                        if (caneta == 1){
                            piso[i][j] = 1;
                        } else {
                            piso[i][j] = 0;
                    }   }
                    i -= 1;
                } else {                        //deslocamento para cima
                    n -= i;
                    for (; i > -n; i--) {
                        if (caneta == 1){
                            piso[i][j] = 1;
                        } else {
                            piso[i][j] = 0;
                    }   }
                    i += 1;
            }   }
            break;
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * descrição do comando de exposição da matriz alterada por
        símbolos
        +------------------------------------------------------------*/
        case 'p':
            auxi = i;
            auxj = j;
            for (j = 65; j < 85; j++) {
                printf("%2c", j);
            }
            puts("");
            for (i = 0; i < 20; i++) {
                for (j = 0; j < 20; j++) {
                    if (piso[i][j] == 1 || piso[i][j] == '*') {
                        piso [i][j] = '*';
                    } else {
                        piso[i][j] = '.';
                    }
                    printf("%2c", piso[i][j]);
                }
                printf("  %-d", i + 1);
                puts("");
            }
            i = auxi;
            j = auxj;
            break;
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * criação do comando "status" cujo objetivo é mostrar os 
        status tartaruga
        +------------------------------------------------------------*/
        case 's':
            if (caneta == 1) {                                          //atual posição da caneta
                puts("A caneta da tartaruga esta para baixo!");
            } else {
                puts("A caneta da tartaruga esta para cima!");
            }
            if (direcao == 'h' && sentido == 1) {                       //atual direção e sentido
                puts("A tartaruga esta apontada para a direita!");
            } else if (direcao == 'h' && sentido == 0){
                puts("A tartaruga esta apontada para a esquerda!");
            } else if (direcao == 'v' && sentido == 1) {
                puts("A tartaruga esta apontada para baixo!");
            } else if (direcao == 'v' && sentido == 0) {
                puts("A tartaruga esta apontada para cima!");           //atual coordenada da tartaruga
            }
            printf("A tartaruga esta na coordenada (%d, %c)\n", i + 1, j + 65);
            break;
        /*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
        * elaboração do comando "travel" cuja função é transportar a
        tartaruga para as coordenadas(i,j) desejada
        +------------------------------------------------------------*/
        case 't':
            puts("Digite as coordenadas de i e J que voce quer levar a tartaruga: ");
            scanf("%d %c", &i, &j);
            while (i > 20 || i < 1 || j > 84 || j < 65) {
                puts("Entrada invalida");
                puts("Informe valores validos de i(1-20) e de j(A-T)");
                scanf("%d %c", &i, &j);
            }
            printf("Ding dong! A tartaruga desembarcou em seu destino --> (%d, %c)\n", i, j);
            i -= 1;
            j -= 65;
            break;
        }
    } while (comando != 'e');
    puts("+------------------------------------+");
    puts("|\t\tTartaruga            |\n|'Obrigado por me levar para passear'|\n|\t\tAte mais!! <3        |");
    puts("+------------------------------------+");
    return 0;
}