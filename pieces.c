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
            break;

        case 3:
            global_id = instance_id + 21;
            break;

        case 4:
            global_id = instance_id + 27;
            break;

        case 5:
            global_id = instance_id + 31;
            break;

        case 6:
            global_id = instance_id + 35;
            break;

        case 7:
            global_id = instance_id + 39;
            break;

        case 8:
            global_id = 42;
            break;
    }
    return global_id;
}


//esta função identifica a posição das peças no tabuleiro em função com o identificador global
void positioning_pieces(int x, int y, int global_id, int board[17][26])
{
    for (int i = 0; i < 5; i++){
        for (int d = 0; d < 5; d++){
            board [x - 1 + i][y - 1 + d] = cabra[global_id][i][d];
        }
    }
    
}