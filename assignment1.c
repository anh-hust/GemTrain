#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int *elem;  // just create one dimension array to handle 2D array
    unsigned int row;
    unsigned int col;
} Matrix;

void printMatrix(const char *name, Matrix *m);
void sumOfMatrix(Matrix *m1, Matrix *m2);
void productOfMatrix(Matrix *m1, Matrix *m2);

int main() {
    Matrix matrixA, matrixB;

    /**
     * Input phase
     */
    /* Input dimension matrix A */
    printf("Matrix A Row:");
    scanf("%u", &matrixA.row);

    printf("Matrix A Col:");
    scanf("%u", &matrixA.col);

    // init matrix A
    matrixA.elem = (int *)malloc(matrixA.row * matrixA.col * sizeof(int));
    if (matrixA.elem == NULL) {
        printf("Allocation for matrix A fail !!!\n");
    }

    /* Input for matrix B */
    printf("Matrix B Row:");
    scanf("%u", &matrixB.row);

    printf("Matrix B Row:");
    scanf("%u", &matrixB.col);

    // init matrix B
    matrixB.elem = (int *)malloc(matrixB.row * matrixB.col * sizeof(int));
    if (matrixB.elem == NULL) {
        printf("Allocation for matrix B fail !!!\n");
    }

    /* Parsing user input for elements*/
    int i;

    // Matrix A
    printf("\nMatrix A:\n");
    for (i = 0; i < matrixA.col * matrixA.row; i++) {
        if (!scanf("%d", (matrixA.elem + i))) {
            printf("Element %d fail !!!\n", i);
        }
    }

    // Matrix A
    printf("\nMatrix B:\n");
    for (i = 0; i < matrixB.col * matrixB.row; i++) {
        if (!scanf("%d", (matrixB.elem + i))) {
            printf("Element %d fail !!!\n", i);
        }
    }
    printMatrix("B", &matrixB);

    /**
     * Calculate
     */

    // free
    free(matrixA.elem);
    free(matrixB.elem);
    return 0;
}

void printMatrix(const char *name, Matrix *m) {
    printf("Matrix %s:\n", name);
    int i, j;
    for (i = 0; i < m->row; i++) {
        for (j = 0; j < m->col; j++) {
            printf("%d ", *(m->elem + i * m->col + j));
        }
        printf("\n");
    }
}

void sumOfMatrix(Matrix *m1, Matrix *m2) {
    if (m1->col == m2->col && m1->row == m2->row) {
        printf("Matrix A + Matrix B:\n");
        int i, j;
        for (i = 0; i < m1->row; i++) {
            for (j = 0; j < m1->col; j++) {
                printf("%d ", *(m1->elem + i * m1->col + j) + *(m2->elem + i * m2->col + j));
            }
            printf("\n");
        }
    } else {
        printf("Matrix A, Matrix B can't add together.\n");
        return;
    }
}

void productOfMatrix(Matrix *m1, Matrix *m2) {
    /* Matrix A * Matrix B */
    if (m1->row == m2->col) {
    } else {
        printf("Matrix A, Matrix B cannot multi together.\n");
    }

    /* Matrix B * Matrix A */
    if (m2->row == m1->col) {
    } else {
        printf("Matrix B, Matrix A cannot multi together.\n");
    }
}