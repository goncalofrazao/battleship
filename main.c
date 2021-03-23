#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"

int main(int argc, char **argv)
{
    int columns = 0;
    int lines = 0;
    int global_id = 0;
    int board[15][24] = {0};
    int modo[] = {0, 1, 1};
    srand(time(NULL));
    for(int i = 1; i < argc; i++){
        if (strcmp(argv[i], "-t") == 0){
            if (argv[i + 1][0] != '-'){
                char* aux = strchr(argv[i+1], 'x');
                //printf("%s\n", aux);
                columns = atoi(aux + 1);
                (*aux) = '\0';
                lines = atoi(argv[i+1]);
                //printf("%d\n", columns);
                //printf("%d\n", lines);
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
    }
    global_id = atoi(argv[argc - 1]);
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

