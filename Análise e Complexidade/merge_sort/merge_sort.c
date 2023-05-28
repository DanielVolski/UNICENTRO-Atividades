#include <stdio.h>
#include <limits.h>
#include <math.h>

#define SIZE_ARRAY 8

int arr[SIZE_ARRAY] = {3, 41, 52, 26, 38, 57, 9, 49};

void merge(int start_array, int mid_array, int end_array)
{
    int n1 = (mid_array - start_array) + 1;
    int n2 = (end_array - mid_array);
    int left[n1], right[n2];
    int i = 0, j = 0, k = 0;

    for (i = 0; i < n1; i++)
        left[i] = arr[start_array + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid_array + j + 1];

    i = 0;
    j = 0;
    k = start_array;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int start_array, int end_array)
{
    if (start_array < end_array)
    {
        int mid_array = start_array + (end_array - start_array) / 2;
        merge_sort(start_array, mid_array);
        merge_sort(mid_array + 1, end_array);
        merge(start_array, mid_array, end_array);
    }
}

void print_array(int arr[], int array_size)
{
    for (int i = 0; i < array_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    print_array(arr, SIZE_ARRAY);
    merge_sort(0, SIZE_ARRAY - 1);
    print_array(arr, SIZE_ARRAY);

    return 0;
}