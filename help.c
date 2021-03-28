#include "help.h"
#include "headers.h"

void help_message() {
	printf("This is a help message\n\
    \n\
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
    \n\
    Usage:\n\
    -t <LxC> ----- L = lines number / C = columns number\n\
    -j <num> ----- num = game mode (integer)\n\
    -p <num> ----- num = positioning mode\n\
    -d <num> ----- num = shotting mode\n\
    -1 <num> ----- num = number of pieces type 1\n\
    -2 <num> ----- num = number of pieces type 2\n\
    -3 <num> ----- num = number of pieces type 3\n\
    -4 <num> ----- num = number of pueces type 4\n\
    -5 <num> ----- num = number of pieces type 5\n\
    -6 <num> ----- num = number of pieces type 6\n\
    -7 <num> ----- num = number of pieces type 7\n\
    -8 <num> ----- num = number of pieces type 8\n\
    \n\
    Rules:\n\
    -t <arg> ----- arg must be an integer between lines and columns\n\
    -j <arg> ----- arg must be an integer between 0 and 2\n\
    -p <arg> ----- arg must be an integer between 1 and 2\n\
    -d <arg> ----- arg must be an integer between 1 and 3\n\
    -1 <arg> ----- arg must be an integer minimum 1\n\
    -2 <arg> ----- arg must be an integer\n\
    -3 <arg> ----- arg must be an integer\n\
    -4 <arg> ----- arg must be an integer\n\
    -5 <arg> ----- arg must be an integer\n\
    -6 <arg> ----- arg must be an integer\n\
    -7 <arg> ----- arg must be an integer\n\
    -8 <arg> ----- arg must be an integer\n\
    \n\
	Restrictions:\n\
    1 ----- Edges and vertices of pieces must be space free. \n\
    2 ----- Max number of pieces: lines * colunms/ 9\n\
    3 ----- Not allowed to have more larger pieces smaller pieces. \n\
    4 ----- Max number of pieces: les than 50 %% of max number of pieces. \n\
    5 ----- The options of -d [1-3] are only available when in the game mode 2. \n\
    6 ----- In game mode 0 and 1, -[1-8] are only available in positioning mode 2.\n\
    \n\
	 \n");
}
