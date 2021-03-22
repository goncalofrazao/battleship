#include "headers.h"
#include "board.h"

void board_printer(int board[15][24], int lines, int columns)
{
    for (int i = 0; i < lines; i++){
        if (i + 1 > 9){
            printf("%d    ", i + 1);
        }
        else {
            printf("0%d    ", i + 1);
        }
        for (int j = 0; j < columns; j++)
            printf( "%d ", board[j][i]);
        printf("\n");
    }
}

void clear_board(int board[15][24], int lines, int columns)
{
    for (int i = 0; i < lines; i++){
        for (int j = 0; j < columns; j++)
            board[j][i] = 0;
    }
}