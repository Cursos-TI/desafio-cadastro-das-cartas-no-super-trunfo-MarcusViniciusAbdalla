#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa



int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    // --- Cadastro da Carta 1 ---
    // Declaração de variáveis para a Carta 1
    char estado1;
    char codigo_carta1[4]; // A01, B03, etc. (3 caracteres + 1 para o terminador nulo '\0')
    char nome_cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int num_pontos_turisticos1;

    // Declaração de variáveis para a Carta 2
    char estado2;
    char codigo_carta2[4];
    char nome_cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int num_pontos_turisticos2;

    // ----- Cadastro da Carta 1 -----
    printf("--- Cadastro da Carta 1 ---\n");

    printf("Digite a letra do estado (A a H): ");
    scanf(" %c", &estado1); // O espaço antes do %c é importante para consumir a quebra de linha do input anterior

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", codigo_carta1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome_cidade1); // %[^\n] permite ler uma string com espaços

    printf("Digite a populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a area em km2: ");
    scanf("%f", &area1);

    printf("Digite o PIB: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &num_pontos_turisticos1);
    
    printf("\n");

    // ----- Cadastro da Carta 2 -----
    printf("--- Cadastro da Carta 2 ---\n");

    printf("Digite a letra do estado (A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", codigo_carta2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome_cidade2);

    printf("Digite a populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a area em km2: ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &num_pontos_turisticos2);
    
    printf("\n");

    // ----- Exibição das Cartas -----
    printf("========================================\n");
    printf("--- Informacoes das Cartas Cadastradas ---\n");
    printf("========================================\n");
    
    // Exibição da Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1); // %.2f para formatar com duas casas decimais
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", num_pontos_turisticos1);
    
    printf("\n");

    // Exibição da Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo_carta2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", num_pontos_turisticos2);




    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
