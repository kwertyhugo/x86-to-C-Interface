#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "header.h"

extern void asmfunc();

int main() {
    //size_t n = 1048576; //n^20
    //size_t n = 16777216; //n^24
    //size_t n = 67108864; //n^26 (upper limit for my device)
    
    //initialize arrays
    float* x1, * x2, * y1, * y2, * zC, * zAsm;
    x1 = (float*)malloc(n * sizeof(float));
    x2 = (float*)malloc(n * sizeof(float));
    y1 = (float*)malloc(n * sizeof(float));
    y2 = (float*)malloc(n * sizeof(float));
    zC = (float*)malloc(n * sizeof(float));
    zAsm = (float*)malloc(n * sizeof(float));

    //set up rng
    time_t t;
    srand((unsigned int)time(&t));

    // Generate X1
    for (size_t i = 0; i < n; i++) {
        x1[i] = (float)rand() / (float)RAND_MAX * 100.0f;
    }

    // Generate X2
    for (size_t i = 0; i < n; i++) {
        x2[i] = (float)rand() / (float)RAND_MAX * 100.0f;
    }

    // Generate Y1
    for (size_t i = 0; i < n; i++) {
        y1[i] = (float)rand() / (float)RAND_MAX * 100.0f;
    }

    // Generate Y2
    for (size_t i = 0; i < n; i++) {
        y2[i] = (float)rand() / (float)RAND_MAX * 100.0f;
    }
    
    //call the kernels and record average execution time
    double total_C = 0;
    double total_Asm = 0;
    for (int i = 0; i < 30; i++) {
        clock_t start_time = clock();
        cfunc(n, x1, x2, y1, y2, zC);
        clock_t end_time = clock();
        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        total_C += elapsed_time;

        start_time = clock();
        asmfunc(n, x1, x2, y1, y2, zAsm);
        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        total_Asm += elapsed_time;
    }
    

    int correctFlag = 1;
    for (int i = 0; i < n; i++) {
        if (zC[i] != zAsm[i]) correctFlag = 0;
    }

    if (correctFlag) {
        printf("The results between C and Assembly match.\n");
        printf("C average execution time:        %f ms\n", total_C / 30 *1000);
        printf("Assembly average execution time: %f ms\n", total_Asm / 30 *1000);
    }

    // Free the dynamically allocated memory
    free(x1);
    free(x2);
    free(y1);
    free(y2);
    return 0;
}