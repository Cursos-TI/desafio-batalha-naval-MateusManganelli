#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int x_vertical = 2, y_vertical = 3; // Coordenada inicial do navio vertical
    int x_horizontal = 5, y_horizontal = 6; // Coordenada inicial do navio horizontal
    int x_diagonal1 = 1, y_diagonal1 = 1; // Coordenada inicial do primeiro navio diagonal
    int x_diagonal2 = 7, y_diagonal2 = 7; // Coordenada inicial do segundo navio diagonal
    
    // Posiciona o navio verticalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_vertical + i][y_vertical] = 1;
    }
    
    // Posiciona o navio horizontalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_horizontal][y_horizontal + i] = 2;
    }
    
    // Posiciona o navio diagonalmente (")
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_diagonal1 + i][y_diagonal1 + i] = 3;
    }
    
    // Posiciona o navio diagonalmente (/)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_diagonal2 - i][y_diagonal2 + i] = 3;
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, char tipo) {
    if (tipo == 'C') { // Habilidade Cone
        int cone[3][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (cone[i][j] == 1 && x + i < TAMANHO_TABULEIRO && y - 2 + j >= 0 && y - 2 + j < TAMANHO_TABULEIRO) {
                    tabuleiro[x + i][y - 2 + j] = 1;
                }
            }
        }
    } else if (tipo == 'O') { // Habilidade Octaedro
        int octaedro[3][5] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (octaedro[i][j] == 1 && x + i < TAMANHO_TABULEIRO && y - 2 + j >= 0 && y - 2 + j < TAMANHO_TABULEIRO) {
                    tabuleiro[x + i][y - 2 + j] = 1;
                }
            }
        }
    } else if (tipo == 'X') { // Habilidade Cruz
        int cruz[3][5] = {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 1, 0, 0}};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (cruz[i][j] == 1 && x + i < TAMANHO_TABULEIRO && y - 2 + j >= 0 && y - 2 + j < TAMANHO_TABULEIRO) {
                    tabuleiro[x + i][y - 2 + j] = 1;
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com zeros
    
    posicionarNavios(tabuleiro);
    
    // Aplicação de habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cone
    aplicarHabilidade(tabuleiro, 7, 2, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 2, 7, 'X'); // Cruz
    
    exibirTabuleiro(tabuleiro);
    
    return 0;
}