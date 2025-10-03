#include <stdbool.h>
#define MAX_LEN 10000

typedef struct stack{
    char *data;
    int top;
    int capacity;
} stack;

void push(stack *stack, char val)
{
    stack->data[stack->top] = val;
    stack->top += 1;
}

char pop(stack *stack)
{
    stack->top -= 1;
    char val = stack->data[stack->top];

    return (val);
}

int isOpen(char c)
{
    return (
        c == '(' ||
        c == '{' ||
        c == '['
    );
}

int isPair(char op, char cl)
{
    return (
        (op == '(' && cl == ')') ||
        (op == '{' && cl == '}') ||
        (op == '[' && cl == ']')
    );
}

bool isValid(char* s) {
    stack stack;
    char buf[MAX_LEN] = {0};
    
    stack.capacity = MAX_LEN;
    stack.top = 0;
    stack.data = buf;

    while(*s)
    {
        if (isOpen(*s))
        {
            if (stack.capacity == stack.top)
                return (false);
            push(&stack, *s);
        }
        else
        {
            if (stack.top == 0)
                return (false);
            if (!isPair(pop(&stack),*s))
                return (false);
        }
        s++;
    }
    return (stack.top == 0);
}