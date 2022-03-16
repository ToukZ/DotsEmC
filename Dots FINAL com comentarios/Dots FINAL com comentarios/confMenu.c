#include "declaraFuncoes.h"
/// VARIÁVEIS GLOBAIS///
short menu = 0; // USADO PARA SABER ONDE O JOGADOR ESTA EM RELAÇÃO AO MENU
char letraSeta = 'z';
/*LETRA QUE O JOGADOR PRESSIONOU PARA SE MOVER NAS OPCOES.
IGUALAMOS A "Z" COMO FORMA DE IGUALAR A "ZERO" INICIALMENTE
O "LETRASETA" É USADO COM A MESMA FINALIDADE DE SEMPRE EM VÁRIAS FUNÇÕES*/
short saitama = 0;
/*VARIAVEL QUE INDICA QUAL EH A POSICAO DO JOGADOR COM AS SETAS.
NÓS VAMOS ATUALIZANDO COM ++ OU -- DEPENDENDO DO JOGADOR.
TEM A FUNÇÃO LITERAL DE SABER ONDE A SETA ESTÁ, PARA QUANDO CLICAR EM ENTER,
SABERMOS QUAL FOI A ESCOLHA DO JOGADOR E ASSIM REDIRECIONÁ-LO EM OUTRA FUNÇÃO.
O "SAITAMA" É USADO COM A MESMA FINALIDADE DE SEMPRE EM VÁRIAS FUNÇÕES*/
///"LETRASETA" E "SAITAMA" SÃO TIPO VARIAVEIS REUTILIZÁVEIS///
int tamanhot = 4;
/*TAMANHO DA TABELA TEM COMO TAMANHO PADRÃO 4. POR SER
UMA VARIAVEL GLOBAL, ESSE PADRÃO PODE SER ALTERADO EM QUALQUER MOMENTO */
short cores1 = 0;// COR DO JOGADOR 1
short cores2 = 1;// COR DO JOGADOR 2

///SEGUE NORMALMENTE AS FUNÇÕES///
void start()//TELA INICIAL
{
    bemvindo();
    formandoPALAVRAdots();
    printf("\n\n");
    system("pause");
    system("cls");
    menu = 1;// MODIFICAMOS A VARIAVEL GLOBAL MENU, ATUALIZANDO A POSIÇÃO DO JOGADOR
}

int APELACAO()
{
    letraSeta = 'z';
    saitama = 0;
    while(letraSeta!=13)// O LOOP QUEBRARAR QUANDO CLICAR ENTER
    {
        system("cls");
        printf("TEM CERTEZA DE QUE QUER SAIR??\n");
        switch (saitama)//IMPRESSAO DAS OPCOES DO JOGO E DO MOVIMENTO DAS SETAS
        {
        case 0:
            printf("--> SIM\n    NAO\n");
            break;
        case 1:
            printf("    SIM\n--> NAO\n");
            break;
        default:
            break;
        }
        letraSeta = getch();
        switch(letraSeta)// LIMITE E ANALISE DO BOTAO PRESSIONADO PELO JOGADOR
        {
        case 'w':
        case 'W':
        case 72:
            saitama--;// ATUALIZAMOD O "SAITAMA", OU SEJA, A POSIÇÃO DO JOGADOR
            if (saitama<0)// E AO MESMO TEMPO DEFINIMOS O LIMITE
            {
                saitama=1;
            }
            break;
        case 's':
        case 'S':
        case 80:
            saitama++;
            if (saitama>1)
            {
                saitama=0;
            }
            break;
        }

    }
    return saitama; //
    /*COMO NESSA SITUAÇÃO SÓ TEMOS SIM OU NAO, 0 OU 1,
    USAREMOS 0 PARA A PESSOA REALMENTE QUERER SAIR E 1
    PARA A PESSOA QUERER PERMANECER NO MENU*/
}


