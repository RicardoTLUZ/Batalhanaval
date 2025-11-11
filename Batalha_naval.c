#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

int main() {

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j; 

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    int meio_skill = TAMANHO_HABILIDADE / 2;

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            if (i == meio_skill || j == meio_skill) {
                cruz[i][j] = 1;
            }

            if (abs(i - meio_skill) + abs(j - meio_skill) <= meio_skill) {
                octaedro[i][j] = 1;
            }

            if (i >= meio_skill && 
                j >= meio_skill - (i - meio_skill) &&
                j <= meio_skill + (i - meio_skill)) {
                cone[i][j] = 1;
            }
        }
    }

    int navio1_lin = 1, navio1_col = 1, navio1_orient = 0; 
    int navio2_lin = 3, navio2_col = 8, navio2_orient = 1; 
    int navio3_lin = 5, navio3_col = 1, navio3_orient = 2; 
    int navio4_lin = 6, navio4_col = 5, navio4_orient = 3; 

    int sobreposicao = 0;

    if (navio1_orient == 0) { 
        if (navio1_lin >= 0 && navio1_lin < TAMANHO_TABULEIRO && navio1_col >= 0 && (navio1_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio1_lin][navio1_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 1.\n"); return 1; }
    } else if (navio1_orient == 1) { 
        if (navio1_lin >= 0 && (navio1_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio1_col >= 0 && navio1_col < TAMANHO_TABULEIRO) {
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio1_lin + i][navio1_col] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 1.\n"); return 1; }
    } else if (navio1_orient == 2) { 
        if (navio1_lin >= 0 && (navio1_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio1_col >= 0 && (navio1_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio1_lin + i][navio1_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 1.\n"); return 1; }
    } else if (navio1_orient == 3) { 
        if (navio1_lin >= 0 && (navio1_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio1_col >= 0 && (navio1_col - TAMANHO_NAVIO + 1 >= 0)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio1_lin + i][navio1_col - i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 1.\n"); return 1; }
    }

    if (navio2_orient == 0) {
        if (navio2_lin >= 0 && navio2_lin < TAMANHO_TABULEIRO && navio2_col >= 0 && (navio2_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio2_lin][navio2_col + i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 2.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio2_lin][navio2_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 2.\n"); return 1; }
    } else if (navio2_orient == 1) {
        if (navio2_lin >= 0 && (navio2_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio2_col >= 0 && navio2_col < TAMANHO_TABULEIRO) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio2_lin + i][navio2_col] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 2.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio2_lin + i][navio2_col] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 2.\n"); return 1; }
    } else if (navio2_orient == 2) {
        if (navio2_lin >= 0 && (navio2_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio2_col >= 0 && (navio2_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio2_lin + i][navio2_col + i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 2.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio2_lin + i][navio2_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 2.\n"); return 1; }
    } else if (navio2_orient == 3) {
        if (navio2_lin >= 0 && (navio2_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio2_col >= 0 && (navio2_col - TAMANHO_NAVIO + 1 >= 0)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio2_lin + i][navio2_col - i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 2.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio2_lin + i][navio2_col - i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 2.\n"); return 1; }
    }

    sobreposicao = 0;
    if (navio3_orient == 0) {
        if (navio3_lin >= 0 && navio3_lin < TAMANHO_TABULEIRO && navio3_col >= 0 && (navio3_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio3_lin][navio3_col + i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 3.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio3_lin][navio3_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 3.\n"); return 1; }
    } else if (navio3_orient == 1) {
        if (navio3_lin >= 0 && (navio3_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio3_col >= 0 && navio3_col < TAMANHO_TABULEIRO) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio3_lin + i][navio3_col] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 3.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio3_lin + i][navio3_col] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 3.\n"); return 1; }
    } else if (navio3_orient == 2) {
        if (navio3_lin >= 0 && (navio3_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio3_col >= 0 && (navio3_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio3_lin + i][navio3_col + i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 3.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio3_lin + i][navio3_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 3.\n"); return 1; }
    } else if (navio3_orient == 3) {
        if (navio3_lin >= 0 && (navio3_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio3_col >= 0 && (navio3_col - TAMANHO_NAVIO + 1 >= 0)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio3_lin + i][navio3_col - i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 3.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio3_lin + i][navio3_col - i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 3.\n"); return 1; }
    }
    
    sobreposicao = 0;
    if (navio4_orient == 0) {
        if (navio4_lin >= 0 && navio4_lin < TAMANHO_TABULEIRO && navio4_col >= 0 && (navio4_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio4_lin][navio4_col + i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 4.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio4_lin][navio4_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 4.\n"); return 1; }
    } else if (navio4_orient == 1) {
        if (navio4_lin >= 0 && (navio4_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio4_col >= 0 && navio4_col < TAMANHO_TABULEIRO) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio4_lin + i][navio4_col] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 4.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio4_lin + i][navio4_col] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 4.\n"); return 1; }
    } else if (navio4_orient == 2) {
        if (navio4_lin >= 0 && (navio4_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio4_col >= 0 && (navio4_col + TAMANHO_NAVIO <= TAMANHO_TABULEIRO)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio4_lin + i][navio4_col + i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 4.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio4_lin + i][navio4_col + i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 4.\n"); return 1; }
    } else if (navio4_orient == 3) {
        if (navio4_lin >= 0 && (navio4_lin + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) && navio4_col >= 0 && (navio4_col - TAMANHO_NAVIO + 1 >= 0)) {
            for (i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[navio4_lin + i][navio4_col - i] != 0) sobreposicao = 1;
            if (sobreposicao) { printf("Erro: Sobreposicao detectada no Navio 4.\n"); return 1; }
            for (i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[navio4_lin + i][navio4_col - i] = 3;
        } else { printf("Erro: Posicionamento invalido para o Navio 4.\n"); return 1; }
    }

    int cone_lin = 8, cone_col = 7;
    int cruz_lin = 2, cruz_col = 4;
    int octa_lin = 6, octa_col = 2;

    int tab_lin, tab_col;

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                tab_lin = cone_lin + (i - meio_skill);
                tab_col = cone_col + (j - meio_skill);

                if (tab_lin >= 0 && tab_lin < TAMANHO_TABULEIRO &&
                    tab_col >= 0 && tab_col < TAMANHO_TABULEIRO) {
                    
                    if (tabuleiro[tab_lin][tab_col] == 0) {
                        tabuleiro[tab_lin][tab_col] = 5;
                    }
                }
            }
        }
    }

    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                tab_lin = cruz_lin + (i - meio_skill);
                tab_col = cruz_col + (j - meio_skill);

                if (tab_lin >= 0 && tab_lin < TAMANHO_TABULEIRO &&
                    tab_col >= 0 && tab_col < TAMANHO_TABULEIRO) {
                    
                    if (tabuleiro[tab_lin][tab_col] == 0) {
                        tabuleiro[tab_lin][tab_col] = 5;
                    }
                }
            }
        }
    }
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                tab_lin = octa_lin + (i - meio_skill);
                tab_col = octa_col + (j - meio_skill);

                if (tab_lin >= 0 && tab_lin < TAMANHO_TABULEIRO &&
                    tab_col >= 0 && tab_col < TAMANHO_TABULEIRO) {
                    
                    if (tabuleiro[tab_lin][tab_col] == 0) {
                        tabuleiro[tab_lin][tab_col] = 5;
                    }
                }
            }
        }
    }

    printf("### Batalha Naval ###\n");
    printf("0=Agua, 3=Navio, 5=Efeito\n\n");
    
    printf("  ");
    for(j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); 
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0; 
}