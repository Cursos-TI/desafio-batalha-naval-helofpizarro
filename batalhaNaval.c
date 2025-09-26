#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
     char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int matriz[11][11] = {0};  // Zera tudo

    // Posicionar navio horizontal na linha 3, colunas 1, 2, 3
    matriz[3][1] = 3;
    matriz[3][2] = 3;
    matriz[3][3] = 3;

    // Posicionar navio vertical na coluna 4, linhas 4, 5, 6
    matriz[4][4] = 3;
    matriz[5][4] = 3;
    matriz[6][4] = 3;


    matriz[1][1] = 3;
    matriz[2][2] = 3;
    matriz[3][3] = 3;


    matriz[1][10] = 3;
    matriz[2][9]  = 3;
    matriz[3][8]  = 3;

    // Impressão da matriz com rótulos
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %c ", letras[j]);
    }
    printf("\n");

    for (int i = 1; i <= 10; i++) {
        printf("%2d ", i);
        for (int j = 1; j <= 10; j++) {
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}


#include <stdio.h>

#define TAM 11

int main() {
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[TAM][TAM] = {0};  // Tabuleiro 10x10 com borda extra para facilitar índices

    // ====== POSICIONA NAVIO (valor 1) ======
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][1] = 1;  // Navio vertical na coluna A (1)
    }

    // ====== CONE (valor 2) ======
    int centro_linha_cone = 2;
    int centro_coluna_cone = 5;
    for (int i = -1; i <= 1; i++) {
        for (int j = -2; j <= 2; j++) {
            int abs_i = i < 0 ? -i : i;
            int abs_j = j < 0 ? -j : j;
            if (abs_i + abs_j <= 2) {
                int linha = centro_linha_cone + i;
                int coluna = centro_coluna_cone + j;
                if (linha > 0 && linha < TAM && coluna > 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 2;
                    }
                }
            }
        }
    }

    // ====== OCTAEDRO (valor 3) ======
    int centro_linha_octa = 6;
    int centro_coluna_octa = 3;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int abs_i = i < 0 ? -i : i;
            int abs_j = j < 0 ? -j : j;
            if (abs_i + abs_j <= 1) {
                int linha = centro_linha_octa + i;
                int coluna = centro_coluna_octa + j;
                if (linha > 0 && linha < TAM && coluna > 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 3;
                    }
                }
            }
        }
    }

    // ====== CRUZ (valor 4) ======
    int centro_linha_cruz = 8;
    int centro_coluna_cruz = 8;
    for (int i = -1; i <= 1; i++) {
        for (int j = -2; j <= 2; j++) {
            if (i == 0 || j == 0) {
                int linha = centro_linha_cruz + i;
                int coluna = centro_coluna_cruz + j;
                if (linha > 0 && linha < TAM && coluna > 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 4;
                    }
                }
            }
        }
    }

    // ====== IMPRESSÃO DO TABULEIRO FINAL ======
    printf("\n=== TABULEIRO FINAL (sem sobreposição) ===\n");
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %c ", letras[j]);
    }
    printf("\n");

    for (int i = 1; i <= 10; i++) {
        printf("%2d ", i);
        for (int j = 1; j <= 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}