void Menu()//MENU PRINCIPAL DO JOGO
{
    int resultado = 0;/// USAREMOS PARA GUARDAR A RESPOSTA DE "APELACAO" MAIS TARDE
    while(letraSeta!=13)//IMPRESSAO DO MENU E MOVIMENTO DA SETA
    {
        system("cls");
        switch (saitama)
        {
        case 0:
            printf("--> Jogar\n    Opcoes\n    Ranking\n    Como Jogar\n    Sair");
            menu = 2;// SEMPRE ATUALIZAMOS PARA CASO CLIQUE ENTER, FICA O ULTIMO A SER SALVO
            break;
        case 1:
            printf("    Jogar\n--> Opcoes\n    Ranking\n    Como Jogar\n    Sair");
            menu = 3;
            break;
        case 2:
            printf("    Jogar\n    Opcoes\n--> Ranking\n    Como Jogar\n    Sair");
            menu = 4;
            break;
        case 3:
            printf("    Jogar\n    Opcoes\n    Ranking\n--> Como Jogar\n    Sair");
            menu = 5;
            break;
        case 4:
            printf("    Jogar\n    Opcoes\n    Ranking\n    Como Jogar\n--> Sair");
            break;
        default:
            break;
        }
        letraSeta = getch();
        switch(letraSeta)// LIMITE E ANALISE DO BOTAO PRESSIONADO PELO JOGADOR
        {
        case 'w':
        case 'W':
        case 72:
            saitama--;// ATUALIZAMOD O "SAITAMA", OU SEJA, A POSIÇÃO DO JOGADOR
            if (saitama<0)// E AO MESMO TEMPO DEFINIMOS O LIMITE
            {
                saitama=4;
            }
            break;
        case 's':
        case 'S':
        case 80:
            saitama++;
            if (saitama>4)
            {
                saitama=0;
            }
            break;
        }
    }// FIM DO LOOP
    if (saitama == 4)
    {
        resultado = APELACAO();
        if (resultado==0)
        {
            menu = 8;///USAREMOS COMO INFORMAÇÃO MAIS TARDE PARA ENCERRAR O PROGRAMA
        }
        else
        {
            menu = 1;
        }
    }
}

void opcoes()//OPCOES DO JOGO
{
    saitama = 0;// "SAITAMA É REINICIADO
    while(letraSeta!=13)// O LOOP QUEBRARAR QUANDO CLICAR ENTER
    {
        system("cls");
        switch (saitama)//IMPRESSAO DAS OPCOES DO JOGO E DO MOVIMENTO DAS SETAS
        {
        case 0:
            printf("--> Cor\n    Tamanho do Tabuleiro\n    Voltar ao Menu");
            menu = 6;
            break;
        case 1:
            printf("    Cor\n--> Tamanho do Tabuleiro\n    Voltar ao Menu");
            menu = 7;
            break;
        case 2:
            printf("    Cor\n    Tamanho do Tabuleiro\n--> Voltar ao Menu");
            menu = 1;
            break;
        default:
            break;
        }
        letraSeta = getch();
        switch(letraSeta)// LIMITE E ANALISE DO BOTAO PRESSIONADO PELO JOGADOR
        {
        case 'w':
        case 'W':
        case 72:
            saitama--;// ATUALIZAMOD O "SAITAMA", OU SEJA, A POSIÇÃO DO JOGADOR
            if (saitama<0)// E AO MESMO TEMPO DEFINIMOS O LIMITE
            {
                saitama=2;
            }
            break;
        case 's':
        case 'S':
        case 80:
            saitama++;
            if (saitama>2)
            {
                saitama=0;
            }
            break;
        }
    }
}

void regras()//IMPRESSÃO DAS REGRAS DO JOGO
{
    char ch, regras[]= "regras.txt";
    FILE *arq;
    arq = fopen(regras,"r+");
    if(arq == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo de regras\n");
        exit(-404);
    }
    else
        while( (ch=fgetc(arq))!= EOF )
        {
            putchar(ch);
        }
    fclose(arq);
    system("pause");
}

void perguntatamanho()
//MUDANÇA DO TAMANHO DA TABELA QUE OS JOGADORES DESEJAM SE SELECIONAR NAS OPCOES A OPCAO "TAMANHO DO TABULEIRO"
{
    printf("Digite o tamanho desejado da tabela.\n tabelas maiores fazem o jogo ser mais competitivo!\n Note tambem que tabelas impares terao quantidades de quadrados pares, permitindo empates!\n Tamanho Atual: %i x %i\nOBS:\nMinimo 3|Maximo 19\n\n", tamanhot,tamanhot);
    while(1)
    {
        fflush(stdin);
        scanf("%i", &tamanhot);
        if(tamanhot<=2 || tamanhot>=20)
        {
            printf("Tamanho Invalido de Tabela!\n Digite novamente\n");

        }
        else
        {
            break;
            ///O LOOP SÓ SERA QUEBRADO QUANDO OS VALORES COLOCADOS FOREM ACEITOS
        }
    }
    printf("SUAS DEFINICOES DE TABELA FORAM ATUALIZADAS...\n\n");
    Sleep(1000);
    printf("Novo tabuleiro: %i x %i\n\n", tamanhot,tamanhot);
    imprimirtabela(tamanhot);// MOSTRANDO AO JOGADOR O TAMANHO ATUAL DA TABELA
    system("pause");
}

