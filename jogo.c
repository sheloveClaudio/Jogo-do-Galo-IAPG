//
// Created by Kayo on 06/12/2022.
//

#include <stdio.h>
#include "jogo.h"
#include "dadosjogadores.h"

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
    registarjogadores();
    gerartabuleiro(mat);
}