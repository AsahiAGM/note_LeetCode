/*
for chatGPT
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void twoSum(int* nums, int left, int right, int target, 
            int* buf, int bufSize, int*** result, int* returnSize, int** returnColumnSizes) {
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            int* comb = malloc(sizeof(int) * (bufSize + 2));
            for (int i = 0; i < bufSize; i++) comb[i] = buf[i];
            comb[bufSize] = nums[left];
            comb[bufSize+1] = nums[right];

            (*result)[*returnSize] = comb;
            (*returnColumnSizes)[*returnSize] = bufSize + 2;
            (*returnSize)++;

            left++;
            while (left < right && nums[left] == nums[left-1]) left++;
            right--;
            while (left < right && nums[right] == nums[right+1]) right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
}

void kSum(int* nums, int start, int end, int k, int target, 
          int* buf, int bufSize, int*** result, int* returnSize, int** returnColumnSizes) {
    if (k == 2) {
        twoSum(nums, start, end, target, buf, bufSize, result, returnSize, returnColumnSizes);
        return;
    }

    for (int i = start; i <= end - k + 1; i++) {
        if (i > start && nums[i] == nums[i-1]) continue;  // 重複除外

        buf[bufSize] = nums[i];
        kSum(nums, i+1, end, k-1, target - nums[i], buf, bufSize+1, result, returnSize, returnColumnSizes);
    }
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int capacity = numsSize * numsSize;  // 上限見積もり
    int** result = malloc(sizeof(int*) * capacity);
    *returnColumnSizes = malloc(sizeof(int) * capacity);
    *returnSize = 0;

    int* buf = malloc(sizeof(int) * 4);

    kSum(nums, 0, numsSize-1, 4, target, buf, 0, &result, returnSize, returnColumnSizes);

    free(buf);
    return result;
}
