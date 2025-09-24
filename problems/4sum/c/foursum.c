
/*
used struct ver.

runtime 39ms  beats 5.75%
*/
#include <stdio.h>
#include <stdlib.h>

#include "../../../util.h"

typedef struct s_pointer{
    int left;
    int right;
    int combIdx;
    int combSize;
}   t_pointer;

int __acsend_sort(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; 
}

int *genComb(int *src, int size)
{
    int *buf = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++)
        buf[i] = src[i];

    return (buf);
}

void tSum(int *nums, int *buf, t_pointer pointer, int target, int *combCount, int **result)
{
    long __p_sum = 0;
    for(int i=0; i<pointer.combSize-2 ;i++)
        __p_sum += buf[i];

    while(pointer.left < pointer.right)
    {
        printf("comb[%d,%d,%d,%d]", buf[0], buf[1], nums[pointer.left], nums[pointer.right]);
        long sum = __p_sum + nums[pointer.left] + nums[pointer.right];
        if (sum == target)
        {
            buf[pointer.combIdx]   = nums[pointer.left];
            buf[pointer.combIdx+1] = nums[pointer.right];
            result[*combCount] = genComb(buf, pointer.combSize);
            printf(" -> gen combination\n");
            *combCount += 1;
            pointer.left += 1;
            while (pointer.left < pointer.right && (nums[pointer.left] == nums[pointer.left-1])) 
                pointer.left += 1;
            pointer.right -= 1;
            while (pointer.left < pointer.right && (nums[pointer.right] == nums[pointer.right+1]))
                pointer.right -= 1;
        }
        if (sum < target)
        {
            pointer.left += 1;
            while (pointer.left < pointer.right && (nums[pointer.left] == nums[pointer.left-1]))
                pointer.left += 1;
            printf("\n");
        }
        if (sum > target)
        {
            pointer.right -= 1;
            while (pointer.left < pointer.right && (nums[pointer.right] == nums[pointer.right+1]))
                pointer.right -= 1;
            printf("\n");
        }
    }
}

void kSum(int* nums, int numsSize, int *buf, t_pointer pointer, int target, int *combCount, int **result)
{
    if (pointer.combIdx == 2)
    {
        tSum(nums, buf, pointer, target, combCount, result);
        return ;
    }
    for(int i=pointer.left; i<numsSize ;i++)
    {
        if (i > pointer.left && (nums[i] == nums[i-1]))
            continue ;

        buf[pointer.combIdx] = nums[i];
        
        t_pointer __next_ptr = pointer;
        __next_ptr.combIdx  += 1;
        __next_ptr.left     = i + 1;

        kSum(nums, numsSize, buf, __next_ptr, target, combCount, result);
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // init
    t_pointer   pointer; 
    int         **result = malloc(sizeof(int *) * (numsSize * numsSize));
    int         combCount = 0;

    qsort(nums, numsSize, sizeof(int), __acsend_sort);
    print_nums(nums, numsSize);

    int *buf = malloc(sizeof(int) * 4);
    for(int i=0; i<4 ;i++) buf[i] = 0;
    pointer.left = 0;
    pointer.right = numsSize - 1;
    pointer.combIdx = 0;
    pointer.combSize = 4;

    // kSum
    kSum(nums, numsSize, buf, pointer, target, &combCount, result);

    // result
    *returnSize = combCount;
    *returnColumnSizes = malloc(sizeof(int)*combCount);
    printf(":result %d combs (target: %d)\n",combCount,target);
    for(int i=0; i<*returnSize ;i++)
        (*returnColumnSizes)[i] = 4;

    // free
    free(buf);
    return (result);
}

/*
first 

:false
cant find all combination
*/
/*
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    // init 
    int **result = malloc(sizeof(int *) * (numsSize * numsSize));
    int combCount = 0;
    qsort(nums, numsSize, sizeof(int), __acsend_sort);
    
    printf(":arrs ");
    print_nums(nums,numsSize);

    // double two_pointer
    int oLeft = 0, oRight = numsSize - 1;
    while(oRight - oLeft >= 3)
    {
        int sum = target - 1;
        int iLeft = oLeft + 1, iRight = oRight -1;
        //printf("ol:%d, or:%d, il:%d, ir:%d\n",oLeft,oRight,iLeft,iRight);
        while(iLeft < iRight)
        {
            sum = nums[oLeft] + nums[oRight] + nums[iLeft] + nums[iRight];
            printf("%d,%d,%d,%d", nums[oLeft], nums[iLeft], nums[iRight], nums[oRight]);
            if (sum == target)
            {
                result[combCount] = genComb(nums[oLeft], nums[iLeft], nums[iRight], nums[oRight]);
                printf(" -> gen combination\n");
                combCount++;
                iLeft++;
                while (iLeft < iRight && (nums[iLeft] == nums[iLeft-1])) 
                    iLeft++;
                iRight--;
                while (iLeft < iRight && (nums[iRight] == nums[iRight+1]))
                    iRight--;
            }
            if (sum < target)
            {
                iLeft++;
                while (iLeft < iRight && (nums[iLeft] == nums[iLeft-1]))
                    iLeft++;
                printf("\n");
            }
            if (sum > target)
            {
                iRight--;
                while (iLeft < iRight && (nums[iRight] == nums[iRight+1]))
                    iRight--;
                printf("\n");
            }
        }

        if (sum <= target)
        {
            oLeft++;
            while (oRight - oLeft >= 3 && (nums[oLeft] == nums[oLeft-1])) 
                oLeft++;
        }
        if (sum > target)
        {
            oRight--;
            while (oRight - oLeft >= 3 && (nums[oRight] == nums[oRight+1]))
                oRight--;
        }
    }

    // result
    *returnSize = combCount;
    *returnColumnSizes = malloc(sizeof(int)*combCount);
    printf(":result (%d)\n",combCount);
    for(int i=0; i<*returnSize ;i++)
        (*returnColumnSizes)[i] = 4;

    return (result);
}
*/
