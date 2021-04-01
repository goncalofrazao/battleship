#include "headers.h"
#include "board.h"

void board_printer(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        for (int j = 0; j <= columns; j++){
            if (j == 0){
                if (i < 10)
                    printf(" %d ",i);
                else
                    printf("%d ", i);
            }
            else if (board[i][j] > 0)
                printf( "%d ", board[i][j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    for (int i = 0; i < columns; i++){
        if (i < 1)
            printf("   ");
        else 
            printf("%c ", i + 'A');
    }
    printf("\n");
}

void clear_board(int board[17][26], int lines, int columns)
{
    for (int i = 0; i < 27; i++){
        for (int j = 0; j < 18; j++){
            board[i][j] = 0;
        }
    }
}