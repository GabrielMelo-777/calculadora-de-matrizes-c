#include <stdio.h>

#define MAX 5
#define TAM 2

float matrizes[MAX][TAM][TAM];
float resultado[TAM][TAM];

int quantidade = 0;
int preenchidas = 0;
int temResultado = 0;

// Le um numero inteiro e verifica se a entrada e valida
int lerInteiro(int *numero) {
    char linha[100];
    char extra;

    if (fgets(linha, sizeof(linha), stdin) == NULL)
        return 0;

    return sscanf(linha, " %d %c", numero, &extra) == 1;
}

// Le um numero decimal e verifica se a entrada e valida
int lerDecimal(float *numero) {
    char linha[100];
    char extra;

    if (fgets(linha, sizeof(linha), stdin) == NULL)
        return 0;

    return sscanf(linha, " %f %c", numero, &extra) == 1;
}

// Exibe o menu principal
void menu() {
    printf("\n===== CALCULADORA DE MATRIZES =====\n");
    printf("1 - Escolher quantidade de matrizes\n");
    printf("2 - Informar matrizes\n");
    printf("3 - Somar matrizes\n");
    printf("4 - Subtrair matrizes\n");
    printf("5 - Multiplicar matrizes\n");
    printf("6 - Dividir matrizes\n");
    printf("7 - Mostrar resultado\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

// Define a quantidade de matrizes
void escolherQuantidade() {
    int numero;

    printf("Quantidade de matrizes (2 a 5): ");

    if (!lerInteiro(&numero) || numero < 2 || numero > MAX) {
        printf("Quantidade invalida!\n");
        quantidade = 0;
    } else {
        quantidade = numero;
        printf("Quantidade definida!\n");
    }

    preenchidas = 0;
    temResultado = 0;
}

// Recebe os valores das matrizes
void informarMatrizes() {
    if (quantidade == 0) {
        printf("Escolha a quantidade primeiro!\n");
        return;
    }

    preenchidas = 0;
    temResultado = 0;

    for (int k = 0; k < quantidade; k++) {
        printf("\nMatriz %d:\n", k + 1);

        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                printf("Posicao [%d][%d]: ", i + 1, j + 1);

                if (!lerDecimal(&matrizes[k][i][j])) {
                    printf("Valor invalido!\n");
                    return;
                }
            }
        }
    }

    preenchidas = 1;
    printf("Matrizes cadastradas!\n");
}

// Soma todas as matrizes
void somarMatrizes() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            resultado[i][j] = 0;

            for (int k = 0; k < quantidade; k++) {
                resultado[i][j] += matrizes[k][i][j];
            }
        }
    }

    printf("Soma realizada!\n");
}

// Subtrai as matrizes da primeira
void subtrairMatrizes() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            resultado[i][j] = matrizes[0][i][j];

            for (int k = 1; k < quantidade; k++) {
                resultado[i][j] -= matrizes[k][i][j];
            }
        }
    }

    printf("Subtracao realizada!\n");
}

// Realiza a multiplicacao matricial
void multiplicarMatrizes() {
    float auxiliar[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            resultado[i][j] = matrizes[0][i][j];
        }
    }

    for (int k = 1; k < quantidade; k++) {
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                auxiliar[i][j] = 0;

                for (int x = 0; x < TAM; x++) {
                    auxiliar[i][j] +=
                        resultado[i][x] * matrizes[k][x][j];
                }
            }
        }

        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                resultado[i][j] = auxiliar[i][j];
            }
        }
    }

    printf("Multiplicacao realizada!\n");
}

// Divide os elementos correspondentes das matrizes
int dividirMatrizes() {
    for (int k = 1; k < quantidade; k++) {
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                if (matrizes[k][i][j] == 0) {
                    printf("Erro: divisao por zero!\n");
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            resultado[i][j] = matrizes[0][i][j];

            for (int k = 1; k < quantidade; k++) {
                resultado[i][j] /= matrizes[k][i][j];
            }
        }
    }

    printf("Divisao realizada!\n");
    return 1;
}

// Mostra a matriz resultante
void mostrarResultado() {
    if (!temResultado) {
        printf("Realize uma operacao primeiro!\n");
        return;
    }

    printf("\nMatriz resultado:\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%.2f\t", resultado[i][j]);
        }
        printf("\n");
    }
}

// Controla o funcionamento do programa
int main() {
    int opcao;

    do {
        menu();

        if (!lerInteiro(&opcao)) {
            printf("Opcao invalida!\n");
            continue;
        }

        if (opcao == 1) {
            escolherQuantidade();
        }
        else if (opcao == 2) {
            informarMatrizes();
        }
        else if (opcao >= 3 && opcao <= 6) {
            if (!preenchidas) {
                printf("Informe as matrizes primeiro!\n");
                continue;
            }

            temResultado = 0;

            if (opcao == 3) {
                somarMatrizes();
                temResultado = 1;
            }
            else if (opcao == 4) {
                subtrairMatrizes();
                temResultado = 1;
            }
            else if (opcao == 5) {
                multiplicarMatrizes();
                temResultado = 1;
            }
            else if (opcao == 6) {
                temResultado = dividirMatrizes();
            }
        }
        else if (opcao == 7) {
            mostrarResultado();
        }
        else if (opcao == 0) {
            printf("Encerrando programa...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
