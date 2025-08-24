#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// --- Definição da Estrutura da Carta ---
typedef struct {
    char nome[50];
    float area;
    unsigned long int populacao;
    float pib;
    float idh;
    float densidade_populacional;
    float super_poder;
} CartaPais;

// --- Protótipos das Funções ---
void obter_dados_carta(CartaPais* carta, int numero);
void calcular_atributos(CartaPais* carta);
void comparar_cartas(const CartaPais* carta1, const CartaPais* carta2);

// --- Função Principal (main) ---
int main() {
    CartaPais carta1, carta2;

    printf("--- SUPER TRUNFO Nivel MESTRE ---\n");
    printf("--- Comparacao de Cartas ---\n\n");

    // 1. Obter dados para a primeira carta
    obter_dados_carta(&carta1, 1);

    // 2. Obter dados para a segunda carta
    obter_dados_carta(&carta2, 2);

    // 3. Calcular atributos derivados para ambas as cartas
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);
    
    printf("\n--- RESULTADO DA COMPARACAO ---\n\n");
    
    // 4. Exibir e comparar os atributos
    printf("ATRIBUTO                | VENCEDOR (1 = Carta 1, 0 = Carta 2)\n");
    printf("------------------------|-------------------------------------\n");
    
    // Comparação do atributo Nome (apenas para exibição)
    printf("Nome                    | Carta 1: %s vs Carta 2: %s\n", carta1.nome, carta2.nome);

    // Comparação de Área (maior valor vence)
    printf("Area                    | %d\n", carta1.area > carta2.area ? 1 : 0);

    // Comparação de Populacao (maior valor vence)
    printf("Populacao               | %d\n", carta1.populacao > carta2.populacao ? 1 : 0);

    // Comparação de PIB (maior valor vence)
    printf("PIB                     | %d\n", carta1.pib > carta2.pib ? 1 : 0);

    // Comparação de IDH (maior valor vence)
    printf("IDH                     | %d\n", carta1.idh > carta2.idh ? 1 : 0);

    // Comparação de Densidade Populacional (menor valor vence)
    printf("Densidade Populacional  | %d\n", carta1.densidade_populacional < carta2.densidade_populacional ? 1 : 0);

    // Comparação de Super Poder (maior valor vence)
    printf("Super Poder             | %d\n", carta1.super_poder > carta2.super_poder ? 1 : 0);

    return 0;
}

// --- Funções de Implementação ---

/**
 * @brief Obtém os dados de uma carta do usuário.
 * @param carta Ponteiro para a struct CartaPais a ser preenchida.
 * @param numero O número da carta (1 ou 2) para exibição.
 */
void obter_dados_carta(CartaPais* carta, int numero) {
    printf("Dados para a Carta %d:\n", numero);
    printf("Nome do pais: ");
    scanf(" %49[^\n]", carta->nome); // Ler a linha inteira, ignorando espaços iniciais

    printf("Area (km^2, float): ");
    scanf("%f", &carta->area);

    printf("Populacao (unsigned long int): ");
    scanf("%lu", &carta->populacao);

    printf("PIB (trilhoes de USD, float): ");
    scanf("%f", &carta->pib);

    printf("IDH (float): ");
    scanf("%f", &carta->idh);
    
    // Limpa o buffer de entrada para a proxima leitura de string
    while (getchar() != '\n'); 
}

/**
 * @brief Calcula a densidade populacional e o "Super Poder".
 * @param carta Ponteiro para a struct CartaPais a ser atualizada.
 */
void calcular_atributos(CartaPais* carta) {
    // Calculo da densidade populacional
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0.0;
    }

    // Calculo do "Super Poder"
    // Super Poder = Soma de todos os atributos, com a densidade populacional invertida (1/densidade)
    // Supõe-se que a população não é somada diretamente, mas sim a densidade populacional invertida,
    // para evitar a distorção da soma por um número muito grande.
    if (carta->densidade_populacional > 0) {
        carta->super_poder = carta->area + carta->pib + carta->idh + (1.0f / carta->densidade_populacional);
    } else {
        // Se a densidade for 0, o Super Poder seria infinito. Atribuímos 0.
        carta->super_poder = carta->area + carta->pib + carta->idh;
    }
}

/**
 * @brief Compara as duas cartas e exibe o vencedor de cada atributo.
 * @param carta1 Ponteiro para a primeira carta.
 * @param carta2 Ponteiro para a segunda carta.
 */
void comparar_cartas(const CartaPais* carta1, const CartaPais* carta2) {
    printf("\n--- Detalhes da Comparacao ---\n");

    // Exibição dos atributos para facilitar a visualização
    printf("Atributo:                     Carta 1 (%s) | Carta 2 (%s)\n", carta1->nome, carta2->nome);
    printf("--------------------------------------------------\n");
    printf("Area:                         %.2f | %.2f\n", carta1->area, carta2->area);
    printf("Populacao:                    %lu | %lu\n", carta1->populacao, carta2->populacao);
    printf("PIB:                          %.2f | %.2f\n", carta1->pib, carta2->pib);
    printf("IDH:                          %.3f | %.3f\n", carta1->idh, carta2->idh);
    printf("Densidade Populacional:       %.2f | %.2f\n", carta1->densidade_populacional, carta2->densidade_populacional);
    printf("Super Poder:                  %.2f | %.2f\n", carta1->super_poder, carta2->super_poder);
}