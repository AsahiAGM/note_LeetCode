#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../../../util.h"

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);

int main(void)
{
    int **res = NULL;
    int nums[] = {1,0,-1,0,-2,2};
    int target = 0;
    int returnSize = 0;
    int *sizes = NULL;

    printf("---test1---\n");
    res = fourSum(nums,6,target,&returnSize,&sizes);
    for(int i=0; i<returnSize ;i++)
        print_nums(res[i], sizes[i]);

    free(sizes);
    arrs_free((void **)res, returnSize);

    printf("---test2---\n");
    int arrs[] = {2,2,2,2,2};
    target = 8;
    res = fourSum(arrs,5,target,&returnSize,&sizes);
    for(int i=0; i<returnSize ;i++)
        print_nums(res[i], sizes[i]);

    free(sizes);
    arrs_free((void **)res, returnSize);

    printf("---test3---\n");
    int test3[] = {-3,-1,0,2,4,5};
    target = 2;
    res = fourSum(test3,6,target,&returnSize,&sizes);
    for(int i=0; i<returnSize ;i++)
        print_nums(res[i], sizes[i]);

    free(sizes);
    arrs_free((void **)res, returnSize);

    printf("---test3 [all zero]---\n");
    int zeros[] = {0,0,0,0,0};
    target = 0;
    res = fourSum(zeros,5,target,&returnSize,&sizes);
    for(int i=0; i<returnSize ;i++)
        print_nums(res[i], sizes[i]);

    free(sizes);
    arrs_free((void **)res, returnSize);

    printf("---too short---\n");
    int tooshort[] = {2,2,2};
    target = 8;
    res = fourSum(tooshort,3,target,&returnSize,&sizes);
    for(int i=0; i<returnSize ;i++)
        print_nums(res[i], sizes[i]);
    free(sizes);
    arrs_free((void **)res, returnSize);

    printf("---big integer---\n");
    int bigints[] = {1000000000,1000000000,1000000000,1000000000};
    target = 0;
    res = fourSum(bigints,4,target,&returnSize,&sizes);
    for(int i=0; i<returnSize ;i++)
        print_nums(res[i], sizes[i]);        

    free(sizes);
    arrs_free((void **)res, returnSize);
}