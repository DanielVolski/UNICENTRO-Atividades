#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *string = "Hello\0";

    while (*string != '\0')
    {
        printf("%c\n", *string);
        string = string + sizeof(char);
    }
    return 0;
}