#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define RECTANGLES 1000

int main()
{
    double height = 0., width = 1. / RECTANGLES, sum = 0., aprox_pi = 0., x = 0.;

    // https://www.openmp.org/spec-html/5.0/openmpsu107.html documentação sobre o reduction
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < RECTANGLES; ++i) {
        x = (i + 0.5) * width;
        height = 4. / (1. + x * x);
        sum += height;
    }

    aprox_pi = width * sum;

    printf("%f\n", aprox_pi);

    return 0;
}