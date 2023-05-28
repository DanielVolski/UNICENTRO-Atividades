#include "metodosIterativos.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double f(double x);
double f2(double x);
/* Corresponde a funçao f para aplicação do MIL */
double phi(double x);

int main()
{
    double (*fx_ptr)(double) = f;
    double (*phi_ptr)(double) = phi;
    double x0 = 1, x1 = 2, delta = 0.01;
    int it = 100;

    //mil(x0, delta, it, fx_ptr, phi_ptr);
    //printf("%f\n", phi_ptr(1.4653379771058));
    printf("%.10f\n", bissec(x0, x1, delta, it, fx_ptr));
    printf("%.10f\n", mil(1.5, delta, it, fx_ptr, phi_ptr));
    printf("%.10f\n", sec(x0, x1, delta, it, fx_ptr));
    printf("%.10f\n", falsi(x0, x1, delta, delta, it, fx_ptr));

    return 0;
}

double f(double x)
{
    return pow(M_E, -pow(x, 2)) - cos(x);
}

double f2(double x)
{
    return pow(x, 3) - 9 * x + 3;
}

double phi(double x)
{
    return cos(x) - pow(M_E, -pow(x, 2)) + x;
}