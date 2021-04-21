#include "headers.h"
#include "pieces.h"

// declaration of all pieces

const int piece[43][5][5] = {  {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        {-1,-1,-1, 0, 0},
                        {-1, 1, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0,-1,-1,-1 ,0},
                        { 0, 0, 1, 0 ,0},
                        { 0, 0, 0, 0 ,0},
                        { 0, 0, 0, 0 ,0},
                        { 0, 0, 0, 0 ,0},},

                        {
                        { 0, 0,-1,-1,-1},
                        { 0, 0, 0, 1,-1},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        {-1, 1, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 1, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 1,-1},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        {-1, 1, 0, 0, 0},
                        {-1,-1,-1, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 1, 0, 0},
                        { 0,-1,-1,-1, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 1,-1},
                        { 0, 0,-1,-1,-1},},

                        {
                        {-1,-1,-1,-1, 0},
                        {-1, 2, 2, 0, 0},
                        {-1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0,-1,-1,-1,-1},
                        { 0, 0, 2, 2,-1},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        {-1, 2, 2, 0, 0},
                        {-1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 2, 2,-1},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        {-1, 2, 2, 0, 0},
                        {-1,-1,-1,-1, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 2, 2,-1},
                        { 0,-1,-1,-1,-1},},

                        {
                        {-1,-1,-1, 0, 0},
                        {-1, 2, 0, 0, 0},
                        {-1, 2, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        {-1, 2, 0, 0, 0},
                        {-1, 2, 0, 0, 0},
                        {-1,-1,-1, 0, 0},},

                        {
                        { 0,-1,-1,-1, 0},
                        { 0, 0, 2, 0, 0},
                        { 0, 0, 2, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 2, 0, 0},
                        { 0, 0, 2, 0, 0},
                        { 0,-1,-1,-1, 0},},

                        {
                        { 0, 0,-1,-1,-1},
                        { 0, 0, 0, 2,-1},
                        { 0, 0, 0, 2,-1},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 2,-1},
                        { 0, 0, 0, 2,-1},
                        { 0, 0,-1,-1,-1},},

                        {
                        {-1,-1,-1,-1,-1},
                        {-1, 3, 3, 3,-1},
                        {-1, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0,-1},
                        {-1, 3, 3, 3,-1},
                        {-1, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0,-1},
                        {-1, 3, 3, 3,-1},
                        {-1,-1,-1,-1,-1},},

                        {
                        {-1,-1,-1, 0, 0},
                        {-1, 3, 0, 0, 0},
                        {-1, 3, 0, 0, 0},
                        {-1, 3, 0, 0, 0},
                        {-1,-1,-1, 0, 0},},

                        {
                        { 0,-1,-1,-1, 0},
                        { 0, 0, 3, 0, 0},
                        { 0, 0, 3, 0, 0},
                        { 0, 0, 3, 0, 0},
                        { 0,-1,-1,-1, 0},},

                        {
                        { 0, 0,-1, 0, -1},
                        { 0, 0, 0, 3, -1},
                        { 0, 0, 0, 3, -1},
                        { 0, 0, 0, 3, -1},
                        { 0, 0,-1,-1, -1},},

                        {
                        {-1,-1,-1,-1, 0},
                        {-1, 4, 4, 0, 0},
                        {-1, 4, 4, 0, 0},
                        {-1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0,-1,-1,-1,-1},
                        { 0, 0, 4, 4,-1},
                        { 0, 0, 4, 4,-1},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 0, 0, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        {-1, 0, 0, 0, 0},
                        {-1, 4, 4, 0, 0},
                        {-1, 4, 4, 0, 0},
                        {-1,-1,-1,-1, 0},},

                        {
                        { 0, 0, 0, 0, 0},
                        { 0, 0, 0, 0,-1},
                        { 0, 0, 4, 4,-1},
                        { 0, 0, 4, 4,-1},
                        { 0,-1,-1,-1,-1},},

                        {
                        {-1,-1,-1,-1,-1},
                        {-1, 5, 5, 5,-1},
                        {-1, 0, 5, 0,-1},
                        { 0, 0, 5, 0, 0},
                        { 0,-1,-1,-1, 0},},

                        {
                        {-1,-1,-1, 0, 0},
                        {-1, 5, 0, 0,-1},
                        {-1, 5, 5, 5,-1},
                        {-1, 5, 0, 0,-1},
                        {-1,-1,-1, 0, 0},},

                        {
                        { 0,-1,-1,-1, 0},
                        { 0, 0, 5, 0, 0},
                        {-1, 0, 5, 0,-1},
                        {-1, 5, 5, 5,-1},
                        {-1,-1,-1,-1,-1},},

                        {
                        { 0, 0,-1,-1,-1},
                        {-1, 0, 0, 5,-1},
                        {-1, 5, 5, 5,-1},
                        {-1, 0, 0, 5,-1},
                        { 0, 0,-1,-1,-1},},

                        {
                        { 0,-1,-1,-1, 0},
                        {-1, 0, 6, 0,-1},
                        {-1, 6, 0, 6,-1},
                        {-1, 6, 6, 6,-1},
                        {-1,-1,-1,-1,-1},},

                        {
                        { 0,-1,-1,-1,-1},
                        {-1, 0, 6, 6,-1},
                        {-1, 6, 0, 6,-1},
                        {-1, 0, 6, 6,-1},
                        { 0,-1,-1,-1,-1},},

                        {
                        {-1,-1,-1,-1,-1},
                        {-1, 6, 6, 6,-1},
                        {-1, 6, 0, 6,-1},
                        {-1, 0, 6, 0,-1},
                        { 0,-1,-1,-1, 0},},

                        {
                        {-1,-1,-1,-1, 0},
                        {-1, 6, 6, 0,-1},
                        {-1, 6, 0, 6,-1},
                        {-1, 6, 6, 0,-1},
                        {-1,-1,-1,-1, 0},},

                        {
                        {-1,-1,-1,-1,-1},
                        {-1, 7, 0, 7,-1},
                        {-1, 7, 7, 7,-1},
                        {-1, 7, 0, 7,-1},
                        {-1,-1,-1,-1,-1},},

                        {
                        {-1,-1,-1,-1,-1},
                        {-1, 7, 7, 7,-1},
                        {-1, 0, 7, 0,-1},
                        {-1, 7, 7, 7,-1},
                        {-1,-1,-1,-1,-1},},

                        {
                        {-1,-1,-1,-1,-1},
                        {-1, 8, 8, 8,-1},
                        {-1, 8, 0, 8,-1},
                        {-1, 8, 8, 8,-1},
                        {-1,-1,-1,-1,-1},}

};

