#include <stdio.h>
#include <stdlib.h>

/*
    先輩コードを勉強してRT:34msになりました。Cで実行速度を速くするには、
    ・標準ライブラリ関数を使う
    ・ポインタ操作を直接行う
    これが実行時間を短くするポイントだそうです

    leetcode側でポインタ操作ver.で書き換えてみたが、28～35msでした
    実行環境がleetcodeのサーバー依存だから、その差異はあるかもしれない。

    beats 90% 超えてるので、まぁ良し。
*/
void print_arr(int *arr, int size);

int compareInt(const void *a, const void *b)
{
    int ia = *(const int*) a;
    int ib = *(const int*) b;
    if (ia == ib)
        return 0;
    return ia > ib;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
    // init
    int **result;
    int count_col;
    result = malloc(sizeof(int *) * (numsSize * numsSize));
    if(result == NULL)
        return NULL;
    qsort(nums, numsSize, sizeof(int), compareInt);
    count_col = 0;
    printf("\n--check sum--\n");

    // make triplet
    int i;
    int left, right;

    i = 0;
    while(i < numsSize - 2 && nums[i] <= 0)
    {
        if(i > 0 && nums[i-1] == nums[i])
        {
            i++;
            continue;
        }
        else
        {
            // two-pointer
            left = i + 1;
            right = numsSize - 1;
            while (left < right)
            {
                if (nums[i] == 0 && nums[left] > 0)
                    break;

                int sum = nums[i] + nums[left] + nums[right];
                printf("(%d,%d,%d)",nums[i], nums[left], nums[right]);
                if (sum == 0)
                {
                    result[count_col] = (int *)malloc(sizeof(int) * 3);
                    if (result[count_col] == NULL)
                    {
                            for(int m=0; m<count_col; m++){
                                free(result[m]);
                            }
                            free(result);
                            return NULL;
                    }
                    result[count_col][0] = nums[i];
                    result[count_col][1] = nums[left];
                    result[count_col][2] = nums[right];
                    count_col++;

                    int prel = nums[left], prer = nums[right];
                    while (left < right && prel == nums[left])
                        left++;
                    while (left < right && prer == nums[right])
                        right--;
                    printf(" --> make triplet\n");
                }
                else if(sum < 0)
                {
                    left++;
                    printf("\n");
                }
                else
                {
                    right--;
                    printf("\n");
                }              
            }
            i++;
        }
   }

    *returnSize = count_col;
    *returnColumnSizes = (int *)malloc(sizeof(int) * count_col);
    if (*returnColumnSizes == NULL)
    {
        for(int i=0; i<count_col; i++){
            free(result[i]);
        }
        free(result);
        return NULL;
    }
    for(int i=0; i<count_col; i++)
    {
            (*returnColumnSizes)[i] = 3;
    }
    return   (result);
}

int main(void)
{
    int *cols_ptr = NULL;
    int re_size;

    int nums[17] = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    int **arr;
    
    arr = threeSum(nums, 17, &re_size, &cols_ptr);

    printf("\n--result--\n");
    for(int i=0; i<re_size ;i++){
        print_arr(arr[i], 3);
        free(arr[i]);
    }
    free(arr);
    free(cols_ptr);
    return (0);
}

void print_arr(int *arr, int size)
{
    for(int i=0; i<size ;i++){
        if(i != 0)
            printf(",");
        printf("%d",arr[i]);
    }
    printf("\n");
}