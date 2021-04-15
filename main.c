#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"
#include "help.h"
#include "input_check.h"
#include "modo_p.h"
#include "modo_d.h"
#include "modo_j.h"


int main(int argc, char **argv)
{
    int columns = 9;                                    // numero de colunas
    int lines = 9;                                      // numero de linhas
    int board[17][26] = {{0}};                            // board predefinida com dimensoes maximas
    int modo[] = {0, 1, 1};                             // modo[0] = modo de jogo :: modo[1] = modo de posicionamento :: modo[2] = modo de disparo
    int p_num[9] = {0};                                 // p_num[i] = numero de peças to tipo i-1
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
                if (i == (argc - 1)){
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
                    //printf("lines: %d\ncolumns: %d\n", lines,columns);
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
                    p_num[1] = (atoi(argv[i+1]));
                    //printf("peças tipo 1: %d\n", p_num[1]);
                    break;
                case '2':
                    p_num[2] = (atoi(argv[i+1]));
                    //printf("peças tipo 2: %d\n", p_num[2]);
                    break;
                case '3':
                    p_num[3] = (atoi(argv[i+1]));
                    //printf("peças tipo 3: %d\n", p_num[3]);
                    break;
                case '4':
                    p_num[4] = (atoi(argv[i+1]));
                    //printf("peças tipo 4: %d\n", p_num[4]);
                    break;
                case '5':
                    p_num[5] = (atoi(argv[i+1]));
                    //printf("peças tipo 5: %d\n", p_num[5]);
                    break;
                case '6':
                    p_num[6] = (atoi(argv[i+1]));
                    //printf("peças tipo 6: %d\n", p_num[6]);
                    break;
                case '7':
                    p_num[7] = (atoi(argv[i+1]));
                    //printf("peças tipo 7: %d\n", p_num[7]);
                    break;
                case '8':
                    p_num[8] = (atoi(argv[i+1]));
                    //printf("peças tipo 8: %d\n", p_num[8]);
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
                if (strlen(argv[i-1]) > 2){
                    printf("-1");
                    help_message();
                    return -1;
                }
            }
        }
    }

    if (check(lines, columns, modo, p_num, flag_d_in) == -1 || restricao3(p_num) == -1 || restricao2(lines, columns, p_num) == -1 || restricao4(lines, columns, p_num) == -1){
        printf("-1\n");
        help_message();
        return -1;
    }

    if (modo[0] == 0){
        modo_j0(modo[1], lines, columns, board, p_num);
    }
    if (modo[0] == 1){
        printf("\n\
* ================================\n\
* Modo de Jogo 1\n\
* Insira as Coordenadas de Disparo\n\
* ================================\n");
        modo_j1(modo[1], lines, columns, board, p_num);
    }
    if (modo[0] == 2){
        printf("\n\
* ================================\n\
* Modo de Jogo 2\n\
* Crie um tabuleiro com as características indicadas * Responda aos disparos do programa\n\
* ================================\n");
        modo_j2(modo[2], lines, columns, board, p_num);
    }


    return 0;
}
