#include <stdio.h>
#include <stdlib.h> // Para a função system()
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

    // Estrutura para representar uma carta do Super Trunfo de Países
typedef struct {
    char nome_pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Nome do Pais: %s\n", carta.nome_pais);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %.2f bilhoes de reais\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Demografica: %.2f hab/km2\n", carta.densidade_demografica);
}

int main() {
    // Definindo duas cartas estaticamente para simplificar, conforme o requisito
    Carta carta1 = {
        "Brasil",
        215000000,
        8515767.0,
        1850.0,
        500,
        0.0 // Densidade será calculada
    };

    Carta carta2 = {
        "India",
        1428000000,
        3287263.0,
        3700.0,
        800,
        0.0 // Densidade será calculada
    };

    // Calculando a densidade demográfica para cada carta
    carta1.densidade_demografica = (float)carta1.populacao / carta1.area;
    carta2.densidade_demografica = (float)carta2.populacao / carta2.area;

    int opcao_menu;

    // Loop do menu principal
    do {
        // Limpar a tela para uma melhor usabilidade
        system("cls || clear");

        printf("========================================\n");
        printf("         Super Trunfo de Paises         \n");
        printf("========================================\n");
        printf("  Cartas em jogo:\n");
        printf("  1. %s\n", carta1.nome_pais);
        printf("  2. %s\n", carta2.nome_pais);
        printf("========================================\n");
        printf("  Escolha o atributo para comparar:\n");
        printf("  1. Populacao\n");
        printf("  2. Area\n");
        printf("  3. PIB\n");
        printf("  4. Pontos Turisticos\n");
        printf("  5. Densidade Demografica (menor valor vence)\n");
        printf("  0. Sair\n");
        printf("========================================\n");
        printf("  Digite sua opcao: ");
        scanf("%d", &opcao_menu);

        // Limpar o buffer do teclado para evitar erros na próxima leitura
        while (getchar() != '\n');

        // Estrutura switch para lidar com a escolha do usuário
        switch (opcao_menu) {
            case 1: // Comparar População
                printf("\nComparando por: Populacao\n");
                printf("%s Populacao: %d\n", carta1.nome_pais, carta1.populacao);
                printf("%s Populacao: %d\n", carta2.nome_pais, carta2.populacao);

                if (carta1.populacao > carta2.populacao) {
                    printf("\n*** %s vence! ***\n", carta1.nome_pais);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("\n*** %s vence! ***\n", carta2.nome_pais);
                } else {
                    printf("\n*** Empate! ***\n");
                }
                break;
            case 2: // Comparar Área
                printf("\nComparando por: Area\n");
                printf("%s Area: %.2f km2\n", carta1.nome_pais, carta1.area);
                printf("%s Area: %.2f km2\n", carta2.nome_pais, carta2.area);
                if (carta1.area > carta2.area) {
                    printf("\n*** %s vence! ***\n", carta1.nome_pais);
                } else if (carta2.area > carta1.area) {
                    printf("\n*** %s vence! ***\n", carta2.nome_pais);
                } else {
                    printf("\n*** Empate! ***\n");
                }
                break;
            case 3: // Comparar PIB
                printf("\nComparando por: PIB\n");
                printf("%s PIB: %.2f bilhoes de reais\n", carta1.nome_pais, carta1.pib);
                printf("%s PIB: %.2f bilhoes de reais\n", carta2.nome_pais, carta2.pib);
                if (carta1.pib > carta2.pib) {
                    printf("\n*** %s vence! ***\n", carta1.nome_pais);
                } else if (carta2.pib > carta1.pib) {
                    printf("\n*** %s vence! ***\n", carta2.nome_pais);
                } else {
                    printf("\n*** Empate! ***\n");
                }
                break;
            case 4: // Comparar Pontos Turísticos
                printf("\nComparando por: Pontos Turisticos\n");
                printf("%s Pontos Turisticos: %d\n", carta1.nome_pais, carta1.pontos_turisticos);
                printf("%s Pontos Turisticos: %d\n", carta2.nome_pais, carta2.pontos_turisticos);
                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("\n*** %s vence! ***\n", carta1.nome_pais);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("\n*** %s vence! ***\n", carta2.nome_pais);
                } else {
                    printf("\n*** Empate! ***\n");
                }
                break;
            case 5: // Comparar Densidade Demográfica (menor valor vence)
                printf("\nComparando por: Densidade Demografica (menor valor vence)\n");
                printf("%s Densidade Demografica: %.2f hab/km2\n", carta1.nome_pais, carta1.densidade_demografica);
                printf("%s Densidade Demografica: %.2f hab/km2\n", carta2.nome_pais, carta2.densidade_demografica);
                if (carta1.densidade_demografica < carta2.densidade_demografica) {
                    printf("\n*** %s vence! ***\n", carta1.nome_pais);
                } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                    printf("\n*** %s vence! ***\n", carta2.nome_pais);
                } else {
                    printf("\n*** Empate! ***\n");
                }
                break;
            case 0:
                printf("\nSaindo do jogo. Ate logo!\n");
                return 0; // Sair do programa
            default:
                printf("\nOpcao invalida. Pressione Enter para tentar novamente.\n");
                break;
        }

        if (opcao_menu != 0) {
            printf("\nPressione Enter para continuar...\n");
            while (getchar() != '\n'); // Espera o usuário pressionar Enter
        }

    } while (1); // Loop infinito, só sai com a opção 0


    return 0;
}
