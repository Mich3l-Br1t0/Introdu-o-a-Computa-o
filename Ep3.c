/***************************************************************/
/**                                                           **/
/**   Michel Trindade de Sousa Brito          NUSP:11257755   **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Alair do Lago                                **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MMAX 90
#define NMAX 90


void inicio_tabela(int n){
    int C, cont_tracejado;
    printf("    ");
    for(C = 1; C <= n; C++){
        if(C > 9){
            printf(" %d", C);
        }
        else
            printf("  %d", C);
    }
    printf("\n   +");
    for(cont_tracejado = 0; cont_tracejado < n*3; cont_tracejado++){
        printf("-");
    }
    printf("-+\n");

}
void fim_tabela(int n){
    int C, cont_tracejado;
    printf("   +");
    for(cont_tracejado = 0; cont_tracejado < n*3; cont_tracejado++){
        printf("-");
    }
    printf("-+\n");
        printf("    ");
    for(C = 1; C <= n; C++){
        if(C > 9){
            printf(" %d", C);
        }
        else
            printf("  %d", C);
    }
    printf("\n");
}

int main()
{
    char comando;
    int MM [MMAX][NMAX] = {{0}}; /*Matriz q guarda os pontos e as marcacoes*/
    int MA [MMAX][NMAX] = {{0}};/*Matriz de atributos 0 = fechado e desmarcado 1 = aberto 2 = fechado e marcado*/
    int T [MMAX][NMAX] = {{0}};
    int m, n, z, s, numero, minas, j_linha, j_coluna, marcacoes, casas_fechadas;
    int i, j, C, L;
    printf("De o numero de linhas do tabuleiro do jogo: ");
    scanf("%d", &m);
    printf("De o numero de coluna do tabuleiro do jogo: ");
    scanf("%d", &n);
    printf("De o numero de minas: ");
    scanf("%d", &z);
    printf("De um numero: ");
    scanf("%d", &s);
    while (m < 3 || m > 90){
        if (m < 3 || m > 90){
            printf("O valor de linhas nao esta entre 3 e 90, por favor digite um valor neste intervalo: ");
            scanf("%d", &m);
        }
    }
    while (n < 3 || n > 90){
        if (n < 3 || n > 90){
            printf("O valor de colunas nao esta entre 3 e 90, por favor digite um valor neste intervalo: ");
            scanf("%d", &n);
        }
    }
    while (z < 1 || z > m*n - 1){
        if (z < 1 || z > m*n - 1){
            printf("O valor de minas nao esta entre 1 e %d, por favor digite um valor neste intervalo: ", m*n -1);
            scanf("%d", &z);
        }
    }

    srand(s);
    /*Atribuicao das minas*/
    for(minas = 0; minas < z; minas++){
        numero = rand();
        i = numero % m + 1;/*linha*/
        j = (numero / m) % n + 1;/*coluna*/
        if(T [i][j] != -1){
            T [i][j] = -1;
        }
        else
            minas--;
    }
    /*checagem das casa adjacentes as minas*/
    for (L = 1; L <= m; L++){
        for(C = 1; C <= n; C++){
            if(T[L][C] == -1){
                if(T[L - 1][C - 1] != -1)
                    T[L - 1][C - 1] ++;
                if(T[L - 1][C] != -1)
                    T[L - 1][C] ++;
                if(T[L - 1][C + 1] != -1)
                    T[L - 1][C + 1] ++;
                if(T[L][C - 1] != -1)
                    T[L][C - 1] ++;
                if(T[L][C + 1] != -1)
                    T[L][C + 1] ++;
                if(T[L + 1][C - 1] != -1)
                    T[L + 1][C - 1] ++;
                if(T[L + 1][C] != -1)
                    T[L + 1][C] ++;
                if(T[L + 1][C + 1] != -1)
                    T[L + 1][C + 1] ++;
            }
        }
    }
    /*inicio do jogo*/
    printf("\nNumero de linhas (3 <= m <= 90): %d\n"
            "Numero de colunas (3 <= n <= 90): %d\n"
            "Numero de minas (1 <= z <= %d): %d\n"
            "Semente (1 <= s <= 12345): %d\n"
            "\nBem vindo ao Caca-Minas!\n\n",m, n,m*n - 1, z, s);
    /*inicio da montagem da tabela*/
    inicio_tabela(n);
    for(L = 1; L <= m; L++){
        if(L > 9){
            printf("%d |", L);
        }
        else
            printf("%d  |", L);
        for(C = 1; C <= n; C++){
            MM[L][C] = 46;/*MM se torna uma matriz de "pontos", por isso o uso do 46*/
            printf("  %c", MM[L][C]);
        }
        printf(" | %d\n", L);
    }
    fim_tabela(n);
    marcacoes = 0;
    casas_fechadas = m*n;
    while(casas_fechadas != m*n - z){
        printf("\nProximo chute: ");
        scanf(" %c %d %d", &comando, &j_linha, &j_coluna);
        printf("\n");
        /*tranforma letras minusculas em maisculas*/
        if(comando == 'a' || comando == 'm' || comando == 'd')
            comando = comando - 32;
        if(comando == 'A'){
            if( MA[j_linha][j_coluna] == 1 || j_linha > m || j_coluna > n || j_linha < 0 || j_coluna < 0)
                printf("Sem efeito.\n");
            if(MA[j_linha][j_coluna] == 0 || MA[j_linha][j_coluna] == 2){
                if (T[j_linha][j_coluna] == -1){
                    printf("BOOOOM! Voce acaba de pisar numa mina !\n\n");
                    inicio_tabela(n);
                    for(L = 1; L <= m; L++){
                        if(L > 9){
                            printf("%d |", L);
                        }
                        else
                            printf("%d  |", L);
                        for(C = 1; C <= n; C++){
                            if(T[L][C] == -1){
                                printf("  @");
                            }
                        else
                            printf("  %d", T[L][C]);
                        }
                    printf(" | %d\n", L);
                    }
                    fim_tabela(n);
                    break;
                }
                /*se a casa escolhida possuir valor de zero na matriz T*/
                if(T[j_linha][j_coluna] == 0 || j_linha > 0 || j_coluna > 0 || j_linha <= m || j_coluna <= m){
                    MA[j_linha][j_coluna] = 1;
                    /*abertura das casas adjacentes*/
                    for(L =  1; L <= m; L++){
                        for(C = 1; C <= n; C++){
                            if(MA[L][C] == 1 && T[L][C] == 0){
                                MA[L - 1][C - 1] = 1;
                                MA[L - 1][C] = 1;
                                MA[L - 1][C + 1] = 1;
                                MA[L][C - 1] = 1;
                                MA[L][C + 1] = 1;
                                MA[L + 1][C - 1] = 1;
                                MA[L + 1][C] = 1;
                                MA[L + 1][C + 1] = 1;
                            }
                        }
                    }
                    for(L = m; L >= 1; L--){
                        for(C = n; C >= 1; C--){
                            if(MA[L][C] == 1 && T[L][C] == 0){
                                MA[L - 1][C - 1] = 1;
                                MA[L - 1][C] = 1;
                                MA[L - 1][C + 1] = 1;
                                MA[L][C - 1] = 1;
                                MA[L][C + 1] = 1;
                                MA[L + 1][C - 1] = 1;
                                MA[L + 1][C] = 1;
                                MA[L + 1][C + 1] = 1;
                            }
                        }
                    }
                    /*contagem casas abertas*/
                    for(L = 1; L <= m; L++){
                        for(C = 1; C <= n; C++){
                            if(MA[L][C] == 1)
                                casas_fechadas--;
                        }
                    }
                }
                /*caso o palpite abra uma casa com valor > 0*/
                if(T[j_linha][j_coluna] > 0){
                    casas_fechadas--;
                    MA[j_linha][j_coluna] = 1;
                }
                /*Em caso de vitoria*/
                if(casas_fechadas - z == 0){
                    printf("Parabens!!! Voce ganhou o jogo sem explodir nenhuma mina\n\n");
                    inicio_tabela(n);
                    for(L = 1; L <= m; L++){
                        if(L > 9){
                            printf("%d |", L);
                        }
                        else
                            printf("%d  |", L);
                        for(C = 1; C <= n; C++){
                            if(T[L][C] == -1){
                                printf("  @");
                            }
                        else
                            printf("  %d", T[L][C]);
                        }
                    printf(" | %d\n", L);
                    }
                    fim_tabela(n);
                    break;
                }
                printf("Por enquanto: %d/%d marcadas, %d livres\n\n", marcacoes, z, casas_fechadas);
                inicio_tabela(n);
                for(L = 1; L <= m; L++){
                    if(L > 9){
                        printf("%d |", L);
                    }
                    else
                        printf("%d  |", L);
                    for(C = 1; C <= n; C++){
                        if(MA[L][C] == 1){
                            printf("  %d", T[L][C]);
                        }
                        else
                            printf("  %c", MM[L][C]);
                    }
                printf(" | %d\n", L);
                }
                fim_tabela(n);
            }
        }
        if(comando == 'M'){
            if(MA[j_linha][j_coluna] == 1 || MA[j_linha][j_coluna] == 2 || marcacoes == z || j_linha > m || j_coluna > n || j_linha < 0 || j_coluna < 0)
                printf("Sem efeito.\n");
            if(marcacoes != z){
                marcacoes++;
                printf("Por enquanto: %d/%d marcadas, %d livres\n\n", marcacoes, z, casas_fechadas);
                inicio_tabela(n);
                for(L = 1; L <= m; L++){
                    if(L > 9){
                        printf("%d |", L);
                    }
                    else
                        printf("%d  |", L);
                    for(C = 1; C <= n; C++){
                        if(C == j_coluna && L == j_linha){
                            MA[j_linha][j_coluna] = 2; /*casa marcada e fechada*/
                            MM[j_linha][j_coluna] = 42; /*42 esta relacionado ao caracter */
                        }
                        if(MA[L][C] == 1){
                            printf("  %d", T[L][C]);
                        }
                        else
                            printf("  %c", MM[L][C]);
                    }
                    printf(" | %d\n", L);
                }
                fim_tabela(n);
            }
        }
        if(comando == 'D'){
            if(MA[j_linha][j_coluna] == 1|| MA[j_linha][j_coluna] == 0|| marcacoes == 0 || j_linha > m || j_coluna > n || j_linha < 0 || j_coluna < 0)
                printf("Sem efeito.\n");
            if(marcacoes != 0){
                marcacoes--;
                printf("Por enquanto: %d/%d marcadas, %d livres\n\n", marcacoes, z, casas_fechadas);
                inicio_tabela(n);
                for(L = 1; L <= m; L++){
                    if(L > 9){
                        printf("%d |", L);
                    }
                    else
                        printf("%d  |", L);
                    for(C = 1; C <= n; C++){
                        if(C == j_coluna && L == j_linha){
                            MA[j_linha][j_coluna] = 0; /*Matriz de atributos recebe 0, fechada e desmarcada*/
                            MM[j_linha][j_coluna] = 46; /*46 esta relacionado ao caracter .*/
                        }
                        if(MA[L][C] == 1){
                            printf("  %d", T[L][C]);
                        }
                        else
                            printf("  %c", MM[L][C]);
                    }
                    printf(" | %d\n", L);
                }
                fim_tabela(n);
            }
        }
    }
    return 0;
}
