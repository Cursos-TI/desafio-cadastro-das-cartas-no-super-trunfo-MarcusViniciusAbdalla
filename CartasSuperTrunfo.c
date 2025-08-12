#include <stdio.h>    // Para funções de entrada/saída como printf e scanf
#include <stdlib.h>   // Para a função system() (para limpar a tela do console)
#include <string.h>   // Para funções de manipulação de strings como strcpy

// Estrutura para representar uma carta do Super Trunfo de Cidades/Países
// Define os atributos que cada carta terá.
typedef struct {
    char estado;                 // Uma letra de 'A' a 'H'
    char codigo_carta[4];        // Ex: A01 (3 caracteres + 1 para o terminador nulo '\0')
    char nome_cidade[50];        // Nome da cidade/país (string)
    int populacao;               // População (inteiro)
    float area;                  // Área em km² (float)
    float pib;                   // Produto Interno Bruto (float)
    int pontos_turisticos;       // Número de pontos turísticos (inteiro)
    float densidade_demografica; // Densidade demográfica (float), será calculada
} Carta;

// Função para exibir os dados detalhados de uma carta
// Recebe uma estrutura Carta como parâmetro e imprime seus atributos.
void exibirDetalhesCarta(const Carta *carta, int numero_carta) {
    printf("Carta %d:\n", numero_carta);
    printf("  Estado: %c\n", carta->estado);
    printf("  Codigo: %s\n", carta->codigo_carta);
    printf("  Nome da Cidade: %s\n", carta->nome_cidade);
    printf("  Populacao: %d\n", carta->populacao);
    printf("  Area: %.2f km2\n", carta->area);
    printf("  PIB: %.2f bilhoes de reais\n", carta->pib);
    printf("  Numero de Pontos Turisticos: %d\n", carta->pontos_turisticos);
    // Exibe a densidade demográfica apenas se já foi calculada e não for zero
    if (carta->densidade_demografica > 0) {
        printf("  Densidade Demografica: %.2f hab/km2\n", carta->densidade_demografica);
    }
}

