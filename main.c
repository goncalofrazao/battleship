#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"
#include "help.h"
#include "input_check.h"



int main(int argc, char **argv)
{
    int columns = 9;                                    // numero de colunas
    int lines = 9;                                      // numero de linhas
    int global_id = 0;                                  // id global das peças
    int board[17][26] = {0};                            // board predefinida com dimensoes maximas
    int modo[] = {0, 1, 1};                             // modo[0] = modo de jogo :: modo[1] = modo de posicionamento :: modo[2] = modo de disparo
    int p_num[8] = {0};                                 // p_num[i] = numero de peças to tipo i-1 
    int flag_d_in = 0;                                  // regista a alteração do modo de disparo
    srand(time(NULL));                                  // inicializaçao do timer

    if (argc > 1){
        for(int i = 1; i < argc; i++){
            if (argv[i][0] == '-'){
                if (strlen(argv[i]) > 2){
                    printf("-1\n");
                    help_message();
                    return -1;
                }
                if (i == (argc - 1) && argv[i][0] == '-'){
                    printf("-1\n");
                    help_message();
                    return -1;
                }
                switch (argv[i][1])
                {
                case 'h':
                    help_message();
                    return -1;
                    break;

                case 't':
                    sscanf(argv[i + 1], "%dx%d", &lines, &columns);
                    break;

                case 'j':
                    modo[0] = (atoi(argv[i+1]));
                    break;

                case 'p':
                    modo[1] = (atoi(argv[i+1]));
                    break;

                case 'd':
                    modo[2] = (atoi(argv[i+1]));
                    flag_d_in = 1;
                    break;

                case '1':
                    p_num[0] = (atoi(argv[i+1]));
                    break;

                case '2':
                    p_num[1] = (atoi(argv[i+1]));
                    break;

                case '3':
                    p_num[2] = (atoi(argv[i+1]));
                    break;

                case '4':
                    p_num[3] = (atoi(argv[i+1]));
                    break;

                case '5':
                    p_num[4] = (atoi(argv[i+1]));
                    break;

                case '6':
                    p_num[5] = (atoi(argv[i+1]));
                    break;

                case '7':
                    p_num[6] = (atoi(argv[i+1]));
                    break;

                case '8':
                    p_num[7] = (atoi(argv[i+1]));
                    break;

                default:
                    printf("-1");
                    help_message();
                    return -1;
                    break;
                }
            }
            else {
                if (argv[i-1][0] != '-'){
                    printf("-1");
                    help_message();
                    return -1;
                }
            }
        }
    }
    
    if (check(lines, columns, modo, p_num, flag_d_in) == -1 || restricao3(p_num) == -1 || \
        restricao2(lines, columns, p_num) == -1 || restricao4(lines, columns, p_num) == -1){
        printf("-1\n");
        help_message();
        return -1;
    }
    
    int x = 1;
    int y = 1;    
    while (1){
        int i = 0;
        while (i < 3){
            global_id = (rand() % 43);
            if (restricao1(x, y, global_id, columns, lines, board) == -1){
                i++;
            }
            else {
                positioning_pieces(x, y, global_id, board);
                break;
            }
        }
        if (x == (columns - 2) && y == (lines - 2)){
            break;
        }
        else if (x == (columns - 2)){
            x = 1;
            y += 3;
        }
        else {
            x += 3;
        }
    }
    
    
    //global_id = atoi(argv[argc - 1]);
    /*
    global_id = 1;
    while (global_id < 43){
        printf("%d\n", global_id);
        positioning_pieces(3 , 3, global_id, board);
        //positioning_pieces(6 , 6, 42, board);
        board_printer(board, lines, columns);
        printf("\n\n");
        global_id++;
        clear_board(board, lines, columns);
    }
    */
    board_printer(board, lines, columns);
    printf("j: %d    p: %d    d: %d\n", modo[0], modo[1], modo[2]);

    return 0;
}

