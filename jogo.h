//
// Created by Kayo on 06/12/2022.
//

#ifndef MAIN_C_JOGO_H
#define MAIN_C_JOGO_H

void jogo1v1();
void jogo1vAI();
void gerartabuleiro();
void jogar1v1();
void jogar1vAI();
void limpar();
void jogada(); // playerXplayer
void jogadavsAI(); // playerXbot
void jogadaAI(); // playerXbot
int verificaPosicao();
void limpartabuleiro();
void registaJogadamatriz();
void mostrarHistorico();
int perguntaTamanho();
//chamar nome
int buscarNome();

//Verificação playerXplayer

int verificarTermino();
int verificarLinha();
int verificarColuna();
int verificarDiagonalPrimaria();
int verificarDiagonalSecundaria();
int verificarEmpate();

//Verificação playerXai

int verificarTerminoAI();
int verificarLinhaAI();
int verificarColunaAI();
int verificarDiagonalPrimariaAI();
int verificarDiagonalSecundariaAI();
int verificarEmpateAI();

typedef struct dadosjogo{
    int id;
    int matrizdados[100][100];
    char nome[100];
    char letra[10];
}DADOS;

#endif //MAIN_C_JOGO_H
