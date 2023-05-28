#include <stdio.h>

int partition(int *vet, int p, int r)
{
    int x = vet[r];
    int i = p - 1, j = 0;
    int aux = 0;

    for (j = p; i < r; i++)
        if (vet[j] <= x)
        {
            i++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    aux = vet[i + 1];
    vet[i] = vet[j];
    vet[j] = aux;
}

void quicksort(int *vet, int p, int r)
{
    if (p < r)
    {
        int q = partition(vet, p, r);
        quicksort(vet, p, q - 1);
        quicksort(vet, q + 1, r);
    }
}

int main()
{
    int vet[6] = {3, 42, 9, 10, 5, 2};

    quicksort(vet, 0, 5);
    
    for (int i = 0; i < 6; i++)
        printf("%d ", vet[i]);

    return 0;
}