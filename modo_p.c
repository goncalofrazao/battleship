#include "headers.h"
#include "modo_p.h"
#include "pieces.h"
#include "restricoes.h"
#include "board.h"

/*******************************************************************************
* Function name: modo_p1()
*
* Arguments: board[17][26] (int) - matrix game
*            lines (int) - lines of the board
*            columns (int) - columns of the board
*            p_num[9] - array to save the pieces positioned
*
* Return: no return
*
* Side-effects: board positions
*
* Description: This function generates a board with position mode 1 rules
*
*******************************************************************************/

void modo_p1(int lines, int columns, int board[17][26], int p_num[9])
{
    // go through all squares of board
    for(int y = 1; y <= lines; y += 3){
        for(int x = 1; x <= columns; x += 3){
            int i = 0;
            // try a max of 3 times to put a piece, else put a global id 5 (type 1 instance 5)
            while (i < 3){
                // generate a random global id
                int global_id = (rand() % 42);
                // if piece fulfill the restrictions position it, else try another one until 3 times
                if (restricao1(x, y, global_id, columns, lines, board) == -1){
                    i++;
                }
                else {
                    positioning_pieces(x, y, global_id, board);
                    int type = global_id_to_type(global_id);
                    p_num[type]++;
                    break;
                }
            }
            if (i == 3){
                positioning_pieces(x, y, 5, board);
                p_num[1]++;
            }
        }
    }
}

/*******************************************************************************
* Function name: modo_p2()
*
* Arguments: board[17][26] (int) - matrix game
*            lines (int) - lines of the board
*            columns (int) - columns of the board
*            p_num[9] (int) - pieces to position
*
* Return: no return
*
* Side-effects: board positions
*
* Description: This function generates a board with position mode 1 rules
*
*******************************************************************************/

void modo_p2(int lines, int columns, int board[17][26], int p_num[9])
{
    // just executes the position if retriction 3 and 4 are fulfilled
    if (restricao3(p_num) != -1 && restricao4(lines, columns, p_num) != -1){ 
        int type;               // save the type of piece generated
        int instance;           // save the instance generated
        int global_id;          // saves the global id of the type and instanec generated
        int counter2 = 0;       // counts how many times program has tried to generate a board
        int n_pecas = 0;        // number of pieces to position
        int x = 0;              // x of the place to position the piece
        int y = 0;              // y of the place to position the piece
        // counts how many pieces it has to position
        for (int i = 1; i < 9; i++)
            n_pecas += p_num[i];
        // saves in position 0 of p_num how many blank spaces it has to put
        p_num[0] = lines * columns / 9 - n_pecas; 
        // runes while it does not try to put the board 1000 times
        while(counter2 < 1000){ 
            int flag = 0;
            // clear board (put every position at 0)
            clear_board(board);
            // initialize number of pieces already positioned at 0 
            int num[9] = {0}; 
            // copy the values of p_num to num
            for (int i = 0; i < 9;i++) 
                num[i] = p_num[i];
            // go through all squares of the board
            for (y = 1; y <= lines; y += 3){
                for (x = 1; x <= columns; x +=3){
                    // try saves the pieces already tried
                    int try[9] = {0};
                    int counter = 0; 
                    // tries a max of 8 different types
                    while(counter < 8){
                        int c = 0;
                        int arr[9] = {0};
                        // generates a type that has not been tried yet and that has still pieces to position
                        while(1){
                            type = (rand() % 9); 
                            if ((arr[type] == 0) && ((num[type] > 0 && try[type] > 0) || num[type] == 0)){
                                c++;
                                arr[type]++;
                            }
                            if (c == 9){
                                flag = 1;
                                break;
                            }
                            if ((num[type] > 0 && try[type] == 0)){
                                num[type]--; 
                                break; 
                            }
                        }
                        if (flag == 1) break;
                        // generate a random instance of the type generated before
                        instance = instance_generator(type); 
                        // converts the type and instance to a global id
                        global_id = global_id_returner(type, instance); 
                        // if the piece fullfill the restriction 1, position it
                        if (restricao1(x, y, global_id, columns, lines, board) != -1){
                            positioning_pieces(x, y, global_id, board); 
                            break; 
                        }
                        // if the piece generated cannot be positioned
                        else{ 
                            instance = 1; 
                            global_id = global_id_returner(type, instance);
                            // try all instances 
                            while (restricao1(x, y, global_id, columns, lines, board) == -1 && global_id <= global_id_returner(type, max_instance(type))){ 
                                global_id++; 
                            }
                            // array try turns 1 in type position if no instance works
                            if (global_id > global_id_returner(type, max_instance(type))){ 
                                counter++; 
                                try[type] = 1; 
                                num[type]++; 
                            }
                            // position the piece if there is a instance that fulfills all the restrictions
                            else { 
                                positioning_pieces(x, y, global_id, board); 
                                break; 
                            }
                        }
                    }
                    if (flag == 1) break;
                }
                if (flag == 1) break;
            }
            if ((x > columns) && (y > lines) && (flag == 0)){ 
                break; 
            }
            counter2++;
        }
        if(counter2 == 1000)
            printf("it was impossible to generate a board\n");
    }
}