void perguntacor()//MUDAR AS CORES DOS JOGADORES SE SELECIONAR NAS OPCOES A OPCAO "COR"
// VAMOS PERGUNTAR A NOVA COR E ATUALIZAR A VARIAVEL GLOBAL
{
    int contador;//CONTAR O FOR (USAMOS PARA DEFINIR A COR DO JOGADOR 1 E DEPOIS DO JOGADOR 2)
    for(contador=0; contador<2; contador++)
    {
        while(letraSeta!=13)// AO CLICAR ENTER, ESSE LOOP SERÁ QUEBRADO
        {
            if(contador%2==0)
            {
                printf("Cor do jogador 1\n");
                //CASO ESTEJAMOS NA VEZ DE ESCOLHER A COR DO JOGADOR 1
            }
            else
            {
                printf("Cor do jogador 2\n");
                //CASO ESTEJAMOS NA VEZ DE ESCOLHER A COR DO JOGADOR 2
            }

            switch (saitama)//IMPRESSAO DAS CORES DISPONIVEIS E MOVIMENTO DAS SETAS
                //SAITAMA SENDO USADO MAIS UMA VEZ
            {
            case 0:
                printf("--> Verde Claro\n    Roxo\n    Lilas\n    Azul Claro\n    Verde Piscina\n    Amarelo\n    Branco\n    Branco Brilhante\n");
                break;
            case 1:
                printf("    Verde Claro\n--> Roxo\n    Lilas\n    Azul Claro\n    Verde Piscina\n    Amarelo\n    Branco\n    Branco Brilhante\n");
                break;
            case 2:
                printf("    Verde Claro\n    Roxo\n--> Lilas\n    Azul Claro\n    Verde Piscina\n    Amarelo\n    Branco\n    Branco Brilhante\n");
                break;
            case 3:
                printf("    Verde Claro\n    Roxo\n    Lilas\n--> Azul Claro\n    Verde Piscina\n    Amarelo\n    Branco\n    Branco Brilhante\n");
                break;
            case 4:
                printf("    Verde Claro\n    Roxo\n    Lilas\n    Azul Claro\n--> Verde Piscina\n    Amarelo\n    Branco\n    Branco Brilhante\n");
                break;
            case 5:
                printf("    Verde Claro\n    Roxo\n    Lilas\n    Azul Claro\n    Verde Piscina\n--> Amarelo\n    Branco\n    Branco Brilhante\n");
                break;
            case 6:
                printf("    Verde Claro\n    Roxo\n    Lilas\n    Azul Claro\n    Verde Piscina\n    Amarelo\n--> Branco\n    Branco Brilhante\n");
                break;
            case 7:
                printf("    Verde Claro\n    Roxo\n    Lilas\n    Azul Claro\n    Verde Piscina\n    Amarelo\n    Branco\n--> Branco Brilhante\n");
                break;
            }
            letraSeta = getch();
            system("cls");
            switch(letraSeta)// LIMITE E ANALISE DO BOTAO PRESSIONADO PELO JOGADOR
            {
            case 'w':
            case 'W':
            case 72:
                saitama--;// ATUALIZAMOD O "SAITAMA", OU SEJA, A POSIÇÃO DO JOGADOR
                if (saitama<0)// E AO MESMO TEMPO DEFINIMOS O LIMITE
                {
                    saitama=7;
                }
                break;
            case 's':
            case 'S':
            case 80:
                saitama++;
                if (saitama>7)
                {
                    saitama=0;
                }
                break;
            }
        }// FIM DO LOOP
        letraSeta = 'z';// "ZERA" A VARIAVEL GLOBAL LETRA SETA
        if(contador%2==0)
        {
            cores1 = saitama;
            //CASO ESTEJAMOS NA VEZ DE ESCOLHER A COR DO JOGADOR 1, SALVAMOS O VALOR DE SAITAMA EM CORES1
        }
        else
        {
            cores2 = saitama;
            //CASO ESTEJAMOS NA VEZ DE ESCOLHER A COR DO JOGADOR 2, SALVAMOS O VALOR DE SAITAMA EM CORES2
        }
        system("cls");
        if((cores1==cores2)&& contador==1)// NÃO ACEITAREMOS CORES IGUAIS
        {
            printf("CORES IGUAIS?? NAO DA PRA JOGAR ASSIM\nEscolha novamente!\n");
            Sleep(1000);
            contador = -1;
            /*AQUI ZERAMOS O CONTADOR PARA QUE O JOGADOR ESCOLHA TUDO NOVAMNETE.
            MAS PORQUE RECEBER -1 E NÃO 0? POIS QUANDO REINICIAR O LOOP, POR SER
            UM FOR, O CONTADOR RECEBERAR ++, OU SEJA, TERÁ O VALOR DE 0.
            AGORA VAI REALMENTE REINICIAR O PROCESSSO*/
            system("pause");
            system("cls");

        }
    }// FIM DO FOR
}


