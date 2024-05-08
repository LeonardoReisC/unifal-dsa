/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−+
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTAÇAO.
* Trabalho..: Atividade 4
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Leonardo Reis Coimbra
* Data......: 08/09/2021
+------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

void isbn_dv(char vetor[10]) 
{   
    int i, w[9], w1[9], s1, s2, aux, soma;
    do {
        for (i = 0; i < 10; i++) {
            scanf("%c", &vetor[i]);
            w[i] = vetor[i] - 48;
            w1[i] = w[i];
            if (i != 0) {
                w1[i] += w1[i - 1];
            }
        }
        vetor[strlen(vetor) - 1] = '\0';
        s1 = w1[i - 2];
        for (i = 1; i < 9; i++) {
            w1[i] += w1[i - 1];
        }
        s2 = w1[i - 1];
        soma = s1 + s2;
        for (i = 0; i <= 10; i++) {
            if (!((s1 + s2) % 11) && (s1 + s2) != 0) {
                aux = i;
                for (i = 0; i < 9; i++) 
                    printf("%d", vetor[i] - 48);
                if ( aux != 10 ) {
                    printf("-%d\n", aux);
                } else
                    puts("-X\n");
                }
            s1++;
        }
    }   while (soma != 0);
}

int main(void) 
{
    char vetor[10];
    isbn_dv(vetor);
    return 0;
}