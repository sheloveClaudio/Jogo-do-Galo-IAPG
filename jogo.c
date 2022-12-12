//
// Created by Kayo on 06/12/2022.
//

#include <stdio.h>
#include "jogo.h"
#include "dadosjogadores.h"|


void gerartabuleiro(char mat[5][5]){
    for (int i = 0; i < 5; i = i+2) {
        for (int j = 1; j < 5; j= j +2) {
            mat[i][j] = '|';
        }
    }
    for (int i = 1; i < 5; i = i+2) {
        for (int j = 0; j < 5; j= j +2) {
            mat[i][j] = '-';
        }
    }
    for (int i = 1; i < 5; i = i+2) {
        for (int j = 1; j < 5; j= j +2) {
            mat[i][j] = '+';
        }
    }
    for (int i = 0; i < 5; i = i +2) {
        for (int j = 0; j < 5; j = j+2) {
            mat[i][j] = ' ';
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%c", mat[i][j]);
        }printf("\n");
    }
}



void jogo1v1() {
    char mat[5][5];
    if(numJogadores < 2){
        printf("\n-x- Nao existem jogares suficientes!! -x-\n-x- Pode inserir atraves do menu Jogadores -x-\n");
    }
    else{
        jogar1v1(mat);
    }
}

void jogar1v1(char mat[5][5]) {
    int vez = 0;
    limpartabuleiro(mat);
    printf("\n-x- Jogador 1 -> X -x-"); // Alterar para nome de jogador presente na struct
    printf("\n-x- Jogador 2 -> 0 -x-"); // Alterar para nome de jogador presente na struct
    do {
        limpar();
        gerartabuleiro(mat);
        jogada(mat,vez);
    }while(verificarTermino(mat) != 1);
}

int verificarTermino(char mat[5][5]) {

}

void limpartabuleiro(char mat[5][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            mat[i][j] = "  ";
        }
    }
}

void jogada(char mat[5][5], int vez){
    int linha, coluna;
    vez++;
    printf("\n -x- Jogador -> %d\n",(vez%2)+1);
    do {
        //Pergunta a linha para jogar
        printf("\n-x- Em que linha quer jogar? -x-\n");
        do {
            scanf("%d", &linha);
        }while (linha <= 0);
        if(linha == 1){
            linha = linha;
        }else{
         linha++;
        }
        // Pergunta a coluna para jogar
        printf("\n-x- Em que coluna quer jogar? -x-\n");
        scanf("%d",&coluna);
        if(coluna == 1){
            coluna = coluna;
        }else{
            coluna++;
        }
        if(verificaPosicao(mat, linha, coluna) != 1){
            printf("\n-x- Posicao nao valida para selecao!! -x-\n");
        }
    }while(verificaPosicao(mat, linha, coluna) != 1);
    if(vez == 1){
        mat[linha][coluna] = "X";
    }else{
        mat[linha][coluna] = "O";
    }
}

int verificaPosicao(char mat[5][5], int linha, int coluna){
    if(linha < 0 || coluna < 0 || coluna > 3 || linha > 3 || mat[linha][coluna] != "  "){
        return 0;
    }else{
        return 1;
    }
}

void limpar() {
    int cont;
    do {
        putchar("\n");
    } while (cont != 100);
}
