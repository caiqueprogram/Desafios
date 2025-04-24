#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Exemplo de navios
    tabuleiro[2][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[8][1] = 3;
}

void criarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE/2 - i && j <= TAM_HABILIDADE/2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void criarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE/2) + abs(j - TAM_HABILIDADE/2) <= TAM_HABILIDADE/2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemX, int origemY) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tabX = origemX - TAM_HABILIDADE / 2 + i;
            int tabY = origemY - TAM_HABILIDADE / 2 + j;
            if (tabX >= 0 && tabX < TAM_TABULEIRO && tabY >= 0 && tabY < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[tabX][tabY] != 3)
                    tabuleiro[tabX][tabY] = 5;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }
}

void turnoComputador(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                     int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE],
                     int matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE],
                     int matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int habilidade = rand() % 3 + 1;
    int linha = rand() % TAM_TABULEIRO;
    int coluna = rand() % TAM_TABULEIRO;

    printf("\n[Computador] aplicando habilidade %d na posição (%d, %d)\n", habilidade, linha, coluna);

    if (habilidade == 1)
        aplicarHabilidade(tabuleiro, matrizCone, linha, coluna);
    else if (habilidade == 2)
        aplicarHabilidade(tabuleiro, matrizCruz, linha, coluna);
    else if (habilidade == 3)
        aplicarHabilidade(tabuleiro, matrizOctaedro, linha, coluna);
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int matrizCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int matrizOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    srand(time(NULL));

    inicializarTabuleiro(tabuleiro);
    criarMatrizCone(matrizCone);
    criarMatrizCruz(matrizCruz);
    criarMatrizOctaedro(matrizOctaedro);

    int escolha, linha, coluna;

    while (1) {
        // limpar tela (opcional)
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        exibirTabuleiro(tabuleiro);

        printf("\n--- SEU TURNO ---\n");
        printf("1 - Cone\n2 - Cruz\n3 - Octaedro\n0 - Sair\n");
        printf("Escolha sua habilidade: ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Jogo encerrado!\n");
            break;
        }

        printf("Linha (0 a 9): ");
        scanf("%d", &linha);
        printf("Coluna (0 a 9): ");
        scanf("%d", &coluna);

        if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
            printf("Coordenadas inválidas!\n");
            continue;
        }

        if (escolha == 1)
            aplicarHabilidade(tabuleiro, matrizCone, linha, coluna);
        else if (escolha == 2)
            aplicarHabilidade(tabuleiro, matrizCruz, linha, coluna);
        else if (escolha == 3)
            aplicarHabilidade(tabuleiro, matrizOctaedro, linha, coluna);
        else {
            printf("Habilidade inválida!\n");
            continue;
        }

        // Turno do computador
        turnoComputador(tabuleiro, matrizCone, matrizCruz, matrizOctaedro);
    }

    return 0;
}
