#include <stdlib.h>

void dfs(char** grid, int gridSize, int* gridColSize, int i, int j) {
    // Boundary check
    if (i < 0 || i >= gridSize || j < 0 || j >= gridColSize[i] || grid[i][j] == '0') {
        return;
    }

    // Mark as visited
    grid[i][j] = '0';

    // Visit all adjacent cells
    dfs(grid, gridSize, gridColSize, i + 1, j); // Down
    dfs(grid, gridSize, gridColSize, i - 1, j); // Up
    dfs(grid, gridSize, gridColSize, i, j + 1); // Right
    dfs(grid, gridSize, gridColSize, i, j - 1); // Left
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int numIslands=0;
    for(int i=0; i<gridSize; i++){
        for(int j=0; j < gridColSize[i]; j++){
            if(grid[i][j] == '1'){
                numIslands++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return numIslands;
}