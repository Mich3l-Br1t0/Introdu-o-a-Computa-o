/***************************************************************/
/**                                                           **/
/**   Michel Trindade de Sousa Brito          NUSP:11257755   **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair do Lago                                **/
/**   Turma: 01                                               **/
/**                                                           **/
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int k, c, i, max, acerto, senha, pal, a, s, p, old, palor, t;
    /* t (numero de tentativas)
       a (numero de divisoes)
       pal (palpite)
       s e p sao os restos da divisao de senha e palpite
       old (senha original)
    */

    printf("\n \tJogo Megasenha (Mastermind)\n");
    printf("Digite o numero de pinos que serao usados na composicao da senha: ");
    scanf("%d", &k);

    printf("Digite um numero maximo de tentativas: ");
    scanf("%d", &max);

    printf("Digite um numero, de 1 a 9, que representara as cores da senha: ");
    scanf("%d", &c);

    printf("Entre com a senha de %d digitos (0 para valor aleatorio): ", k);
    scanf("%d",&senha);
    /* aqui onde o numero aleatorio e gerado*/
    if (senha == 0)
    {
        srand(time(NULL));
        for (i=0; i<k; i++)
        senha = senha*10 + (rand() % c + 1);
    }
    old = senha;/* lembrar a senha original para ser usado no final do codigo*/
    for (t = 1; t <= max; t++)
    {
    printf("Digite seu palpite: ");
    scanf("%d", &palor);
    acerto = 0;
    senha = old;
    pal = palor;
        for(a = 1; a <= k; a++)
            {
            s = senha % 10;
            p = pal % 10;
            senha = senha / 10;
            pal = pal / 10;
            if (s == p)
                {
                acerto++;
                }
            }
    printf("%d pretos\n", acerto);
    if (acerto == k)
        {
        printf("Parabens ! Voce acertou a senha em %d tentativas", t);
        break;
        }
    }
    if (t > max)
        {
        printf("Sinto muito ! Voce excedeu o numero de tentativas, a senha correta era %d", old);
        }
    return 0;
}
