#include <stdio.h>
#include <stdlib.h>

int check_unique(int **matrix, int n) {
    int *count = (int *)calloc(n * n + 1, sizeof(int)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value = matrix[i][j];
            if (value < 1 || value > n * n || count[value] != 0) {
                free(count);
                return 0; 
            }
            count[value] = 1;
        }
    }

    free(count);
    return 1;
}

int is_magic_square(int **matrix, int n) {
    int sum = 0;

    for (int j = 0; j < n; j++) {
        sum += matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += matrix[i][j];
        }
        if (row_sum != sum) return 0;
    }

    for (int j = 0; j < n; j++) {
        int col_sum = 0;
        for (int i = 0; i < n; i++) {
            col_sum += matrix[i][j];
        }
        if (col_sum != sum) return 0;
    }

    int diag_sum1 = 0;
    for (int i = 0; i < n; i++) {
        diag_sum1 += matrix[i][i];
    }
    if (diag_sum1 != sum) return 0;

    int diag_sum2 = 0;
    for (int i = 0; i < n; i++) {
        diag_sum2 += matrix[i][n - i - 1];
    }
    if (diag_sum2 != sum) return 0;

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("error\n");
        return 1;
    }

    int n;
    fscanf(file, "%d\n", &n); 

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);

    if (!check_unique(matrix, n)) {
        printf("not-magic\n");
    } else if (is_magic_square(matrix, n)) {
        printf("magic\n");
    } else {
        printf("not-magic\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}