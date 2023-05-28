#ifndef HEAP_FUNCTIONS
    #define HEAP_FUNCTIONS
    void swap(int *i, int *j);
    void heapify(int *a, int a_size, int i);
    void build_max_heap(int *a, int a_size);
    void heapsort(int *heap, int heap_size);
#endif