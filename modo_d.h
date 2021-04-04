#ifndef MODO_D
#define MODO_D

void modo_d1(int lines, int columns, int p_num[9]);
void modo_d2(int board[17][26], int lines, int columns, int p_num[9]);
void modo_d3(int lines, int columns, int p_num[9]);
int piece_compare(int board[17][26], int x, int y, int type);
int end(int p_num[9], int p[9]);
int piece_existance(int p_num[9], int p[9]);
int peca_killer_checker(int board[17][26], int x, int y, int p[9], int last);
void anulator(int board[17][26], int x, int y);
int center(int pos);
int y_pc_to_user(int y, int lines);
int x_pc_to_user(int x);

#endif