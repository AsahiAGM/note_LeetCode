#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../util.h"

bool isValidSudoku(char** board, int boardSize, int* boardColSize);

int main(void)
{
    int size = 9;
    int colsize[9] = {9,9,9,9,9,9,9,9,9};
    
    char **board = malloc(sizeof(char *)*9);
    for(int i=0; i<9; i++)
        board[i] = malloc(sizeof(char)*10);
    strcpy(board[0],"53..7....");
    strcpy(board[1],"6..195...");
    strcpy(board[2],".98....6.");
    strcpy(board[3],"8...6...3");
    strcpy(board[4],"4..8.3..1");
    strcpy(board[5],"7...2...6");
    strcpy(board[6],".6....28.");
    strcpy(board[7],"...419..5");
    strcpy(board[8],"....8..79");
    printf("\nresult:(%d)\n",isValidSudoku(board,size,colsize));
    arrs_free((void **)board,9);

    char **board2 = malloc(sizeof(char *)*9);
    for(int i=0; i<9; i++)
        board2[i] = malloc(sizeof(char)*10);
    strcpy(board2[0],"83..7....");
    strcpy(board2[1],"6..195...");
    strcpy(board2[2],".98....6.");
    strcpy(board2[3],"8...6...3");
    strcpy(board2[4],"4..8.3..1");
    strcpy(board2[5],"7...2...6");
    strcpy(board2[6],".6....28.");
    strcpy(board2[7],"...419..5");
    strcpy(board2[8],"....8..79");
    printf("\nresult:(%d)\n",isValidSudoku(board2,size,colsize));
    arrs_free((void **)board2,9);
}