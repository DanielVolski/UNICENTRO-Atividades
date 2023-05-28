#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Método da Bissecção */
double bissec(double a, double b, double delta, int it, double (*f)(double))
{
    double raiz_aproximada, epsilon, f1, f2;
    int k = 0; // Variável de controle de iterações

    if (fabs(b - a) < delta)
        return (b + a) / 2;
    
    do
    {
        f1 = f(a);
        epsilon = (a + b) / 2;
        f2 = f(epsilon);
        if (f1 * f2 < 0)
            b = epsilon;
        else
            a = epsilon;

        k++;
    } while (fabs(b - a) > delta && k < it);

    raiz_aproximada = epsilon;
    return raiz_aproximada;
}

/* Método iterativo linear */
double mil(double x0, double delta, int it, double (*f)(double), double (*phi)(double))
{
    double raiz_aproximada, x1;
    int k = 0; // Variável de controle de iterações

    if (fabs(f(x0)) < delta)
    {
        raiz_aproximada = x0;
        printf("%f\n", f(x0));
        return raiz_aproximada;
    }

    k++;

    do
    {
        x1 = phi(x0);

        if (fabs(f(x1)) < delta || fabs(x1 - x0) < delta)
        {
            raiz_aproximada = x1;
            return raiz_aproximada;
        }

        x0 = x1;
        k++;
    } while (k < it);
}

/* Método da Secante */
double sec(double x0, double x1, double delta, int it, double (*f)(double))
{
    double raiz_aproximada, x2;
    int k = 1; // Variável de controle de iterações

    if (fabs(f(x0)) < delta) 
    {
        raiz_aproximada = x0;
        return raiz_aproximada;
    }
    if (fabs(f(x1)) < delta || fabs(x1 - x0) < delta)
    {
        raiz_aproximada = x1;
        return raiz_aproximada;
    }

    do 
    {
        x2 = x1 - ((f(x1) * (x1 - x0)) / (f(x1) - (f(x0))));

        if (fabs(f(x2)) < delta || fabs(x2 - x1) < delta) 
        {
            raiz_aproximada = x2;
            return raiz_aproximada;
        }

        x0 = x1;
        x1 = x2;
        k++;

    } while (k < it);

    raiz_aproximada = x2;
    return raiz_aproximada;
}

/* Método Regula Falsi */
double falsi(double a, double b, double delta1, double delta2, int it, double (*f)(double))
{
    double raiz_aproximada = 0, M = 0, x = 0;
    int k = 1; //Variável de controle

    if (fabs(b - a) < delta1)
    {
        raiz_aproximada = (a + b)/2;
        return raiz_aproximada;
    }
        
    else if (fabs(f(a)) < delta2 || fabs(f(b)) < delta2)
    {
        raiz_aproximada = a;
        return raiz_aproximada;
    }

    do
    {    
        M = f(a);
        x = (a * f(b) - b * f(a))/(f(b) - f(a));
        
        if (fabs(f(x)) < delta2 || k > it)
        {
            raiz_aproximada = x;
            return raiz_aproximada;
        }

        if ((M * f(x)) > 0)
            a = x;
        else
            b = x;

        if (fabs(b - a) < delta1)
        {
            raiz_aproximada = (a + b)/2;
            printf("teste\n");
            return raiz_aproximada;
        }
        k++;
    } while (k < it);      
}