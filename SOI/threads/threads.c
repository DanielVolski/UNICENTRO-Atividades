#include <stdio.h>
#include <pthread.h>

typedef struct sum_args
{
    int x;
    int y;
} sum_args;

void* sum(void *args)
{
    int *result = malloc(sizeof(int));
    sum_args *struct_args = (sum_args *) args;
    *result = struct_args->x + struct_args->y;
    return result;
}

int main()
{
    pthread_t thread1, thread2;
    sum_args *args1 = malloc(sizeof(sum_args)), *args2 = malloc(sizeof(sum_args));
    int n = 0, *result1 = NULL, *result2 = NULL;

    scanf("%d", &n);
    args1->x = n;
    args1->y = 5;
    args2->x = n;
    args2->y = 10;

    pthread_create(&thread1, NULL, &sum, args1);
    pthread_create(&thread2, NULL, &sum, args2);
    pthread_join(thread1, &result1);
    pthread_join(thread2, &result2);
    printf("%d\n", *result1 + *result2);
    free(args1);
    free(args2);

    return 0;
}