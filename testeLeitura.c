#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char comma[] = ",";
    char pointOpen[] = "(";
    char pointClose[] = ")";
    // char *slice;

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        char *slice = strtok(line, " "); // Quebra inicial por espaços

        // Ignorar a palavra "points"
        if (strcmp(slice, "points") == 0) {
            slice = strtok(NULL, " "); // Avançar para o próximo token
        }

        // Processar todos os pontos na linha
        while (slice != NULL) {
            // Verifica se o token começa com '('
            if (slice[0] == '(') {
                // Usar sscanf para extrair x e y diretamente
                int x, y;
                if (sscanf(slice, "(%d,%d)", &x, &y) == 2) {
                    fprintf(fp_out, "[%d|%d] ", x, y); // Escreve no arquivo de saída
                }
            }
            slice = strtok(NULL, " "); // Avança para o próximo token
        }
        fprintf(fp_out, "\n");
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
    