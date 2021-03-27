#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"
#include "help.h"
#include "input_check.h"

int main(int argc, char **argv)
{
    int columns = 9;                                    // variavel que guarda o numero de colunas
    int lines = 9;                                      // variavel que guarda o numero de linhas
    int global_id = 0;                                  // id global das peças
    int board[15][24] = {0};                            // board predefinida com dimensoes maxima
    int modo[] = {0, 1, 1};                             // modo[0] = modo jogo :: modo[1] = modo posicionamento :: modo[2] = modo disparo
    int p_num[8] = {0};                                 // p_num[i] = numero de peças to tipo i-1 
    srand(time(NULL));                                  // inicializaçao do timer

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '-'){
            if (strlen(argv[i+1]) > 2){
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
                break;
            }
        }
        /*
        if (strcmp(argv[i], "-t") == 0){
            if (argv[i + 1][0] != '-'){
                sscanf(argv[i + 1], "%dx%d", &lines, &columns);
                //char* aux = strchr(argv[i+1], 'x');
                //printf("%s\n", aux);
                //columns = atoi(aux + 1);
                //(*aux) = '\0';
                //lines = atoi(argv[i+1]);
                printf("%d\n", lines);
                printf("%d\n", columns);
                if (columns % 3 != 0 || columns < 9 || columns >24){
                    printf("-1\n");
                    return -1;
                }
                if (lines % 3 != 0 || lines < 9 || lines > 15){
                    printf("-1\n");
                    return -1;
                }
            }
            else{
                printf("-1\n");
                return -1;
            }
        }
        */
    }
    int checker = check(lines, columns, modo, p_num);
    if (checker == -1)
        return -1;
    
    board_printer(board, lines, columns);
    //global_id = atoi(argv[argc - 1]);
    /*
    while (global_id < 43){
        printf("%d\n", global_id);
        positioning_pieces(0 , 0, global_id, board);
        //positioning_pieces(6 , 6, 42, board);

        board_printer(board, lines, columns);
        global_id++;
        clear_board(board, lines, columns);
    }
    */

    printf("%d    %d    %d\n", modo[0], modo[1], modo[2]);

    return 0;
}

