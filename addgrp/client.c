#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
int main(int argc, char *argv[])
{
    char *first = argv[1];
    char *second = argv[3];
    char *third = argv[5];
    char *usersInput;
    char* id = argv[2];
    char* password = argv[4];
    char* name = argv[6];
    if (argc == 8)
    {
        usersInput = argv[7];
    }
    if (argc < 7) // if less arguments given
    {
        printf("Less arguements passed \n");
        return 0;
    }    
    if(check(first, second, third) ==1){
        getData(id,password,name,usersInput);
    }
    else{ // wrong syntax 
        printf("Wrong way of using addgroup command \n");
    }    
    putData(); // data added to concerned file
}
