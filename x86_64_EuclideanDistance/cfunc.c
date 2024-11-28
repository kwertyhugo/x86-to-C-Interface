#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>



void cfunc(int n, float* x1, float* x2, float* y1, float* y2, float* zC) {
    for (int i = 0; i < n; i++) {
        zC[i] = (x1[i] - x2[i])*(x1[i] - x2[i]) + (y1[i] - y2[i])*(y1[i] - y2[i]);
        zC[i] = sqrt(zC[i]);
    }
}

