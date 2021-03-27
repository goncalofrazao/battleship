#include "help.h"
#include "headers.h"

void help_message() {
	printf("This is a help message\
            Arguments:\
            -h							show help message\
			-t						    board dimensions (lines x column)\
            -j					        mode game (0 to 2)\
            -p					        positioning mode (1 to 2)\
            -d					        shooting mode (1 to 3)\
            -1					        number of pieces type 1 (Minimum 1)\
            -2					        number of pieces type 2\
            -3					        number of pieces type 3\
            -4					        number of pieces type 4\
            -5					        number of pieces type 5\
            -6					        number of pieces type 6\
            -7					        number of pieces type 7\
            -8					        number of pieces type 8\
            Usage:\
            -t <LxC>                    L = lines number / C = columns number\
            -j <num>                    num = game mode\
            \
            -2 <num>                    num = numberof pieces type 2\
            Rules:\
            -t <arg>                    arg must be and integer between 0 and 2\
            \
            \n");
}
