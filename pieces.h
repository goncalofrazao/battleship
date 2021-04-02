#ifndef PIECES
#define PIECES

extern const int piece[43][5][5];
int global_id_returner(int type_id, int instance_id);
void positioning_pieces(int x, int y, int global_id, int board[17][26]);
int instance_generator(int type);
int max_instance(int type);
int global_id_to_type(int global_id);


#endif