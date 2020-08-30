#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 200
#define COLUMNS 100
#include"header.h"

int main(int argc, char *argv[])
{
    if (strcmp(argv[1], "deluser") == 0) //checks if deluser command is given
    {   
        delete(argv[2],"passwd"); //delets user from passwd file
        delete(argv[2],"shadow"); //deletes user from shadow file
    }
    else
    {
        printf("Invalid command \n"); //if anything other than deluser is entered
    }
    if (argc>3){
        printf("Wrong way to use command read docs\n");
    }
   

    return 0;
}
