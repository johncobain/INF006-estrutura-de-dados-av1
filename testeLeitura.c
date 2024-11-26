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
    FILE *fp_out = fopen("L0Q1.out", "w");
    char line[1000];
    if (fp_in == NULL || fp_out == NULL){
        printf("Arquivos não podem ser abertos.");
        return EXIT_FAILURE;
    }

    char space[] = " ";
    char comma[] = ",";
    char *slice;

    while (fgets(line, 255, fp_in) != NULL){
        //strtok: (1)não é thread-safe e (2) modifica a string
        slice = strtok(line, space);
        char text[20];
        while (slice != NULL){
            if(strcmp(slice, "points") == 0){
                slice = strtok(NULL, space);
            }
            strcpy(text, slice);
            slice = strtok(NULL, space);
            fputs(text, fp_out);
        }
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}