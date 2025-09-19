#include <stdio.h>
#include <stdlib.h>

void print_arr(const char *arr, int size)
{
    printf("[");
    for(int i=0; i<size ;i++){
        if(i != 0)
            printf(",");
        printf("%c",arr[i]);
    }
    printf("]\n");
}

void arrs_free(void **arrs, size_t arrssize)
{
    for(size_t i=0; i<arrssize ;i++)
    {
        if(arrs[i])
            free(arrs[i]);
    }
    free(arrs);
}