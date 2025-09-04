#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
TLEでした。どうやらHashtable使わないといけないらしいです
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
	print_arr(arr, 5);

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
   int i,j,k;
   int prei,prej,prek;

   i = 0;
   j = 0;
   k = 0;
   prei = INT_MIN;
   while(i < numsSize)
   {
        if (nums[i] == prei)
        {
            i++;
            continue;
        }
        j = i + 1;
		prej = INT_MIN;
        while (j < numsSize)
        {
            if (nums[j] == prej)
            {
                j++;
                continue;
            }
            k = j + 1;
			prek = INT_MIN;
            while (k < numsSize)
            {
                if (nums[k] == prek)
                {
                    k++;
                    continue;
                }
                // check sum
				printf("(%d,%d,%d)\n",nums[i],nums[j],nums[k]);
                if (nums[i] + nums[j] + nums[k] == 0)
                {                    
                    result[count_col] = make_trip(nums[i], nums[j], nums[k]);
                    count_col++;
                }

                prek = nums[k];
                k++;
            }
            prej = nums[j];
            j++;
        }
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

    int nums[5] = {1, -1, 0, -2, 1};
    int **arr;
    
    arr = threeSum(nums, 5, &re_size, &cols_ptr);

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