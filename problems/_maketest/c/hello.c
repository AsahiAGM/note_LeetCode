#include <stdio.h>
#include <stdlib.h>

void __print_arr(char *arr[], int size)
{
    for(int i=0; i<size ;i++){
        printf("%s",arr[i]);
    }
}

void hello(void)
{
    char *str[] = {
        "\ncan use command is [all, clean, fclean, re]\n\n",
        "all [language] [problem_name] [solution_name]\n",
        " -language: supported languages\n",
        "\tc, cpp, python, cs(csharp), rust, go\n",
        " -problem_name: folder name (as leetcode problem name)\n",
        " -solution_name: name of script\n\n"
    };
    __print_arr(str, 6);

    // segmentation fault and not free
    int *buf = malloc(sizeof(int) * 3);
    while(*buf++)

    *buf = 4;
}

