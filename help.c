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
	 1 ----- Pieces can never have edges or vertices in contact with other pieces\n\
	 2 ----- The maximum number of pieces per board is limited to: lines * colunms/ 9\n\
	 3 ----- In a game, the rule is to never have more pieces of a larger type than pieces of a smaller type\n\
	 4 ----- Total number of pieces must not exceed 50 percent of the number of 3x3 matrices on a board\n\
	 5 ----- The options of -d [1-3] are only valid when the game mode is j2_mode. Otherwise, the help message should be printed in stdout\n\
	 6 ----- The options - [1-8] indicate the number of pieces of each type.In game mode 0 and 1, they are only valid when considering the
	 			mode_p2 positioning\n\

	 \n");
}
