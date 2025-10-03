/*
DPでやろうとして失敗した。やっぱりDFSでないと解けないらしい。
DPなのかDFSなのかの判断ってどこでやるんだろうか。
パターン認識だと未踏破領域に弱くなるんだよな
*/

#include "../../../util.h"

// #include <stdlib.h>

// void arrs_free(void **arrs, size_t arrssize)
// {
//     for(size_t i=0; i<arrssize ;i++)
//     {
//         if(arrs[i])
//             free(arrs[i]);
//     }
//     free(arrs);
// }

int numIslands(char** grid, int gridSize, int* gridColSize) {  
    int islandCount = 0;
    int **__grid;

    __grid = malloc(sizeof(int *) * gridSize);
    for(int i=0; i<gridSize ;i++)
        __grid[i] = malloc(sizeof(int) * gridColSize[i]);
    for(int r=0; r<gridSize; r++)
        for(int c=0; c<gridColSize[r]; c++)
            __grid[r][c] = grid[r][c] - '0';

    for(int r=0; r<gridSize ;r++){
        for(int c=0; c<gridColSize[r]; c++){
            if (__grid[r][c] == 0)
                continue ;
            int tarY = (r==0) ? 0 : __grid[r-1][c];
            int tarX = (c==0) ? 0 : __grid[r][c-1];
            // new          
            if( tarY == 0 && tarX == 0){
                __grid[r][c] = __grid[r][c] + islandCount;
                islandCount += 1;
                continue ;
            }
            // join
            if( tarY == 0 || tarX == 0 ){
                __grid[r][c] = (tarY == 0) 
                                ? tarX
                                : tarY;
                continue ;
            }
            // union
            __grid[r][c]   = (tarY > tarX) ? tarX : tarY;
            __grid[r-1][c] = (tarY > tarX) ? tarX : tarY;
            __grid[r][c-1] = (tarY > tarX) ? tarX : tarY;
        }
    }

    // find max
    int max = 0;
    for(int r=0; r<gridSize; r++)
        for(int c=0; c<gridColSize[r]; c++)
            max = (__grid[r][c] > max) ? __grid[r][c] : max; 

    for(int i=0; i<gridSize; i++)
        print_nums(__grid[i],gridColSize[i]);
    arrs_free((void **)__grid, gridSize);

    return (max);
}