#ifndef MODO_D
#define MODO_D

void modo_d1(int board[17][26], int lines, int columns);
void modo_d2(int board[17][26], int lines, int columns);
void rebentador_de_tabuleiros(int board[17][26], int lines, int columns);
int end_check(int board[17][26], int lines, int columns);
int peca_killer_checker(int board[17][26], int x, int y);
void anulator(int board[17][26], int x, int y);

#endif