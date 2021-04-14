#include "headers.h"
#include "modo_p.h"
#include "pieces.h"
#include "restricoes.h"
#include "board.h"


void modo_p1(int lines, int columns, int board[17][26], int p_num[9])
{
    for(int y = 1; y <= lines; y += 3){
        for(int x = 1; x <= columns; x += 3){
            int i = 0;
            while (i < 3){
                int global_id = (rand() % 42);
                if (restricao1(x, y, global_id, columns, lines, board) == -1){
                    i++;
                }
                else {
                    positioning_pieces(x, y, global_id, board);
                    int type = global_id_to_type(global_id);
                    p_num[type]++;
                    break;
                }
            }
            if (i == 3){
                positioning_pieces(x, y, 5, board);
                p_num[1]++;
            }
        }
    }
}

void modo_p2(int lines, int columns, int board[17][26], int p_num[9])
{
    if (restricao3(p_num) != -1 && restricao4(lines, columns, p_num) != -1){ // confirma se a restriçao 3 e 4 sao respeitadas antes de começar a colocar o tabuleiro
        int type; // variavel que vai guardar o tipo da peça gerado randomly
        int instance; // vai guardar a variante da peça quando gerada randomly
        int global_id; // vai guardar o global id correspondente ao tipo e variante gerados
        int counter2 = 0; // conta as vezes que o programa tenta gerar o tabuleiro
        int n_pecas = 0; // vai guardar o numero de peças a colocar
        int x;
        int y;
        for (int i = 1; i < 9; i++) // calcula a soma do total de peças a colocar
            n_pecas += p_num[i];
        p_num[0] = lines * columns / 9 - n_pecas; // calcula o numero de espaços vazio no tabuleiro
        
        while(counter2 < 1000){ // tenta colocar o tabuleiro 1000 vezes, ou corre até conseguir gerar o tabuleiro
            int flag = 0;
            clear_board(board);
            int num[9] = {0}; // num serve para ir descontando as peças que ja foram colocadas
            for (int i = 0; i < 9;i++) // este for copia o numero de peças de cada tipo do p_num para o num
                num[i] = p_num[i];

            for (y = 1; y <= lines; y += 3){
                for (x = 1; x <= columns; x +=3){
                    int try[9] = {0};
                    int counter = 0; // este counter conta as vezes que se tentou outro tipo
                    while(counter < 8){ // enquanto não tentar 8 vezes
                        int c = 0;
                        int arr[9] = {0};
                        while(1){
                            type = (rand() % 9); // gera um numero random de 0 a 8 (0 = espaço vazio, 1-8 tipo da peça)
                            if ((arr[type] == 0) && ((num[type] > 0 && try[type] > 0) || num[type] == 0)){
                                c++;
                                arr[type]++;
                            }
                            if (c == 9){
                                flag = 1;
                                break;
                            }
                            if ((num[type] > 0 && try[type] == 0)){ // se o houver peças do tipo gerado para colocar e se ainda nao tiver sido testada
                                num[type]--; // subtrai 1 peça do tipo gerado 
                                //printf("num of %d: %d\n", type, num[type]);
                                break; // da break no while porque já encontrou um tipo não testado
                            }
                        }
                        if (flag == 1) break;
                        instance = instance_generator(type); // gera uma variante consoante o tipo da peça
                        global_id = global_id_returner(type, instance); // global id em funçao do tipo e da instance
                        if (restricao1(x, y, global_id, columns, lines, board) != -1){ // se cumprir a restriçao 1
                            positioning_pieces(x, y, global_id, board); // coloca a peça
                            break; // dá break do while
                        }
                        else{ // se nao cumprir a a restriçao 1
                            instance = 1; // inicializa a instance a 1
                            global_id = global_id_returner(type, instance); // daá return no global id da primeira instance
                            while (restricao1(x, y, global_id, columns, lines, board) == -1 && global_id <= global_id_returner(type, max_instance(type))){ // enquanto a restriçao 1 não se verificar e o global id for menor ou igual que o global id maximo do tipo da peça
                                global_id++; // soma 1 ao global id
                            }
                            if (global_id > global_id_returner(type, max_instance(type))){ // se o global id tiver passado para um id do proximo tipo de peça
                                counter++; // adiciona 1 ao counter que conta as vezes que ja se mudou o tipo de peça 
                                try[type] = 1; // a tentativa do tipo de peça passa a 1
                                num[type]++; // adiciona 1 as peças que faltam colocar, porque a peça acabou por não ser colocada
                            }
                            else { // se o tiver encontrado um global id possivel dentro do tipo de peça
                                positioning_pieces(x, y, global_id, board); // posiciona a peça
                                break; // e da break do while
                            }
                        }
                    }
                    //board_printer2(board, lines, columns);
                    if (flag == 1) break;
                }
                if (flag == 1) break;
            }
            //printf("counter: %d\n", counter2);
            if ((x > columns) && (y > lines) && (flag == 0)){ // se tiver dado break porque estava no ultimo bloco
                break; // da break porque já colocou o tabuleiro todo
            }
            counter2++;
        }
        if(counter2 == 1000)
            printf("it was impossible to generate a board\n");
    }
}