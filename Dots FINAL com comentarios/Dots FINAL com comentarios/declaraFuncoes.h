#ifndef DECLARAFUNCOES_H_INCLUDED
#define DECLARAFUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>

/// FUNÇOES UTILIZADAS

void start();
void Menu();
void opcoes();
void regras();
void perguntatamanho();
void perguntacor();
void MenuOrganiza();
void mudarCor(short n);
void imprimiRanking();
void gotoxy(int x, int y);
void imprimirtabela(int a);
int jogojogavel(int x, short c1, short c2);
void Dots(short cor1, short cor2, short tamanhotabela);
void D();
void DO();
void DOT();
void DOTSpalavra();
void formandoPALAVRAdots();
void bemvindo();
int APELACAO();

/// VARIAVEIS GLOBAIS

short menu;
char letraSeta;
short saitama;
int tamanhot;
short cores1;
short cores2;


#endif // DECLARAFUNCOES_H_INCLUDED
