#include "headers.h"
#include "modo_d.h"
#include "board.h"

void modo_d1(int board[17][26], int lines, int columns)
{
    int x = 0;
    int y = 0;
    while (end_check(board, lines, columns) != 1){
        x = (rand() % columns) + 1;
        y = (rand() % lines) + 1;
        if (board[y][x] < 9){
            //printf("x: %d y: %d \n", x, y);
            board[y][x] += 10;
            board_printer(board, lines, columns);
        }
    }
}


void rebentador_de_tabuleiros(int board[17][26], int lines, int columns)
{
    int x = 2;
    int y = 2;
    while(1){
        while(1){
            board[y][x] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y - 1][x] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y + 1][x] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y][x - 1] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y][x + 1] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y - 1][x - 1] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y + 1][x + 1] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y - 1][x + 1] += 10;
            if (peca_killer(board, x, y) == 1) break;
            board[y + 1][x - 1] += 10;
            if (peca_killer(board, x, y) == 1) break;
        }
        if (end_check(board, lines, columns) == 1){
            break;
        }
        if (x == (columns - 1) && y == (lines - 1)){
            break;
        }
        else if (x == (columns - 1)){
            x = 2;
            y += 3;
        }
        else{
            x += 3;
        }
    }
    board_printer(board, lines, columns);
}



int end_check(int board[17][26], int lines, int columns)
{
    for (int i = 1; i <= lines; i++){
        for (int d = 1; d <= columns; d++){
            if (board[i][d] < 9 && board[i][d] > 0)
                return -1;
        }
    }
    return 1;
}

int peca_killer(int board[17][26], int x, int y)
{ 
    for (int i = (y - 1); i < (y + 2); i++) {
        for (int j = (x - 1); j < (x + 2); j++){
            if (board[i][j] > 0 && board[i][j] < 9)
                return -1;
        }
    }
    return 1;
}