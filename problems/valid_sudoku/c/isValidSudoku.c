#include <stdbool.h>
#include <stdio.h>

void arrinit(int *arr, int size)
{
    for(int i=0; i<size; i++)
        arr[i] = 0;
}

int isNum(char c)
{
    return (c >= '0' && c <= '9');
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int buf[10] = {0};

    // hori
    printf("hori:\n");
    for(int r=0; r<boardSize; r++){
        arrinit(buf,10);
        for(int c=0; c<boardColSize[r]; c++){
            if (!isNum(board[r][c])) 
                continue ;
            printf("%d",board[r][c] - '0');
            if (buf[board[r][c] - '0'] != 0)
                return (false);
            buf[board[r][c] - '0'] = 1;
        }
        printf("\n");
    }

    // vart
    printf("vart:\n");
    for(int c=0; c<boardSize; c++){
        arrinit(buf,10);
        for(int r=0; r<boardColSize[c]; r++){
            if (!isNum(board[r][c])) 
                continue ;
            printf("%d",board[r][c] - '0');
            if (buf[board[r][c] - '0'] != 0)
                return (false);
            buf[board[r][c] - '0'] = 1;
        }
        printf("\n");
    }
    
    // room
    printf("room:\n");
    for(int rp=0; rp<7; rp+=3){
        for(int cp=0; cp<7; cp+=3){
            arrinit(buf,10);
            for(int r=0; r<3; r++){
                for(int c=0; c<3; c++){
                    if (!isNum(board[r+rp][c+cp])) 
                        continue ;
                    printf("%d",board[r+rp][c+cp] - '0');
                    if (buf[board[r+rp][c+cp] - '0'] != 0)
                        return (false);
                    buf[board[r+rp][c+cp] - '0'] = 1;
                }
            }
            printf("\n");
        }
    }
    return (true);
}