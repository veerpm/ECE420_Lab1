#include <stdlib.h>
#include <stdio.h>
#include "lab1_IO.h"
#include "timer.h"

int main(int argc, char const *argv[]) {
    int **A, **B, **C, n;
    double start, end;

    Lab1_loadinput(&A, &B, &n);

    C = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        C[i] = malloc(n * sizeof(int));
    }

    GET_TIME(start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    GET_TIME(end);
    printf("Serial execution time: %f seconds\n", end - start);

    Lab1_saveoutput(C, &n, end - start);

    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
