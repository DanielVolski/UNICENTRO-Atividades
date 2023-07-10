#include <stdio.h>
#include <omp.h>
#include <math.h>

#define N 1000
#define N_THREADS 1

void init_sieve(int *v, int n);
void print_v(int *v, int n);
void pre_calculate_n_primes(int *v, int n);
int is_prime(int n);
void set_next_prime(int *sieve, int sieve_size, int *v, int index_to_put_prime);
void get_primes_from_sieve(int *sieve, int sieve_size);

int main()
{
    int sieve[N], primes[N_THREADS], thread_id;

    init_sieve(sieve, N);
    pre_calculate_n_primes(primes, N_THREADS);
    
    #pragma omp parallel num_threads(N_THREADS)
    {
        thread_id = omp_get_thread_num();
        while (primes[thread_id] != 0)
        {
            for (int i = primes[thread_id] + 1; i < N; i += primes[thread_id])
                sieve[i] = 0;
            set_next_prime(sieve, N, primes, thread_id);
        }
    }
    //printf("%d\n", is_prime(2));
    //print_v(sieve, N);
    get_primes_from_sieve(sieve, N);
}

// Inicia o crivo assumindo que todos os valores são primos
void init_sieve(int *v, int n)
{
    for (int i = 0; i <= n; i++)
        v[i] = 1;
}

void print_v(int *v, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

void pre_calculate_n_primes(int *v, int n)
{
    int j = 2, prime_not_found = 1;
    for (int i = 0; i < n; i++)
    {
        prime_not_found = 1;
        while (prime_not_found)
        {
            if (is_prime(j))
            {
                v[i] = j;
                prime_not_found = 0;
            }
            j++;
        }
    }
}

int is_prime(int n)
{
    int sqrt_n = floor(sqrt(n));
    for (int i = 1; i <= sqrt_n; i += 1)
        if (n % i == 0 && i != 1) return 0;
    return 1;
}

// Procura o próximo primo não marcado
void set_next_prime(int *sieve, int sieve_size, int *v, int index_to_put_prime)
{
    int i = 2;
    while (sieve[i] != 0 && i < sieve_size)
        i++;
    v[index_to_put_prime] = (sieve[i] == 0) ? 0 : i;
}

void get_primes_from_sieve(int *sieve, int sieve_size)
{
    for (int i = 1; i < sieve_size; i++)
        if (sieve[i] == 1)
            printf("%d ", i);
}