#include "headers.h"
#include "input_check.h"
#include "help.h"

/******************************************************************************
* Function name: check()
*
* Arguments: lines (int) - number of lines of the board in the game
*            columns (int) - number of columns of the board in the game
*            modo[3] (int) - array that saves all the modes
*                           mode[0] - game mode
*                           mode[1] - positioning mode
*                           mode[2] - shooting mode
*            p_num[9] (int) - array that saves the number of each type
*                            p_num[0] - number of free spaces
*                            p_num[1] - number of pieces type 1
*                            ...
*                            p_num[8] - number of pieces type 8
*            flag_d_in (int) - variable that says if there was shooting mode input
*            flag_pieces_in (int) - variable that says if there was pieces
*                                   input
*
* Return: -1 - if any of the propositions is true
*         1 - if all propositions are false
*           (all the propositions are non valid inputs)
*
* Side-effects: none
*
* Where funtion is used: main()
*
* Description: Check if every input is in valid parameters.
*              
*
*******************************************************************************/

int check(int lines, int columns, int modo[3], int p_num[9], int flag_d_in, int flag_pieces_in)
{
    // columns must multiple of 3 and between 9 and 24
    if (columns % 3 != 0 || columns < 9 || columns >24){
        return -1;
    }
    // lines must multiple of 3 and between 9 and 24
    if (lines % 3 != 0 || lines < 9 || lines > 15){
        return -1;
    }
    // game mode must be 0, 1 or 2
    if (modo[0] < 0 || modo[0] > 2 ){
        return -1;
    }
    // positioning mode must be 1 or 2
    if (modo[1] < 1 || modo[1] > 2 ){
        return -1;
    }
    // shooting mode must me 1 oe 2
    if (modo[2] < 1 || modo[2] > 3 ){
        return -1;
    }
    // number of pieces must be higher than 0
    if (p_num[0] < 0 || p_num[1] < 0 || p_num[2] < 0 || p_num[3] < 0 || p_num[4] < 0 || p_num[5] < 0 || p_num[6] < 0 || p_num[7] < 0){
        return -1;
    }
    // if both game and positioning modes are different of 2, there must be no input of pieces
    if (modo[0] != 2 && modo[1] != 2 && flag_pieces_in == 1){
        return -1;
    }
    // it is just valid shooting mode input if game mode = 2
    if (modo[0] != 2 && flag_d_in != 0){
        return -1;
    }
    return 1;
}