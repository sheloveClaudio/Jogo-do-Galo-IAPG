//
// Created by Kayo on 06/12/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "jogo.h"
#include "dadosjogadores.h"
#include "menu.h"

DADOS Dados[MAX_VECTOR];


int x, vez = 0;


void gerartabuleiro(char mat[x][x]){
    for (int i = 0; i < x; i = i+2) {
        for (int j = 1; j < x; j= j +2) {
            mat[i][j] = '|';
        }
    }

    for (int i = 1; i < x; i = i+2) {
        for (int j = 0; j < x; j= j +2) {
            mat[i][j] = '-';
        }
    }
    for (int i = 1; i < x; i = i+2) {
        for (int j = 1; j < x; j= j +2) {
            mat[i][j] = '+';
        }
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            printf("%c", mat[i][j]);
        }printf("\n");
    }
}

//A partir daqui jogo1vAI
//A partir daqui jogo1vAI
//A partir daqui jogo1vAI


void jogo1vAI(JOGADORES *vecJogadores){
    int n;
    printf("\n-x- Tamanho do tabuleiro? -x-\n");
    printf("-x- Minimo 3! -x-\n");
    scanf("%d",&n);
    x=n+(n-1);

    char mat[x][x];
    int id1,k=0;
    if(numJogadores<1){
        limpar();
        printf("\n-x- Nao existem jogadores suficientes!! -x-\n-x- Pode inserir atraves do menu Jogadores -x-\n");
    }else{
        printf("\n-x- Id do jogador -x-");
        do{
            scanf("%d",&id1);
            for (int i = 0; i < MAX_VECTOR; ++i) {
                if(id1==vecJogadores[i].id){
                    k = 1;
                }
            }
        }while(k!=1);
        jogar1vAI(mat,id1,vecJogadores,n);
    }
}

void jogar1vAI(char mat[x][x], int id1 ,JOGADORES *vecJogadores,int n){
    int inome1;
    limpartabuleiro(mat);
    inome1 = buscarNome(id1,vecJogadores);
    do {
        limpar();
        printf("\n-x- %s -> X -x-", vecJogadores[inome1].nome);
        printf("\n-x- AI -> O -x-\n\n");
        gerartabuleiro(mat);
        jogadavsAI(mat,vecJogadores,inome1,x);
    }while(verificarTerminoAI(mat,vecJogadores,inome1,n) != 1);
}

void jogadavsAI(char mat[x][x], JOGADORES *vecJogadores, int inome1){
    int linha, coluna;
    if((vez%2)+1==1){
        printf("\n -x- Vez de %s -x-\n",vecJogadores[inome1].nome);
    }else{
        printf("\n -x- Vez de AI -x-\n");
    }
    if(vez%2 == 0){
        do {
            //Pergunta a linha para jogar
            printf("\n-x- Em que linha quer jogar? -x-\n");
            do {
                scanf("%d", &linha);
            }while (linha <= 0);
            if(linha<4) {
                if (linha == 1) {
                    linha = linha - 1;
                } else {
                    if (linha % 2 != 0) {
                        linha++;
                    } else {
                        linha = linha;
                    }
                }
            }else{
                linha = 2 + linha + (linha-4);
            }
            // Pergunta a coluna para jogar
            printf("\n-x- Em que coluna quer jogar? -x-\n");
            scanf("%d",&coluna);
            if(coluna<4){
                if(coluna == 1){
                    coluna = coluna - 1;
                }else{
                    if(coluna%2 != 0) {
                        coluna++;
                    }else{
                        coluna = coluna;
                    }
                }
            }else{
                coluna = 2 + coluna + (coluna-4);
            }
            if(verificaPosicao(mat, linha, coluna) != 1){
                printf("\n-x- Posicao nao valida para selecao!! -x-\n");
            }
        }while(verificaPosicao(mat, linha, coluna) != 1);
    }else{
        jogadaAI(mat);
    }

    if(vez%2 == 0){
        mat[linha][coluna] = 'X';
    }
    vez++;
}

void jogadaAI(char mat[x][x]) {
    int linha, coluna;
    srand(time(0));
    do{
        linha = (rand() % (x - 0 + 1)) + 0;
        coluna = (rand() % (x - 0 + 1)) + 0;
    } while(verificaPosicao(mat, linha, coluna) != 1);
    mat[linha][coluna]= 'O';
}

