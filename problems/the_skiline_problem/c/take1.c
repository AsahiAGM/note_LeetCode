/*
it's troll answer :(
*/

#include "../../../util.h"

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes) {
    int **lines = malloc(sizeof(int *) * INT_MAX);
	int *skyline = malloc(sizeof(int) * INT_MAX);
	int rightLimit = 0;
	
	(void)buildingsColSize;

	// input
	for(int bld=0; bld<buildingsSize ;bld++){
		// [0]left,[1]right,[2]height
		for(int ceil=buildings[bld][0]; ceil<=buildings[bld][1] ;ceil++){
			skyline[ceil] = (buildings[bld][2] > skyline[ceil])
							? buildings[bld][2]
							: skyline[ceil];
		}
		rightLimit = (buildings[bld][1] > rightLimit)
					 ? buildings[bld][1]
					 : rightLimit;
	}

	// make point
	int lineid = 0;
	if (skyline[0] != 0)
	{
		int *point = malloc(sizeof(int) * 2);
		point[0] = 0;
		point[1] = skyline[0];
		lines[lineid] = point;
		lineid++;
	}
	for(int r=1; r<rightLimit ;r++){
		if (skyline[r-1] != skyline[r]){
			int *point = malloc(sizeof(int) * 2);
			point[0] = r;
			point[1] = skyline[r];
			lines[lineid] = point;
			lineid++;
		}
	}

	// result
	*returnSize = lineid;
	*returnColumnSizes = malloc(sizeof(int *) * *returnSize);
	for(int i=0; i<*returnSize; i++){
		int *buf = malloc(sizeof(int));
		*buf = 2;
		returnColumnSizes[i] = buf; 
	}

	return (lines);
}