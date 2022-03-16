#include "declaraFuncoes.h"

void mudarCor(short n)
//DEFINE AS CORES (LITERALMENTE APLICANDO AS CORES) DOS JOGADORES, QUE FORAM ESCOLHIDAS NO VOID PERGUNTACOR
{
    switch (n)
    {
    case 0:
        system("color 0a");
        break;
    case 1:
        system("color 05");
        break;
    case 2:
        system("color 0d");
        break;
    case 3:
        system("color 09");
        break;
    case 4:
        system("color 0b");
        break;
    case 5:
        system("color 06");
        break;
    case 6:
        system("color 07");
        break;
    case 7:
        system("color 0f");
        break;
    }
}

void imprimiRanking()//IMPRESSAO DO RANKING
{
    char ch;
    FILE* rankg = fopen("ranking.txt", "r+");
    while((ch=fgetc(rankg))!= EOF )
    {
        putchar(ch);
    }
    fclose(rankg);
    printf("\n");
    system("pause");
}

void gotoxy(int x, int y)//MOVIMENTO DO JOGADOR/CURSOR NO TABULEIRO
{
    COORD coord;
    coord.Y = y;
    coord.X = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void imprimirtabela(int a)//IMPRESSAO DO TABULEIRO
{
    int i, j;
    for ( i=0; i<a; i++)
    {
        for ( j=0; j<a; j++)
        {
            printf("%c   ",254);
        }
        printf("\n\n");
    }

}

int jogojogavel(int x, short c1, short c2)
{
    bool achaponto = false;// SERA USADO COMO PERMIÇÃO PARA PASSAR A VEZ // É UMA SITUAÇÃO ESPECÍFICA
    int i, j; // VAIAVEIS DE CONTAR LOOP
    int newx = (x*2)-1;//NOVO TAMANHO DA TABELA. AGORA COM OS ESPAÇOS INCLUSOS
    int posimay = 0, posimax = 0;//VARIAVEIS QUE USAREMOS PARA SABER ONDE O JOGADOR ESTÁ
    char letrama; //SERÁ USADO PARA SALVAR AS TECLAS CLICADAS PELO JOGADOR
    bool manterloop = true;//QUANDO QUISERMOS QUEBRAR O LOOP INTERNO
    imprimirtabela(x); // IMPRIMIMOS A TABELA PARA QUE POSSAMOS COMEÇAR O JOGO. SÓ SERÁ NECESSÁRIO IMPRIMIR UMA VEZ
    int tabelabi[newx][newx]; //" TABELA BINARIA" É UMA TABELA QUE CORRESPONDE Á TABELA DO JOGO PRINCIPAL ("POR TRÁS DAS CORTINAS")
    int joga1 = 0, joga2 = 0, vez = 0; // VARIAVEIS DE PONTUAÇÃO DE CADA JOGADOR E PARA SABER DE QUEM É A VEZ
    for (i=0; i<newx; i++)
        // DEFININDO OS VALORES INICIAIS DA TABELA BINÁRIA
    {
        for (j=0; j<newx; j++)
        {
            if (i%2==0 && j%2==0)
            {
                tabelabi[i][j]= 1;// PONTOS
            }
            else
            {
                for (int c=0; c<newx; c++)
                {
                    tabelabi[i][j]=0;// ESPAÇOS
                }
            }
        }
    }
    gotoxy(0,0);
    while((joga1+joga2)<(x-1)*(x-1))// LOOP EXTERNO
    {
        //QUEBRA O LOOP EXTERNO QUANDO A SOMA DAS PONTUAÇÕES FOREM MAIOR OU IGUAL A PONTUAÇÃO MAX
        while(manterloop)// LOOP INTERNO
        {
            if(vez%2==0)//AQUI CHAMAREMOS A FUNÇÃO PRA MUDAR A COR DEPENDENDO DA VEZ
            {
                mudarCor(c1); // C1: RESPONSAVEL POR ARMAZENAR A COR DO JOGADOR 1
                vez = 0;
            }
            else
            {
                mudarCor(c2); // C2: RESPONSAVEL POR ARMAZENAR A COR DO JOGADOR 2
            }
            letrama = getch();
            switch(letrama)//ANALISE DO BOTAO SELECIONADO PELO JOGADOR
            {
            case 'w':
            case 'W':
            case 72:
                posimay --; // ATUALIZAMOS A POSIÇÃO DO JAGADOR EM RELAÇÃO AO EIXO Y
                break;
            case 's':
            case 'S':
            case 80:
                posimay ++;
                break;
            case 'a':
            case 'A':
            case 75:
                posimax --;// ATUALIZAMOS A POSIÇÃO DO JAGADOR EM RELAÇÃO AO EIXO X etc
                break;
            case 'd':
            case 'D':
            case 77:
                posimax ++;
                break;
            case 13:
            case 32:
                manterloop = false;//AO CLICAR EM ENTER OU ESPAÇO, QUEBRAREMOS O LOOP INTERNO PARA SEGUIR A PROGRAMAÇÃO
                break;
            case 27:
                manterloop = false;//SAI DO JOGO (ESC)// QUEBRAMOS O LOOP INTERNO E MAIS NA FRENTE QUEBRAREMOS DE NOVO PARA ASSIM SAIR
                break;
            }
//ESTABELECENDO OS LIMITES//////////////////////
            if (posimay<0)
            {
                posimay = newx-1;
            }
            else if (posimay>(newx-1))
            {
                posimay = 0;
            }
            if (posimax<0)
            {
                posimax = newx-1;
            }
            else if (posimax>(newx-1))
            {
                posimax = 0;
            }
            gotoxy(posimax*2,posimay);
        }
// FIM DO LOOP INTERNO///////////////////////////

        if (letrama==27) // SE O LOOP INTERNO FOI QUEBRADO PELA TECLA 27 (ESC) SAIMOS DO LOOP EXTERNO TAMBEM
        {
            break;
        }
//AQUI TEREMOS A IMPRESSAO DAS BARRAS E PONTOS DE ACORDO COM A POSICAO ATUAL DO JOGADOR//////////////
        if((posimax%2!=posimay%2) && tabelabi[posimay][posimax]==0)// MANEIRA DE CONFIRMAR QUE A IMPRESSÃO É VÁLIDA
        {
            if (posimax%2==0)
            {
                printf("|");
            }
            else
            {
                printf("-");
                gotoxy((posimax*2)-1,posimay);
                printf("-");
                gotoxy((posimax*2)+1,posimay);
                printf("-");
            }
            tabelabi[posimay][posimax] = 1;// APOS IMPRESSÃO VÁLIDA, CONFIRMAMOS NA TABELA BINÁRIA QUE HÁ ALGO ALI
            vez++; // PASSAMOS A VEZ
        }
        gotoxy(posimax*2,posimay); // APÓS IMPRIMIR, O CURSOR SE MOVE. ENTÃO TRAZEMOS ELE DE VOLTA A POSIÇÃO CORRETA
        manterloop = true; // AGORA, AO REINICIAR, O LOOP INTERNO PODE SE REPETIR

        for ( int i=0; i<newx; i++ )// PROCURANDO PONTOS
        {
            for ( int j=0; j<newx; j++ )
            {
                if(tabelabi[i-1][j]==1 && tabelabi[i-2][j-1]==1 && tabelabi[i-1][j-2]==1 && tabelabi[i][j-1]==1 && tabelabi[i-1][j-1]==0)
                    // CONDIÇÃO PARA PONTO VÁLIDO
                {
                    gotoxy((j-1)*2,i-1);// MANDA O CURSOR PARA A POSIÇÃO DO PONTO PARA IMPRIMIR 1 OU 2
                    if (vez%2==1)
                    {
                        printf("1");
                        joga1++;// ADCIONA 1 NA PONTUAÇÃO DO JOGADOR 1
                    }
                    else if(vez%2==0)
                    {
                        printf("2");// ADCIONA 1 NA PONTUAÇÃO DO JOGADOR 2
                        joga2++;
                    }
                    tabelabi[i-1][j-1]=1;// MOSTRA PRA TABELA BINÁRIA QUE AGORA HÁ ALGO ALÍ
                    gotoxy(posimax*2,posimay); // SEMPRE VOLTANDO A POSIÇÃO APÓS IMPRIMIR
                    achaponto = true; // AGORA É VALIDO PASSAR A VEZ. (EXPLICAREMOS MELHOR O CASO)
                }
            }
        }
        if (achaponto == true)// VALIDO PASSAR A VEZ
        {
            vez++;
            achaponto = false;
        }

    }// FIM DO LOOP EXTERNO
    // AGORA É O RETORNO DE VALORES
    if (letrama==27)// SE SAIU PELO ESC, RETORNA 0
    {
        return 0;
    }
    else
    {
        gotoxy(0,newx);// AJUSTAMOS A POSIÇÃO DO CURSOR PARA PODE IMPRIMIR AS SEGUINTES MENSAGENS
        if (joga1>joga2)// SE O JOGADOR 1 GANHOU
        {
            printf("\n\n     PARABENS \n JOGADOR 1 GANHOU\n");
            return joga1;
        }
        else if(joga1<joga2)// SE O JOGADOR 2 GANHOU
        {
            printf("\n\n     PARABENS \n JOGADOR 2 GANHOU\n");
            return joga2;
        }
        else// SE DEU EMPATE
        {
            printf("\n\n  PARABENS \n DEU EMPATE\n");
            Sleep(2000);
            system("cls");
            printf("\n\n JOGUE OUTRA VEZ\n");
            Sleep(1500);
            system("cls");
            return jogojogavel(x,c1,c2);// VC VAI SER "OBRIGAD0" A JOGAR NOVAMENTE
        }
    }

}

void Dots(short cor1, short cor2, short tamanhotabela)
{
    struct placar
    {
        char codnome[5];
        int pontos;
    } a;
    a.pontos = jogojogavel(tamanhotabela, cor1, cor2);
    if (a.pontos!=0)// SE O RETORNO FOI 0 (ESC), APENAS SEGUIREMOS NORMAL, SEM SALVAR NADA NO RANKING.
    {
        printf("\n\n\n INSIRA O CODNOME (no max 5 caracteres):");
        scanf("%s", &(a.codnome[0]));
        printf(" %s, sua pontuacao eh %i\n", a.codnome, a.pontos);

        FILE* ranarquivo = fopen("ranking.txt", "a");
        fprintf(ranarquivo, "%s|%d\n", &(a.codnome[0]), a.pontos);
        fclose(ranarquivo);
        system("pause");
    }
}
/* NA FUNÇÃO TIPO VOID, DOTS, NÓS CHAMAMOS E RODAMOS O JOGO EM SI, PEGANDO
OS POSSIVEIS RETORNOS E ARMAZENANDO EM "A", TIPO STRUCT PLACAR. PERGUNTAMOS
O CODNOME DO JOGADOR E MANDAMOS ESSAS INFORMAÇÕES PARA O RANKING,
ATUALIZANDO, ASSIM, O RANKING */



