#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

void print_arr(int *arr, int size);

// int minCostClimbingStairs(int* cost, int costSize) {
//     // err hnd
//     if (!cost && costSize < 2)
//         return (0);
    
//     // init
//     int buf[MAX_LEN + 1];
//     for(int i=0; i<=costSize; i++)
//         buf[i] = 0;

//     // dp
//     buf[0] = cost[0];
//     buf[1] = cost[1];
//     for(int i=2; i<costSize; i++)
//     {
//         printf("%d:%d (i=%d,cost[i]=%d)\n",buf[i-2], buf[i-1], i, cost[i]);
//         if (buf[i-2] < buf[i-1])
//             buf[i] = buf[i-2] + cost[i];
//         else
//             buf[i] = buf[i-1] + cost[i]; 
//     }
//     print_arr(buf, costSize + 1);

//     if (buf[costSize-2] < buf[costSize-1])
//         return (buf[costSize-2]);
    
//     return (buf[costSize-1]);
// }
/*
2変数で解けるDP問題も存在する。
保存する状態の数がいくつあるのかを見極めることが大切
*/
int minCostClimbingStairs(int* cost, int costSize) {
    // err hnd
    if (!cost && costSize < 2)
        return (0);
    
    // init
    int prev1 = cost[0];
    int prev2 = cost[1];
    for(int i=2; i<costSize ;i++)
    {
        printf("%d,%d + %d\n",prev1,prev2,cost[i]);
        int better = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        prev1 = prev2;
        prev2 = better;
    }

    return (prev1 < prev2 ? prev1 : prev2);
}

int main(void)
{
    const int LEN = 5;
    int cost[] = {2,1,0,1,3};

    printf("---result---\n%d\n",minCostClimbingStairs(cost, LEN));

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