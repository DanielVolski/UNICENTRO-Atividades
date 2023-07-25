#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 100

int main()
{
    int v1[SIZE], v2[SIZE], sum[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        v1[i] = i;
        v2[i] = i;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < SIZE; ++i) {
            sum[i] = v1[i] + v2[i];
        }
    }

    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", sum[i]);

    return 0;
}