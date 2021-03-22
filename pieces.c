#include "headers.h"
#include "pieces.h"

/*Esta função irá returnar o identificador global das peças em função do 
identificador da peça e da variante
*/

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


//esta função identifica a posição das peças no tabuleiro em função com o identificador global
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

    case 3:
        board[x + 2][y] = 1;
        break;

    case 4:
        board[x][y + 1] = 1;
        break;

    case 5:
        board[x + 1][y + 1] = 1;
        break;

    case 6:
        board[x + 2][y + 1] = 1;
        break;

    case 7:
        board[x][y + 2] = 1;
        break;

    case 8:
        board[x + 1][y + 2] = 1;
        break;

    case 9:
        board[x + 2][y + 2] = 1;
        break;

    case 10:
        board[x][y] = 2;
        board[x + 1][y] = 2;
        break;

    case 11:
        board[x + 1][y] = 2;
        board[x + 2][y] = 2;
        break;

    case 12:
        board[x][y + 1] = 2;
        board[x + 1][y + 1] = 2;
        break;
    
    case 13:
        board[x + 1][y + 1] = 2;
        board[x + 2][y + 1] = 2;
        break;

    case 14:
        board[x][y + 2] = 2;
        board[x + 1][y + 2] = 2;
        break;

    case 15:
        board[x + 1][y + 2] = 2;
        board[x + 2][y + 2] = 2;
        break;

    case 16:
        board[x][y] = 2;
        board[x][y + 1] = 2;
        break;

    case 17:
        board[x][y + 1] = 2;
        board[x][y + 2] = 2;
        break;

    case 18:
        board[x + 1][y] = 2;
        board[x + 1][y + 1] = 2;
        break;

    case 19:
        board[x + 1][y + 1] = 2;
        board[x + 1][y + 2] = 2;
        break;

    case 20:
        board[x + 2][y] = 2;
        board[x + 2][y + 1] = 2;
        break;

    case 21:
        board[x + 2][y + 1] = 2;
        board[x + 2][y + 2] = 2;
        break;
    
    case 22:
        board[x][y] = 3;
        board[x + 1][y] = 3;
        board[x + 2][y] = 3;
        break;

    case 23:
        board[x][y + 1] = 3;
        board[x + 1][y + 1] = 3;
        board[x + 2][y + 2] = 3;
        break;

    case 24:
        board[x][y + 2] = 3;
        board[x + 1][y + 2] = 3;
        board[x + 2][y + 2] = 3;
        break;

    case 25:
        board[x][y] = 3;
        board[x][y + 1] = 3;
        board[x][y + 2] = 3;
    break;

    case 26:
        board[x + 1][y] = 3;
        board[x + 1][y + 1] = 3;
        board[x + 1][y + 2] = 3;
    break;

    case 27:
        board[x + 2][y] = 3;
        board[x + 2][y + 1] = 3;
        board[x + 2][y + 2] = 3;
    break;

    case 28:
        board[x][y] = 4;
        board[x + 1][y] = 4;
        board[x][y + 1] = 4;
        board[x + 1][y + 1] = 4;
    break;

    case 29:
        board[x + 1][y] = 4;
        board[x + 2][y] = 4;
        board[x + 1][y + 1] = 4;
        board[x + 2][y + 1] = 4;
    break;

    case 30:
        board[x][y + 1] = 4;
        board[x + 1][y + 1] = 4;
        board[x][y + 2] = 4;
        board[x + 1][y + 2] = 4;
    break;

    case 31:
        board[x + 1][y + 1] = 4;
        board[x + 2][y + 1] = 4;
        board[x + 1][y + 2] = 4;
        board[x + 2][y + 2] = 4;
    break;

    case 32:
        board[x][y] = 5;
        board[x + 1][y] = 5;
        board[x + 2][y] = 5;
        board[x + 1][y + 1] = 5;
        board[x + 1][y + 2] = 5;
    break;

    case 33:
        board[x][y] = 5;
        board[x][y + 1] = 5;
        board[x][y + 2] = 5;
        board[x + 1][y + 1] = 5;
        board[x + 2][y + 1] = 5;
    break;

    case 34:
        board[x + 1][y] = 5;
        board[x + 1][y + 1] = 5;
        board[x][y + 2] = 5;
        board[x + 1][y + 2] = 5;
        board[x + 2][y + 2] = 5;
    break;

    case 35:
        board[x][y + 1] = 5;
        board[x + 1][y + 1] = 5;
        board[x + 2][y] = 5;
        board[x + 2][y + 1] = 5;
        board[x + 2][y + 2] = 5;
    break;

    case 36:
        board[x + 1][y] = 6;
        board[x][y + 1] = 6;
        board[x + 2][y + 1] = 6;
        board[x][y + 2] = 6;
        board[x + 1][y + 2] = 6;
        board[x + 2][y + 2] = 6;
    break;

    case 37:
        board[x][y + 1] = 6;
        board[x + 1][y] = 6;
        board[x + 2][y] = 6;
        board[x + 2][y + 1] = 6;
        board[x + 2][y + 2] = 6;
        board[x + 1][y + 2] = 6;
    break;

    case 38:
        board[x + 1][y + 2] = 6;
        board[x][y + 1] = 6;
        board[x][y] = 6;
        board[x + 1][y] = 6;
        board[x + 2][y] = 6;
        board[x + 2][y + 1] = 6;
    break;

    case 39:
        board[x + 2][y + 1] = 6;
        board[x + 1][y + 2] = 6;
        board[x][y + 2] = 6;
        board[x][y + 1] = 6;
        board[x][y] = 6;
        board[x + 1][y] = 6;
    break;

     case 40:
        board[x][y] = 7;
        board[x][y + 1] = 7;
        board[x][y + 2] = 7;
        board[x + 1][y + 1] = 7;
        board[x + 2][y] = 7;
        board[x + 2][y + 1] = 7;
        board[x + 2][y + 1] = 7;
    break;   

    case 41:
       board[x][y] = 7;
       board[x + 1][y] = 7;
       board[x + 2][y] = 7;
       board[x + 1][y + 1] = 7;
       board[x][y + 2] = 7;
       board[x + 1][y + 2] = 7;
       board[x + 2][y + 2] = 7;
    break;   

    case 42:
       board[x][y] = 8;
       board[x + 1][y] = 8;
       board[x + 2][y] = 8;
       board[x][y + 1] = 8;
       board[x][y + 2] = 8;
       board[x + 1][y + 2] = 8;
       board[x + 2][y + 2] = 8;
       board[x + 2][y + 1] = 8;
    break; 

    default:
        break;
    }

}