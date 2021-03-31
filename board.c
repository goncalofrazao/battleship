#include "headers.h"
#include "board.h"

void board_printer(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        for (int j = 1; j <= columns; j++)
            if (board[i][j] > 0)
                printf( "%d ", board[i][j]);
            else
                printf("- ");
        printf("\n");
    }
}

void clear_board(int board[17][26], int lines, int columns)
{
    for (int i = 0; i < 27; i++){
        for (int j = 0; j < 18; j++){
            board[i][j] = 0;
        }
    }
}