/*
hashtableを使って作成したtripletをlookupする方法にしたが、TLE。
結局敗北宣言してAIに聞いたら、q_sort & tow-pointerが正解らしいのでそれを実装します。

two-pointerは三重ループでやっていたことを二分探索してtriplet候補を探すことで
見つけているようです
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define HASH_KEY 10003

void print_arr(int *arr, int size);

typedef struct hashnode{
    struct hashnode    *next;
    long long   		key;
}   hnode;

int trymake_key(hnode htable[], int min, int mid, int max)
{
    while(min > mid || mid > max)
    {
		if (min > mid)
		{
			int tmp = mid;
			mid = min;
			min = tmp;
		}
		if (mid > max)
		{
			int tmp = max;
			max = mid;
			mid = tmp;
		}
	}

    // make key
    long long	key = ((long long)min << 40) ^ ((long long)mid << 20) ^ (long long)max;
    int			idx = key % HASH_KEY;

	if (idx < 0) 
		idx += HASH_KEY;
    
    if (htable[idx].key == 0)
    {
		htable[idx].key = key;
		htable[idx].next = NULL;
		return (1);
    }
    
	// check & add key
	hnode	*current = &htable[idx];
	while(current){
		if (current->key == key)
			return (0);
		if (current->next == NULL)
			break;
		current = current->next;
	}
	hnode	*newnode = malloc(sizeof(hnode));
	newnode->key = key;
	newnode->next = NULL;
	current->next = newnode;

    return (1);
}

int *make_trip(int a, int b, int c)
{
    int *trip = malloc(sizeof(int) * 3);
	trip[0] = a;
	trip[1] = b;
	trip[2] = c;

    for(int i=0; i<2 ;i++)
		for(int j=i+1; j<3 ;j++){
			if (trip[i] < trip[j]){
				int tmp = trip[i];
				trip[i] = trip[j];
				trip[j] = tmp;
			}
		}

    return (trip);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) 
{
	hnode 	htable[HASH_KEY];
	int 	**result;
	int 	count_col;

	// init
    result = (int **)malloc(sizeof(int *) * 3000);
	count_col = 0;
	for(int h=0; h<HASH_KEY ;h++)
	{
		htable[h].key = 0;
		htable[h].next = NULL;
	}

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
				printf("(%d,%d,%d)",nums[i],nums[j],nums[k]);
				if (nums[i] + nums[j] + nums[k] == 0)
				{                    
					if (trymake_key(htable, nums[i], nums[j], nums[k]))
					{
						printf(" --> make key");
						result[count_col] = make_trip(nums[i], nums[j], nums[k]);
						count_col++;
					}   
				}
				printf("\n");
				prek = nums[k];
				k++;
			}
			prej = nums[j];
			j++;
		}
		prei = nums[i];
		i++;
	}

	for(int i=0; i<HASH_KEY ;i++)
	{
		hnode *current = htable[i].next;
		while(current){
			hnode *next = current->next;
			free(current);
			current = next;
		}
	}

	*returnSize = count_col;
    *returnColumnSizes = malloc(sizeof(int) * count_col);
    for(int i=0; i<count_col; i++){
        (*returnColumnSizes)[i] = 3;
    }

	return   (result);
}

int main(void)
{
    int *cols_size;
    int re_size;

    int nums[6] = {-1, 0, 1, 2, -1, -4};
    int **arr;
    
    arr = threeSum(nums, 6, &re_size, &cols_size);

    printf("\n--result--\n");
    for(int i=0; i<re_size ;i++){
        print_arr(arr[i], cols_size[i]);
        free(arr[i]);
    }
    free(arr);
	free(cols_size);

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