#include <unistd.h>

void __putnum(int num);

void __putarr(int *arr, int size)
{
    write(1, "{", 1);
    for(int i=0; i<size  ;i++)
    {
        if (i!=0)
            write(1, ", ", 1);
        __putnum(arr[i]);
    }
    write(1, "}", 1);
}