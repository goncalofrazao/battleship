#include "headers.h"
#include "restricoes.h"
#include "pieces.h"

int restricao1(int x, int y, int global_id, int columns, int lines, int board[17][26])
{
    for (int i = 1; i < 4; i++){
        for (int d = 1; d < 4; d++){
            if (board[y - 1 + i][x - 1 + d] == -1 && piece[global_id][i][d] > 0)
                return -1;
        }
    }
    return 1;
}

int restricao2(int lines, int columns, int p_num[9])
{
    int sum = 0;
    for (int i = 1; i < 9; i++)
        sum += p_num[i];
    if (sum > (lines * columns / 9)){
        printf("(.)(.)");
        return -1;
    }
    return 1;
}

int restricao3(int p_num[9])
{
    for (int i = 8; i > 1; i--){
        if (p_num[i] > p_num[i - 1]){
            printf(".|.\n");
            return -1;
        }
    }
    return 1;
}

int restricao4(int lines, int columns, int p_num[9])
{
    int n_pecas = 0;
    for (int i = 1; i < 9; i++)
        n_pecas += p_num[i];
    if (n_pecas > (lines * columns / 9 / 2)){
        printf("(.)\n");
        return -1;
    }
    return 1;
}
