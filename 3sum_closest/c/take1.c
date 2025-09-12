#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

/*
3つの数字の和がINT_MAXを越える場合を想定して、minDist、sumおよびdistの型はlongにすること
*/
int __cpr_assend(const void *a, const void *b)
{
    int Inta = *(int *) a;
    int Intb = *(int *) b;
    return Inta - Intb;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // init 
    int minDist = INT_MAX;
    int result = 0;
    qsort(nums, numsSize, sizeof(int), __cpr_assend);

    // check dist
    for(int i=0; i<numsSize - 2; i++)
    {
        int *left = &nums[i+1];
        int *right = &nums[numsSize - 1];
        while(left < right)
        {
            int sum = nums[i] + *left + *right;
            int dist = target - sum;
            printf("mdist(%d), tar(%d) - (%d,%d,%d)= dist:%d\n", minDist, target, nums[i], *left, *right, dist);
            if(abs(dist) < minDist)
            {
                result = sum;
                minDist = abs(dist);

                // int prel = *left, prer = *right;
                // while(left < right && prel == *left)
                //     left++;
                // while(left < right && prer == *right)
                //     right--;
            }
            else if(dist > 0)
                left++;
            else
                right--;
        }
    }

    return (result);
}

int main(void)
{
    const int LEN = 9;
    int arr[] = {10,20,30,40,50,60,70,80,90};
    int target = 1;

    printf("---result---\n%d\n",threeSumClosest(arr, LEN, target));

    return (0);
}