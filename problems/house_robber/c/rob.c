
/*
house robber
https://leetcode.com/problems/house-robber/submissions/1768142734/

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

void print_arr(int *arr, int size)
{
    for(int i=0; i<size ;i++){
        if(i != 0)
            printf(",");
        printf("%d",arr[i]);
    }
    printf("\n");
}

/*
静的宣言配列をバッファにしたdp。配列長が決まっているので上限を考慮する手間がない。
i-2から0まで候補を確認するのでnが大きくなるほど実行時間も指数的に増えてしまうが、
とりあえずこれでも問題は通過する。
*/
// int rob(int* nums, int numsSize) {
//     if(numsSize == 1)
//         return (nums[0]);
//     if(numsSize == 2)
//         return (nums[0] > nums[1] ? nums[0] : nums[1]);

//     // init    
//     int max = 0;
//     int buf[MAX_LEN];

//     for(int i=0; i<MAX_LEN ;i++)
//         buf[i] = 0;

//     // dp
//     buf[0] = nums[0];
//     buf[1] = nums[1];
//     for(int i=0; i<numsSize ;i++)
//     {	
//         for(int j=i-2; j>=0; j--)
//         {
//             int sum = nums[i]+buf[j];
//             if (max <= sum)
//             {
//                 max = sum;
//                 buf[i] = sum;
//             }
//         }
//         print_arr(buf, numsSize);
//     }
//     return (max > buf[numsSize-2] ? max : buf[numsSize-2]);
// }

/*
配列使用最適化Ver.
iの要素について、「盗むor盗まない」を判断すればいいだけなので、候補の頭までさかのぼる必要はない
*/
// int rob(int* nums, int numsSize) {
//     if(numsSize == 1)
//         return (nums[0]);
//     if(numsSize == 2)
//         return (nums[0] > nums[1] ? nums[0] : nums[1]);

//     // init    
//     int buf[MAX_LEN] = {0};
//     buf[0] = nums[0];
//     buf[1] = nums[0] > nums[1] ? nums[0] : nums[1];

// 	//dp
//     for(int i=2; i<numsSize ;i++)
//     {	
//         int rob = buf[i-2] + nums[i];
// 		int skip = buf[i-1];
// 		buf[i] = rob > skip ? rob : skip;

//         print_arr(buf, numsSize);
//     }
//     return (buf[numsSize-1]);
// }

/*
配列なし最適化ver.
*/
int rob(int* nums, int numsSize) {
    if(numsSize == 1)
        return (nums[0]);
    if(numsSize == 2)
        return (nums[0] > nums[1] ? nums[0] : nums[1]);

    // init    
    int pv2 = nums[0];
    int pv1 = (nums[0] > nums[1] ? nums[0] : nums[1]);

	//dp
    for(int i=2; i<numsSize ;i++)
    {	
		printf("rob,%d : skip,%d\n",pv2 + nums[i], pv1);
        int better = (pv2 + nums[i] > pv1 ? pv2 + nums[i] : pv1);
		pv2 = pv1;
		pv1 = better;
    }
    return (pv1);
}

int main(void)
{
    const int LEN = 5;
    int arr[] = {7,1,3,9,2};

    printf("---result---\n%d\n\n",rob(arr,LEN));

	// ex1
	int ex1[] = {1,2,3,1};
	printf("---result---\n%d\n\n",rob(ex1,4));

	// ex2
	int ex2[] = {2,7,9,3,1};
	printf("---result---\n%d\n\n",rob(ex2,5));

	// ex3
	int ex3[] = {1,3,1};
	printf("---result---\n%d\n\n",rob(ex3,3));

    return (0);
}
