#include "headers.h"
#include "restricoes.h"
#include "pieces.h"
#include "board.h"
#include "help.h"
#include "input_check.h"

void board (int **arr, int lines, int columns);

int main(int argc, char **argv)
{
    int arr[3][3] = {0};
    board(arr, 3, 3);
    return 0;
}


void board (int **arr, int lines, int columns)
{
    for (int i = 0; i < lines; i++){
        for (int d = 0; d < columns; d++){
            printf("%d", arr[i][d]);
        }
    }
}