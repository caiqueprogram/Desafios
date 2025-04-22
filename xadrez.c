#include <stdio.h>

// Tabuleiro de xadrez: 8x8
#define TAM 8

// Converte coordenadas numéricas para letras (ex: 0 -> A)
char colunaToChar(int col) {
    return 'A' + col;
}

// Valida posição dentro do tabuleiro
int posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// ========== TORRE ==========
void moverTorreCima(int linha, int coluna, int passos) {
    if (passos == 0 || !posicaoValida(linha, coluna)) return;

    printf("Torre: %c%d -> ", colunaToChar(coluna), linha + 1);
    linha--;
    if (posicaoValida(linha, coluna))
        printf("%c%d (Cima)\n", colunaToChar(coluna), linha + 1);

    moverTorreCima(linha, coluna, passos - 1);
}

void moverTorreDireita(int linha, int coluna, int passos) {
    if (passos == 0 || !posicaoValida(linha, coluna)) return;

    printf("Torre: %c%d -> ", colunaToChar(coluna), linha + 1);
    coluna++;
    if (posicaoValida(linha, coluna))
        printf("%c%d (Direita)\n", colunaToChar(coluna), linha + 1);

    moverTorreDireita(linha, coluna, passos - 1);
}

// ========== BISPO ==========
void moverBispoDiagonalDireitaCima(int linha, int coluna, int passos) {
    if (passos == 0 || !posicaoValida(linha, coluna)) return;

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            printf("Bispo: %c%d -> ", colunaToChar(coluna), linha + 1);
            linha--;
            coluna++;
            if (posicaoValida(linha, coluna))
                printf("%c%d (Diagonal Superior Direita)\n", colunaToChar(coluna), linha + 1);
        }
    }
    moverBispoDiagonalDireitaCima(linha, coluna, passos - 1);
}

// ========== RAINHA ==========
void moverRainha(int linha, int coluna, int passos) {
    if (passos == 0 || !posicaoValida(linha, coluna)) return;

    printf("Rainha: %c%d -> ", colunaToChar(coluna), linha + 1);
    linha--;
    printf("%c%d (Cima)\n", colunaToChar(coluna), linha + 1);

    printf("Rainha: %c%d -> ", colunaToChar(coluna), linha + 1);
    coluna++;
    printf("%c%d (Direita)\n", colunaToChar(coluna), linha + 1);

    printf("Rainha: %c%d -> ", colunaToChar(coluna), linha + 1);
    linha++;
    coluna--;
    printf("%c%d (Diagonal Inferior Esquerda)\n", colunaToChar(coluna), linha + 1);

    moverRainha(linha, coluna, passos - 1);
}

// ========== CAVALO ==========
void moverCavalo(int linha, int coluna) {
    printf("Cavalo a partir de %c%d:\n", colunaToChar(coluna), linha + 1);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if ((i == linha - 2 && j == coluna + 1) ||
                (i == linha - 1 && j == coluna + 2)) {
                if (posicaoValida(i, j)) {
                    printf(" -> %c%d (L em cima-direita)\n", colunaToChar(j), i + 1);
                }
            }

            if (i + j > 10) break;
        }
    }
}

// ========== MAIN ==========
int main() {
    int linhaInicial = 4;  // E5 (linha 4, coluna 4)
    int colunaInicial = 4;
    int passos = 3;

    printf("=== MOVIMENTAÇÃO DA TORRE ===\n");
    moverTorreCima(linhaInicial, colunaInicial, passos);
    moverTorreDireita(linhaInicial, colunaInicial, passos);
    printf("\n");

    printf("=== MOVIMENTAÇÃO DO BISPO ===\n");
    moverBispoDiagonalDireitaCima(linhaInicial, colunaInicial, passos);
    printf("\n");

    printf("=== MOVIMENTAÇÃO DA RAINHA ===\n");
    moverRainha(linhaInicial, colunaInicial, passos);
    printf("\n");

    printf("=== MOVIMENTAÇÃO DO CAVALO ===\n");
    moverCavalo(linhaInicial, colunaInicial);
    printf("\n");

    return 0;
}
