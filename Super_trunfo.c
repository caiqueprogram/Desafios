#include <stdio.h>

int main() {
    // Variáveis para a Carta 1
    unsigned long int populacao1;
    float area1, PIB1;
    unsigned int pontos_turisticos1;
    float PIB_per_capita1, densidade_populacional1, super_poder1;
    
    // Variáveis para a Carta 2
    unsigned long int populacao2;
    float area2, PIB2;
    unsigned int pontos_turisticos2;
    float PIB_per_capita2, densidade_populacional2, super_poder2;

    // Leitura dos dados da Carta 1
    printf("=== Carta 1 ===\n");
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    
    printf("Digite a área (km²): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &PIB1);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%u", &pontos_turisticos1);

    // Cálculos para Carta 1
    PIB_per_capita1 = (PIB1 * 1000000) / populacao1;
    densidade_populacional1 = populacao1 / area1;
    super_poder1 = populacao1 + area1 + PIB1 + pontos_turisticos1 + 
                  PIB_per_capita1 + (1 / densidade_populacional1);

    // Leitura dos dados da Carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    
    printf("Digite a área (km²): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &PIB2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%u", &pontos_turisticos2);

    // Cálculos para Carta 2
    PIB_per_capita2 = (PIB2 * 1000000) / populacao2;
    densidade_populacional2 = populacao2 / area2;
    super_poder2 = populacao2 + area2 + PIB2 + pontos_turisticos2 + 
                  PIB_per_capita2 + (1 / densidade_populacional2);

    // Comparação das cartas
    printf("\nComparação de Cartas:\n");
    printf("População: %d\n", populacao1 > populacao2);
    printf("Área: %d\n", area1 > area2);
    printf("PIB: %d\n", PIB1 > PIB2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1 > pontos_turisticos2);
    printf("Densidade Populacional: %d\n", densidade_populacional1 < densidade_populacional2);
    printf("PIB per Capita: %d\n", PIB_per_capita1 > PIB_per_capita2);
    printf("Super Poder: %d\n", super_poder1 > super_poder2);

    return 0;
}
