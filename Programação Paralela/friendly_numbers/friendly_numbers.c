#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 1000

int sum_divisors(int num);

int main()
{
    int sums[MAX + 1] = { 0 };

    #pragma omp parallel for
    for (int i = 1; i <= MAX; i++)
        sums[i] = sum_divisors(i);

    // https://www.openmp.org/spec-html/5.0/openmpsu107.html documentação sobre o reduction
    #pragma omp parallel for reduction(+:count)
    for (int i = 1; i <= MAX; i++)
        if (sums[i] <= MAX && i != sums[i] && sums[sums[i]] == i)
            printf("%d %d\n", i, sums[i]);

    return 0;
}

int sum_divisors(int num) 
{
    int sum = 1;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i)
                sum += num / i;
        }
    }

    return sum;
}