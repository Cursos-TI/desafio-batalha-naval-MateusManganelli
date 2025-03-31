#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

void posicionarNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int x_vertical = 2, y_vertical = 3; // Coordenada inicial do navio vertical
    int x_horizontal = 5, y_horizontal = 6; // Coordenada inicial do navio horizontal
    int x_diagonal1 = 1, y_diagonal1 = 1; // Coordenada inicial do primeiro navio diagonal
    int x_diagonal2 = 7, y_diagonal2 = 2; // Coordenada inicial do segundo navio diagonal
    
    // Posiciona o navio verticalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_vertical + i][y_vertical] = 1;
    }
    
    // Posiciona o navio horizontalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_horizontal][y_horizontal + i] = 2;
    }
    
    // Posiciona o primeiro navio na diagonal (↖)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_diagonal1 + i][y_diagonal1 + i] = 3;
    }
    
    // Posiciona o segundo navio na diagonal (↘)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[x_diagonal2 - i][y_diagonal2 + i] = 3;
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
    exibirTabuleiro(tabuleiro);
    
    return 0;
}