int verificarTerminoAI(char mat[x][x], JOGADORES *vecJogadores, int inome1, int n) {
    if(verificarLinhaAI(mat,vecJogadores,inome1,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarColunaAI(mat,vecJogadores,inome1,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarDiagonalPrimariaAI(mat,vecJogadores,inome1,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarDiagonalSecundariaAI(mat,vecJogadores,inome1,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarEmpateAI(mat,vecJogadores,inome1,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
}
int verificarEmpateAI(char mat[x][x], JOGADORES *vecJogadores, int inome1, int n) {
    int cont=0;
    for (int i = 0; i <x ; i=i+2){
        for (int j = 0; j < x; j= j+2) {
            if(mat[i][j] != ' '){
                cont++;
            }
        }
    }
    if(cont == pow(n,2)){
        limpar();
        printf("Empate!\n\n");
        vecJogadores[inome1].empates++;
        return(1);
    }
}

int verificarDiagonalSecundariaAI(char mat[x][x], JOGADORES *vecJogadores, int inome1, int n){
    int cont_o = 0, cont_x = 0;
    for (int i = 0; i < x; i = i+2) {
        if (mat[i][x-1-i] == 'X') {
            cont_x++;
        } else if (mat[i][x-1-i] == 'O') {
            cont_o++;
        }
        if(n<4){
            if (cont_x == x - 2) {
                limpar();
                printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                vecJogadores[inome1].vitorias++;
                return (1);
            } else if (cont_o == x - 2) {
                limpar();
                printf("O vencedor e AI!\n\n");
                vecJogadores[inome1].derrotas++;
                return (1);
            }
        }else{
            if (cont_x == n) {
                limpar();
                printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                vecJogadores[inome1].vitorias++;
                return (1);
            } else if (cont_o == n) {
                limpar();
                printf("O vencedor e AI!\n\n");
                vecJogadores[inome1].derrotas++;
                return (1);
            }
        }
    }
}



int verificarColunaAI(char mat[x][x], JOGADORES *vecJogadores, int inome1, int n) {
    int cont, cont1;
    for (int i = 0; i < x; i = i+2) {
        cont=0;cont1=0;
        for (int j = 0; j < x; j = j+2) {
            // Mudar o valor de x quando é introduzido. Corro as linhas
            if (mat[j][i] == 'X') {
                cont++;
            } else if (mat[j][i] == 'O') {
                cont1++;
            }
            if(n<4){
                if (cont == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    return (1);
                } else if (cont1 == x - 2) {
                    limpar();
                    printf("O vencedor e AI!\n\n");
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }else{
                if (cont == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    return (1);
                } else if (cont1 == n) {
                    limpar();
                    printf("O vencedor e AI!\n\n");
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }
        }
    }
}
int verificarDiagonalPrimariaAI(char mat[x][x], JOGADORES *vecJogadores, int inome1, int n) {
    int cont_x = 0, cont_o = 0;
    for (int i = 0; i < x; i = i + 2) {
        for (int j = 0; j < x; j = j + 2) {
            if (i == j) {
                if (mat[i][j] == 'X') {
                    cont_x++;
                } else if (mat[i][j] == 'O') {
                    cont_o++;
                }
            }
            if(n<4){
                if (cont_x == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    return (1);
                } else if (cont_o == x - 2) {
                    limpar();
                    printf("O vencedor e AI!\n\n");
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }else{
                if (cont_x == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    return (1);
                } else if (cont_o == n) {
                    limpar();
                    printf("O vencedor e AI!\n\n");
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }
        }
    }
}



int verificarLinhaAI(char mat[x][x], JOGADORES *vecJogadores, int inome1, int n) {
    int cont, cont1;
    for (int i = 0; i < x; i = i+2) {
        cont = 0; cont1 = 0;
        for (int j = 0; j < x; j = j+2) {
            // Mudar o valor de x quando é introduzido. Corro as linhas
            if (mat[i][j] == 'X') {
                cont++;
            } else if (mat[i][j] == 'O') {
                cont1++;
            }
            if(n<4){
                if (cont == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    return (1);
                } else if (cont1 == x - 2) {
                    limpar();
                    printf("O vencedor e AI!\n\n");
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }else{
                if (cont == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    return (1);
                } else if (cont1 == n) {
                    limpar();
                    printf("O vencedor e AI!\n\n");
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }
        }
    }
}



// A partir daqui jogo 1v1
// A partir daqui jogo 1v1
// A partir daqui jogo 1v1


void jogo1v1(JOGADORES *vecJogadores) {
    int n;
    printf("\n-x- Tamanho do tabuleiro? -x-\n");
    printf("-x- Minimo 3! -x-\n");
    scanf("%d",&n);
    x=n+(n-1);
    char mat[x][x];
    int id1,id2;
    if(numJogadores < 2){
        limpar();
        printf("\n-x- Nao existem jogadores suficientes!! -x-\n-x- Pode inserir atraves do menu Jogadores -x-\n");
    }
    else{
        printf("\n-x- Id do primeiro jogador -x-");
        scanf("%d",&id1);
        do{
        printf("\n-x- Id do segundo jogador -x-");
        scanf("%d",&id2);
        } while (id1==id2);
        jogar1v1(mat,id1,id2,vecJogadores,n);
    }
}

void jogar1v1(char mat[x][x], int id1, int id2,JOGADORES *vecJogadores, int n) {
    int inome1, inome2;
    limpartabuleiro(mat);
    inome1 = buscarNome(id1,vecJogadores);
    inome2 = buscarNome(id2,vecJogadores);
    do {
        limpar();
        printf("\n-x- %s -> X -x-", vecJogadores[inome1].nome);
        printf("\n-x- %s -> O -x-\n\n", vecJogadores[inome2].nome);
        gerartabuleiro(mat);
        jogada(mat,vecJogadores,inome1,inome2);
    }while(verificarTermino(mat,vecJogadores,inome1,inome2, n) != 1);
}

int buscarNome(int id, JOGADORES *vecJogadores) {
    for (int i = 0; i < MAX_VECTOR; ++i) {
        if (vecJogadores[i].id == id){
            return i;
        }
    }
}

int verificarTermino(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2, int n) {
    if(verificarLinha(mat,vecJogadores,inome1,inome2, n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarColuna(mat,vecJogadores,inome1,inome2,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarDiagonalPrimaria(mat,vecJogadores,inome1,inome2,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarDiagonalSecundaria(mat,vecJogadores,inome1,inome2,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
    if(verificarEmpate(mat,vecJogadores,inome1,inome2,n) == 1){
        gerartabuleiro(mat);
        putchar('\n');
        return(1);
    }
}

int verificarEmpate(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2, int n) {
    int cont=0;
    for (int i = 0; i <x ; i=i+2){
        for (int j = 0; j < x; j= j+2) {
            if(mat[i][j] != ' '){
                cont++;
            }
        }
    }
    if(cont == pow(n,2)){
        limpar();
        printf("Empate!\n\n");
        vecJogadores[inome1].empates++;
        vecJogadores[inome2].empates++;
        return(1);
    }
}

int verificarDiagonalSecundaria(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2, int n){
    int cont_o = 0, cont_x = 0;
    for (int i = 0; i < x; i = i+2) {
        if (mat[i][x-1-i] == 'X') {
            cont_x++;
        } else if (mat[i][x-1-i] == 'O') {
            cont_o++;
        }
        if(n<4){
            if (cont_x == x - 2) {
                limpar();
                printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                vecJogadores[inome1].vitorias++;
                vecJogadores[inome2].derrotas++;
                return (1);
            } else if (cont_o == x - 2) {
                limpar();
                printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                vecJogadores[inome2].vitorias++;
                vecJogadores[inome1].derrotas++;
                return (1);
            }
        }else{
            if (cont_x == n) {
                limpar();
                printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                vecJogadores[inome1].vitorias++;
                vecJogadores[inome2].derrotas++;
                return (1);
            } else if (cont_o == n) {
                limpar();
                printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                vecJogadores[inome2].vitorias++;
                vecJogadores[inome1].derrotas++;
            }
        }
    }
}



int verificarColuna(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2, int n) {
    int cont, cont1;
    for (int i = 0; i < x; i = i+2) {
        cont = 0; cont1 = 0;
        for (int j = 0; j < x; j = j+2) {
            // Mudar o valor de x quando é introduzido. Corro as linhas
            if (mat[j][i] == 'X') {
                cont++;
            } else if (mat[j][i] == 'O') {
                cont1++;
            }
            if(n<4){
                if (cont == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    vecJogadores[inome2].derrotas++;
                    return (1);
                } else if (cont1 == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                    vecJogadores[inome2].vitorias++;
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }else{
                if (cont == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    vecJogadores[inome2].derrotas++;
                    return (1);
                } else if (cont1 == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                    vecJogadores[inome2].vitorias++;
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }
        }
    }
}
int verificarDiagonalPrimaria(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2, int n) {
    int cont_x = 0, cont_o = 0;

    for (int i = 0; i < x; i = i + 2) {
        for (int j = 0; j < x; j = j + 2) {
            if (i == j) {
                if (mat[i][j] == 'X') {
                    cont_x++;
                } else if (mat[i][j] == 'O') {
                    cont_o++;
                }
            }
            if(n<4){
                if (cont_x == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    vecJogadores[inome2].derrotas++;
                    return (1);
                } else if (cont_o == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                    vecJogadores[inome2].vitorias++;
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }else{
                if (cont_x == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    vecJogadores[inome2].derrotas++;
                    return (1);
                } else if (cont_o == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                    vecJogadores[inome2].vitorias++;
                    vecJogadores[inome1].derrotas++;
                }
            }
        }
    }
}



int verificarLinha(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2, int n) {
    int cont, cont1;
    for (int i = 0; i < x; i = i+2) {
        cont = 0; cont1 = 0;
        for (int j = 0; j < x; j = j+2) {
            // Mudar o valor de x quando é introduzido. Corro as linhas
            if (mat[i][j] == 'X') {
                cont++;
            } else if (mat[i][j] == 'O') {
                cont1++;
            }
            if(n<4){
                if (cont == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    vecJogadores[inome2].derrotas++;
                    return (1);
                } else if (cont1 == x - 2) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                    vecJogadores[inome2].vitorias++;
                    vecJogadores[inome1].derrotas++;
                    return (1);
                }
            }else{
                if (cont == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome1].nome);
                    vecJogadores[inome1].vitorias++;
                    vecJogadores[inome2].derrotas++;
                    return (1);
                } else if (cont1 == n) {
                    limpar();
                    printf("O vencedor e %s!\n\n", vecJogadores[inome2].nome);
                    vecJogadores[inome2].vitorias++;
                    vecJogadores[inome1].derrotas++;
                }
            }
        }
    }
}

void limpartabuleiro(char mat[x][x]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            mat[i][j] = ' ';
        }
    }
}

void jogada(char mat[x][x], JOGADORES *vecJogadores, int inome1, int inome2){
    int linha, coluna;
    if((vez%2)+1==1){
        printf("\n -x- Vez de %s -x-\n",vecJogadores[inome1].nome);
    }else{
        printf("\n -x- Vez de %s -x-\n",vecJogadores[inome2].nome);
    }
    do {
        //Pergunta a linha para jogar
        printf("\n-x- Em que linha quer jogar? -x-\n");
        do {
            scanf("%d", &linha);
        }while (linha <= 0);
            if(linha == 1){
                linha = linha - 1;
            }else{
                if(linha%2 != 0){
                    linha++;
                }else{
                    linha = linha;
                }
            }
        // Pergunta a coluna para jogar
        printf("\n-x- Em que coluna quer jogar? -x-\n");
        scanf("%d",&coluna);
            if(coluna == 1){
                coluna = coluna - 1;
            }else{
                if(coluna%2 != 0) {
                    coluna++;
                }else{
                    coluna = coluna;
                }
            }
        if(verificaPosicao(mat, linha, coluna) != 1){
            printf("\n-x- Posicao nao valida para selecao!! -x-\n");
        }
    }while(verificaPosicao(mat, linha, coluna) != 1);
    if(vez%2 == 0){
        mat[linha][coluna] = 'X';
    }else{
        mat[linha][coluna] = 'O';
    }
    vez++;
}

void registaJogadamatriz(JOGADORES *vecJogadores, int inome1, int inome2, int linha, int coluna, DADOS *Dados,int vez){
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {

        }
    }
}

void registaJogada(JOGADORES *vecJogadores, int inome1, int inome2, int linha, int coluna, DADOS Dados[MAX_VECTOR],int vez) {
    char dados_x[5] = "(x)";
    char dados_o[5] = "(o)";
    char dadox[5] = "x";
    char dadoo[5] = "o";
    char linhas[5];
    char colunas[5];
    char nome[MAX_VECTOR];
    char nome1[MAX_VECTOR];
    sprintf(linhas,"%d",linha);
    sprintf(colunas, "%d", coluna);
    strcpy(nome,vecJogadores[inome1].nome);
    strcpy(nome1,vecJogadores[inome2].nome);
    for (int i = 0; i < MAX_VECTOR; ++i) {
         if (Dados[i].dados != '-'){
             strcat(nome,dados_x);
             strcat(nome1,dados_o);
             strcat(nome,nome1);
             if(vez%2 == 0){
                 strcat(linhas,colunas);
                 strcat(dadox,linhas);
                 strcat(nome,dadox);
             }else{
                 strcat(linhas,colunas);
                 strcat(dadoo,linhas);
                 strcat(nome,dadoo);
             }
             strcat('-',nome);
             strcpy(Dados[i].dados,nome);
        }
    }
}

int verificaPosicao(char mat[x][x], int linha, int coluna){
    if(linha < 0 || coluna < 0 || coluna > x || linha > x || mat[linha][coluna] != ' '){
        return 0;
    }else{
        return 1;
    }
}

void limpar() {
    int cont = 0;
    do {
        putchar('.\n');
        cont++;
    } while (cont != 100);
}