//
// Created by claud on 06/12/2022.
//

#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "jogo.h"
#include <stdlib.h>
#include "dadosjogadores.h"

JOGADORES vecJogadores[MAX_VECTOR];


int menu() {
    int opcao = 0;
    while(true){
        printf("\n-x- Jogo do Galo -x-\n");
        inicio_menu();
        printf("\n-x- Escolha uma das opcoes -x-\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                limpar();
                jogar_menu();
                break;
            case 2:
                limpar();
                jogadores_menu();
                //Funcao de mostrar dados
                break;
            case 3:
                limpar();
                printf("-x- A salvar dados... -x-\n");
                //funcao de salvar
                break;
            case 4:
                limpar();
                printf("-x- A salvar dados... -x-\n");
                //funcao de salvar
                printf("-x- Ate a proxima! -x-\n");
                exit(0);
            case 5:
                limpar();
                tutorial();
                break;
            case 0:
                limpar();
                printf("-x- Ate a proxima! -x-");
                exit(0);
            default:
                limpar();
                printf("O numero inserido nao e valido!!\n");
                break;
        }
    }
}

void jogadores_menu() {
        int po = 0;
        printf("\n-x- Menu de Jogares -x-\n");
        jogares_menu2();
        printf("\n-x- Escolha uma das opcoes -x-\n");
        do {
            scanf("%d", &po);
            switch (po) {
                case 1:
                    registarjogadores(vecJogadores);
                    break;
                case 2:
                    limpar();
                    apagarJogadores(vecJogadores);
                    break;
                case 3:
                    limpar();
                    verJogadores(vecJogadores);
                    break;
                case 4:
                    carregarJogadores(vecJogadores);
                    break;
                case 0:
                    limpar();
                    menu();
                    break;
                default:
                    printf("O numero inserido nao e valido!!\n");
                    break;
            }
        } while (po != 0);
    }

void jogares_menu2() {
    printf("\n1 - Novo Jogador\n");
    printf("2 - Apagar Jogador\n");
    printf("3 - Lista de Jogadores\n");
    printf("4 - Carregar Jogadores\n");
    printf("0 - Regressar ao menu principal\n");
}

void tutorial() {
    int t ;
    printf("\n-x- Tutorial -x-\n");
    printf("\nNo Jogo do Galo o tabuleiro e composto por 9 quadrados vazios, alinhados em um tabuleiro 3x3. O objetivo do jogo e de   fazer 3 marcas proprias numa linha, coluna ou diagonal. Se o tabuleiro esta cheio mas nenhum jogador conseguiu chegar a este objetivo, entao o jogo termina empatado.\n\n0 - Voltar\n");
    printf("\n-x- Escolha uma das opcoes -x-\n");
    do{
    scanf("%d", &t);
        switch (t) {
            case 0:
                limpar();
                menu();
                break;
            default:
                printf("\nO numero inserido nao e valido!!\n");
                break;
        }
    }while(t!=0);
}



void jogar_menu() {
    int valor = 0;
    do{
        printf("\n -x- Jogar -x-\n");
        jogar_menu2();
        printf("\n-x- Escolha uma das opcoes -x-\n");
        scanf("%d",&valor);
        switch (valor) {
            case 1:
                jogo1v1(vecJogadores);
                break;
            case 2:
                jogo1vAI(vecJogadores);
                break;
            case 3:
                mostrarHistorico();
                break;
            case 0:
                limpar();
                printf("\n-x- A ir para o menu principal... -x-\n");
                menu();
                break;
            default:
                limpar();
                printf("O numero inserido nao e valido!!\n");
                break;
        }
    } while (valor!=0);
}


void jogar_menu2() {
    printf("\n1 - Jogar  Um vs Um\n");
    printf("2 - Jogar contra Computador\n");
    printf("0 - Voltar\n");
}

void inicio_menu() {
    printf("\n1 - Jogar\n");
    printf("2 - Menu de Jogadores\n");
    printf("3 - Salvar\n");
    printf("4 - Salvar e sair\n");
    printf("5 - Tutorial\n");
    printf("0 - Sair\n");
}