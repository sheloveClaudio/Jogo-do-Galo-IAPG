//
// Created by Kayo on 08/12/2022.
//

#ifndef MAIN_C_DADOSJOGADORES_H
#define MAIN_C_DADOSJOGADORES_H

#define MAX_VECTOR 50 // Tamanho maximo dos nomes

void registarjogadores();
void apagarJogadores();
void verJogadores();
void carregarJogadores();

extern int numJogadores;


typedef struct dadosjogadores{
    int id;
    int vitorias; // Resgistar no fim de cada jogo
    int derrotas;   // Registar no fim de cada jogo
    int empates; // Registar no fim de cada jogo
    char nome[MAX_VECTOR];  // Escrever no inico do jogo
    char apelido[MAX_VECTOR]; // Escrever no inico do jogo
    char historico[MAX_VECTOR];

}JOGADORES;


#endif //MAIN_C_DADOSJOGADORES_H
