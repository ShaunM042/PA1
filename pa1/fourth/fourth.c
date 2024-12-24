#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void multiply_matrices(int **A, int A_rows, int A_cols, int **B, int B_rows, int B_cols) {
    if (A_cols != B_rows) {
        printf("bad-matrices\n");  
        return;
    }

    int **C = allocate_matrix(A_rows, B_cols);

    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < A_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            if (j > 0) printf("\t");
            printf("%d", C[i][j]);
        }
        printf("\n");
    }

    free_matrix(C, A_rows);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "error\n");
        return 1;
    }

    int A_rows, A_cols;
    fscanf(file, "%d\t%d\n", &A_rows, &A_cols);
    int **A = allocate_matrix(A_rows, A_cols);

    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < A_cols; j++) {
            fscanf(file, "%d", &A[i][j]);
        }
    }

    int B_rows, B_cols;
    fscanf(file, "%d\t%d\n", &B_rows, &B_cols);
    int **B = allocate_matrix(B_rows, B_cols);

    for (int i = 0; i < B_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            fscanf(file, "%d", &B[i][j]);
        }
    }

    multiply_matrices(A, A_rows, A_cols, B, B_rows, B_cols);

    free_matrix(A, A_rows);
    free_matrix(B, B_rows);

    fclose(file);
    return 0;
}