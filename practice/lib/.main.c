#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	__putchar(char c);
void	__putstr(char *str);
void	__putnum(int num);
void	__putarr(int *arr, int size);
int		__strlen(char* str);
int		__strcmp(char* s1, char* s2);
void	__swap(int *a, int *b);

int main(void)
{
    write(1, "__putchar:\n", 12);
    __putchar('z');
    write(1, "\n", 1);

    write(1, "__putstr:\n", 11);
    __putstr("hello!!");
    write(1, "\n", 1);

    write(1, "__putnum:\n", 11);
    __putnum(INT_MAX);
    write(1, "\n", 1);
    __putnum(INT_MIN);
    write(1, "\n", 1);

    write(1, "__strlen:\n", 11);
    __putnum(__strlen("world!!"));
    write(1, "\n", 1);

	write(1, "__swap:\n", 9);
    int arrA[3] = {1,2,3};
	__swap(&arrA[0], &arrA[2]);
	__putarr(arrA, 3);
    write(1, "\n", 1);

	write(1, "__strcmp:\n", 11);
	__putnum(__strcmp("hello","hello"));
	write(1, "\n", 1);
	__putnum(__strcmp("hello","hello!!"));
	write(1, "\n", 1);

    return 0;
}