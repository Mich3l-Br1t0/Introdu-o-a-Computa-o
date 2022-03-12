/***************************************************************/
/**                                                           **/
/**   Michel Trindade de Sousa Brito          NUSP:11257755   **/
/**   Exercício-Programa 02                                   **/
/**   Professor: Alair do Lago                                **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#define exp 0.00000001/* 10 elevado a menos 8*/

/*Declaracao das variveis
Algumas sao definidas aqui pois pelo fato de serem variaveis globais
ja recebem 0, e isso sera util mais a frente*/
double caixa;
double pontosjogador, pontosbanca;
int desempatejogador, desempatebanca;
double derrotas;

/*Declaracao das funcoes*/
double module(double x){/*Funcao usada na funcao Raiz Cubica*/
    if(x < 0){
    x = -x;
    }
    return x;
}
double RaizCubica(double x){
double r = x, i = x + 1, rant = 1;
    if(x != 0 && x > 0){
        while (module(r - i) > exp){
        r = ((double)2/3*rant)+(x/(3*rant*rant));
        i = rant;
        rant = r;
        }

    }
    return r;
}
int chao(double x){/*funcao devolve um numero inteiro*/
return (int)x;
}
double NovaCaixa (double x){
double rifa;
rifa = 9821.0 * RaizCubica(x) + 0.211327;
caixa = rifa - chao( rifa );
return caixa;
}

int main(){

    int simulacoes, contador, ponto;
    double teto, carta, semente;

    printf("Digite uma semente: ");
    scanf("%lf", &semente);
    caixa = semente;
    while (caixa >= 1 ){/*caixa é transformada em um numero decimal < 1*/
        caixa = caixa/10;
    }
    for(teto = 0.5; teto <= 7.5; teto = teto + 0.5){
        for(simulacoes = 0; simulacoes < 10000; simulacoes ++){
            /*jogada jogador*/
            while (pontosjogador < teto){
                carta = chao( caixa*10 + 1 );                /*sorteio das cartas, e caso ela esteja entre 8 e 10*/
                if(carta == 8 || carta == 9 || carta == 10){               /*recebe o valor 0.5*/
                    carta = 0.5;
                }
                pontosjogador = carta + pontosjogador;
                caixa = NovaCaixa(caixa);
                desempatejogador ++;
            }
            /*condicao para banca jogar*/
            if (pontosjogador <= 7.5){
                /*inicio da jogada da banca*/
                while(pontosbanca < pontosjogador){
                    carta = chao( caixa*10 + 1 );
                    if(carta == 8 || carta == 9 || carta == 10){
                        carta = 0.5;
                    }
                    pontosbanca = carta + pontosbanca;
                    caixa = NovaCaixa(caixa);
                    desempatebanca ++;
                }
                /*analise dos pontos para determinar se a banca perdeu ou nao*/
                if(pontosjogador > pontosbanca || pontosbanca > 7.5){
                    derrotas ++;
                }
                if (pontosjogador == pontosbanca && desempatebanca < desempatejogador){
                    derrotas ++;
                }
            }
            pontosbanca = pontosjogador = desempatebanca = desempatejogador = 0;/*variaveis precisam ser zeradas para
        fim rodada                                                                 nao dar conflito na proxima rodada*/
        }
            printf("\n %.1f  %5.0f ", teto, derrotas);
            /*aqui é onde o "grafico" é gerado*/
            ponto = chao( 100*(derrotas/10000) + 0.5 );
            for (contador = 0; contador < ponto; contador ++){
                printf("*");
            }
    derrotas = 0;/*zerada para no dar conflito no proximo teto*/
    }/*fim teto*/
    printf("\n");/*Apenas estético, para que ao fim do programa, as mensagens apareçam apos o fim do grafico de 7.5*/
    return 0;
}
