#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s);

int main(void)
{
    printf("%d\n", isValid("()"));
    printf("%d\n", isValid("()[]{}"));
    printf("%d\n", isValid("(]"));
    printf("%d\n", isValid("([])"));
    printf("%d\n", isValid("([)]"));
    printf("%d\n", isValid("("));
}