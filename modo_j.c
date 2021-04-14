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
    
    }
}

void modo_j1(int modo_p, int lines, int columns, int board[17][26], int p_num[9])
{
    char column_input;
    int column;
    int line;
    switch (modo_p)
    {
    case 1:
        modo_p1(lines, columns, board, p_num);
        break;

    case 2:
        modo_p2(lines, columns, board, p_num);
        break;
    }
    printf("%dx%d %d %d %d %d %d %d %d %d \n\n", lines, columns, p_num[1], p_num[2], p_num[3], p_num[4], p_num[5], p_num[6], p_num[7], p_num[8]);
    time_t begin;
    time_t end;
    time(&begin);
    int counter = 0;
    while(end_check(board, lines, columns) != 1){
        counter++;
        while(1){
            scanf(" %c%d", &column_input, &line);
            line = lines - line + 1;
            column = column_input - 'A' + 1;
            //printf("C:%d L:%d\n", column, line);
            if (input(line, column, board, lines, columns) == 1){
                break;
            }
            else{ 
                printf("invalid input, try again\n");
            }
        }
        if (board[line][column] < 1){
            printf("-\n");
        }
        else{
            printf("%d\n", board[line][column]);
            board[line][column] += 10;
        }
    }
    time(&end);
    printf("Fim de Jogo: %d jogadas em %ld segundos\n", counter, end - begin);
    board_printer1(board, lines, columns);
}

void modo_j2(int modo_d, int lines, int columns, int board[17][26], int p_num[9])
{
    time_t begin;
    time_t end;
    int counter;
    time(&begin);
    switch (modo_d)
    {
    case 1:
        counter = modo_d1(board, lines, columns, p_num);
        break;

    case 2:
    case 3:
        counter = modo_d3(board, lines, columns, p_num, modo_d);
        break;
    }
    time(&end);
    printf("Fim de Jogo: %d jogadas em %ld segundos\n", counter, end - begin);
    board_printer2(board, lines, columns);
}

int input(int line, int column, int board[17][26], int lines, int columns)
{
    if(board[line][column] > 8 || line > lines || line < 1 || column > columns || column < 1){
        return -1;
    }
    else {
        return 1;
    }
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