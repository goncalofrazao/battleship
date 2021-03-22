#include "headers.h"
#include "restricoes.h"
#include "pieces.h"

int main(int argc, char **argv)
{
    if (argc == 2)
        printf("nice\n");
    
    printf("%c\n", argv[1][0]);
    switch (argv[1][1])
    {
    case 'h':
        printf("fds\n");
        break;
    
    default:
        break;
    }
    return 0;
}
