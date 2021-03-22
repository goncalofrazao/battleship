#include "headers.h"
#include "restricoes.h"
#include "pieces.h"

int main(int argc, char **argv)
{
    int columns = 0;
    int lines = 0;
    int global_id = 0;
    int board[15][24] = {0};
    for(int i = 1; i < argc; i ++){
        if (strcmp(argv[i], "-t") == 0){
            if (argv[i + 1][0] != '-'){
                char* aux = strchr(argv[i+1], 'x');
                //printf("%s\n", aux);
                columns = atoi(aux + 1);
                (*aux) = '\0';
                lines = atoi(argv[i+1]);
                //printf("%d\n", columns);
                //printf("%d\n", lines);
                if (columns % 3 != 0 || columns < 9 || columns >24){
                    printf("-1\n");
                    return -1;
                }
                if (lines % 3 != 0 || lines < 9 || lines > 15){
                    printf("-1\n");
                    return -1;
                }
            }
            else{
                printf("-1\n");
                return -1;
            }
        }
    }

}

