#include "headers.h"
#include "pieces.h"

int global_id_returner(int type_id, int instance_id)
{
    int global_id;
    switch (type_id)
    {
    case 1:
        switch (instance_id)
        {
        case 1:
            global_id = 1;
            break;

        case 2:
            global_id = 2;
            break;
        
        break;


        }
    }
    return global_id;
}