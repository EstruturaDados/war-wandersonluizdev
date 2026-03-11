#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define MAX_STRING 20

typedef struct {
    char nome[MAX_STRING];
    char cor[MAX_STRING];
    int tropas;
} Territorio;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
    printf("\n===================================\n");
    printf("JOGO DE GUERRA\n");
    printf("===================================\n");
    printf("1. Adicionar território\n");
    printf("2. Listar Regras\n");
    printf("3. Listar Mapa\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

void adicionarTerritorio(Territorio mapa[], int *numTerritorios) {
    if (*numTerritorios >= MAX_TERRITORIOS) {
        printf("Limite máximo de territórios atingido!\n");
        return;
    }
    
    printf("\n--- Adicionar Território ---\n");
    
    printf("Nome: ");
    fgets(mapa[*numTerritorios].nome, MAX_STRING, stdin);
    mapa[*numTerritorios].nome[strcspn(mapa[*numTerritorios].nome, "\n")] = 0;
    
    printf("Cor: ");
    fgets(mapa[*numTerritorios].cor, MAX_STRING, stdin);
    mapa[*numTerritorios].cor[strcspn(mapa[*numTerritorios].cor, "\n")] = 0;
    
    printf("Número de tropas: ");
    scanf("%d", &mapa[*numTerritorios].tropas);
    limparBuffer();
    
    (*numTerritorios)++;
    printf("Território cadastrado com sucesso!\n");
}

void listarRegras() {
    printf("\n--- REGRAS DO JOGO ---\n");
    printf("1. Cada jogador controla territórios\n");
    printf("2. Territórios têm cores e quantidade de tropas\n");
    printf("3. Objetivo: conquistar todos os territórios\n");
    printf("4. Ataques: compare o número de tropas\n");
    printf("5. Quem tiver mais tropas vence a batalha\n");
}

void listarMapa(Territorio mapa[], int numTerritorios) {
    if (numTerritorios == 0) {
        printf("\nNenhum território cadastrado ainda!\n");
        return;
    }
    
    printf("\n--- MAPA DOS TERRITÓRIOS ---\n");
    for (int i = 0; i < numTerritorios; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("  Nome: %s\n", mapa[i].nome);
        printf("  Cor: %s\n", mapa[i].cor);
        printf("  Tropas: %d\n", mapa[i].tropas);
        printf("----------------------\n");
    }
}

int main() {
    Territorio mapa[MAX_TERRITORIOS];
    int numTerritorios = 0;
    int opcao;
    
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                adicionarTerritorio(mapa, &numTerritorios);
                break;
                
            case 2:
                listarRegras();
                break;
                
            case 3:
                listarMapa(mapa, numTerritorios);
                break;
                
            case 4:
                printf("Saindo do jogo. Até mais!\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        if (opcao != 4) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
        
    } while (opcao != 4);
    
    return 0;
}
