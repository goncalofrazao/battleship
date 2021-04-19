/*******************************************************************************
*  2º Semestre do 1º ano do curso de MEEC - Instituto Superior Técnico
*  Unidade Curricular - Programação
*
*  Nome do Projeto: Meec Wargame
*
*  Autores: Gonçalo Frazão (99945) e Tomás Lopes (100097)
*  Data de começo: 19/03/2021
*******************************************************************************/

#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"
#include "help.h"
#include "input_check.h"
#include "modo_p.h"
#include "modo_d.h"
#include "modo_j.h"

/******************************************************************************
* Function name: main()
*
* Arguments: argc (int) - number of command line arguments
*            argv (char **) - arguments of command line
*
* Return: 0 - if program runs as expected
*         -1 - if program detects any error of input
*
*
* Description: Main is divided in 2 parts:
*       1st part: input read.
*           - gives all the input arguments to respective variable
*           - if the order (word with ifen + word without ifen + ...) loop
*           breaks and print -1 + show help message (help_message()) + print -1
*           - calls the function input_check() to check the input
*       2nd part: calls the game mode.
*           - calls the game mode funtion that has been choosed by input (or 
*           the default one)
*
* Comments: the variable flag_d_in detects if shooting mode was a input
*
*******************************************************************************/

int main(int argc, char **argv)
{
    // variables declaration and initialization with default values
    int columns = 9;
    int lines = 9;
    int board[17][26] = {{0}};
    int modo[] = {0, 1, 1};
    int p_num[9] = {0};
    int flag_d_in = 0;
    int flag_pieces_in = 0;
    srand(time(NULL));

    if (argc > 1){
        // loop to read all arguments of argv
        for(int i = 1; i < argc; i++){
            // check if string starts with '-'
            if (argv[i][0] == '-'){
                // if word starts with '-' and it is longer than 2 : return -1 (invalid input) + help msg
                if (strlen(argv[i]) > 2){
                    printf("-1\n");
                    help_message();
                    return -1;
                }
                // if the last argument of the command line starts with '-' : return -1 (invalid input) + help msg
                if (i == (argc - 1)){
                    printf("-1\n");
                    help_message();
                    return -1;
                }
                // assigns input to the correspondenct variable
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
                    p_num[1] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '2':
                    p_num[2] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '3':
                    p_num[3] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '4':
                    p_num[4] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '5':
                    p_num[5] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '6':
                    p_num[6] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '7':
                    p_num[7] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                case '8':
                    p_num[8] = (atoi(argv[i+1]));
                    flag_pieces_in = 1;
                    break;

                default:
                    printf("-1");
                    help_message();
                    return -1;
                    break;
                }
            }
            else {
                // if neither the argument nor the argument before starts with a '-' : return -1 (invalid input) + help msg
                if (argv[i-1][0] != '-'){
                    printf("-1");
                    help_message();
                    return -1;
                }
                // if the argument before is longer than 2 : return -1 (invalid input) + help msg
                if (strlen(argv[i-1]) > 2){
                    printf("-1");
                    help_message();
                    return -1;
                }
            }
        }
    }
    // if any of the restrictions about number of pieces or the check funtion returns -1 : return -1 (invalid input) + help msg
    if (check(lines, columns, modo, p_num, flag_d_in, flag_pieces_in) == -1 || restricao3(p_num) == -1 || restricao2(lines, columns, p_num) == -1 || restricao4(lines, columns, p_num) == -1){
        printf("-1\n");
        help_message();
        return -1;
    }
    // calls modo_j0 if modo[0] = 0
    if (modo[0] == 0){
        modo_j0(modo[1], lines, columns, board, p_num);
    }
    // calls modo_j1 if modo[0] = 1
    if (modo[0] == 1){
        printf("\n\
* ================================\n\
* Modo de Jogo 1\n\
* Insira as Coordenadas de Disparo\n\
* ================================\n");
        modo_j1(modo[1], lines, columns, board, p_num);
    }
    // calls modo_j2 if modo[0] = 2
    if (modo[0] == 2){
        printf("\n\
* ================================\n\
* Modo de Jogo 2\n\
* Crie um tabuleiro com as características indicadas \n\
* Responda aos disparos do programa\n\
* ================================\n");
        modo_j2(modo[2], lines, columns, board, p_num);
    }

    return 0;
}