void MenuOrganiza()//ORGANIZACAO DO MENU
//AQUI É A AREA QUE TEM FUNÇÃO DE FAZER O REDIRECIONAMENTO DO MENU
{
    mudarCor(0);///NÓS ESCOLHEMOS A COR 0 (VERDE CLARO) COMO COR PADRÃO
    while(menu!=8)
    {
        switch (menu)
        {
        case 0:
            start();//VOID QUE INICIA O PROGRAMA
            break;
        case 1:
            Menu();//VOID QUE CHAMA A PROGRAMACAO DO MENU
            break;
        case 2:
            Dots(cores1,cores2,tamanhot);//VOID QUE CONTEM O JOGO DOTS
            menu = 1;
            /*APOS ACABAR O JOGO, ATUALIZAMOS A VARIAVEL menu PARA 1,
            CORRESPONDENTE AO MENU (ONDE TEM OPÇÕES, RANKING ETC).
            AO REPETIR O LOOP LÁ DE CIMA, O NOVO VALOR DE menu É 1,
            LOGO, O JOGADOR SERÁ ENVIADO PARA A VOID MENU */
            mudarCor(0);
            /*VOLTAMOS PARA A COR PADRÃO. ISSO É NECESSARIO POIS
            DENTRO DA FUNÇÃO Dots, A COR DA TELA É ALTERADA
            VÁRIAS VEZES. DESSA FORMA, SEMPRE VOLTAMOS PARA A COR
            PADRÃO AO SAIR DO Dots*/
            break;
        case 3:
            opcoes();//VOID DAS OPCOES DE JOGO
            break;
        case 4:
            imprimiRanking();//VOID QUE IMPRIME O RANKING DOS JOGADORES
            menu = 1;//APÓS ACABAR A FUNÇÃO ANTERIOR, O JOGADOR RETORNARÁ PARA O MENU AO REINICIAR O LOOP
            break;
        case 5:
            regras();//VOID QUE CONTEM AS REGRAS DO JOGO
            menu = 1;//APÓS ACABAR A FUNÇÃO ANTERIOR, O JOGADOR RETORNARÁ PARA O MENU AO REINICIAR O LOOP
            break;
        case 6:
            perguntacor();//VOID QUE EH SELECIONADO NAS OPCOES, ONDE MUDA AS CORES DOS JOGADORES
            menu = 3;//APÓS ACABAR A FUNÇÃO ANTERIOR, O JOGADOR RETORNARÁ PARA O MENU AO REINICIAR O LOOP
            break;
        case 7:
            perguntatamanho();//VOID QUE EH SELECIONADO NAS OPCOES, ONDE MUDA O TAMANHO DO TABULEIRO
            menu = 3;//APÓS ACABAR A FUNÇÃO ANTERIOR, O JOGADOR RETORNARÁ PARA O MENU AO REINICIAR O LOOP
            break;
        }
        system("cls");// LIMPAR A TELA
        letraSeta = 'z';// "ZERAR" A INPUT DO TECLADO

    }// FIM DO LOOP.
    system("cls");
    printf("GAME OVER");
    Sleep(800);
}
