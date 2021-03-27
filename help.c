#include "help.h"
#include "headers.h"

void help_message() {
	printf("This is a help message\n\
    Arguments:\n\
    -h ----- show help message\n\
    -t ----- board dimensions (lines x column)\n\
    -j ----- mode game (0 to 2)\n\
    -p ----- positioning mode (1 to 2)\n\
    -d ----- shooting mode (1 to 3)\n\
    -1 ----- number of pieces type 1 (Minimum 1)\n\
    -2 ----- number of pieces type 2\n\
    -3 ----- number of pieces type 3\n\
    -4 ----- number of pieces type 4\n\
    -5 ----- number of pieces type 5\n\
    -6 ----- number of pieces type 6\n\
    -7 ----- number of pieces type 7\n\
    -8 ----- number of pieces type 8\n\
    Usage:\n\
    -t <LxC> ----- L = lines number / C = columns number\n\
    -j <num> ----- num = game mode\n\
    \n\
    -2 <num> ----- num = numberof pieces type 2\n\
    Rules:\n\
    -t <arg> ----- arg must be and integer between 0 and 2\n\
    \n\
    \n");
}
