/*
Restrição 0) - As peças só podem ser colocadas em quadrículas de 3x3, conforme ilustrado na Fig. 2.
Uma peça não pode ocupar mais do que uma quadrícula de 3x3 definida no tabuleiro. As quadrículas
de 3x3 do tabuleiro definem-se avançando no eixo vertical e no eixo horizontal de 3 em 3. Dado que
o tabuleiro tem sempre dimensão múltipla de 3 em ambos os eixos, pode ser sempre construído com
base num número inteiro de quadrículas de 3x3 em ambas as direções.

Restrição 1) - As peças nunca podem ter arestas ou vértices de contacto com outras peças. A Fig. 3 a)
contém um exemplo de tabuleiro inválido, enquanto a Fig. 3b) contém um tabuleiro semelhante, mas
válido.

Restrição 2) - O número máximo de peças por tabuleiro está limitado a: linhas * colunas / 9. No caso
de o número de peças ser inferior ao limite, devem-se considerar, nos espaços restantes, matrizes de
3x3 vazias.

Restrição 3) - Num jogo, segue-se a regra de nunca ter mais peças de um tipo de maior dimensão
do que peças de um tipo de menor dimensão. Por exemplo:

Restrição 4) - Mais, o número total de peças não deve exceder 50% do número de matrizes 3x3
num tabuleiro. Por exemplo:
*/

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
    for (int i = 8; i > 0; i--){
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
