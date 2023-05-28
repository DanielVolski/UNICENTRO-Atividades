#include <stdio.h>
#include "../headers/heap.h"

//Simple function to swap the values pointed by two pointers
void swap(int *i, int *j)
{
    int aux = *i;
    *i = *j;
    *j = aux;
}

void max_heapify(int *a, int a_size, int i)
{
    int greatest = i; //The root node
    int left = 2 * i + 1; //Gets the left node of the root
    int right = 2 * i + 2; //Gets the right node of the root

    //If the left node is greater than the root the greatest is updated
    if (left < a_size && a[left] > a[greatest])
        greatest = left;
    //If the right node is greater than the root the greatest is updated
    if (right < a_size && a[right] > a[greatest])
        greatest = right;
    //If the greatest value is not the root than it is swapped
    if (greatest != i)
    {
        swap(&a[i], &a[greatest]);
        max_heapify(a, a_size, greatest);
    }
}

void build_max_heap(int *a, int a_size)
{
    for (int i = (a_size / 2); i >= 0; i--)
        max_heapify(a, a_size, i);
}

void heapsort(int *a, int a_size)
{
    //Creates the max heap before sorting it
    build_max_heap(a, a_size);

    for (int i = a_size - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]); //Swaps the root node with the most right leaf node
        max_heapify(a, i, 0); //Corrects the heap after the swapping
    }
}