#include <stdlib.h>
#include <pthread.h>
#include "lab1_IO.h"

void* threadfunc (void* rank){

}

int main(int argc, char const *argv[]){
    int **A; int **B; int **C; int n;
    Lab1_loadinput(&A, &B, &n);

    C = malloc(n * sizeof(int*));
    for (int i=0; i<n; i++){
        C[i] = malloc(n * sizeof(int));
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            C[i][j] = 0;
            for (int k = 0; k < n; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    Lab1_saveoutput(C, &n, 10);
    return 0;
}
