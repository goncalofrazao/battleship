#include "headers.h"
#include "restricoes.h"
#include "pieces.h"

/*******************************************************************************
* Function name: restricao1()
*
* Arguments: x (int) - x of the top left of the square to check
*            y (int) - y of the top left of the square to check
*            global_id (int) - global id of piece to position
*            columns (int) - columns of the game
*            lines (int) - lines of the game
*            board[17][26] - matrix of the board
*
* Return: 1 - if the piece fulfills the retriciont 1
*         -1 - if piece does not fulfill the restriction 1
*
* Side-effects: none
*
* Description: This function checks if the piece to put fulfills the 
*              restriction 1
*
*******************************************************************************/

int restricao1(int x, int y, int global_id, int columns, int lines, int board[17][26])
{
    for (int i = 1; i < 4; i++){
        for (int d = 1; d < 4; d++){
            // if the spot of the piece is more than 1 and the board is -1 in the position break with a return -1
            if (board[y - 1 + i][x - 1 + d] == -1 && piece[global_id][i][d] > 0)
                return -1;
        }
    }
    return 1;
}

/*******************************************************************************
* Function name: restricao2()
*
* Arguments: columns (int) - columns of the game
*            lines (int) - lines of the game
*            p_num[9] - number of pieces of each type to position
*
* Return: 1 - if the piece fulfills the retriciont 2
*         -1 - if piece does not fulfill the restriction 2
*
* Side-effects: none
*
* Description: This function checks if the piece to put fulfills the 
*              restriction 2
*
*******************************************************************************/

int restricao2(int lines, int columns, int p_num[9])
{
    int sum = 0;
    // total pieces to position
    for (int i = 1; i < 9; i++)
        sum += p_num[i];
    // return -1 if total pieces > max pieces possible
    if (sum > (lines * columns / 9)){
        return -1;
    }
    return 1;
}

/*******************************************************************************
* Function name: restricao3()
*
* Arguments: p_num[9] - number of pieces of each type to position
*
* Return: 1 - if the piece fulfills the retriciont 3
*         -1 - if piece does not fulfill the restriction 3
*
* Side-effects: none
*
* Description: This function checks if the piece to put fulfills the 
*              restriction 3
*
*******************************************************************************/

int restricao3(int p_num[9])
{
    for (int i = 8; i > 1; i--){
        // if pieces of type i-1 are less than of type i return -1
        if (p_num[i] > p_num[i - 1]){
            return -1;
        }
    }
    return 1;
}

/*******************************************************************************
* Function name: restricao4()
*
* Arguments: p_num[9] - number of pieces of each type to position
*            lines (int) - lines of the game
*            columns (int) - columns of the game
*
* Return: 1 - if the piece fulfills the retriciont 4
*         -1 - if piece does not fulfill the restriction 4
*
* Side-effects: none
*
* Description: This function checks if the piece to put fulfills the 
*              restriction 4
*
*******************************************************************************/

int restricao4(int lines, int columns, int p_num[9])
{
    int n_pecas = 0;
    // calcule the sum of total pieces to position
    for (int i = 1; i < 9; i++)
        n_pecas += p_num[i];
    // check if pieces to position are less than the max pieces allowed and if not return -1
    if (n_pecas > (lines * columns / 9 / 2)){
        return -1;
    }
    return 1;
}
