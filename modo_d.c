#include "headers.h"
#include "modo_d.h"
#include "board.h"
#include "pieces.h"

void modo_d1(int lines, int columns, int p_num[9])
{
    int board[17][26] = {0};
    int x = 0;
    int y = 0;
    int xp = 0;
    int yp = 0;
    int input;
    int type = 0;
    int p[9] = {0};
    while (end(p_num, p) != 1){
        x = (rand() % columns) + 1;
        y = (rand() % lines) + 1;
        if (board[y][x] > 0){
            xp = x_pc_to_user(x);
            yp = y_pc_to_user(y, lines);
            printf(" %c%d\n", xp, yp);
            scanf(" %lc", &input);
            if (input == '-')
                    board[y][x] = 9;
            else if (input > '0' && input < '9'){
                type = input - '0';
                board[y][x] = input - '0';
                x = center(x);
                y = center(y);
                if (peca_killer_checker(board, x, y, p, 0) == 1){
                    if (piece_compare(board, x, y, type) == 1){
                        printf("this piece does not exist\n");
                        break;
                    }
                    if (piece_existance(p_num, p) == 1){
                        printf("you did not declare enough pieces of this type\n");
                        break;
                    }
                    anulator(board, x, y);
                }
            }
            if (end(p_num, p) == 1)
                break;
            //board_printer1(board, lines, columns);
        }
    }
}

void modo_d2(int board[17][26], int lines, int columns, int p_num[9])
{
    int x = 2;
    int y = 2;
    int p[9] = {0};
    while(1){
        while(1){
            board[y][x] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y - 1][x] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y + 1][x] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y][x - 1] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y][x + 1] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y - 1][x - 1] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y + 1][x + 1] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y - 1][x + 1] += 10;
            if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            board[y + 1][x - 1] += 10;
            if (peca_killer_checker(board, x, y, p, 1) == 1) break;
        }
        if (end(p_num, p) == 1){
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
    //board_printer1(board, lines, columns);
}

void modo_d3(int lines, int columns, int p_num[9])
{
    int board[17][26] = {0};
    int x = 2;
    int y = 2;
    int xp = 0;
    int yp = 0;
    int input;
    int type = 0;
    int p[9] = {0};
    //printf("lines: %d :: columns: %d\n", lines, columns);
    while(1){
        while(1){
            if (board[y][x] == 0){
                xp = x_pc_to_user(x);
                yp = y_pc_to_user(y, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y][x] = 10;
                else if (input > '0' && input < '9'){
                    type = input - '0';
                    board[y][x] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y - 1][x] == 0){
                xp = x_pc_to_user(x);
                yp = y_pc_to_user(y - 1, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y - 1][x] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y - 1][x] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y + 1][x] == 0){
                xp = x_pc_to_user(x);
                yp = y_pc_to_user(y + 1, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y + 1][x] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y + 1][x] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y][x - 1] == 0){
                xp = x_pc_to_user(x - 1);
                yp = y_pc_to_user(y, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y][x - 1] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y][x - 1] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y][x + 1] == 0){
                xp = x_pc_to_user(x + 1);
                yp = y_pc_to_user(y, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y][x + 1] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y][x + 1] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y - 1][x - 1] == 0){
                xp = x_pc_to_user(x - 1);
                yp = y_pc_to_user(y - 1, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y - 1][x - 1] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y - 1][x - 1] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y + 1][x + 1] == 0){
                xp = x_pc_to_user(x + 1);
                yp = y_pc_to_user(y + 1, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y + 1][x + 1] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y + 1][x + 1] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y - 1][x + 1] == 0){
                xp = x_pc_to_user(x + 1);
                yp = y_pc_to_user(y - 1, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y - 1][x + 1] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y - 1][x + 1] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 0) == 1) break;
            }
            if (board[y + 1][x - 1] == 0){
                xp = x_pc_to_user(x - 1);
                yp = y_pc_to_user(y + 1, lines);
                printf("%c%d\n", xp, yp);
                scanf(" %lc", &input);
                //printf("%d\n", input);
                if (input == '-')
                    board[y + 1][x - 1] = 10;
                else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                    type = input - '0';
                    board[y + 1][x - 1] = input - '0';
                }
                if (peca_killer_checker(board, x, y, p, 1) == 1) break;
            }
            break;
        }
        if (piece_compare(board, x, y, type) == 1){
            printf("this piece does not exist\n");
            break;
        }
        if (peca_killer_checker(board, x, y, p, 1) < 1){
            printf("this is not a valid piece\n");
            break;
        }
        p[type]++;
        if (piece_existance(p_num, p) == -1){
            printf("you did not declare enough pieces of this type\n");
            break;
        }
        anulator(board, x, y);
        //board_printer(board, lines, columns);
        if (end(p_num, p) == 1){
            board_printer2(board, lines, columns);
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
    //board_printer(board, lines, columns);
}

int piece_compare(int board[17][26], int x, int y, int type)
{
    for (int global_id = global_id_returner(type, 1); global_id <= global_id_returner(type, max_instance(type)); global_id++){
        int flag = 1;
        for (int i = 0; i < 3; i++){
            for (int d = 0; d < 3; d++){
                if (board[y - 1 + i][x - 1 + d] != piece[global_id][i][d]) flag  = 0;
                if (flag == 0) break;
            }
            if (flag == 0) break;
        }
        if (flag == 1) return 1;
    }
    return 0;
}

int end(int p_num[9], int p[9])
{
    for (int d = 1; d < 9; d++){
        if (p_num[d] != p[d]){
            return -1;
        }
    }
    return 1;
}

int piece_existance(int p_num[9], int p[9])
{
    for (int i = 1; i < 9; i++){
        if (p_num[i] < p[i])
            return -1;
    }
    return 1;
}

int peca_killer_checker(int board[17][26], int x, int y, int p[9], int last)
{
    int sum = 0;
    int type = 0;
    for (int i = (y - 1); i < (y + 2); i++) {
        for (int j = (x - 1); j < (x + 2); j++){
            if (board[i][j] > 0 && board[i][j] < 9){
                type = board[i][j];
                sum++;
                if (sum == type){
                    return 1;
                }
            }
        }
    }
    if (type == 0 && last == 1)
        return 1;
    return -1;
}

void anulator(int board[17][26], int x, int y)
{
    for (int i = (y - 1); i < (y + 2); i++){
        for (int j = (x - 1); j < (x + 2); j++){
            if (board[i][j] > 0 && board[i][j] < 9){
                for (int d = (i - 1); d < (i + 2); d++){
                    for (int e = (j - 1); e < (j + 2); e++){
                        if (board[d][e] < 1)
                            board[d][e] = 9;
                    }
                }
            }
        }
    }
}

int center(int pos)
{
    if (pos % 3 == 1)
        return pos + 1;
    if (pos % 3 == 2)
        return pos;
    if (pos % 3 == 0)
        return pos - 1; 
    return 0;
}

int y_pc_to_user(int y, int lines)
{
    return lines + 1 - y;
}

int x_pc_to_user(int x)
{
    return x + 'A' - 1;
}