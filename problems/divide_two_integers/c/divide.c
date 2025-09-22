#include <limits.h>

int divide(int dividend, int divisor) {
    long result = (long)dividend / (long)divisor;

    if (result < INT_MIN)
        result = (long)INT_MIN;
    if (result > INT_MAX)
        result = (long)INT_MAX;

    return ((int)result);
}