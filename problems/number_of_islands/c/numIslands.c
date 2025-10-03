/*
first result
Runtime 20ms   , beats 62.47%
Memory  11.86MB, beats 35.77%
         → total beats 21%

*/

#include "../../../util.h"

#define CAPACITY 300*300

typedef struct s_point{
	int x;
	int y;
}	point;

void push(point *list, int *top, int y, int x)
{
	list[*top].x = x;
	list[*top].y = y;
	*top += 1;
}

point pop(point *list, int *top)
{
	*top -= 1;
	return (list[*top]);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    point	stack[CAPACITY];
    int		top = 0;
	int		islandCount = 0;

	for(int r=0; r<gridSize; r++){
		print_str(grid[r],gridColSize[r]);
	}
	printf("↓\n");

	for(int r=0; r<gridSize; r++){
		for(int c=0; c<gridColSize[r]; c++){
			if (grid[r][c] == '1')
			{
				push(stack,&top,r,c);
				grid[r][c] = '0';
				islandCount++;
			}	
			while(top > 0)
			{
				point current = pop(stack,&top);
				if (current.x > 0 && grid[current.y][current.x-1] == '1'){
					push(stack,&top,current.y,current.x-1);
					grid[current.y][current.x-1] = '0';
				}
				if (current.x < gridColSize[current.y] - 1 && grid[current.y][current.x+1] == '1'){
					push(stack,&top,current.y,current.x+1);
					grid[current.y][current.x+1] = '0';
				}
				if (current.y > 0 && grid[current.y-1][current.x] == '1'){
					push(stack,&top,current.y-1,current.x);
					grid[current.y-1][current.x] = '0';
				}
				if (current.y < gridSize - 1 && grid[current.y+1][current.x] == '1'){
					push(stack,&top,current.y+1,current.x);
					grid[current.y+1][current.x] = '0';
				}
			}
		}
	}

	for(int r=0; r<gridSize; r++){
		print_str(grid[r],gridColSize[r]);
	}

	return (islandCount);
}