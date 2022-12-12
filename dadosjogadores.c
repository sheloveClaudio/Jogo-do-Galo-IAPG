//
// Created by Kayo on 08/12/2022.
//

#include "dadosjogadores.h"
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"



int numJogadores = 0;


void registarjogadores(JOGADORES vecJogadores_2[MAX_VECTOR]){

    JOGADORES j;
    printf("ID:");
    scanf("%d", &j.id);
    for (int i = 0; i < MAX_VECTOR; ++i) {
        if(vecJogadores_2[i].id == j.id){
            printf("Ja existe um jogador com esse ID!!\nInsira novamente: ");
            registarjogadores(vecJogadores_2);
        }
        else if (vecJogadores_2[i].id == 0){
            printf("Nome:");
            scanf("%s",&j.nome);
            printf("Apelido:");
            scanf("%s",&j.apelido);
            printf("Jogador registado com sucesso!\n");

            numJogadores++;
            vecJogadores_2[i] = j;
            jogadores_menu();
        }
    }
}
void apagarJogadores(JOGADORES vecJogadores_2[MAX_VECTOR]) {
    int idapagar;
    int verificarid = 0;

    JOGADORES vecJogadores_Aux[MAX_VECTOR];
    if (numJogadores > 0) {

        verJogadores(vecJogadores_2);
        printf("\n-x- Por favor insira o ID do jogador a apagar -x- \n");
        scanf("%d", &idapagar);
        for (int i = 0; i < MAX_VECTOR; ++i) {
            if (vecJogadores_2[i].id == idapagar) {
                verificarid++; // Verificar se o ID existe
            }
        }
        if (verificarid == 1) {
            for (int i = 0; i < MAX_VECTOR; ++i) {
                if (vecJogadores_2[i].id != idapagar) {
                    vecJogadores_Aux[i] = vecJogadores_2[i];
                } else {
                    for (int j = i; j < MAX_VECTOR; ++j) {
                        vecJogadores_Aux[j] = vecJogadores_2[j + 1]; // Passar os valores 1 para trás
                    }
                    numJogadores--;
                }
            }
            for (int k = 0; k < MAX_VECTOR; ++k) {  // Passar para o original
                vecJogadores_2[k] = vecJogadores_Aux[k];
            }
        } else {
            printf("\n-x- ID inexistente -x-\n");
            apagarJogadores(vecJogadores_2);
        }
    }
    jogadores_menu();
}

void verJogadores(JOGADORES vecJogadores_2[MAX_VECTOR]){
    printf("\nO numero total de jogadores e: %d",numJogadores);
    printf("\n -x- Jogadores -x- \n");
    for (int i = 0; i < numJogadores; i++) {
        printf("\nID: %d\nNome: %s %s\nEstatistica: V -> %d D -> %d\n", vecJogadores_2[i].id, vecJogadores_2[i].nome, vecJogadores_2[i].apelido, vecJogadores_2[i].vitorias, vecJogadores_2[i].derrotas);
    }
}

void carregarJogadores(JOGADORES vecJogadores[MAX_VECTOR]){
    int c;
    FILE *carregarJogadores;
    carregarJogadores = fopen("jogadores.txt", "r");
    if(carregarJogadores == NULL){
        printf("\n-x- O ficheiro jogardores.txt nao existe -x-\n");
        jogadores_menu();
    }
}