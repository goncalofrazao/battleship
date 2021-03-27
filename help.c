#include "help.h"
#include "headers.h"

void help_message() {
	printf("This is a help message\
            -h							show help message\
			-j						board dimensions (lines x column)\
           -t					mode game (0 to 2)\
            -p					mode of positioning parts by the computer (1 to 2)\
            -d					mode of firing parts by the computer (1 to 3)\
            -1					number of pieces type 1 (Minimum 1)\
            -2					number of pieces type 2\
            -3					number of pieces type 3\
            -4					number of pieces type 4\
            -5					number of pieces type 5\
            -6					number of pieces type 6\
            -7					number of pieces type 7\
            -8					number of pieces type 8\
            \n");
}
