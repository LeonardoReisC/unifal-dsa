/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*           UNIFAL - Universidade Federal de Alfenas.
*             BACHARELADO EM CIENCIA DA COMPUTAÇAO.
* Trabalho..: Atividade 1
* Disciplina: Programacao
* Professor.: Luiz Eduardo da Silva
* Aluno.....: Leonardo Reis Coimbra
* Data......: 10/07/2021
-------------------------------------------------------------*/

#include <stdio.h>

int main (void)
{   
    /*----------------------------------------------------------------
    declaração de variáveis       
    ----------------------------------------------------------------*/                                                     
    int ID, IDMAIORIDADE = 0, IDMENORIDADE = 0, IDADE, IDADEMAIOR = 0, IDADEMENOR = 0, SOMAIDADE = 0, PESSOAS = 0, QTDEM = 0, QTDEF = 0, QTDEO = 0;
    char SEXO;
    float MEDIAIDADE;
    
    do {
        /*----------------------------------------------------------------
        leitura dos valores de entrada
        ----------------------------------------------------------------*/                                                                            
        scanf("%d %c %i", &ID, &SEXO, &IDADE);                          

        if (ID != 0 && SEXO != 'x' && IDADE != 0) {
            /*----------------------------------------------------------------
            somatório das idades dos pesquisados
            cálculo do número de pessoas
            ----------------------------------------------------------------*/
            SOMAIDADE += IDADE;                                         
            PESSOAS += 1;                                               

            /*----------------------------------------------------------------
            cálculo da quantidade de pessoas do sexo masculino, feminino e de
            outros não listados
            ----------------------------------------------------------------*/
            if (SEXO == 'm') {                           
                QTDEM += 1; 
            } else if (SEXO == 'f') {                    
                QTDEF += 1;
            } else {
                QTDEO += 1;                                             
            }    

            /*----------------------------------------------------------------
            seleção da maior idade entre os pesquisados e sua ID
            seleção da menor idade entre os pesquisas e sua ID
            ----------------------------------------------------------------*/
            if (IDADE > IDADEMAIOR) {                                   
                if (IDADEMAIOR <= IDADEMENOR){
                    IDADEMENOR = IDADEMAIOR;
                    if (IDMAIORIDADE < IDMENORIDADE) {
                        IDMENORIDADE = ID - 1;
                    }
                }
                IDADEMAIOR = IDADE;
                IDMAIORIDADE = ID;
            } else { 
                IDADEMENOR = IDADE;
                IDMENORIDADE = ID;
            }

        }
    }while (ID != 0 && SEXO != 'x' && IDADE != 0);
    
    /*----------------------------------------------------------------
    cálculo da média aritmética das idades dos pesquisados 
    ----------------------------------------------------------------*/
    MEDIAIDADE = (float)SOMAIDADE/PESSOAS;

    /*----------------------------------------------------------------
    tabulação das informações coletadas acima       
    ----------------------------------------------------------------*/
    puts("+------------------+--------+");
    printf("| Soma das idades  |%7.d |\n", SOMAIDADE);
    printf("| Total de pessoas |%7.d |\n", PESSOAS);
    printf("| Media de idades  |%7.1f |\n", MEDIAIDADE);
    printf("| Homens           |%7d |\n", QTDEM);
    printf("| Mulheres         |%7d |\n", QTDEF);
    printf("| Outros           |%7d |\n", QTDEO);
    printf("| Maior idade      |%7d |\n", IDADEMAIOR);
    printf("| ID do mais velho |%7d |\n", IDMAIORIDADE);
    printf("| Menor idade      |%7d |\n", IDADEMENOR);
    printf("| ID do mais novo  |%7d |\n", IDMENORIDADE);
    puts("+------------------+--------+");
    return 0;
}