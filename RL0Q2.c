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

typedef struct nomes{
    char nome[100];
} nomes;

void bubbleStr(nomes str[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            nomes aux;
            if(strcmp(str[j].nome, str[j+1].nome) > 0){
                aux = str[j];
                str[j] = str[j+1];
                str[j+1] = aux;
            }
        }
    }
}

void bubbleInt(int inteiros[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            int aux;
            if(inteiros[j] > inteiros[j+1]){
                aux = inteiros[j];
                inteiros[j] = inteiros[j+1];
                inteiros[j+1] = aux;
            }
        }
    }
}

void bubbleReal(float reais[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            float aux;
            if(reais[j] > reais[j+1]){
                aux = reais[j];
                reais[j] = reais[j+1];
                reais[j+1] = aux;
            }
        }
    }
}

void bubblePoints(points p[], int n){
    for(int i = 0; i < n; i++){    
        for(int j = 0; j < n-1-i; j++){
            points aux;
            if(p[j].distancia_origem > p[j+1].distancia_origem){
                aux = p[j];
                p[j] = p[j+1];
                p[j+1] = aux;
            }
        }
    }
}

int main() {
    FILE *fp_in = fopen("L0Q2.in", "r");
    FILE *fp_out = fopen("L0Q2.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos não podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        points p[200];
        nomes str[200];
        int inteiros[200];
        float reais[200];
        
        int countP = 0;
        int countStr = 0;
        int countInt = 0;
        int countReal = 0;

        char *slice = strtok(line, space); // Quebra inicial por espaços

        // Ignorar a palavra "points"
        if (strcmp(slice, "points") == 0) {
            slice = strtok(NULL, space); // Avançar para o próximo token
        }

        // Processar todos os pontos na linha
        while (slice != NULL) {
            int eh_float = 0;
            // Verifica se o token começa com '(', se sim é ponto
            if (slice[0] == '(') {
                // Usar sscanf para extrair x e y diretamente
                float x, y;
                if (sscanf(slice, "(%f,%f)", &x, &y) == 2) {
                    p[countP].x = x;
                    p[countP].y = y;
                    p[countP].ordem_entrada = countP;
                    // Calcular a distância Euclidiana até a origem
                    p[countP].distancia_origem = sqrt(x * x + y * y);
                    countP++;
                }
            }else if(slice[0] >= 'a' && slice[0] <= 'z' || slice[0] >= 'A' && slice[0] <= 'Z'){
                strcpy(str[countStr].nome, slice);
                countStr++;
            }else{
                for(int i = 0; i < strlen(slice); i++){
                    if(slice[i] == '.') eh_float = 1;
                }
                if(eh_float == 1){
                    reais[countReal] = atof(slice);
                    countReal++;
                }else{
                    inteiros[countInt] = atoi(slice);
                    countInt++;
                }
            }
            slice = strtok(NULL, space); // Avança para o próximo token
        }
        
        //ordena
        bubbleStr(str, countStr);
        bubbleInt(inteiros, countInt);
        bubbleReal(reais, countReal);
        bubblePoints(p, countP);
        // Escrever os pontos da linha no arquivo de saída
        fprintf(fp_out, "str:");
        for(int i = 0; i<countStr; i++){
            fprintf(fp_out, "%s ", str[i].nome);
        }

        fprintf(fp_out, "int:");
        for(int i = 0; i<countInt; i++){
            fprintf(fp_out, "%d ", inteiros[i]);
        }

        fprintf(fp_out, "float:");
        for(int i = 0; i<countReal; i++){
            fprintf(fp_out, "%.2f ", reais[i]);
        }
        fprintf(fp_out, "p:");
        for(int i = 0; i<countP; i++){
            if(i<countP-1)fprintf(fp_out, "(%.1f,%.1f) ", p[i].x, p[i].y);
            else fprintf(fp_out, "(%.1f,%.1f)", p[i].x, p[i].y);
        }
        fprintf(fp_out, "\n");

    }// fim da linha
    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
    

