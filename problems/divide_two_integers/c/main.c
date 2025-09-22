#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor);

int main(void)
{
    printf("\n%d -> %d\n", 10, divide(10,3));
    printf("%d -> %d\n", 10, divide(10,-3));
    printf("%d -> %d\n", INT_MAX, divide(INT_MAX,100));
    printf("%d -> %d\n", INT_MIN, divide(INT_MIN,-1));
    printf("\n");
}