#include "headers.h"
#include "modo_j.h"
#include "modo_d.h"
#include "modo_p.h"
#include "board.h"

/*******************************************************************************
* Function name: modo_j0()
*
* Arguments: modo_p (int) - position mode
*            lines (int) - lines of board
*            columns (int) - columns of board
*            board[17][26] (int) - matrix of board
*            p_num[9] - number of pieces to put in the board
*
* Return: no return
*
* Side-effects: none
*
* Description: This function generates a board calling the positioning mode
*              input, prints board characteristics the board generated has and
*              prints the board
*
*******************************************************************************/

void modo_j0(int modo_p, int lines, int columns, int board[17][26], int p_num[9])
{
    // choose position mode and generate board
    switch (modo_p)
    {
    case 1:
        modo_p1(lines, columns, board, p_num);
        
        break;

    case 2:
        modo_p2(lines, columns, board, p_num);
        
        break;
    
    }
    // print characteristics of board
    printf("%dx%d", lines, columns);
    for (int i = 1; i < 9; i++)
        printf(" %d", p_num[i]);
    printf("\n");
    // print board
    board_printer(board, lines, columns);
}

/*******************************************************************************
* Function name: modo_j1()
*
* Arguments: modo_p (int) - position mode
*            lines (int) - lines of board
*            columns (int) - columns of board
*            board[17][26] (int) - matrix of board
*            p_num[9] - number of pieces to put in the board
*
* Return: no return
*
* Side-effects: none
*
* Description: This function generates a board calling the positioning mode
*              input, 
*
*******************************************************************************/

void modo_j1(int modo_p, int lines, int columns, int board[17][26], int p_num[9])
{
    char column_input;
    int column;
    int line;
    // generate a board with the position mode choose
    switch (modo_p)
    {
    case 1:
        modo_p1(lines, columns, board, p_num);
        break;

    case 2:
        modo_p2(lines, columns, board, p_num);
        break;
    }
    // print board characteristics
    printf("%dx%d", lines, columns);
    for (int i = 1; i < 9; i++)
        printf(" %d", p_num[i]);
    printf("\n");
    // get initial time
    time_t begin;
    time_t end;
    time(&begin);
    // get inputs of user until game ends
    int counter = 0;
    while(end_check(board, lines, columns) != 1){
        counter++;
        // get a valid input
        while(1){
            scanf(" %c%d", &column_input, &line);
            line = lines - line + 1;
            column = column_input - 'A' + 1;
            if (input(line, column, board, lines, columns) == 1){
                break;
            }
            else{ 
                printf("invalid input, try again\n");
            }
        }
        // print in stdout what is in position of the input
        if (board[line][column] < 1){
            printf("-\n");
        }
        else{
            printf("%d\n", board[line][column]);
            board[line][column] += 10;
        }
    }
    // get the end time
    time(&end);
    // print end game and board
    printf("Fim de Jogo: %d jogadas em %ld segundos\n", counter, end - begin);
    board_printer(board, lines, columns);
}

/*******************************************************************************
* Function name: modo_j2()
*
* Arguments: modo_d (int) - shooting mode
*            lines (int) - lines of board
*            columns (int) - columns of board
*            board[17][26] (int) - matrix of board
*            p_num[9] - number of pieces of the board
*
* Return: no return
*
* Side-effects: none
*
* Description: This function executes the shooting mode of the input, or the
*              default if there is no shooting mode in input
*
*******************************************************************************/

void modo_j2(int modo_d, int lines, int columns, int board[17][26], int p_num[9])
{
    // get initial time
    time_t begin;
    time_t end;
    int counter;
    time(&begin);
    // execute the input shooting mode
    switch (modo_d)
    {
    case 1:
        counter = modo_d1(board, lines, columns, p_num);
        break;

    case 2:
    case 3:
        counter = modo_d23(board, lines, columns, p_num, modo_d);
        break;
    }
    // get final time
    time(&end);
    // print game characteristics
    printf("Fim de Jogo: %d jogadas em %ld segundos\n", counter, end - begin);
    board_printer(board, lines, columns);
}

/*******************************************************************************
* Function name: input()
*
* Arguments: line (int) - y to check
*            column (int) - x to check
*            board[17][26] (int) - matrix of board
*            lines (int) - lines of the board
*            columns (iny) - columns of the board
*
* Return: -1 - if input is not valid
*         1 - if input is valid
*
* Side-effects: none
*
* Description: This function generates a board calling the positioning mode
*              input, 
*
*******************************************************************************/

int input(int line, int column, int board[17][26], int lines, int columns)
{
    // check if input is valid
    if(board[line][column] > 8 || line > lines || line < 1 || column > columns || column < 1){
        return -1;
    }
    else {
        return 1;
    }
}

/*******************************************************************************
* Function name: end_check()
*
* Arguments: board[17][26] (int) - matrix game
*            lines (int) - lines of the board
*            columns (iny) - columns of the board
*
* Return: -1 - if pieces left to destroy
*         1 - if board completely destroied
*
* Side-effects: none
*
* Description: This function checks if the game has ended
*
*******************************************************************************/

int end_check(int board[17][26], int lines, int columns)
{
    // go through all board positions
    for (int i = 1; i <= lines; i++){
        for (int d = 1; d <= columns; d++){
            // if a position is between 1 and 8 (not shooted yet) return -1
            if (board[i][d] < 9 && board[i][d] > 0)
                return -1;
        }
    }
    // if no piece left to shoot return 1
    return 1;
}