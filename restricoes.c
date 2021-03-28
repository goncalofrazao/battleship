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

int restricao0()
{

}

int restricao1(int x, int y, int global_id, int columns, int lines)
{
    columns--;
    lines--;
    int flag_up = 0, flag_left = 0, flag_down = 0, flag_right = 0;
    if (x + 3 > columns){
        flag_right = 1;
    }
    if (x - 1 < 0){
        flag_left = 1;
    }
    if (y - 1 < 0){
        flag_up = 1;
    }
    if (y + 3 > lines){
        flag_down = 1;
    }
}

int restricao2(int lines, int columns, int p_num[8])
{
    int sum = 0;
    for (int i = 0; i < 8; i++)
        sum += p_num[i];
    if (sum > (lines * columns / 9)){
        printf("(.)(.)");
        return -1;
    }
    return 1;
}

int restricao3(int p_num[8])
{
    if (p_num[7] > p_num[6]){
        printf(".|.\n");
        return -1;
    }
    if (p_num[6] > p_num[5]){
        printf(".|.\n");
        return -1;
    }
    if (p_num[5] > p_num[4]){
        printf(".|.\n");
        return -1;
    }
    if (p_num[4] > p_num[3]){
        printf(".|.\n");
        return -1;
    }
    if (p_num[3] > p_num[2]){
        printf(".|.\n");
        return -1;
    }
    if (p_num[2] > p_num[1]){
        printf(".|.\n");
        return -1;
    }
    if (p_num[1] > p_num[0]){
        printf(".|.\n");
        return -1;
    }
    return 1;
}

int restricao4(int lines, int columns, int p_num[8])
{
    int sum = 0;
    for (int i = 0; i < 8; i++)
        sum += p_num[i];
    if (sum > (lines * columns / 9 / 2)){
        printf("(.)\n");
        return -1;
    }
    return 1;
}
