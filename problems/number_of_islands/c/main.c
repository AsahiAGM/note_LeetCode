#include "../../../util.h"

int numIslands(char** grid, int gridSize, int* gridColSize);

int main(void)
{
    int     row = 4;
    int     col[] = {5,5,5,5};
    
    char a[] = {'1','1','1','1','0','\0'};
    char b[] = {'1','1','0','1','0','\0'};
    char c[] = {'1','1','0','0','0','\0'};
    char d[] = {'0','0','0','0','0','\0'};
    char *grid[] = {a,b,c,d};
    printf("%d\n\n", numIslands(grid,row,col));

    char a2[] = {'1','1','0','0','0','\0'};
    char b2[] = {'1','1','0','0','0','\0'};
    char c2[] = {'0','0','1','0','0','\0'};
    char d2[] = {'0','0','0','1','1','\0'};
    char *grid2[] = {a2,b2,c2,d2};
    printf("%d\n\n", numIslands(grid2,row,col));

    char a3[] = {'1','0','1','1','0','1','1','\0'};
    char *grid3[] = {a3};
    int  col3[] = {7};
    row = 1;
    printf("%d\n\n", numIslands(grid3,row,col3));

    char a4[] = {'1','1','1','\0'};
    char b4[] = {'0','1','0','\0'};
    char c4[] = {'1','1','1','\0'};
    char *grid4[] = {a4,b4,c4};
    int  col4[] = {3,3,3};
    row = 3;
    printf("%d\n\n", numIslands(grid4,row,col4));

    char a5[] = {'1','1','1','1','1','1','\0'};
    char b5[] = {'1','0','0','0','0','1','\0'};
    char c5[] = {'1','0','1','1','0','1','\0'};
    char d5[] = {'1','0','0','0','0','1','\0'};
    char e5[] = {'1','1','1','1','1','1','\0'};
    char *grid5[] = {a5,b5,c5,d5,e5};
    int  col5[] = {6,6,6,6,6};
    row = 5;
    printf("%d\n\n", numIslands(grid5,row,col5));

    char a6[] = {'1','0','1','1','1','\0'};
    char b6[] = {'1','0','1','0','1','\0'};
    char c6[] = {'1','1','1','0','1','\0'};
    char *grid6[] = {a6,b6,c6};
    int  col6[] = {5,5,5};
    row = 3;
    printf("%d\n\n", numIslands(grid6,row,col6));
}