// Função para limpar o buffer de entrada do teclado
// Essencial após o uso de scanf() para inteiros/floats antes de ler strings.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função principal do programa
int main() {
    // Declaração de duas estruturas Carta para armazenar os dados das cartas do usuário.
    Carta carta1;
    Carta carta2;
    int opcao_menu; // Variável para armazenar a escolha do usuário no menu

    // === PARTE 1: CADASTRO DAS CARTAS (Requisitos do Nível 1) ===

    printf("========================================\n");
    printf("--- Cadastro das Cartas do Super Trunfo ---\n");
    printf("========================================\n\n");

    // --- Cadastro da Carta 1 ---
    printf("--- Insira os dados para a CARTA 1 ---\n");
    printf("Digite a letra do estado (A a H): ");
    scanf(" %c", &carta1.estado); // O espaço antes do %c consome qualquer '\n' pendente

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", carta1.codigo_carta);
    limparBuffer(); // Limpa o buffer após scanf("%s")

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.nome_cidade); // %[^\n] permite ler a linha inteira, incluindo espaços
    limparBuffer(); // Limpa o buffer após scanf(" %[^\n]")

    printf("Digite a populacao: ");
    scanf("%d", &carta1.populacao);
    limparBuffer();

    printf("Digite a area em km2: ");
    scanf("%f", &carta1.area);
    limparBuffer();

    printf("Digite o PIB: ");
    scanf("%f", &carta1.pib);
    limparBuffer();

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    limparBuffer();
    printf("\n");

    // --- Cadastro da Carta 2 ---
    printf("--- Insira os dados para a CARTA 2 ---\n");
    printf("Digite a letra do estado (A a H): ");
    scanf(" %c", &carta2.estado);

    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", carta2.codigo_carta);
    limparBuffer();

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.nome_cidade);
    limparBuffer();

    printf("Digite a populacao: ");
    scanf("%d", &carta2.populacao);
    limparBuffer();

    printf("Digite a area em km2: ");
    scanf("%f", &carta2.area);
    limparBuffer();

    printf("Digite o PIB: ");
    scanf("%f", &carta2.pib);
    limparBuffer();

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    limparBuffer();
    printf("\n");

    // === Exibição das Cartas Cadastradas ===
    printf("========================================\n");
    printf("--- Informacoes das Cartas Cadastradas ---\n");
    printf("========================================\n\n");
    exibirDetalhesCarta(&carta1, 1); // Passa o endereço da carta
    printf("\n");
    exibirDetalhesCarta(&carta2, 2); // Passa o endereço da carta
    printf("\n");

    printf("Pressione Enter para ir para a comparacao...\n");
    limparBuffer(); // Aguarda o Enter

    // === PARTE 2: INTERATIVIDADE E COMPARAÇÃO (Requisitos do Nível 2) ===

    // Calcula a densidade demográfica para ambas as cartas.
    // É importante fazer isso antes de qualquer comparação que a utilize.
    if (carta1.area > 0) {
        carta1.densidade_demografica = (float)carta1.populacao / carta1.area;
    } else {
        carta1.densidade_demografica = 0.0; // Evita divisão por zero
    }

    if (carta2.area > 0) {
        carta2.densidade_demografica = (float)carta2.populacao / carta2.area;
    } else {
        carta2.densidade_demografica = 0.0; // Evita divisão por zero
    }

    // Loop principal do jogo para exibir o menu e permitir múltiplas comparações
    do {
        // Limpa a tela do console. "cls" para Windows, "clear" para Unix/Linux.
        system("cls || clear");

        printf("========================================\n");
        printf("         Super Trunfo de Cidades        \n");
        printf("========================================\n");
        printf("  Cartas em jogo:\n");
        printf("  1. %s (%s)\n", carta1.nome_cidade, carta1.codigo_carta);
        printf("  2. %s (%s)\n", carta2.nome_cidade, carta2.codigo_carta);
        printf("========================================\n");
        printf("  Escolha o atributo para comparar:\n");
        printf("  1. Populacao\n");
        printf("  2. Area\n");
        printf("  3. PIB\n");
        printf("  4. Pontos Turisticos\n");
        printf("  5. Densidade Demografica (MENOR valor vence)\n");
        printf("  0. Sair do Jogo\n");
        printf("========================================\n");
        printf("  Digite sua opcao: ");
        scanf("%d", &opcao_menu);
        limparBuffer(); // Limpa o buffer após ler a opção do menu

        // Estrutura switch para processar a escolha do usuário
        switch (opcao_menu) {
            case 1: // Comparar População
                printf("\nComparando por: Populacao\n");
                printf(" %s: %d habitantes\n", carta1.nome_cidade, carta1.populacao);
                printf(" %s: %d habitantes\n", carta2.nome_cidade, carta2.populacao);

                // Lógica de comparação: maior população vence
                if (carta1.populacao > carta2.populacao) {
                    printf("\n*** %s vence na Populacao! ***\n", carta1.nome_cidade);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("\n*** %s vence na Populacao! ***\n", carta2.nome_cidade);
                } else {
                    printf("\n*** Empate na Populacao! ***\n");
                }
                break; // Sai do switch

            case 2: // Comparar Área
                printf("\nComparando por: Area\n");
                printf(" %s: %.2f km2\n", carta1.nome_cidade, carta1.area);
                printf(" %s: %.2f km2\n", carta2.nome_cidade, carta2.area);

                // Lógica de comparação: maior área vence
                if (carta1.area > carta2.area) {
                    printf("\n*** %s vence na Area! ***\n", carta1.nome_cidade);
                } else if (carta2.area > carta1.area) {
                    printf("\n*** %s vence na Area! ***\n", carta2.nome_cidade);
                } else {
                    printf("\n*** Empate na Area! ***\n");
                }
                break;

            case 3: // Comparar PIB
                printf("\nComparando por: PIB\n");
                printf(" %s: %.2f bilhoes de reais\n", carta1.nome_cidade, carta1.pib);
                printf(" %s: %.2f bilhoes de reais\n", carta2.nome_cidade, carta2.pib);

                // Lógica de comparação: maior PIB vence
                if (carta1.pib > carta2.pib) {
                    printf("\n*** %s vence no PIB! ***\n", carta1.nome_cidade);
                } else if (carta2.pib > carta1.pib) {
                    printf("\n*** %s vence no PIB! ***\n", carta2.nome_cidade);
                } else {
                    printf("\n*** Empate no PIB! ***\n");
                }
                break;

            case 4: // Comparar Pontos Turísticos
                printf("\nComparando por: Pontos Turisticos\n");
                printf(" %s: %d pontos turisticos\n", carta1.nome_cidade, carta1.pontos_turisticos);
                printf(" %s: %d pontos turisticos\n", carta2.nome_cidade, carta2.pontos_turisticos);

                // Lógica de comparação: mais pontos turísticos vence
                if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                    printf("\n*** %s vence nos Pontos Turisticos! ***\n", carta1.nome_cidade);
                } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
                    printf("\n*** %s vence nos Pontos Turisticos! ***\n", carta2.nome_cidade);
                } else {
                    printf("\n*** Empate nos Pontos Turisticos! ***\n");
                }
                break;

            case 5: // Comparar Densidade Demográfica (REGRA INVERTIDA: MENOR valor vence)
                printf("\nComparando por: Densidade Demografica (MENOR valor vence)\n");
                printf(" %s: %.2f hab/km2\n", carta1.nome_cidade, carta1.densidade_demografica);
                printf(" %s: %.2f hab/km2\n", carta2.nome_cidade, carta2.densidade_demografica);

                // Lógica de comparação: MENOR densidade demográfica vence
                if (carta1.densidade_demografica < carta2.densidade_demografica) {
                    printf("\n*** %s vence na Densidade Demografica (menor valor)! ***\n", carta1.nome_cidade);
                } else if (carta2.densidade_demografica < carta1.densidade_demografica) {
                    printf("\n*** %s vence na Densidade Demografica (menor valor)! ***\n", carta2.nome_cidade);
                } else {
                    printf("\n*** Empate na Densidade Demografica! ***\n");
                }
                break;

            case 0: // Sair do jogo
                printf("\nSaindo do jogo. Ate logo!\n");
                return 0; // Termina o programa

            default: // Opção inválida
                printf("\nOpcao invalida! Por favor, escolha um numero entre 0 e 5.\n");
                break;
        }

        // Aguarda o usuário pressionar Enter para continuar, a menos que a opção seja Sair.
        if (opcao_menu != 0) {
            printf("\nPressione Enter para continuar...\n");
            limparBuffer(); // Espera por uma nova linha
        }

    } while (opcao_menu != 0); // O loop continua até que o usuário escolha '0' para sair

    return 0; // Retorna 0 indicando que o programa executou com sucesso
}
