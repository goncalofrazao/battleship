#include "headers.h"
#include "modo_j.h"
#include "modo_d.h"
#include "modo_p.h"
#include "board.h"

void modo_j0(int modo_p, int lines, int columns, int board[17][26], int p_num[9])
{
    switch (modo_p)
    {
    case 1:
        modo_p1(lines, columns, board, p_num);
        printf("%dx%d %d %d %d %d %d %d %d %d \n\n", lines, columns, p_num[1], p_num[2], p_num[3], p_num[4], p_num[5], p_num[6], p_num[7], p_num[8]);
        board_printer2(board, lines, columns);
        break;

    case 2:
        modo_p2(lines, columns, board, p_num);
        printf("%dx%d %d %d %d %d %d %d %d %d \n\n", lines, columns, p_num[1], p_num[2], p_num[3], p_num[4], p_num[5], p_num[6], p_num[7], p_num[8]);
        board_printer2(board, lines, columns);
        break;
    
    default:
        break;
    }
}

void modo_j1()
{

}