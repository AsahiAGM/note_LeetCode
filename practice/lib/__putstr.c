#include <unistd.h>

void __putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}