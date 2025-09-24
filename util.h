#ifndef UTIL_H
# define UTIL_H

#include <stdlib.h>
void print_str(const char *arr, int size);
void print_nums(const int *arr, int size);
void arrs_free(void **arrs, size_t arrssize);

#endif