#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "lab1_IO.h"
#include <math.h>
#include "timer.h"

int **A, **B, **C, n, thread_count;
double start, end;

void* threadfunc(void* rank) {
    long my_rank = (long) rank;
    int sqrt_p = (int) sqrt(thread_count);
    int block_size = n / sqrt_p;

    int x = my_rank / sqrt_p;
    int y = my_rank % sqrt_p;

    // Determine the boundaries of the block
    int start_row = x * block_size;
    int end_row = (x + 1) * block_size;
    int start_col = y * block_size;
    int end_col = (y + 1) * block_size;

    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return NULL;
}

int main(int argc, char const *argv[]){
    if (argc != 2) {
        printf("Correct Usage is as following: %s <number_of_threads>\n", argv[0]);
        return -1;
    }

    thread_count = strtol(argv[1], NULL, 10);
    if (thread_count <= 0) {
        printf("Error: Number of threads must be greater than 0.\n");
        return -1;
    }
    Lab1_loadinput(&A, &B, &n);

    C = malloc(n * sizeof(int*));
    for (int i=0; i<n; i++){
        C[i] = malloc(n * sizeof(int));
    }
    
    GET_TIME(start);

    pthread_t* threads = malloc(thread_count * sizeof(pthread_t));
    for (long thread = 0; thread < thread_count; thread++) {
        pthread_create(&threads[thread], NULL, threadfunc, (void*) thread);
    }

    for (int thread = 0; thread < thread_count; thread++) {
        pthread_join(threads[thread], NULL);
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
