#include <stdio.h>
#include <omp.h>

#define N 1000

int main()
{
    int a[N], b[N], c[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = i;
        b[i] = i;
        c[i] = 0;
    }

    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < N; i++)
            c[i] = a[i] + b[i];
    }

    return 0;
}