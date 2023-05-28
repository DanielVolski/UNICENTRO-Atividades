#ifndef LIST
    #define LIST
    typedef struct List 
    {
        int value;
        struct List *next;
    } List;
#endif

#ifndef HASH_MAP_FUNCTIONS
    #define HASH_MAP_FUNCTIONS
    void insert_hash(int value, List **list, int(*hash_function)(int));
    List *search_hash(int value, List **list, int(*hash_function)(int));
    void print_hash_table(List **list, int classes, int(*hash_function)(int));
#endif