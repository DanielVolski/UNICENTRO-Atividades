#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define POINTS 1000

int main()
{
    int circle_points = 0;
    double x = 0., y = 0. , aprox_pi = 0.;

    srand(omp_get_wtime());

    // https://www.openmp.org/spec-html/5.0/openmpsu107.html documentação sobre o reduction
    // https://www.openmp.org/wp-content/uploads/OpenMPRefCard-5-2-web.pdf documentação sobre o private
    #pragma omp parallel for private(x, y) reduction(+:circle_points)
    for (int i = 0; i < POINTS; ++i) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if ((x * x + y * y) <= 1.)
            circle_points++;
    }

    aprox_pi = 4.0 * circle_points / POINTS;

    printf("%f\n", aprox_pi);

    return 0;
}