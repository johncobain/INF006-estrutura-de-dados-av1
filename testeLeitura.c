#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct points{
    int ordem_entrada;
    float distancia_origem;
    float x;
    float y;
} points;

int main() {
    FILE *fp_in = fopen("L0Q1.in", "r");
    FILE *fp_out = fopen("L0Q1teste.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos não podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    // char *slice;

    int linha = 0;
    while (fgets(line, sizeof(line), fp_in) != NULL) {
        points p[200];
        int count = 0;

        char *slice = strtok(line, space); // Quebra inicial por espaços

        // Ignorar a palavra "points"
        if (strcmp(slice, "points") == 0) {
            slice = strtok(NULL, space); // Avançar para o próximo token
        }

        // Processar todos os pontos na linha
        while (slice != NULL) {
            // Verifica se o token começa com '('
            if (slice[0] == '(') {
                // Usar sscanf para extrair x e y diretamente
                float x, y;
                if (sscanf(slice, "(%f,%f)", &x, &y) == 2) {
                    p[count].x = x;
                    p[count].y = y;
                    p[count].ordem_entrada = count;
                    // Calcular a distância Euclidiana até a origem
                    p[count].distancia_origem = sqrt(x * x + y * y);
                    count++;
                }
            }
            slice = strtok(NULL, space); // Avança para o próximo token
        }
        // Escrever os pontos da linha no arquivo de saída
        fprintf(fp_out, "Linha %d:\n", ++linha);
        for (int i = 0; i < count; i++) {
            fprintf(fp_out, "Ponto %d: (%.2f, %.2f), Distância: %.2f\n",
                    p[i].ordem_entrada,
                    p[i].x,
                    p[i].y,
                    p[i].distancia_origem
                    );
        }
    }
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
    