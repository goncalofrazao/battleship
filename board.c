#include "headers.h"
#include "board.h"

/******************************************************************************
* Function name: board_printer()
*
* Arguments: board[][] (int) - board matrix
*            lines (int) - number of lines of the game
*            columns (int) - number of columns of the game
*
* Return: No return
*         
*
* Side-effects: none
*
* Description: This function is used in all modes. It reads the values of each
*              position in matrix and prints it in stdout.
*              In the beggining of each line it also prints the number of the
*              line, and after printing all lines it prints a line with column
*              identification.
*
*******************************************************************************/

void board_printer(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        // print number of line
        printf("%2d ", lines - i + 1);
        for (int j = 1; j <= columns; j++){
            // print 'board position i j' the board if board[i][j] has the type of piece
            if (board[i][j] < 9 && board[i][j] > 0)
                printf( "%d ", board[i][j]);
            // print 'position i j - 10' the board if board[i][j] has the type of piece
            else if (board[i][j] > 10 && board[i][j] < 19)
                printf( "%d ", board[i][j] - 10);
            // print '-' if it is not a piece
            else
                printf("- ");
        }
        printf("\n");
    }
    // prints line with column identifier
    printf("   ");
    for (int i = 0; i < columns; i++){
        printf("%c ", i + 'A');
    }
    
    printf("\n");
}

/******************************************************************************
* Function name: clear_board()
*
* Arguments: board[][] (int) - 2 dimensions matrix of the game with the
*                              value of each position
*
* Return: No return.
*
* Side-effects: all the matrix to 0
*
* Description: This funtion is used to reset all the board positions to 0.
*
*******************************************************************************/

void clear_board(int board[17][26])
{
    for (int i = 0; i < 17; i++){
        for (int j = 0; j < 26; j++){
            // position i j to 0
            board[i][j] = 0;
        }
    }
}