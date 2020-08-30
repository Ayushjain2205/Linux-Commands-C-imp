#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 200
#define RSIZ 100
#include"header.h"

int main(int argc, char *argv[])
{   
    if (argc < 2) // if less arguments given
    {
        printf("Less arguements passed \n");
        return 0;
    }
    if (strcmp(argv[1], "pwck") == 0)
    {        
        checkShadow();
        checkPasswd();
    }
    else
    {
        printf("Invalid command \n");
    }

    return 0;
}
