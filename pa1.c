#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]) {
    int numberofrows = 0;
    int numberofcolumns = 0;
    FILE * stream = fopen(argv[1], "r");
    if (stream == NULL) {
        printf("Error opening file\n");
        return EXIT_FAILURE;
    }
    char buffer [1050];
    while (fgets(buffer, sizeof(buffer), stream) != NULL) {
        numberofrows = numberofrows + 1;
        // printf("%s", buffer);
    }
    // printf("Number of rows = %i\n", numberofrows);
    char * token = NULL;
    token = strtok(buffer, ",");
    while (token != NULL) {
        token = strtok(NULL, ",");
        numberofcolumns = numberofcolumns + 1;
    }
    // printf("Number of columns = %i\n", numberofcolumns);
    fclose(stream);
    int ** matrix = malloc(numberofrows * sizeof(int *));
    for (int i = 0; i <= numberofrows - 1; i++) {
        matrix[i] = malloc(numberofcolumns * sizeof(int));
    }
    stream = fopen(argv[1], "r");
    for (int r = 0; r <= numberofrows - 1; r++) {
        fgets(buffer, sizeof(buffer), stream);
        if (numberofcolumns == 1) {
            token = strtok(buffer, "\n");
            matrix[r][0] = atoi(token);
            continue;
        }
        for (int c = 0; c <= numberofcolumns - 1; c++) {
            if (c == 0) {
                token = strtok(buffer, ",");
            } else if (c == numberofcolumns - 1) {
                token = strtok(NULL, "\n");
            } else {
                token = strtok(NULL, ",");
            }
            matrix[r][c] = atoi(token);
        }
    }
    fclose(stream);
    // for (int r = 0; r <= numberofrows - 1; r++) {
    //     for (int c = 0; c <= numberofcolumns - 2; c++) {
    //         printf("%i ", matrix[r][c]);
    //     }
    //     printf("%i\n", matrix[r][numberofcolumns-1]);
    // }
    if (argv[2][0] == 'r') {
        int rowindex = atoi(argv[3]);
        int rownumber = rowindex + 1;
        if (rownumber > numberofrows || rownumber < 1) {
            printf("error in input format at line %i\n", rownumber);
            for (int r = 0; r <= numberofrows - 1; r++) {
                free(matrix[r]);
            }
            free(matrix);
            return EXIT_FAILURE;
        }
        int min = matrix[rowindex][0];
        int max = matrix[rowindex][0];
        double sum = (double)matrix[rowindex][0];
        for (int i = 1; i <= numberofcolumns - 1; i++) {
            int current = matrix[rowindex][i];
            if (current < min) {
                min = current;
            }
            if (current > max) {
                max = current;
            }
            sum = sum + current;
        }
        double average = sum / numberofcolumns;
        printf("%s row %.2f %i %i\n", argv[1], average, max, min);

        

    } else {
        int columnindex = atoi(argv[3]);
        int columnnumber = columnindex + 1;
        if (columnnumber > numberofcolumns || columnnumber < 1) {
            printf("error in input format at line 1\n");
            for (int r = 0; r <= numberofrows - 1; r++) {
                free(matrix[r]);
            }
            free(matrix);
            return EXIT_FAILURE;
        }
        int min = matrix[0][columnindex];
        int max = min;
        double sum = (double)max;
        for (int i = 1; i <= numberofrows - 1; i++) {
            int current = matrix[i][columnindex];
            if (current < min) {
                min = current;
            }
            if (current > max) {
                max = current;
            }
            sum = sum + current;
        }
        double average = sum / numberofrows;
        printf("%s column %.2f %i %i\n", argv[1], average, max, min);
    }


    for (int r = 0; r <= numberofrows - 1; r++) {
        free(matrix[r]);
    }
    free(matrix);
    

}