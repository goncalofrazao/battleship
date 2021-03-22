#include "headers.h"
#include "pieces.h"

//Esta função irá returnar o identificador global das peças

int global_id_returner(int type_id, int instance_id)
{
    int global_id;
    switch (type_id)
    {
        case 1:
            global_id = instance_id;    
            break;

        case 2:
            global_id = instance_id + 9;

        case 3:
            global_id = instance_id + 21;

        case 4:
            global_id = instance_id + 27;

        case 5:
            global_id = instance_id + 31;

        case 6:
            global_id = instance_id + 35;

        case 7:
            global_id = instance_id + 39;
        
        case 8:
            global_id = 42;
    }
    return global_id;
}

void positioning_board(int x, int y, int global_id, int board[15][24])
{
    switch (global_id)
    {
    case 1: 
            board[x][y] = 1;
        break;
    
    case 2: 
            board[x + 1][y] = 1;
        break;

    case 10:
            board[x][y] = 2;
            board[x+1][y] = 2;
        break;
    
    default:
        break;
    }

}
