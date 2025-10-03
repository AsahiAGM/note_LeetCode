#include "../../../util.h"

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes);

int main(void)
{
	int **building;
	int size = 0;
	int *_size;
	int **_colSize;
	int **result = NULL;

	// 1
	printf("-----\n");
	size = 5;
	int colSize[] = {3,3,3,3,3};
	building = malloc(sizeof(int *) * size);

	int bld_a[] = {2,9,10};
	int bld_b[] = {3,7,15}; 
	int bld_c[] = {4,12,12};
	int bld_d[] = {15,20,10};
	int bld_e[] = {19,24,8};
	building[0] = bld_a;
	building[1] = bld_b;
	building[2] = bld_c;
	building[3] = bld_d;
	building[4] = bld_e;

	_size = NULL;
	_colSize = NULL;
	result = getSkyline(building,size,colSize,_size,_colSize);
	for(int i=0; i<*_size ;i++)
		print_nums(result[i],_colSize[i][0]);
	arrs_free((void **)building,size);
	arrs_free((void **)_colSize,*_size);
	arrs_free((void **)result,*_size);
	
	// 2
	printf("-----\n");
	size = 2;
	int colSize2[] = {3,3};
	building = malloc(sizeof(int *) * size);

	int bld_a2[] = {0,2,3};
	int bld_b2[] = {2,5,3};
	building[0] = bld_a2;
	building[1] = bld_b2;

	_size = NULL;
	_colSize = NULL;
	result = getSkyline(building,size,colSize2,_size,_colSize);
	for(int i=0; i<*_size ;i++)
		print_nums(result[i],colSize2[i]);
	arrs_free((void **)building,size);
	arrs_free((void **)_colSize,*_size);
	arrs_free((void **)result,*_size);

	return (0);
}