#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Estrutura para representar uma carta de cidade
typedef struct {
    char  estado;        // 'A'..'H'
    char  codigo[5];     // ex.: "A01"
    char  cidade[51];    // nome da cidade
    int   populacao;     // número de habitantes
    float area;          // km²
    float pib_bilhoes;   // PIB em bilhões de reais
    int   pontos;        // pontos turísticos

    // Campos calculados
    float densidade;     // hab/km²
    float pib_per_capita;// em reais
} Carta;

int main(void) {
    Carta c1, c2;

    // Cadastro da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c1.estado);

    printf("Codigo (ex.: A01): ");
    scanf(" %4s", c1.codigo);

    getchar(); // consome \n
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c1.cidade);

    printf("Populacao (inteiro): ");
    scanf("%d", &c1.populacao);

    printf("Area em km2 (float): ");
    scanf("%f", &c1.area);

    printf("PIB em bilhoes de reais (float): ");
    scanf("%f", &c1.pib_bilhoes);

    printf("Numero de Pontos Turisticos (inteiro): ");
    scanf("%d", &c1.pontos);

    // Cadastro da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &c2.estado);

    printf("Codigo (ex.: B02): ");
    scanf(" %4s", c2.codigo);

    getchar();
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", c2.cidade);

    printf("Populacao (inteiro): ");
    scanf("%d", &c2.populacao);

    printf("Area em km2 (float): ");
    scanf("%f", &c2.area);

    printf("PIB em bilhoes de reais (float): ");
    scanf("%f", &c2.pib_bilhoes);

    printf("Numero de Pontos Turisticos (inteiro): ");
    scanf("%d", &c2.pontos);

    // Processamento
    c1.densidade      = c1.populacao / c1.area;
    c1.pib_per_capita = (c1.pib_bilhoes * 1e9f) / c1.populacao;

    c2.densidade      = c2.populacao / c2.area;
    c2.pib_per_capita = (c2.pib_bilhoes * 1e9f) / c2.populacao;

    // Comparação de Cartas
    // Definir o atributo usado
    // Exemplo: comparar POPULAÇÃO
    printf("\n===== Comparacao de Cartas (Atributo: Populacao) =====\n");
    printf("Carta 1 - %s: %d habitantes\n", c1.cidade, c1.populacao);
    printf("Carta 2 - %s: %d habitantes\n", c2.cidade, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    // Para comparar outro atributo, alterar o if:
    // - Área: use c1.area vs c2.area
    // - PIB: use c1.pib_bilhoes vs c2.pib_bilhoes
    // - Densidade Populacional: vence o MENOR valor
    // - PIB per capita: use c1.pib_per_capita vs c2.pib_per_capita

    return 0;
}
