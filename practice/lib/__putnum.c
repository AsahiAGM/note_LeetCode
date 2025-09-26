#include <unistd.h>
#include <limits.h>

void __putnum(int num)
{
    if (num == INT_MIN)
    {
        write(1, "-2147483648", 12);
        return ;
    }
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
    }
    if (num / 10 != 0)
        __putnum(num / 10);

    char c = (num % 10) + '0';
    write(1, &c, 1);
}