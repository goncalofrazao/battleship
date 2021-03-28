#include "headers.h"
#include "input_check.h"
#include "help.h"

// modo[0] = modo jogo :: modo[1] = modo posicionamento :: modo[2] = modo disparo
// p_num[i] = numero de peças to tipo i-1

int check(int lines, int columns, int modo[3], int p_num[8], int flag_d_in)
{
    if (columns % 3 != 0 || columns < 9 || columns >24){
        printf("-1\n");
        help_message();
        return -1;
    }
    if (lines % 3 != 0 || lines < 9 || lines > 15){
        printf("-2\n");
        help_message();
        return -1;
    }
    if (modo[0] < 0 || modo[0] > 2 ){
        printf("-3\n");
        help_message();
        return -1;
    }
    if (modo[1] < 1 || modo[1] > 2 ){
        printf("-4\n");
        help_message();
        return -1;
    }
    if (modo[2] < 1 || modo[2] > 3 ){
        printf("-5\n");
        help_message();
        return -1;
    }
    if (p_num[0] < 0 || p_num[1] < 0 || p_num[2] < 0 || p_num[3] < 0 || p_num[4] < 0 || p_num[5] < 0 || p_num[6] < 0 || p_num[7] < 0){
        printf("-6\n");
        help_message();
        return -1;
    }
    if (modo[0] == 2 && modo[1] == 2){
        printf("-7\n");
        help_message();
        return -1;
    }
    if (modo[0] != 2 && modo[1] != 2 && (p_num[0] != 0 || p_num[1] != 0 || p_num[2] != 0 || p_num[3] != 0 || p_num[4] != 0 || p_num[5] != 0 || p_num[6] != 0 || p_num[7] != 0)){
        printf("-8\n");
        help_message();
        return -1;
    }
    if (modo[0] != 2 && flag_d_in != 0){
        printf("-9\n");
        help_message();
        return -1;
    }
    if (modo[0] == 2 && modo[2] == 0){
        modo[2] = 1;
    }
    return 1;
}