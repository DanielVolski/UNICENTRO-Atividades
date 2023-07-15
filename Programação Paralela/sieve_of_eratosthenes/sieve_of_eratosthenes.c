#include <stdio.h>
#include <omp.h>

#define N_THREADS 4
#define N 1000

void print_sieve(int *sieve, int sieve_size);

int main() 
{
    omp_set_num_threads(N_THREADS);

    int primes[N + 1];

    #pragma omp parallel for
    for (int i = 2; i <= N; i++) {
        primes[i] = 1;
    }

    for (int i = 2; i * i <= N; i++)
        if (primes[i] == 1) 
            #pragma omp parallel for
            for (int j = i * i; j <= N; j += i)
                primes[j] = 0;

    print_sieve(primes, N);

    return 0;
}

void print_sieve(int *sieve, int sieve_size)
{
    for (int i = 2; i <= N; i++)
        if (sieve[i])
            printf("%d ", i);
}