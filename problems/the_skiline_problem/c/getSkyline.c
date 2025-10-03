
#include "../../../util.h"

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes) {
	int **lines = malloc(sizeof(int *) * (buildingsSize * 2));
	int *buf = malloc(sizeof(int) * (buildingsSize * 2));
	int idx = 0;

	for(int bld=0; bld<buildingsSize ;bld++){
		for(int i=0; i<buildingsColSize[bld] ;i++){

		}
	}
	// result
	*returnSize = 1;
	*returnColumnSizes = malloc(sizeof(int *) * *returnSize);
	for(int i=0; i<*returnSize; i++){
		int *buf = malloc(sizeof(int));
		*buf = 2;
		returnColumnSizes[i] = buf; 
	}

	return (lines);
}