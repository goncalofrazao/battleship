#include "headers.h"
#include "board.h"

void board_printer(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        for (int j = 1; j <= columns; j++)
            printf( "%d ", board[j][i]);
        printf("\n");
    }
}

void clear_board(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        for (int j = 1; j <= columns; j++){
            board[j][i] = 0;
        }
    }
}