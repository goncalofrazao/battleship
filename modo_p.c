#include "headers.h"
#include "modo_p.h"
#include "pieces.h"
#include "restricoes.h"
#include "board.h"


void modo_p1(int lines, int columns, int board[17][26], int p_num[9])
{
    for(int y = 1; y <= lines; y += 3){
        for(int x = 1; x <= columns; x += 3){
            int i = 0;
            while (i < 3){
                int global_id = (rand() % 42);
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

void modo_p2(int lines, int columns, int board[17][26], int p_num[9])
{
    if (restricao3(p_num) != -1 && restricao4(lines, columns, p_num) != -1){ 
        int type; 
        int instance; 
        int global_id; 
        int counter2 = 0;
        int n_pecas = 0;
        int x;
        int y;
        for (int i = 1; i < 9; i++)
            n_pecas += p_num[i];
        p_num[0] = lines * columns / 9 - n_pecas; 
        
        while(counter2 < 1000){ 
            int flag = 0;
            clear_board(board);
            int num[9] = {0}; 
            for (int i = 0; i < 9;i++) 
                num[i] = p_num[i];

            for (y = 1; y <= lines; y += 3){
                for (x = 1; x <= columns; x +=3){
                    int try[9] = {0};
                    int counter = 0; 
                    while(counter < 8){
                        int c = 0;
                        int arr[9] = {0};
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
                        instance = instance_generator(type); 
                        global_id = global_id_returner(type, instance); 
                        if (restricao1(x, y, global_id, columns, lines, board) != -1){
                            positioning_pieces(x, y, global_id, board); 
                            break; 
                        }
                        else{ 
                            instance = 1; 
                            global_id = global_id_returner(type, instance); 
                            while (restricao1(x, y, global_id, columns, lines, board) == -1 && global_id <= global_id_returner(type, max_instance(type))){ 
                                global_id++; 
                            }
                            if (global_id > global_id_returner(type, max_instance(type))){ 
                                counter++; 
                                try[type] = 1; 
                                num[type]++; 
                            }
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