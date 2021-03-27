#include "headers.h"
#include "input_check.h"
#include "help.h"

int check(int lines, int columns, int modo[3], int p_num[8])
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
    return 1;
}