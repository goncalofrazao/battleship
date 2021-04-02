#include "headers.h"
#include "modo_p.h"
#include "pieces.h"
#include "restricoes.h"
#include "board.h"


void modo_p1(int lines, int columns, int board[17][26], int p_num[9])
{
    int x = 1;
    int y = 1;
    while (1){
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
        if ((x > (columns - 3)) && (y > (lines - 3))){ // finish positioning
            break;
            //printf("columns:%d   lines: %d\n", x, y);
        }
        else if (x > (columns - 3) && y < (lines - 3)){ // go to the first block of the next line
            x = 1; // reset x
            y += 3; // increment y
            //printf("columns:%d   lines: %d\n", x, y);
        }
        else { // go to the next block
            x += 3; // increment x
            //printf("columns:%d   lines: %d\n", x, y);
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
        for (int i = 1; i < 9; i++) // calcula a soma do total de peças a colocar
            n_pecas += p_num[i];
        p_num[0] = lines * columns / 9 - n_pecas; // calcula o numero de espaços vazio no tabuleiro

        while(counter2 < 1000){ // tenta colocar o tabuleiro 1000 vezes, ou corre até conseguir gerar o tabuleiro
            //clear_board(board, lines, columns);
            int num[9] = {0}; // num serve para ir descontando as peças que ja foram colocadas
            for (int i = 0; i < 9;i++) // este for copia o numero de peças de cada tipo do p_num para o num
                num[i] = p_num[i];
            int x = 1; // inicializaçao do x na primeira posiçao
            int y = 1; // inicializaçao do y na primeira posiçao

            while (1){ // corre enquanto não colocar a última peça
                int try[9] = {0}; // esta array serve para confirmar se uma peça já foi testada ou não e inicializa-a a 0
                int counter = 0; // este counter conta as vezes que se tentou outro tipo
                while(counter < 8){ // enquanto não tentar 8 vezes
                    while(1){ 
                        type = (rand() % 9); // gera um numero random de 0 a 8 (0 = espaço vazio, 1-8 tipo da peça)
                        if ((num[type] > 0 && try[type] == 0)){ // se o houver peças do tipo gerado para colocar e se ainda nao tiver sido testada
                            num[type]--; // subtrai 1 peça do tipo gerado 
                            break; // da break no while porque já encontrou um tipo não testado
                        }
                    }
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
                if (counter > 7){ // se o while anterior tiver dado break por causa do contador chegar ao fim
                    counter2++; // adiciona 1 as vezes que o programa ja tentou colocar o tabuleiro
                    break; // e dá break para voltar a tentar colocar o tabuleiro
                }
                else if (x > (columns - 3) && y > (lines - 3)){ // se tiver dado break e tiver colocado a ultima peça
                    //printf("lines:%d\ncolumns: %d\n", lines, columns);
                    break; // dá break do posicionamento
                }
                else if (x > (columns - 3)){ // se tiver chegado ao final de uma linha
                    x = 1; // da reset ao x
                    y += 3; // e incrementa o y para a proxima linha
                    //printf("lines:%d\ncolumns: %d\n", lines, columns);
                }
                else { // caso nenhum dos anteriores se verifique
                    x += 3; // incrementa o x para o proximo bloco
                    //printf("lines:%d\ncolumns: %d\n", lines, columns);
                }
            }
            if (x > (columns - 3) && y > (lines - 3)){ // se tiver dado break porque estava no ultimo bloco
                break; // da break porque já colocou o tabuleiro todo
            }
        }
    }
}