/*******************************************************************************
* Function name: global_id_returner()
*
* Arguments: type_id (int) - type of the piece
*            instance_id (int) - instance of the piece
*
* Return: global_id
*
* Side-effects: none
*
* Description: This function return the global id correspondent to the type
*              and instance of the input
*
*******************************************************************************/

int global_id_returner(int type_id, int instance_id)
{
    switch (type_id)
    {
        case 1:
            return instance_id;

        case 2:
            return instance_id + 9;

        case 3:
            return instance_id + 21;

        case 4:
            return instance_id + 27;

        case 5:
            return instance_id + 31;

        case 6:
            return instance_id + 35;

        case 7:
            return instance_id + 39;

        case 8:
            return 42;
    }
    return 0;
}

/*******************************************************************************
* Function name: positioning_pieces()
*
* Arguments: x (int) - x of the top left position of the square to position the piece
*            y (int) - y of the top left position of the square to position the piece
*            global_id (int) - global id of the piece to position
*            board[17][26] (int) - matrix of board
*
* Return: no return
*
* Side-effects: changes the positions of the board
*
* Description: This funtion returns a random instance of the type of piece
*
*******************************************************************************/

void positioning_pieces(int x, int y, int global_id, int board[17][26])
{
    // go through all the positions of a square
    for (int i = 0; i < 5; i++){
        for (int d = 0; d < 5; d++){
            // changes the value of the square in the board to the values of the matrix of the pieces
            if (piece[global_id][i][d] > 0 || (piece[global_id][i][d] == -1 && board [y - 1 + i][x - 1 + d] == 0))
                board[y - 1 + i][x - 1 + d] = piece[global_id][i][d];
        }
    }

}

/*******************************************************************************
* Function name: instance_generator()
*
* Arguments: type (int) - type of the piece
*
* Return: random instance (int)
*
* Side-effects: none
*
* Description: This funtion returns a random instance of the type of piece
*
*******************************************************************************/

int instance_generator(int type)
{
    int instance = 0;
    // select the type and generate a random instance between the possible instances of a type
    switch (type)
    {
    case 1:
        instance = (rand() % 9) + 1;
        break;

    case 2:
        instance = (rand() % 12) + 1;
        break;

    case 3:
        instance = (rand() % 6) + 1;
        break;

    case 4:
    case 5:
    case 6:
        instance = (rand() % 4) + 1;
        break;

    case 7:
        instance = (rand() % 2) + 1;
        break;

    case 8:
        instance = 1;
    default:
        instance = 0;
        break;
    }
    return instance;
}

/*******************************************************************************
* Function name: max_instance()
*
* Arguments: type (int) - type of the piece
*
* Return: max instance (int)
*
* Side-effects: none
*
* Description: This funtion returns the max instance of the type of piece
*
*******************************************************************************/

int max_instance(int type)
{
    int max = 0;
    if (type == 1)
        max = 9;
    if (type == 2)
        max = 12;
    if (type == 3)
        max = 6;
    if (type > 3 && type < 7)
        max = 4;
    if (type == 7)
        max = 2;
    if (type == 8)
        max = 1;
    return max;
}

/*******************************************************************************
* Function name: global_id_to_type()
*
* Arguments: global_id (int) - global id of the piece
*
* Return: type (int)
*
* Side-effects: none
*
* Description: This funtion returns the type of the piece from the global id
*              input
*
*******************************************************************************/

int global_id_to_type(int global_id)
{
    if (global_id == 0){
        return 0;
    }
    else if (global_id < 10){
        return 1;
    }
    else if (global_id < 22){
        return 2;
    }
    else if (global_id < 28){
        return 3;
    }
    else if (global_id < 32){
        return 4;
    }
    else if (global_id < 36){
        return 5;
    }
    else if (global_id < 40){
        return 6;
    }
    else if (global_id < 42){
        return 7;
    }
    else{
        return 8;
    }
}
