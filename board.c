#include "headers.h"
#include "board.h"

void board_printer1(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        
        
        printf("%2d ", lines - i + 1);
        
        for (int j = 1; j <= columns; j++){
            /*
            if (board[i][j] == 19){
                printf("| ");
            }
            */
            if (board[i][j] > 9 && board[i][j] < 19)
                printf( "%d ", board[i][j] - 10);
            else if (board[i][j] == 9)
                printf("0 ");
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("   ");
    for (int i = 0; i < columns; i++){
        printf("%c ", i + 'A');
    }
    
    printf("\n");
}

void board_printer2(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        
        
        printf("%2d ", lines - i + 1);
        
        for (int j = 1; j <= columns; j++){
            /*
            if (board[i][j] == 19){
                printf("| ");
            }
            */
            if (board[i][j] < 9 && board[i][j] > 0)
                printf( "%d ", board[i][j]);
                /*
            else if (board[i][j] == 9)
                printf("0 ");
            */
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("   ");
    for (int i = 0; i < columns; i++){
        printf("%c ", i + 'A');
    }
    
    printf("\n");
}

void clear_board(int board[17][26])
{
    for (int i = 0; i < 17; i++){
        for (int j = 0; j < 26; j++){
            board[i][j] = 0;
        }
    }
}