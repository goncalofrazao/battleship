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
* Description: This funtion prints in stdout coordinates following a pre defined
*              order and receive an input by stdin with the value of the board in 
*              the coordinates generated while game does not end.
*
*******************************************************************************/

int modo_d23(int board[17][26], int lines, int columns, int p_num[9], int modo_d)
{
    int shoot_x[9] = {0, 0, 0, -1, 1, -1, 1, 1, -1};
    int shoot_y[9] = {0, -1, 1, 0, 0, -1, 1, -1, 1};
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
            for(int i = 0; i < 9; i++){
                // just shot if position is 0
                if (board[y + shoot_y[i]][x + shoot_x[i]] == 0){
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

/*******************************************************************************
* Function name: end()
*
* Arguments: p_num[9] (int) - pieces in the board
*            p[9] (int) - 
*
* Return: -1 - if any pieces left to destroy
*         1 - if all pieces destroied
*
* Side-effects: none
*
* Description: This function confirms if the destroied pieces correpond to the
*              total pieces in the game.
*
*******************************************************************************/

int end(int p_num[9], int p[9])
{
    // go through all the array positions
    for (int d = 1; d < 9; d++){
        // if pieces already shot and total pieces of the type d are different
        if (p_num[d] != p[d]){
            return -1;
        }
    }
    return 1;
}

/*******************************************************************************
* Function name: peca_killer_checker()
*
* Arguments: board[17][26] (int) - matrix of board
*            x (int) - center x of square to check
*            y (int) - center y of square to check
*            p[9] (int) - number of pieces of each type already destroied
*            type (int) - type of piece to check
*
* Return: -1 - if the piece has not been destroied
*         1 - if the piece has been destroied
*
* Side-effects: p[type] ++ if any piece destroied (type is the type of the piece
*               in the square)
*
* Description: This function confirms if the piece in the square has been 
*              destroied
*
*******************************************************************************/

int peca_killer_checker(int board[17][26], int x, int y, int p[9], int type)
{
    // sum counts how many positions of the square had been shot
    int sum = 0;
    // x and y are in the middle of the board, so for start checking at y-1 and x-1
    for (int i = (y - 1); i < (y + 2); i++) {
        for (int j = (x - 1); j < (x + 2); j++){
            // if board position is between 1 and 8 add 1 to positions already shot
            if (board[i][j] > 0 && board[i][j] < 9){
                sum++;
            }
        }
    }
    // if the number of positions is the same as the type of the piece => return 1 and add 1 to pieces destroied of the type
    if (sum == type && type != 0){
        p[type]++;
        return 1;
    }
    return -1;
}

/*******************************************************************************
* Function name: anulator()
*
* Arguments: board[17][26] (int) - matrix of board
*            x (int) - center x of square to anulate
*            y (int) - center y of square to anulate
*
* Return: no return
*
* Side-effects: all the positions around the piece destroied turn 9
*
* Description: This function rewrite all the positions around a piece already
*              destroied to the value 9.
*
*******************************************************************************/

void anulator(int board[17][26], int x, int y)
{
    // loops to go through all positions of a square
    for (int i = (y - 1); i < (y + 2); i++){
        for (int j = (x - 1); j < (x + 2); j++){
            // if a positions in the square is between 1 and 8
            if (board[i][j] > 0 && board[i][j] < 9){
                // run all positions around the position
                for (int d = (i - 1); d < (i + 2); d++){
                    for (int e = (j - 1); e < (j + 2); e++){
                        // if the position has not a number of a type, turn it to 9
                        if (board[d][e] < 1)
                            board[d][e] = 9;
                    }
                }
            }
        }
    }
}

/*******************************************************************************
* Function name: center()
*
* Arguments: position (int) - position to move to square center
*
* Return: (position + 1) - when (position % 3 = 1) the position is in the left 
*         side of the square (if we talking about 'x') or is in the top
*         of the square (if we talking about 'y')
*           
*         (position) - when (position % 3 = 2) the position is in the center 
*         of the square (if we talking about 'x' or 'y)
*
*         (position - 1) - when (position % 3 = 0 (else) ) the position is in the right 
*         side of the square (if we talking about 'x') or is in the bottom
*         of the square (if we talking about 'y')
*
* Side-effects: no side effects
*
* Description: This function return the x or y coordinate of the center of the
*              square that contains the position of input
*
*******************************************************************************/

int center(int position)
{
    if (position % 3 == 1)
        return position + 1;
    else if (position % 3 == 2)
        return position;
    else
        return position - 1; 
}

/*******************************************************************************
* Function name: y_pc_to_user()
*
* Arguments: y (int) - y to convert to user read
*            lines (int) - lines of the game
*
* Return: (lines + 1 - y) - always return this
*
* Side-effects: no side effects
*
* Description: This function converts the 'y' number that the computer uses to 
*              the number that the player sees.
*
*******************************************************************************/

int y_pc_to_user(int y, int lines)
{
    return lines + 1 - y;
}

/*******************************************************************************
* Function name: x_pc_to_user()
*
* Arguments: x (int) - x to convert to user read
*
* Return: (lines + 'A' - 1) - always return this
*
* Side-effects: no side effects
*
* Description: This function converts the 'x' number that the computer uses to 
*              the number in ascii code that the player sees.
*
*******************************************************************************/

int x_pc_to_user(int x)
{
    return x + 'A' - 1;
}

/*******************************************************************************
* Function name: pieces_declared()
*
* Arguments: p_num[9] (int) - pieces declared in the input
*
* Return: -1 - if no pieces declared
*         1 - if there are pieces declared
*
* Side-effects: no side effects
*
* Description: This function converts the 'x' number that the computer uses to 
*              the number in ascii code that the player sees.
*
*******************************************************************************/

int pieces_declared(int p_num[9])
{
    int i = 1;
    for (i = 1; i < 9; i++){
        // if all the p_num positions are 0 i ends at 9
        if (p_num[i] != 0)
            break;
    }
    // if i is bigger than 8 => none of p_num is different of 0 => no pieces to shoot 
    if (i > 8) {
        return -1;
    }
    else{
        return 1;
    }
}