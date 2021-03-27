#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"
#include "help.h"


int main(int argc, char **argv)
{
    int columns = 0;                                    // variavel que guarda o numero de colunas
    int lines = 0;                                      // variavel que guarda o numero de linhas
    int global_id = 0;                                  // id global das peças
    int board[15][24] = {0};                            // board predefinida com dimensoes maxima
    int modo[] = {0, 1, 1};                             // modo[0] = modo jogo :: modo[1] = modo posicionamento :: modo[2] = modo disparo
    int p_num[8] = {0};                                 // p_num[i] = numero de peças to tipo i-1 
    srand(time(NULL));                                  // inicializaçao do timer

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '-'){
            switch (argv[i][1])
            {
            case 'h':
                help_message();
                break;

            case 't':
                sscanf(argv[i + 1], "%dx%d", &lines, &columns);
                if (columns % 3 != 0 || columns < 9 || columns >24){
                    help_message();
                    return -1;
                }
                if (lines % 3 != 0 || lines < 9 || lines > 15){
                    help_message();
                    return -1;
                }
                break;

            case 'j':
                switch (atoi(argv[i+1]))
                {
                case 0:
                    modo[0] = 0;
                    break;
                
                case 1:
                    modo[0] = 1;
                    break;

                case 2:
                    modo[0] = 2;
                    break;

                default:
                    help_message();
                    return -1;
                    break;
                }
                break;

            case 'p':
                switch (atoi(argv[i+1]))
                {
                case 1:
                    modo[1] = 1;
                    break;
                
                case 2:
                    modo[1] = 2;
                    break;

                default:
                    help_message();
                    return -1;
                    break;
                }
                break;

            case 'd':
                switch (atoi(argv[i+1]))
                {
                case 1:
                    modo[2] = 1;
                    break;
                
                case 2:
                    modo[2] = 2;
                    break;

                case 3:
                    modo[2] = 3;
                    break;

                default:
                    help_message();
                    return -1;
                    break;
                }
                break;
                break;

            case '1':
                
                break;

            case '2':
                
                break;

            case '3':
                
                break;

            case '4':
                
                break;

            case '5':
                
                break;

            case '6':
                
                break;

            case '7':
                
                break;

            case '8':
                
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



    return 0;
}

