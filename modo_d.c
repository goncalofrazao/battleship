#include "headers.h"
#include "modo_d.h"
#include "board.h"
#include "pieces.h"

/*******************************************************************************
* Function name: modo_d1()
*
* Arguments: board[17][26] (int) - matrix of board
*            lines (int) - lines of the game
*            columns (int) - columns of the game
*            p_num[9] - number of pieces of each type
*
* Return: counter (int) - if mode runs as expected
*         -1 - if there are no pieces to shoot
*
* Side-effects: none
*
* Description: This funtion prints in stdout random generated coordinates
*              and receive an input by stdin with the value of the board in the 
*              coordinates generated while game does not end.
*
*******************************************************************************/

int modo_d1(int board[17][26], int lines, int columns, int p_num[9])
{
    // check if there are any pieces declared
    if (pieces_declared(p_num) == -1){
        printf("You must declared some pieces first\n");
        return -1;
    }
    int x = 0;              // x coordinate
    int y = 0;              // y coordinate
    int xp = 0;             // x to print for user
    int yp = 0;             // y to print for user
    int counter = 0;        // count how many shots
    int input = 0;          // user input saver
    int type = 0;           // type of input saver
    int p[9] = {0};         // pieces destroied
    // while there are still ships on the board
    while (end(p_num, p) == -1){
        // random generate x and y not used yet
        do{
            x = (rand() % columns) + 1;
            y = (rand() % lines) + 1;
        } while(board[y][x] != 0);
        // convert x and y to to user read
        xp = x_pc_to_user(x);
        yp = y_pc_to_user(y, lines);
        // print the coordinates
        printf("%c%d\n", xp, yp);
        // get the user input
        scanf(" %lc", &input);
        // add 1 to shot
        counter++;
        // save the position of matrix as 9 if input is '-'
        if (input == '-'){
            board[y][x] = 9;
        }
        // save the position of matrix with the type of the piece shoot
        else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
            type = input - '0';
            board[y][x] = type;
            // put x and y to the center of the square
            x = center(x);
            y = center(y);
            // check if it has killed a piece
            peca_killer_checker(board, x, y, p, type);
        }
        else {
            printf("invalid input\n");
        }
    }
    return counter;
}

/*******************************************************************************
* Function name: modo_d23()
*
* Arguments: board[17][26] (int) - matrix of board
*            lines (int) - lines of the game
*            columns (int) - columns of the game
*            p_num[9] - number of pieces of each type
*            modo_d - shooting mode
*
* Return: counter (int) - if mode runs as expected
*         -1 - if there are no pieces to shoot
*
* Side-effects: none
*
* Description: This funtion prints in stdout random generated coordinates
*              and receive an input by stdin with the value of the board in the 
*              coordinates generated while game does not end.
*
*******************************************************************************/

int modo_d23(int board[17][26], int lines, int columns, int p_num[9], int modo_d)
{
    
    int xp = 0;             // x to print for user
    int yp = 0;             // y to print fot user
    int counter = 0;        // count how many shots
    int input;              // user input saver
    int type = 0;           // input type saver
    int p[9] = {0};         // pieces destroied
    // 2 fors to go through all board squares
    for(int y = 2; y <= lines; y += 3){
        for (int x = 2; x <= columns; x += 3){
            // this while is used to break the square shots if a piece is destroied
            while(1){
                // just shot if position is 0
                if (board[y][x] == 0){
                    // convert x and y to user print
                    xp = x_pc_to_user(x);
                    yp = y_pc_to_user(y, lines);
                    // print coordinates
                    printf("%c%d\n", xp, yp);
                    // get user input
                    scanf(" %lc", &input);
                    // +1 to shots
                    counter++;
                    // board = 9 means water
                    if (input == '-')
                        board[y][x] = 9;
                    // board between 1 and 8 means the type of piece there
                    else if (input > '0' && input < '9'){
                        type = input - '0';
                        board[y][x] = type;
                    }
                    // break while if it has destroied a piece
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y - 1][x] == 0){
                    xp = x_pc_to_user(x);
                    yp = y_pc_to_user(y - 1, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y - 1][x] = 9;
                    else if (input > '0' && input < '9'){
                        type = input - '0';
                        board[y - 1][x] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y + 1][x] == 0){
                    xp = x_pc_to_user(x);
                    yp = y_pc_to_user(y + 1, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y + 1][x] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y + 1][x] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y][x - 1] == 0){
                    xp = x_pc_to_user(x - 1);
                    yp = y_pc_to_user(y, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y][x - 1] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y][x - 1] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y][x + 1] == 0){
                    xp = x_pc_to_user(x + 1);
                    yp = y_pc_to_user(y, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y][x + 1] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y][x + 1] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y - 1][x - 1] == 0){
                    xp = x_pc_to_user(x - 1);
                    yp = y_pc_to_user(y - 1, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y - 1][x - 1] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y - 1][x - 1] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y + 1][x + 1] == 0){
                    xp = x_pc_to_user(x + 1);
                    yp = y_pc_to_user(y + 1, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y + 1][x + 1] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y + 1][x + 1] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y - 1][x + 1] == 0){
                    xp = x_pc_to_user(x + 1);
                    yp = y_pc_to_user(y - 1, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y - 1][x + 1] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y - 1][x + 1] = type;
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                // exatly the same as if before but for a different coordinate
                if (board[y + 1][x - 1] == 0){
                    xp = x_pc_to_user(x - 1);
                    yp = y_pc_to_user(y + 1, lines);
                    printf("%c%d\n", xp, yp);
                    scanf(" %lc", &input);
                    counter++;
                    if (input == '-')
                        board[y + 1][x - 1] = 9;
                    else if (input > '0' && input < '9' && p_num[input - '0'] > 0){
                        type = input - '0';
                        board[y + 1][x - 1] = input - '0';
                    }
                    if (peca_killer_checker(board, x, y, p, type) == 1) break;
                }
                break;
            }
            // if shooting mode is 3, all the positions around the piece go -1
            if (modo_d == 3)
                anulator(board, x, y);
            // if all pieces destroied, return counter and finish game
            if (end(p_num, p) == 1){
                x = columns + 1;
                y = lines + 1;
            }
        }
    }
    return counter;
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

int peca_killer_checker(int board[17][26], int x, int y, int p[9], int type)
{
    int sum = 0;
    for (int i = (y - 1); i < (y + 2); i++) {
        for (int j = (x - 1); j < (x + 2); j++){
            if (board[i][j] > 0 && board[i][j] < 9){
                sum++;
            }
        }
    }
    if (sum == type && type != 0){
        p[type]++;
        return 1;
    }
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

int pieces_declared(int p_num[9])
{
    // check if there are any pieces declared
    int i = 1;
    for (i = 1; i < 9; i++){
        if (p_num[i] != 0)
            break;
    }
    if (i > 8) {
        return -1;
    }
    else{
        return 1;
    }
}