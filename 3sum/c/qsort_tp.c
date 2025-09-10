#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    TLE突破して提出できたコード。しかし、RT:93msで中央値と比較してもかなり遅かった。
    
*/
void print_arr(int *arr, int size);

void swap(int *a, int *b)
{
	int buf;
	buf = *a;
	*a = *b;
	*b = buf;
}

int separate(int *arr, int left, int right)
{
	int pv = arr[right];
	int i = left - 1;

	printf("pivot[%d] :",pv);
	for(int j=left; j<right ;j++){
		if(arr[j] < pv){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[right]);
	print_arr(arr, 17);

	return (i + 1);
}

void my_qsort(int *nums, int left, int right)
{
	if(left < right)
	{
		int pv = separate(nums, left, right);
		my_qsort(nums, left, pv - 1);
		my_qsort(nums, pv + 1, right);
	}
}

int *make_trip(int a, int b, int c)
{
    int *trip = (int *)malloc(sizeof(int) * 3);

    trip[0] = a;
    trip[1] = b;
    trip[2] = c;

    return trip;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **result;
    int count_col;

   // init
	printf("--init--\n");
    result = (int **)malloc(sizeof(int *) * 3000);
    my_qsort(nums, 0, numsSize - 1);
	printf("\nsort end:\n");
	print_arr(nums, numsSize);
    count_col = 0;
    printf("\n--check sum--\n");

   // make triplet
   int i;
   int prei;
   int left, right;

   i = 0;
   prei = INT_MIN;
   while(i < numsSize - 2)
   {
        if (nums[i] == prei)
        {
            i++;
            continue;
        }
        // two-pointer
        left = i + 1;
        right = numsSize - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            printf("(%d,%d,%d)",nums[i], nums[left], nums[right]);
            if (sum == 0)
            {
                result[count_col] = make_trip(nums[i], nums[left], nums[right]);
                count_col++;

                int prel = nums[left];
                while (left < right && prel == nums[left])
                    prel = nums[left++];

                int prer = nums[right];
                while (left < right && prer == nums[right])
                    prer = nums[right--];
                printf(" --> make triplet\n");
            }
            else if(sum < 0)
            {
                int prel = nums[left];
                while (left < right && prel == nums[left])
                    prel = nums[left++];
                printf("\n");
            }
            else
            {
                int prer = nums[right];
                while (left < right && prer == nums[right])
                    prer = nums[right--];
                printf("\n");
            }
        }
        //
        prei = nums[i];
        i++;
   }

   *returnSize = count_col;
   **returnColumnSizes = 3;
   return   (result);
}

int main(void)
{
    int col_size;
    int *cols_ptr = &col_size;
    int re_size;

    int nums[17] = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    int **arr;
    
    arr = threeSum(nums, 17, &re_size, &cols_ptr);

    printf("\n--result--\n");
    for(int i=0; i<re_size ;i++){
        print_arr(arr[i], col_size);
        free(arr[i]);
    }
    free(arr);
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